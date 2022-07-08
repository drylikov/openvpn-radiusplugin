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


#include "Config.h"


/** The constructor The constructor initializes all char arrays with 0.
 */

Config::Config(void)
{
	
	this->usernameascommonname=false;
	this->clientcertnotrequired=false;
	this->overwriteccfiles=true;
        this->useauthcontrolfile=false;
        this->useclientconnectdeferfile=false;
	this->accountingonly=false;
	this->nonfatalaccounting=false;
	this->defacctinteriminterval=0;
	this->ccdPath="";
	this->openvpnconfig="";
	this->vsanamedpipe="";
	this->vsascript="";
	memset(this->subnet,0,16);
	memset(this->p2p,0,16);
	memset(this->p2p6,0,40);
}

/** The constructor initializes all char arrays with 0. After the initialization
 * the configfile is parsed and the information which are
 * found are copied to the attributes.
 * @param configfile The name of the configfile.
 */

Config::Config(char * configfile)
{
	memset(this->subnet,0,16);
	memset(this->p2p,0,16);
	memset(this->p2p6,0,40);
	this->ccdPath="";
	this->openvpnconfig="";
	this->vsanamedpipe="";
	this->vsascript="";
	this->usernameascommonname=false;
	this->clientcertnotrequired=false;
	this->overwriteccfiles=true;	
        this->useauthcontrolfile=false;
        this->useclientconnectdeferfile=false;
	this->accountingonly=false;
	this->nonfatalaccounting=false;
	this->defacctinteriminterval=0;
	this->parseConfigFile(configfile);
	
}


/** The destructur clears the serverlist. */
Config::~Config(void)
{
	
	
}



/** The method parse the configfile for attributes and 
 * radius server, the attributes are copied to the
 * member variables.
 * @param configfile The name of the configfile.
 * @return An integer, 0 if everything is ok 
 * or PARSING_ERROR or BAD_FILE if something is wrong.*/
