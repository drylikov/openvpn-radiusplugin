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
 
#ifndef _RADIUSPACKET_H_
#define _RADIUSPACKET_H_

#include <stdio.h>
#include <gcrypt.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>
#include <iostream>

#include "error.h"
#include "radius.h"
#include "RadiusAttribute.h"
#include "RadiusServer.h"


#include <map>
#include <list>
#include <utility> 

using namespace std;
using std::multimap;

/** The class represents a radius packet with additional variables*/

class RadiusPacket
{
private:
	
	multimap<Octet,RadiusAttribute> attribs; 	/**The multimap for the radius attributes.*/
	int					sock; 					/**<The socket which is used.*/
	Octet				code; 					/**< The code of the packet, see the Radius RFC or radius.h*/
	Octet				identifier; 			/**<The identifier of the packet, it is generated randomly.*/			
	unsigned short int	length;					/**<The length of the packet on the network in bytes. */			
	Octet				authenticator[RADIUS_PACKET_AUTHENTICATOR_LEN];/**<Authenticator. 
	In ACCEPT-Request packets it is a random number, 
	in Accounting-Request it is a hash over whole packet and shared secret. The send-method
	generates it, when the code is an Accounting-Request*/ 
	Octet				req_authenticator[RADIUS_PACKET_AUTHENTICATOR_LEN]; /**<A copy of the authenticator. 
	The server sends in the authenticator field: code + idntifier + length + request authenticator + attribute and secret.
	So you can authenticate the packet, if it is the real response on the request.>*/
	
	
	Octet				*sendbuffer;  			/**<Buffer for sending the packet over the network.*/
	int					sendbufferlen; 			/**<Length of the buffer.*/
	Octet				*recvbuffer;  			/**<Buffer for recveing the packet over the network.*/
	int					recvbufferlen; 			/**<Length of the buffer.*/
	void            	calcacctdigest(const char *secret); /**Method to generate the hash 
	for the authenticator in Accounting-Requests.*/
	
	//private functions
	void 			getRandom(int len, Octet *num);
	int				shapeRadiusPacket(const char *);
	int				unShapeRadiusPacket(void);
	
public:
					RadiusPacket(void);
					~RadiusPacket(void);
					RadiusPacket(Octet code);
					
	int				addRadiusAttribute(RadiusAttribute *);
		
	void			dumpRadiusPacket(void);
	void			dumpShapedRadiusPacket(void);
	
	int				radiusSend(list<RadiusServer>::iterator);
	int				radiusReceive(list<RadiusServer> *);
	
	int				getRadiusAttribNumber(void);
	char *			getAuthenticator(void);
	
	int				getCode(void);
	
	int				authenticateReceivedPacket(const char *secret);
	
	pair<multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator> findAttributes(int type);
	
};





#endif //_RADIUSPACKET_H_
