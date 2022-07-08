/*
 *  RadiusClass -- An C++-Library for radius authentication 
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
 
#include "RadiusConfig.h"


/** The constructor The constructor initializes all char arrays with 0.
 */

RadiusConfig::RadiusConfig(void)
{
	
	memset(this->nasPortType,0,2);
	memset(this->framedProtocol,0,2);
	memset(this->serviceType,0,2);
	memset(this->nasIdentifier,0,128);
	memset(this->nasIpAddress,0,16);
	
}

/** The constructor initializes all char arrays with 0. After the initialization
 * the configfile is parsed and the information which are
 * found are copied to the attributes.
 * @param configfile The name of the configfile.
 */

RadiusConfig::RadiusConfig(string configfile)
{
	memset(this->nasPortType,0,2);
	memset(this->framedProtocol,0,2);
	memset(this->serviceType,0,2);
	memset(this->nasIdentifier,0,128);
	memset(this->nasIpAddress,0,16);
	this->parseConfigFile(configfile.c_str());
}


/** The destructur clears the serverlist. */
RadiusConfig::~RadiusConfig(void)
{
	
	server.clear();
	
}

/** The getter method for the radius server list.
 * @return The server list.*/

list<RadiusServer> * RadiusConfig::getRadiusServer(void)
{
	return (&server);
}

/** The method parse the configfile for attributes and 
 * radius server, the attributes are copied to the
 * member variables.
 * @param configfile The name of the configfile.
 * @return An integer, 0 if everything is ok 
 * or PARSING_ERROR or BAD_FILE if something is wrong.*/
int RadiusConfig::parseConfigFile(const char * configfile)
{
	string line;
	
	RadiusServer *tmpServer=NULL;
	ifstream file;
	file.open(configfile, ios::in);
	if (file.is_open())
	{
		while (file.eof()==false)
		{
			getline(file,line);
			this->deletechars(&line);
			if (strncmp(line.c_str(),"Framed-Protocol=",16)==0)
			{
				if((line.size()-16)>2)
				{
					return BAD_FILE;
				}
				line.copy(this->framedProtocol,line.size()-16,16);
			}
			if (strncmp(line.c_str(),"NAS-Port-Type=",14)==0)
			{
				if((line.size()-14)>1)
				{
					return BAD_FILE;
				}
				line.copy(this->nasPortType,line.size()-14,14);
			}
			if (strncmp(line.c_str(),"Service-Type=",13)==0)
			{
				if((line.size()-13)>1)
				{
					return BAD_FILE;
				}
				line.copy(this->serviceType,line.size()-13,13);
			}
			if (strncmp(line.c_str(),"NAS-Identifier=",15)==0)
			{
				if((line.size()-15)>127)
				{
					return BAD_FILE;
				}
				line.copy(this->nasIdentifier,line.size()-15,15);
			}
			if (strncmp(line.c_str(),"NAS-IP-Address=",15)==0)
			{
				if((line.size()-15)>15)
				{
					return BAD_FILE;
				}
				line.copy(this->nasIpAddress,line.size()-15,15);
			}
			if(strncmp(line.c_str(),"server",6)==0)
			{
				tmpServer=new RadiusServer;
				while((line.find("{")==string::npos) && (file.eof()==false))
				{
					getline(file,line);
					deletechars(&line);
					if(line.find_first_not_of("}"))
					{
						return PARSING_ERROR;	
					}
				}
				
				while (strstr(line.c_str(),"}")==NULL && (file.eof()==false))
				{
					
					getline(file,line);
					deletechars(&line);
						
					if (strncmp(line.c_str(),"authport=",9)==0) 
					{
						tmpServer->setAuthPort(atoi(line.substr(9,5).c_str()));
					}
					if (strncmp(line.c_str(),"acctport=",9)==0)
					{
						tmpServer->setAcctPort(atoi(line.substr(9,5).c_str()));
					}
					if (strncmp(line.c_str(),"name=",5)==0)
					{
						tmpServer->setName(line.substr(5));
					}
					if (strncmp(line.c_str(),"retry=",6)==0)
					{
						tmpServer->setRetry(atoi(line.substr(6).c_str()));
					}
					if (strncmp(line.c_str(),"sharedsecret=",13)==0)
					{
						tmpServer->setSharedSecret(line.substr(13));
					}
					if (strncmp(line.c_str(),"wait=",5)==0)
					{
						tmpServer->setWait(atoi(line.substr(5).c_str()));
					}
				}
				if(strstr(line.c_str(),"}"))
				{
					this->server.push_back(*tmpServer);
				}
				//No "}" was found - something in config is wrong
				else
				{
					return PARSING_ERROR;
				}
				
				
				if (tmpServer!=NULL)
				{
					delete tmpServer;
				}
			}
		}
		file.close();
	}
	else
	{
		return BAD_FILE;
	}
	return 0;
}
	
	
/** The method deletes chars from a string.
 * This is used to delete tabs, spaces, # and '\0'
 * from a string.
 * @param text The string which should be cleaned.
 */ 
