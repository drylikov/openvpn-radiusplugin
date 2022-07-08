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
 
#ifndef _CONFIG_H_

#define _CONFIG_H_
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "RadiusClass/error.h"

#include <list>
#include <utility> 
using namespace std;

/**This class represents the configurations attributes (without radius configuration) which 
 * can set in the configuration file and methods for the attributes.
 */
class Config
{
private:
			
    string ccdPath; 				/**<The client config dir, where the plugin writes the config informations (framed routes & ip address of the client)*/
    string statusfile; 				/**< The path and filename of the status file, where openvpn writes the status information.*/ 
	char subnet[16];				/**<The subnet which is assigned to the client in topology option.*/
	char p2p[16];					/**<The OpenVPN server address which is assigned to the client in topology p2p.*/
	char p2p6[40];					/**<The OpenVPN server IPv6 address which is assigned to the client in topology p2p.*/
	string vsascript;				/**<A script which handles vendor specific attributes.*/
	string vsanamedpipe;		/**<The named pipe to the vsascript.*/
	bool usernameascommonname;		/**<Use the username as commonname in the plugin (for OpenVPN option username-as-common-name (no commonname in the enviroment!)).*/
	bool clientcertnotrequired;		/**<For OpenVPN option client_cert_not_required, commonname = UNDEF.*/
	string openvpnconfig;			/**<Path to OpenVPN config.*/
	bool overwriteccfiles; 			/**<If true the plugin overwrites the client config files.*/
        bool useauthcontrolfile;                /**<If true and the OpenVPN version supports auth control files, the acf is used.*/
        bool useclientconnectdeferfile;         /**<If true and the OpenVPN version supports client-connect defer files, it is used.*/
        bool accountingonly;			/**<Only the accounting is done by the plugin.*/
	bool nonfatalaccounting;		/**<If errors during the accounting occurs, the users can still connect.*/
	int defacctinteriminterval;		/**<Default Acct-Interim-Interval in seconds.*/
	void deletechars(string * );
	
public:
	Config(void);
	Config(char * configfile);
	~Config();
	
	int parseConfigFile(const char * configfile);
	
		
	
	void getValue(const char * text, char * value);
		
	string getCcdPath(void);
	void setCcdPath(string);
	
	string getStatusFile(void);
	void setStatusFile(string);
	
	char * getSubnet(void);
	void setSubnet(char * );
	
	char * getP2p(void);
	void setP2p(char * );
	
	char * getP2p6(void);
	void setP2p6(char * );
	
	string getVsaScript(void);
	void setVsaScript(string);
	
	string getVsaNamedPipe(void);
	void setVsaNamedPipe(string);
	
	bool getUsernameAsCommonname(void);
	void setUsernameAsCommonname(bool);
	
	bool getClientCertNotRequired(void);
	void setClientCertNotRequired(bool);
	
	bool getOverWriteCCFiles(void);
	void setOverWriteCCFiles(bool);

        bool getUseAuthControlFile(void);
	void setUseAuthControlFile(bool);

        bool getUseClientConnectDeferFile(void);
	void setUseClientConnectDeferFile(bool);
	
	bool getAccountingOnly(void);
	void setAccountingOnly(bool);
	
	bool getNonFatalAccounting(void);
	void setNonFatalAccounting(bool);

	int getDefAcctInterimInterval(void);
	void setDefAcctInterimInterval(int);
	
	string getOpenVPNConfig(void);
	void setOpenVPNConfig(string);
};

#endif //_CONFIG_H_

