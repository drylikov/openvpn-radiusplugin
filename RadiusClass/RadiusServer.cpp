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
 
#include "RadiusServer.h"
#include <string.h>


/** The constructer of the class.
	 * @param char * name : Represents the name or the ip address. The default is 127.0.0.1.
	 * @param char * secret : The sharedsecret in plaintext.
	 * @param int authport : The UDP port for authentication, the default is 1812.
	 * @param int acctport : The UDP port for accounting, the default is 1813.
	 * @param int retry : How many times the client should try to send a packet if he doesn't get an answer.
	 * @param int wait : The time (in seconds) to wait on a response of the radius server.
	 */
RadiusServer::RadiusServer(string name, string secret,
	int authport,  int acctport, int retry, int wait)
{
	this->acctport=acctport;
	this->authport=authport;
	this->name=name;
	this->retry=retry;
	this->wait=wait;
	this->sharedsecret=secret;
	
	
}

/** The destructur of the class.
 * It does nothing.
 */
RadiusServer::~RadiusServer()
{
	
}

/** The allocation operator.
 * @param const RadiusServer &s : A reference to a RadiusServer.
*/
RadiusServer &RadiusServer::operator=(const RadiusServer &s)
{
	this->name=s.name;
	this->wait=s.wait;
	this->retry=s.retry;
	this->acctport=s.acctport;
	this->authport=s.authport;
	this->sharedsecret=s.sharedsecret;
	return (*this);
}

/** The setter method for the authport.
 * There is no correctness checking.
 *@param port The number of the UDP port.
 */
void RadiusServer::setAuthPort(short int port)
{
	this->authport=port;
}

/** The getter method for the authport.
 * @return A integer of the authport.
 */
int RadiusServer::getAuthPort()
{
	return (this->authport);
}


/** The setter method for the acctport.
 * There is no correctness checking.
 * @param port The number of the UDP port.
 */
void RadiusServer::setAcctPort(short int port)
{
	this->acctport=port;
}


/** The getter method for the acctport.
 * @return A integer of the acctport.
 */
int RadiusServer::getAcctPort()
{
	return (this->acctport);
}


/**The setter method for the server name.
 * There is no correctness checking. The name could be a name or an ip address.
 * @param name : The name or ip address of the radius server.
 */
void RadiusServer::setName(string name)
{
	this->name=name;
}


/** The getter method for the server name.
 * @return A string with the server name.
 */
string RadiusServer::getName()
{
	return (this->name);
}


/** The setter method for the retries.
 * Is the value less or equal 0 it ist set to 1.
 * @param retry The number of retries the client should try to send a radius packet to the server, if the doesn't get an answer.
 */
void RadiusServer::setRetry(int retry)
{
	if (retry<=0)
	{
		retry=1;
	}
	this->retry=retry;
}


/** The getter method for the retry.
 * @return A integer of the retries.
 */
int RadiusServer::getRetry()
{
	return (this->retry);
}


/** The setter method for the sharedsecret
 * @param secret The sharedsecret in plaintext.
 */
void RadiusServer::setSharedSecret(string secret)
{
	this->sharedsecret=secret;
}

/** The getter method for the  sharedsecret
 * @return A string with the plaintext shared secret.
 */
string RadiusServer::getSharedSecret(void)
{
	return this->sharedsecret;
}


/** The getter method for the private member wait*
 * @return A interger of the time to wait for a resopnse.
 */
int RadiusServer::getWait(void)
{
	return this->wait;
}


/** The setter method for the private member wait
 * @param w The seconds to wait for response of the server. If w is less or equal 0 it is set to 1.
 */
void RadiusServer::setWait(int w)
{
	if (w>0)
	{
		this->wait=w;
	}
	else
	{
		this->wait=1;
	}
}

ostream& operator << (ostream& os, RadiusServer& server)
{
     os << "\n\nRadiusServer:";
     os << "\nName: " << server.name;
     os << "\nAuthentication-Port: " << server.authport;
     os << "\nAccounting-Port: " << server.acctport;
     os << "\nRetries: " << server.retry;
     os << "\nWait: " << server.wait;
     os << "\nSharedSecret: *******";
 	return os;
 	
}

