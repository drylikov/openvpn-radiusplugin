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
 
#ifndef _RADIUSSERVER_H_
#define _RADIUSSERVER_H_
#include <string>
#include <iostream>

using namespace std;
/** This class represents a radius server.*/

class RadiusServer
{
private:
	short int authport; 		/**< The UDP port for authentication packets.*/
	short int acctport; 		/**< The UDP port for accounting packets.*/
	string name;				/**< The name or the ip address of the server.*/
	int 	retry; 				/**< The number of retries how many times a radius ticket is send to the server, if it doesn#t answer.*/
	string sharedsecret;		/**< The sharedsecret, the maximum space is 16 chars.*/
	int 	wait;				/**< The time to wait for a response of the server.*/

public:
	
	
	RadiusServer(string name="127.0.0.1",string secret = "", int authport=1812, int acctport=1813, int retry=3, int wait=1);
	~RadiusServer();
	RadiusServer &operator=(const RadiusServer &);
	
	int getRetry();
	void setRetry(int);
	
	void setWait(int);
	int getWait(void);
	
	void setSharedSecret(string);
	string getSharedSecret(void);
	
	int getAuthPort();
	void setAuthPort(short int);
	
	int getAcctPort();
	void setAcctPort(short int);
	
	string getName();
	void setName(string);
	
	friend ostream& operator << (ostream& os, RadiusServer& server);
};

#endif //_RADIUSSERVER_H_

	