int Config::parseConfigFile(const char * configfile)
{
	string line;
	
	ifstream file;
	file.open(configfile, ios::in);
	if (file.is_open())
	{
		while (file.eof()==false)
		{
			getline(file,line);
			this->deletechars(&line);
			if(line.empty()==false)
			{
				if (strncmp(line.c_str(),"subnet=",7)==0)
				{
					if((line.size()-7)>15)
					{
						return BAD_FILE;
					}
					line.copy(this->subnet,line.size()-7,7);
					
				}
				if (strncmp(line.c_str(),"p2p=",4)==0)
				{
					if((line.size()-4)>15)
					{
						return BAD_FILE;
					}
					line.copy(this->p2p,line.size()-4,4);
				}
				if (strncmp(line.c_str(),"p2p6=",5)==0)
				{
					if((line.size()-5)>39)
					{
						return BAD_FILE;
					}
					line.copy(this->p2p6,line.size()-5,5);
				}
				if (strncmp(line.c_str(),"vsascript=",10)==0)
				{
					this->vsascript=line.substr(10,line.size()-10);
				}
				if (strncmp(line.c_str(),"vsanamedpipe=",13)==0)
				{
					this->vsanamedpipe=line.substr(13,line.size()-13);
				}
							
				if (strncmp(line.c_str(),"OpenVPNConfig=",14)==0)
				{
					this->openvpnconfig=line.substr(14,line.size()-14);
				}
				if (strncmp(line.c_str(),"overwriteccfiles=",17)==0)
				{
					
					string stmp=line.substr(17,line.size()-17);
					deletechars(&stmp);
					if(stmp == "true") this->overwriteccfiles=true;
					else if (stmp =="false") this->overwriteccfiles=false;
					else return BAD_FILE;
						
				}
                                if (strncmp(line.c_str(),"useauthcontrolfile=",19)==0)
				{
					
					string stmp=line.substr(19,line.size()-19);
					deletechars(&stmp);
					if(stmp == "true") this->useauthcontrolfile=true;
					else if (stmp =="false") this->useauthcontrolfile=false;
					else return BAD_FILE;
						
				}
                                if (strncmp(line.c_str(),"useclientconnectdeferfile=",26)==0)
				{

					string stmp=line.substr(26,line.size()-26);
					deletechars(&stmp);
					if(stmp == "true") this->useclientconnectdeferfile=true;
					else if (stmp =="false") this->useclientconnectdeferfile=false;
					else return BAD_FILE;

				}
				if (strncmp(line.c_str(),"accountingonly=",15)==0)
				{
					
					string stmp=line.substr(15,line.size()-15);
					deletechars(&stmp);
					if(stmp == "true") this->accountingonly=true;
					else if (stmp =="false") this->accountingonly=false;
					else return BAD_FILE;
						
				}
				if (strncmp(line.c_str(),"nonfatalaccounting=",19)==0)
				{
					
					string stmp=line.substr(19,line.size()-19);
					deletechars(&stmp);
					if(stmp == "true") this->nonfatalaccounting=true;
					else if (stmp =="false") this->nonfatalaccounting=false;
					else return BAD_FILE;
						
				}
				if (strncmp(line.c_str(),"defacctinteriminterval=",23)==0)
				{

					string stmp=line.substr(23,line.size()-23);
					deletechars(&stmp);
					char *stemp;
					long defacctinteriminterval = 0;
					defacctinteriminterval = strtol(stmp.c_str(), &stemp, 0);
					if (stemp == stmp.c_str() || *stemp != '\0' || defacctinteriminterval < 0)
						return BAD_FILE;
					this->defacctinteriminterval=(int)defacctinteriminterval;
				}
			}
			
		}
		file.close();
		// if the main files contains references to other config files
		// we don't need to care about recursive includes, OpenVPN does it already
		list<string> configfiles; 
		configfiles.push_back(this->openvpnconfig);
		//open OpenVPN config
		while(configfiles.size() > 0)
		{
		  ifstream file2;
		  string filename=configfiles.front();
		  file2.open(filename.c_str(), ios::in);
		  char const* delims = " \t\r\n\0";
		  if (file2.is_open())
		  {
			  while(file2.eof()==false)
			  {
				  getline(file2,line);
				  
				  if(line.empty()==false)
				  {
					  string param=line;
					  // trim leading whitespace
					  string::size_type  pos = param.find_first_not_of(delims);
					  if (pos != string::npos) param.erase(0,pos );
					  pos=param.find_first_of(delims);
					  if (pos != string::npos) param.erase(pos);
					  if (param == "client-cert-not-required")
					  {
						  this->deletechars(&line);
						  if (line == "client-cert-not-required")
						  {
							  this->clientcertnotrequired=true;
						  }
					  }
					  if (param == "username-as-common-name")
					  {
						  this->deletechars(&line);
						  if (line == "username-as-common-name")
						  {
							  this->usernameascommonname=true;
						  }
					  }
					  if (param == "client-config-dir")
					  {
						  this->deletechars(&line);
						  line.erase(0, 17);
						  this->setCcdPath(line);
					  }
					  if (param == "config")
					  {
						  this->deletechars(&line);
						  line.erase(0, 6);
						  configfiles.push_back(line);
					  }
					  if (param == "status")
					  {
						  //method deletechars don't work, entry has formet: status <file> [time]
						  pos  = line.find_first_of("#");
						  if (pos != string::npos) 
						  {
							  line.erase(pos);
						  }
						  // trim leading whitespace
						  pos = line.find_first_not_of(delims);
						  if (pos != string::npos) line.erase(0,pos);
						  line.erase(0, 6);
						  // trim leading whitespace again
						  pos = line.find_first_not_of(" \t");
						  if (pos != string::npos) line.erase(0,pos);
						  //delete the trailing version of status if there
						  pos = line.find_first_of(delims);
						  if (pos != string::npos) line.erase(pos);
						  this->deletechars(&line);
						  if(!line.empty())
						  {
							    
						    this->statusfile=line;
						  }
					  }	
				  }
			  }
			  file.close();
			  configfiles.remove(filename);
		  }
		  else
		  {
			  return BAD_FILE;
		  }
		}
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
void Config::deletechars(string * line)
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
   	 line->erase(pos,1);
   	 pos  = line->find_first_of(delims);
   }
   
   // trim comments
   pos  = line->find_first_of("#");
   if (pos != string::npos) 
   {
   	line->erase(pos);
   }
   
}


/**The method finds the part of the string after the
 * '=' and puts it in the value.
 * @param text The string with the value.
 * @param value The value where to put the part of the string. */
void Config::getValue(const char * text, char * value)
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




	
/** The getter methid for the client config dir (ccd).
 * @return A string to the ccd.
 */
string Config::getCcdPath(void)
{
	return this->ccdPath;
}


/** The setter method for the client config dir (ccd).
 * @param path A string to the ccd path.
 */
void Config::setCcdPath(string path)
{
	if(path[path.length()]!= '/')
	{
		path +='/';	
	}
	this->ccdPath=path;
}

/** Returns the path to the status file.
 * @param A string to path of the status file.
 */
string Config::getStatusFile(void)
{
	return this->statusfile;
}

/** The setter method for thepath to the statusfile (path + filename).
 * @param file A string of the filepath.
 */
void Config::setStatusFile(string file)
{
	
	this->statusfile=file;
}

/** The setter method for the nas ip address.
 * @param ip A string with ip address.
 */	
void Config::setSubnet(char * ip)
{
	strncpy(this->subnet,ip, 16);
}


