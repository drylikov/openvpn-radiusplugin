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
 
#ifndef _IPCSOCKET_H_
#define _IPCSOCKET_H_

//#include "radiusplugin.h"
#include <string>
#include <cstring>
#include "User.h"
#include "Exception.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


typedef unsigned char Octet;

/** This class implements the inter process communication
 * in this software. Different datatypes can the send over the
 * socket: string, int , code (8 bit int). 
 * For the strings additional the length is sent before the string
 * is sent itself. So you don't need to know the length, if you receive
 * a string.
 */

class IpcSocket
{
private:
	int socket;		/**The socket number.*/
	
public:
	IpcSocket();
	IpcSocket(int);
	~IpcSocket();
	
	int getSocket(void);
	void setSocket(int);
	
	void send(string);
	
	void send(int);
	
	void send(Octet *, ssize_t);
	
	int recvInt(void);
	
	string recvStr(void);
	
	void recvBuf(User *);
	
};

#endif //_IPCSOCKET_H_
