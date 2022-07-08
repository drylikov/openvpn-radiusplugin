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
 
#include "PluginContext.h"



/** The constructor. All sockets all set to -1, the process ids and the
 * verbosity level are set to 0. The session id is set to to 1.*/
PluginContext::PluginContext()
{
	
  	this->authsocketforegr.setSocket(-1);
  	this->authsocketbackgr.setSocket(-1);
	this->acctsocketforegr.setSocket(-1);
	this->acctsocketbackgr.setSocket(-1);
  	
  	this->authpid=0;
  	this->acctpid=0;
 	
  	this->verb=0;
  	this->sessionid=1;

        this->stopthread=false;
	this->startthread=true;

        pthread_mutex_init(&usermutex, NULL);
}

/** The destructor clears the users and nasportlist.*/
PluginContext::~PluginContext()
{
	this->users.clear();
	this->nasportlist.clear();
	pthread_mutex_destroy(&usermutex);
}

/** The method searches the first free nas port in a list.
 * @return The nas port.
 */
int PluginContext::addNasPort(void)
{
	int newport=0;
	list<int>::iterator i;
	list<int>::iterator j;
	i=nasportlist.begin();
	j=nasportlist.end();
	
	if (this->nasportlist.empty())
	{
		newport=1;
		this->nasportlist.push_front(newport);
	}
	
	else
	{
		newport=1;
		while( i != this->nasportlist.end()) 
		{
		    if (newport < *i)
		    {
		    	j=i;
		    	i=this->nasportlist.end();
		    }
		    else
		    {
		    	i++;
		    	newport++;
		    }
		}
		this->nasportlist.insert(j, newport);
	}
	return newport;
}

/**The method deletes the nas port from the list.
 * @param The nas port number to delete.
 */
void PluginContext::delNasPort(int num)
{
	this->nasportlist.remove(num);
}

/**The method adds an user to the user map of the foreground
 * process.
 * @param newuser A pointer to the user.
 * @throws Exception::ALREADYAUTHENTICATED if the user could not add to the map, this happens if a user with the key is already in the list.
 */
void PluginContext::addUser(UserPlugin * newuser)
{
	pair<map<string,UserPlugin *>::iterator,bool> success;
	
	success=users.insert(make_pair(newuser->getKey(),newuser));
	
	if(success.second==false)
	{
		throw Exception(Exception::ALREADYAUTHENTICATED);
	}
	else
	{
		this->sessionid++;
	}
	
}

/**The method deletes the user from the map with the key.
 * @param key The key of the user.
 */
void PluginContext::delUser(string key)
{
	users.erase(key);	
}

/**The method finds a user in the user map.
 * @param key The key of the user.
 * @return A pointer to the user.
 */
UserPlugin * PluginContext::findUser(string key)
{
	map<string,UserPlugin *>::iterator iter =  users.find(key);
	if (iter != users.end())
	{
		return iter->second;
	}
	return NULL;
}


/** The getter method for the verbosity level.
 * @return The verbosity level.
 */
int PluginContext::getVerbosity(void)
{
	return this->verb;
}

/** The setter method for the verbosisty level.
 * @param v The verbosity level.
 */
void PluginContext::setVerbosity(int v)
{
	this->verb=v;
}

/** The getter method for the authentication
 * background process id.
 * @returns The process id.
 */
pid_t PluginContext::getAuthPid(void)
{				
	return this->authpid;
}

/** The setter method for the authentication
 * background process id.
 * @param The process id.
 */
void PluginContext::setAuthPid(pid_t p)
{
	this->authpid=p;
} 

/** The getter method for the accounting
 * background process id.
 * @returns The process id.
 */	
pid_t PluginContext::getAcctPid(void)
{
	return this->acctpid;
}	

/** The setter method for the accounting
 * background process id.
 * @param The process id.
 */		
void PluginContext::setAcctPid(pid_t p)
{
	this->acctpid=p;
}


/** The setter method method for the session id.
 * @returns The sessionid.
 */
int PluginContext::getSessionId(void)
{
	return this->sessionid;
}


/**The method adds an new user to the user list of users waiting for authentication
 * @param newuser A pointer to the user.
 */
void PluginContext::addNewUser(UserPlugin * newuser)
{
  pthread_mutex_lock(&usermutex);
  this->newusers.push_back(newuser);
  pthread_mutex_unlock(&usermutex);
}

/**The method adds an new user to the user list of users waiting for accounting
 * @param newuser A pointer to the user.
 */
void PluginContext::addNewAcctUser(UserPlugin * newuser)
{
  pthread_mutex_lock(&usermutex);
  this->newacctusers.push_back(newuser);
  pthread_mutex_unlock(&usermutex);
}

/**The method return the first element in the list of waiting for authentication users.
 */
UserPlugin * PluginContext::getNewUser()
{
    
      pthread_mutex_lock(&usermutex);
      UserPlugin * user = this->newusers.front();
      this->newusers.pop_front();
      pthread_mutex_unlock(&usermutex);
      return user;
	
}

/**The method return the first element in the list of waiting for accounting users.
 */
UserPlugin * PluginContext::getNewAcctUser()
{
    
      pthread_mutex_lock(&usermutex);
      UserPlugin * user = this->newacctusers.front();
      this->newacctusers.pop_front();
      pthread_mutex_unlock(&usermutex);
      return user;
	
}

pthread_cond_t  * PluginContext::getCondSend(void )
{
  return &condsend;
}
pthread_cond_t  * PluginContext::getCondRecv(void )
{
  return &condrecv;
}

pthread_mutex_t * PluginContext::getMutexSend(void )
{
  return &mutexsend;
}

pthread_mutex_t * PluginContext::getMutexRecv(void )
{
  return &mutexrecv;
}

pthread_cond_t  * PluginContext::getAcctCondSend(void )
{
  return &acctcondsend;
}
pthread_cond_t  * PluginContext::getAcctCondRecv(void )
{
  return &acctcondrecv;
}

pthread_mutex_t * PluginContext::getAcctMutexSend(void )
{
  return &acctmutexsend;
}

pthread_mutex_t * PluginContext::getAcctMutexRecv(void )
{
  return &acctmutexrecv;
}


pthread_t * PluginContext::getThread()
{
  return &thread;
}

pthread_t * PluginContext::getAcctThread()
{
  return &acctthread;
}

int PluginContext::getResult()
{
  return result;
}

void PluginContext::setResult(int r)
{ 
  result=r;
}

bool PluginContext::UserWaitingtoAuth()
{
  bool result;

  pthread_mutex_lock(&usermutex);
  result = this->newusers.size()>0;
  pthread_mutex_unlock(&usermutex);
  return result;
} 

bool PluginContext::UserWaitingtoAcct()
{
  bool result;

  pthread_mutex_lock(&usermutex);
  result = this->newacctusers.size()>0;
  pthread_mutex_unlock(&usermutex);
  return result;
} 


bool PluginContext::getStopThread()
{
  return stopthread;
}

void PluginContext::setStopThread(bool s)
{
  stopthread=s;
}


bool PluginContext::getStartThread()
{
  return startthread;
}

void PluginContext::setStartThread(bool value)
{
  startthread=value;
}