/** The getter method for the nas ip address.
 * @return A pointer to the nas ipaddress.
 */
char * Config::getSubnet(void)
{
	return this->subnet;
}

/** The setter method for the p2p address.
 * @param ip A string with p2p address.
 */	
void Config::setP2p(char * ip)
{
	strncpy(this->p2p,ip, 16);
}


/** The getter method for the p2p address.
 * @return A pointer to the p2p address.
 */
char * Config::getP2p(void)
{
	return this->p2p;
}

/** The setter method for the p2p6 address.
 * @param ip A string with p2p6 address.
 */	
void Config::setP2p6(char * ip)
{
	strncpy(this->p2p6,ip, 40);
}


/** The getter method for the p2p6 address.
 * @return A pointer to the p2p6 address.
 */
char * Config::getP2p6(void)
{
	return this->p2p6;
}

/** The setter method for the vsascript.
 * @param script A path of the script.
 */	
void Config::setVsaScript(string script)
{
	this->vsascript=script;
}


/** The getter method for vsascript.
 * @return A pointer to the path of the script.
 */
string Config::getVsaScript(void)
{
	return this->vsascript;
}

/** The setter method for the usernameascommonname value.
 * @param b A boolean for option usernameascommonname.
 */	
void Config::setUsernameAsCommonname(bool b)
{
	this->usernameascommonname=b;
}


/** The getter method for the usernameascommonname value.
 * @return A boolean for option usernameascommonname.
 */
bool Config::getUsernameAsCommonname(void)
{
	return this->usernameascommonname;
}

/** The setter method for the vsanamedpipe.
 * @param script A path of the pipe.
 */	
void Config::setVsaNamedPipe(string pipe)
{
	this->vsanamedpipe=pipe;
}


/** The getter method for vsanamedpipe.
 * @return A pointer to the path of the pipe.
 */
string Config::getVsaNamedPipe(void)
{
	return this->vsanamedpipe;
}


/** The setter method for the clientcertnotrequired value.
 * @param b A boolean for option clientcertnotrequired.
 */	
void Config::setClientCertNotRequired(bool b)
{
	this->clientcertnotrequired=b;
}


/** The getter method for the clientcertnotrequired value.
 * @return A boolean for option clientcertnotrequired.
 */
bool Config::getClientCertNotRequired(void)
{
	return this->clientcertnotrequired;
}

/** The getter method for the path to the OpenVPN config
 * @return A string to the path.
 */
string Config::getOpenVPNConfig(void)
{
	return this->openvpnconfig;	
}

/** The setter method for the path to the OpenVPN config
 * @param conf Path to the config file.
 */
void Config::setOpenVPNConfig(string conf)
{
	this->openvpnconfig=conf;
}

/** The getter method for the overwriteccfiles variable.
 * @return A bool of overwriteccfiles.
 */
bool Config::getOverWriteCCFiles(void)
{
	return this->overwriteccfiles;
}

/** The setter method for the overwriteccfiles varibale
 * @param overwrite Set to true if the plugin is allowed to overwrite the client config files.
 */
void Config::setOverWriteCCFiles(bool overwrite)
{
	this->overwriteccfiles=overwrite;	
}

/** Getter method for the authcontrolfile variable.
 * @return A bool of authcontrolfile .
 */
bool Config::getUseAuthControlFile(void)
{
	return this->useauthcontrolfile;
}

/** The setter method for the authcontrolfile  varibale
 * @param overwrite Set to true if the plugin if auth control files should be if supported by the OpenVPN version.
 */
void Config::setUseAuthControlFile(bool b)
{
	this->useauthcontrolfile=b;	
}

/** Getter method for the clientconnectdeferfile variable.
 * @return A bool of clientconnectdeferfile .
 */
bool Config::getUseClientConnectDeferFile(void)
{
	return this->useclientconnectdeferfile;
}

/** The setter method for the clientconnectdeferfile  varibale
 * @param overwrite Set to true if the plugin if client-connect control files should be if supported by the OpenVPN version.
 */
void Config::setUseClientConnectDeferFile(bool b)
{
	this->useclientconnectdeferfile=b;
}


bool Config::getAccountingOnly(void)
{
 return this->accountingonly; 
}

void Config::setAccountingOnly(bool b)
{
 this->accountingonly=b; 
}


bool Config::getNonFatalAccounting(void)
{
 return this->nonfatalaccounting; 
}

void Config::setNonFatalAccounting(bool b)
{
 this->nonfatalaccounting=b; 
}

int Config::getDefAcctInterimInterval(void)
{
 return this->defacctinteriminterval; 
}

void Config::setDefAcctInterimInterval(int b)
{
 this->defacctinteriminterval=b; 
}
