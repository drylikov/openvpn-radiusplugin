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
 
#ifndef _USER_H_
#define _USER_H_
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
//#include "radiusplugin.h"
//#include "openvpn-plugin.h"


/** The datatype for sending and receiving data to and from the network */ 
typedef	unsigned char	Octet;



using namespace std;

/** The user class represents a general user for the three different processes (foreground,
 * authentication background, accounting background). Here are defined the
 * common attributes and functions.*/

class User
{
protected:
	string username;		/**<The username.*/
	string commonname;		/**<The commonname.*/
	string dev;			/**<The device.*/
	string framedroutes;		/**<The framedroutes, they are stored as a string. If there are more routes, they must be delimited by an ';'*/
	string framedip;		/**<The framed ip.*/
	string framedroutes6;		/**<The framed IPv6 routes, they are stored as a string. If there are more routes, they must be delimited by an ';'*/
	string framedip6;		/**<The framed ipv6.*/
	string callingstationid;	/**<The calling station id, in this case the real ip address of the client.*/
	string key;			/**<A unique key to find the user in a map. */
	string statusfilekey;		/**<Unique identifier in the status log file (version 1) "commonname,untrusted_ip:untrusted_port"*/
	int portnumber;			/**<The portnumber.*/
	time_t acctinteriminterval;	/**<The acct interim interval.*/
	string untrustedport;		/**<The untrusted port number from OpenVPN for a client.*/
	//string trustedport;		/**<The trusted port number from OpenVPN for a client.*/
	//string trustedip;		/**<The trusted ip from OpenVPN for a client.*/
	Octet * vsabuf;			/**<Buffer for all VSA attributes.*/
	unsigned int vsabuflen;		/**<Length of vsabuf.*/
	string sessionid;		/**<The user sessionid.*/
	
public:
	User();
	//User(int);
	~User();
	
	User & operator=(const User &);
	User(const User &);
	
	string getUsername(void);
	void setUsername(string);
	
	string getCommonname(void);
	void setCommonname(string);
		
	string getDev(void);
	void setDev(string);
	
	string getFramedRoutes(void);
	void setFramedRoutes(string);
	
	string getFramedIp(void);
	void setFramedIp(string);
	
	string getFramedRoutes6(void);
	void setFramedRoutes6(string);
	
	string getFramedIp6(void);
	void setFramedIp6(string);
	
	string getKey(void);
	void setKey(string);

        string getStatusFileKey(void);
	void setStatusFileKey(string);
	
	string getCallingStationId(void);
	void setCallingStationId(string);
	
	int getPortnumber(void);
	void setPortnumber(int);
	
	time_t getAcctInterimInterval(void);
	void setAcctInterimInterval(time_t);
			
	string getUntrustedPort(void);
	void setUntrustedPort(string);
	
	int appendVsaBuf(Octet *, unsigned int len);
	Octet * getVsaBuf();
	void setVsaBuf(Octet *);
	
	unsigned int getVsaBufLen();
	void setVsaBufLen(unsigned int);
	
	string getSessionId(void);
	void setSessionId(string);

// 	void setTrustedPort ( const string& theValue );
// 	
// 
// 	string getTrustedPort() const;
// 
// 	void setTrustedIp ( const string& theValue );
// 	
// 
// 	string getTrustedIp() const;
	
	
	
	
	
};

#endif //_USER_H_