/** The method deletes chars from a string.
 * This is used to delete tabs, spaces, # and '\0'
 * from a string.
 * @param text The string which should be cleaned.
 */ 
void RadiusConfig::deletechars(string * line)
{
	char const* delims = " \t\r\n\0";
    
   // trim leading whitespace
   string::size_type  pos = line->find_first_not_of(delims);
   if (pos != string::npos) line->erase(0,pos );

   // trim trailing whitespace
   pos  = line->find_last_not_of(delims); 
   if (pos != string::npos)  line->erase(pos+1);
   
   //trim whitespaces in line
   pos  = line->find_first_of(delims);
   while (pos != string::npos) 
   {
   	 line->erase(pos);
   	 pos  = line->find_first_of(delims);
   }
   
   // trim comments
   pos  = line->find_first_of("#");
   if (pos != string::npos) line->erase(pos);
}


/**The method finds the part of the string after the
 * '=' and puts it in the value.
 * @param text The string with the value.
 * @param value The value where to put the part of the string. */
void RadiusConfig::getValue(const char * text, char * value)
{
	
	int i=0,j=0;
	while (text[i]!='=' && text[i]!='\0')
	{
		i++;
	}
	i++;
	while (text[i]!='\0')
	{
		value[j]=text[i];
		i++;
		j++;
	}
	value[j]='\0';
}


/** The setter method for the service type.
 * @param type A string with the service type.*/
void RadiusConfig::setServiceType(char * type)
{
	strncpy(this->serviceType, type, 2);
}

/** The getter method for the service type
 * @return A pointer to the service type.*/
char * RadiusConfig::getServiceType(void)
{
	return this->serviceType;
}
	
/** The setter method for the framed protocol.
 * @param proto A string with the framed protocol.*/
void RadiusConfig::setFramedProtocol(char * proto)
{
	strncpy(this->framedProtocol, proto, 2);
}

/**The getter method for the framed protocol
 * @return A pointer to the framed protocol.
 */
char * RadiusConfig::getFramedProtocol(void)
{
	return this->framedProtocol;
}

/** The setter method for the nas port type.
 * @param type A string with the nas port type.
 */

void RadiusConfig::setNASPortType(char * type)
{
	strncpy(this->nasPortType, type, 2);
}

/** The getter method for the nas port type.
 * @return A pointer to the nas port type.
 */
char * RadiusConfig::getNASPortType(void)
{
	return this->nasPortType;
}

/** The setter method for the nas identifier.
 * @param identifier A string with the identifier.
 */
void RadiusConfig::setNASIdentifier(char * identifier)
{
	strncpy(this->nasIdentifier,identifier, 128);
}

/** The getter method for the nas identifier.
 * @return A pointer to the nas identifier.
 */
char * RadiusConfig::getNASIdentifier(void)
{
	return this->nasIdentifier;
}


/** The setter method for the nas ip address.
 * @param ip A string with ip address.
 */	
void RadiusConfig::setNASIpAddress(char * ip)
{
	strncpy(this->nasIpAddress,ip, 16);
}


/** The getter method for the nas ip address.
 * @return A pointer to the nas ipaddress.
 */
char * RadiusConfig::getNASIpAddress(void)
{
	return this->nasIpAddress;
}

ostream& operator << (ostream& os, RadiusConfig& config)
{
     list<RadiusServer> * serverlist;
	 list<RadiusServer>::iterator server;
     os << "RadiusConfig: \n";
     os << "\nFramedProtocol: " << config.getFramedProtocol();
     os << "\nNASIdentifier: "<< config.getNASIdentifier();
     os << "\nNASIpAdress: "<< config.getNASIpAddress();
     os << "\nNASPortTyoe: "<< config.getNASPortType();
     os << "\nServiceType: " << config.getServiceType();
    
	//get the server list
	serverlist=config.getRadiusServer();
	//set server to the first server
	server=serverlist->begin();
 	while(server != serverlist->end())
 	{
 		cout << *server;
 		server++;
 	}
 	
 	return os;
 	
}
	
