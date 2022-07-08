/*
 *  radiusplugin -- An OpenVPN plugin for do radius authentication 
 *					and accounting.
 * 
 *  Copyright (C) 2005 EWE TEL GmbH/Ralf Luebben <ralfluebben@gmx.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
#include "AcctScheduler.h"
#include "PluginContext.h"
#include "RadiusClass/RadiusConfig.h"
#include "Config.h"
#include "radiusplugin.h"




using namespace std;

/** The constructor of the class.
 * Nothing happens here.
 */

AcctScheduler::AcctScheduler()
{
}

/**The destructor of the class.
 * The user lists are cleared here.
 */
AcctScheduler::~AcctScheduler()
{
	activeuserlist.clear();
	passiveuserlist.clear();
}

/** The method adds an user to the user lists. An user with an acct interim 
 * interval is added to the activeuserlist, an user
 * without this interval is added to passiveuserlist.
 * @param user A pointer to an object from the class UserAcct.
 */
void AcctScheduler::addUser(UserAcct *user)
{
	if (user->getAcctInterimInterval()==0)
	{
		
		this->passiveuserlist.insert(make_pair(user->getKey(),*user));
	}
	else
	{
		this->activeuserlist.insert(make_pair(user->getKey(),*user));
	}
}

/** The method deletes an user from the user lists. Before 
 * the user is deleted the status file is parsed for the sent and received bytes
 * and the stop accounting ticket is send to the server.
 * @param context The plugin context as an object from the class PluginContext.
 * @param user A pointer to an object from the class UserAcct
 */
void AcctScheduler::delUser(PluginContext * context, UserAcct *user)
{
	
	if (DEBUG (context->getVerbosity()))
	    cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Got accounting data from file, CN: " << user->getCommonname() << " in: " << user->getBytesIn() << " out: " << user->getBytesOut() << ".\n";
	
	
	//send the stop ticket
	if (user->sendStopPacket(context)==0)
	{
			if (DEBUG (context->getVerbosity()))
		    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Stop packet was sent. CN: " << user->getCommonname() << ".\n";
	}
	else 
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Error on sending stop packet.";
	}
	
	if (user->getAcctInterimInterval()==0)
	{
		passiveuserlist.erase(user->getKey());
	}
	else
	{
		
		activeuserlist.erase(user->getKey());
	}

}


/** The method deletes all users from the user lists. Before 
 * the user is deleted the status file is parsed for the sent and received bytes
 * and the stop accounting ticket is send to the server.
 * @param context The plugin context as an object from the class PluginContext.
 */
void AcctScheduler::delallUsers(PluginContext * context)
{
	map<string, UserAcct>::iterator iter1, iter2;
	if (DEBUG (context->getVerbosity()))
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Delete all users.";
	iter1=activeuserlist.begin();
	iter2=activeuserlist.end();
		
	
	while (iter1!=iter2)
	{
		this->delUser(context,&(iter1->second));
		iter1++;
	}
	
}

/** The accounting method. When the method is called it
 * searches for users in activeuserlist for users who need an update.
 * If a user is found the sent and received bytes are read from the
 * OpenVpn status file.
 * @param context The plugin context as an object from the class PluginContext.
 */

void AcctScheduler::doAccounting(PluginContext * context)
{	
	time_t t;
		
	uint64_t bytesin=0, bytesout=0;
	map<string, UserAcct>::iterator iter1, iter2;
	
	
	iter1=activeuserlist.begin();
	iter2=activeuserlist.end();
		
	
	while (iter1!=iter2)
	{
		//get the time
		time(&t);
		//if the user needs an update
		if ( t>=iter1->second.getNextUpdate())
		{
			if (DEBUG (context->getVerbosity()))
		    cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Scheduler: Update for User " << iter1->second.getUsername() << ".\n";
					
			this->parseStatusFile(context, &bytesin, &bytesout,iter1->second.getStatusFileKey().c_str()); 
			if (bytesin > 0 && bytesout > 0){
				iter1->second.setBytesIn(bytesin & 0xFFFFFFFF);
				iter1->second.setBytesOut(bytesout & 0xFFFFFFFF);
				iter1->second.setGigaIn(bytesin >> 32);
				iter1->second.setGigaOut(bytesout >> 32);
				iter1->second.sendUpdatePacket(context);

				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Scheduler: Update packet for User " << iter1->second.getUsername() << " was send.\n";
			}else{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Scheduler: Don't update for "<< iter1->second.getUsername() << " because of lack of data.\n";
			}
		
			//calculate the next update
			iter1->second.setNextUpdate(iter1->second.getNextUpdate()+iter1->second.getAcctInterimInterval());
		}
		iter1++;
	}
}

/**The method parses the status file for accounting information. It reads the bytes sent
 * and received from the status file. It finds the values about the commonname. The method will
 * only work if there are no changes in the structure of the status file.
 * The method was tested with OpenVpn 2.0.
 * @param context The plugin context as an object from the class PluginContext.
 * @param bytesin An int pointer for the received bytes.
 * @param bytesout An int pointer for the sent bytes.
 * @param key  A key which identifies the row in the statusfile, it looks like: "commonname,ip:port".
 */
void AcctScheduler::parseStatusFile(PluginContext *context, uint64_t *bytesin, uint64_t *bytesout, string key)
{
	char line[512], newline[512];
	memset(newline, 0, 512);
	
	//open the status file to read
	ifstream file(context->conf.getStatusFile().c_str(), ios::in);
	if (file.is_open())
	{
		if (DEBUG (context->getVerbosity()))
			 cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND ACCT: Scheduler: Read Statusfile.\n";
	  	
	  	//find the key, is delimited with a ',' from the informations
	  	
	  	//loop until the name is found, there is no delimiter, the string
	  	//"ROUTING TABLE" is found or EOF
		
		do
		{
			file.getline(line, 512);
			
		}
		while (line!=NULL && strncmp(line,key.c_str(),key.length())!=0 && strcmp(line,"ROUTING TABLE")!=0 && file.eof()==false);
		
		
		//the information is behind the next delimiters
		if (line!=NULL && strncmp(line,key.c_str(),key.length())==0)
		{
			memcpy(newline, line+key.length(), strlen(line)-key.length()+1);
			*bytesin=strtoull(strtok(newline,","),NULL,10);
			*bytesout=strtoull(strtok(NULL,","),NULL,10);
		}
		else
		{
			
			cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND ACCT: No accounting data was found for "<< key << " in file " << context->conf.getStatusFile() << endl;
			
		}
		file.close();
	}
	else
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Statusfile "<< context->conf.getStatusFile() <<" could not opened.\n";
	}
}

/** The method finds an user.
 * @param key The commonname of the user to find.
 * @return A poniter to an object of the class UserAcct.
 */
UserAcct * AcctScheduler::findUser(string key)
{
	map<string, UserAcct>::iterator iter;
	iter=activeuserlist.find(key);
	if (iter!=activeuserlist.end())
	{
		return &(iter->second);
	}
	iter=passiveuserlist.find(key);
	if (iter!=passiveuserlist.end())
	{
		return &(iter->second);
	}
	
	return NULL;
}
