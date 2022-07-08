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
 
#ifndef _CONFIGPARSER_H_

#define _CONFIGPARSER_H_
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "RadiusServer.h"
#include"RadiusServer.h"
#include "error.h"

#include <list>
#include <utility> 

using std::list;
using namespace std;

/**This class represents the configurations attributes which 
 * can set in the configuration file and methods for the attributes.
 */
class RadiusConfig
{
private:
	list<RadiusServer> server; 		/**<An list with radius server, it is created dynamically by parsing the configuration file.*/
	char serviceType[2]; 			/**<The service type which is set in the radius packet.*/
    char framedProtocol[2]; 		/**<The framed protocol which is set in the radius packet as an attribute.*/
    char nasPortType[2]; 			/**<The nas port type which is set in radius packet.*/
    char nasIdentifier[128]; 		/**<The nas identifier which is set in the radius packet.*/
    char nasIpAddress[16]; 			/**<The nas ipaddress which is set in the radius packet.*/
    
	void deletechars(string *);
	
	
public:
	RadiusConfig(void);
	RadiusConfig(string configfile);
	~RadiusConfig();
	
	int parseConfigFile(const char * configfile);
	
		
	
	void getValue(const char * text, char * value);
	
	list<RadiusServer>* getRadiusServer(void);
	
	
	void setServiceType(char *);
	char * getServiceType(void);
	
	void setFramedProtocol(char *);
	char * getFramedProtocol(void);
	
    
    void setNASPortType(char *);
    char * getNASPortType(void);
    
    void setNASIdentifier(char *);
    char * getNASIdentifier(void);
    
    char * getNASIpAddress(void);
	void setNASIpAddress(char * );
	
	
	
	friend ostream& operator << (ostream& os, RadiusConfig& config);
};

#endif //_CONFIGPARSER_H_
