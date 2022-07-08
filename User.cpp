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
 
#include "User.h"

/** The constructor sets the acctinteriminterval and the portnumber to 0.*/
User::User()
{
	this->dev="";
	this->framedip="";
	this->framedroutes="";
	this->framedip6="";
	this->framedroutes6="";
	this->key="";
        this->statusfilekey="";
	this->untrustedport="";
//         this->trustedport="";
//         this->trustedip="";
	this->acctinteriminterval=0;
	this->portnumber=0;
	this->vsabuf=NULL;
	this->vsabuflen=0;
}

/** The constructor sets the acctinteriminterval to 0 and the portnumber to num.
 * @param num  The portnumber.*/
/*User::User(int num)
{
	this->dev="";
	this->framedip="";
	this->framedroutes="";
	this->framedip6="";
	this->framedroutes6="";
	this->key="";
	this->untrustedport="";
	this->acctinteriminterval=0;
	this->portnumber=num;
	this->vsabuf=NULL;
	this->vsabuflen=0;
}*/

/** The destructor.*/
User::~User()
{
	
	if(this->getVsaBufLen() > 0)
	{ 
		delete [] this->getVsaBuf();
	}
}

/** The overloading of the assignment operator.
 * @param u A reference to an object of the User class.
 * @return A reference to the User class.*/
User & User::operator=(const User & u)
{
	this->username=u.username;
	this->commonname=u.commonname;
	this->dev=u.dev;
	this->framedip=u.framedip;
	this->framedroutes=u.framedroutes;
	this->framedip6=u.framedip6;
	this->framedroutes6=u.framedroutes6;
	this->key=u.key;
        this->statusfilekey=u.statusfilekey;
	this->callingstationid=u.callingstationid;
	this->portnumber=u.portnumber;
	this->acctinteriminterval=u.acctinteriminterval;
	this->untrustedport=u.untrustedport;
	this->sessionid=u.sessionid;
//         this->trustedport=u.trustedport;
//         this->trustedip=u.trustedip;
	this->vsabuflen=u.vsabuflen;
	if(u.vsabuf != NULL)
	{
		try{
		  this->vsabuf=new Octet[this->vsabuflen];
		}
		catch(...)
		{
		  cerr <<  "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for vsabuflen." << endl;
		}
		
		
		memcpy(this->vsabuf, u.vsabuf, this->vsabuflen);
	}
	else
	{
		this->vsabuf=u.vsabuf;	
	}	
	
	return *this;
}

/** The copy constructor.
 * @param u A reference to an object of the User class.*/ 

User::User(const User & u)
{
	this->username=u.username;
	this->commonname=u.commonname;
	this->dev=u.dev;
	this->framedip=u.framedip;
	this->framedroutes=u.framedroutes;
	this->framedip6=u.framedip6;
	this->framedroutes6=u.framedroutes6;
	this->key=u.key;
        this->statusfilekey=u.statusfilekey;
	this->callingstationid=u.callingstationid;
	this->portnumber=u.portnumber;
	this->acctinteriminterval=u.acctinteriminterval;
	this->untrustedport=u.untrustedport;
	this->sessionid=u.sessionid;
//         this->trustedport=u.trustedport;
//         this->trustedip=u.trustedip;
	this->vsabuflen=u.vsabuflen;
	if(u.vsabuf != NULL)
	{
		try{
		  this->vsabuf=new Octet[this->vsabuflen];
		}
		catch(...)
		{
		  cerr  << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for vsabuflen." << endl;
		}
		memcpy(this->vsabuf, u.vsabuf, this->vsabuflen);
	}
	else
	{
		this->vsabuf=u.vsabuf;	
	}	
}

/** The getter method for the username.
 * @return The username as a string.*/
string User::getUsername(void)
{
	return this->username;
}
/** The setter method for the username.
 * @param uname The username.*/
void User::setUsername(string uname)
{
	this->username=uname;
}

/** The getter method for the commonname.
 *  @return The commonname as a string.*/
string User::getCommonname(void)
{
	return this->commonname;
}
/** The setter method for the commonname.
 * @param cn The commonname.*/
void User::setCommonname(string cn)
{
	this->commonname=cn;
}

/** The getter method for the device.
 *  @return The device as a string.*/
string User::getDev(void)
{
	return this->dev;
}
/** The setter method for the device.
 * @param dev The device.*/
void User::setDev(string dev)
{
	this->dev=dev;
}

/** The getter method for the framed routes.
 *  @return The framed routes as a string.*/	
string User::getFramedRoutes(void)
{
	return this->framedroutes;
}
/** The setter method for the framedroutes.
 * @param froutes The framedroutes, if there are more 
 * routes they are divided through a ';'.*/
void User::setFramedRoutes(string froutes)
{
	this->framedroutes=froutes;
}

/** The getter method for the framed ip.
 *  @return The framed ip as a string.*/
string User::getFramedIp(void)
{
	return this->framedip;
}
/** The setter method for the framedip.
 * @param ip The framedip.*/
void User::setFramedIp(string ip)
{
	this->framedip=ip;
}

/** The getter method for the framed IPv6 routes.
 *  @return The framed IPv6 routes as a string.*/
string User::getFramedRoutes6(void)
{
	return this->framedroutes6;
}
/** The setter method for the framed IPv6 routes.
 * @param froutes6 The framed IPv6 routes, if there are more 
 * routes they are divided through a ';'.*/
void User::setFramedRoutes6(string froutes6)
{
	this->framedroutes6=froutes6;
}

/** The getter method for the framed IPv6.
 *  @return The framed IPv6 as a string.*/
string User::getFramedIp6(void)
{
	return this->framedip6;
}
/** The setter method for the framedip6.
 * @param ip The framedip.*/
void User::setFramedIp6(string ip)
{
	this->framedip6=ip;
}

/** The getter method for the fkey.
 *  @return The unique key as a string.*/
string User::getKey(void)
{
	return this->key;
}
/** The setter method for a unique, it is build from ip and port.
 * @param key The unique key.
 */
void User::setKey(string key)
{
	this->key=key;
}

/** The getter method for the status file key.
 *  @return The unique status file key as a string.*/
string User::getStatusFileKey(void)
{
	return this->statusfilekey;
}
/** The setter method for a unique, it is build from commonname, ip and port.
 * @param key The unique status file key.
 */
void User::setStatusFileKey(string key)
{
	this->statusfilekey=key;
}

/** The getter method for the calling station id.
 *  @return The calling station id as a string.*/
string User::getCallingStationId(void)
{
	return this->callingstationid;
}
/** The setter method for the callingstationid.
 * @param id The callingstationid.*/
void User::setCallingStationId(string id)
{
	this->callingstationid=id;
}

/** The getter method for the portnumber.
 *  @return The portnumber as an integer.*/
int User::getPortnumber(void)
{
	return this->portnumber;
}
/** The setter method for the portnumber.
 * @param port The portnumber.*/
void User::setPortnumber(int port)
{
	this->portnumber=port;
}

/** The getter method for the acctinteriminterval.
 *  @return The acctinteriminterval as struct time_t.*/
time_t User::getAcctInterimInterval(void)
{
	return this->acctinteriminterval;
}
/** The setter method for the username.
 * @param t  The acctinteriminterval.*/
void User::setAcctInterimInterval(time_t t)
{
	this->acctinteriminterval=t;
}


/** The getter method for untrusted port.
 * @return untrusted port
 */
string User::getUntrustedPort(void)
{
	return this->untrustedport;
}


/**The setter method for untrusted port.
 * @param The untrusted port number as string.
 */
void User::setUntrustedPort(string port)
{
	this->untrustedport=port;
}

/**This method copies the octets form the vendor specific attributes to
 * the buffer vsabuf. It also calculates the length of the buffer.
 * @param value Pointer to vendor specific attribute.
 * @param len Length of the attribute.
 * @return 0 in case of no error.
 */

int User::appendVsaBuf(Octet *value, unsigned int len)
{
	if(this->vsabuf == NULL)
	{	
		try{
		  this->vsabuf=new Octet[len];
		}
		catch(...)
		{
		  cerr  << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for vsabuflen." << endl;
		}
		memcpy(this->vsabuf, value, len);
		this->vsabuflen=len;
	}	
	else
	{
		Octet old_vsa[this->vsabuflen];
		memcpy(old_vsa, this->vsabuf, this->vsabuflen);
		delete [] this->vsabuf;
		try{
		  this->vsabuf=new Octet[this->vsabuflen+len];
		}
		catch(...)
		{
		  cerr  << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for vsabuflen." << endl;
		}
		memcpy(this->vsabuf, old_vsa, this->vsabuflen);
		memcpy((this->vsabuf+this->vsabuflen), value, len);
		this->vsabuflen=this->vsabuflen+len;
	}
	return 0;
	
}

/** Getter method for the vsabuf
 * @return Pointer to the buffer.
 */
Octet * User::getVsaBuf()
{
	return this->vsabuf;
}

/** Setter method for the vsabuf.
 * @param pbuf Pointer to buffer.
 */
void User::setVsaBuf(Octet * pbuf)
{
	this->vsabuf=pbuf;
}

/** Getter method for the buffer length.
 * @return Length of the buffer.
 */
unsigned int User::getVsaBufLen()
{
	return this->vsabuflen;	
}
/** Setter method for the vsabuf length.
 * @param len Length of the buffer.
 */
void User::setVsaBufLen(unsigned int len)
{
	this->vsabuflen=len;	
}

/** The getter method for the sessionid.
 * @return An integer of the sessionid.*/
string User::getSessionId(void)
{
	return this->sessionid;
}
/**The setter method for the sessionid.
 * @param id The session id.*/
void User::setSessionId(string id)
{
	this->sessionid=id;
}



/** The getter method for trusted port.
 * @return trusted port
 */
// string User::getTrustedPort() const
// {
// 	return trustedport;
// }

/**The setter method for trusted port.
 * @param The trusted port number as string.
 */
// void User::setTrustedPort ( const string& port )
// {
// 	trustedport = port;
// }

/** The getter method for trusted ip.
 * @return trusted ip
 */
// string User::getTrustedIp() const
// {
// 	return trustedip;
// }

/**The setter method for trusted ip.
 * @param The trusted ip as string.
 */
// void User::setTrustedIp ( const string& ip )
// {
// 	trustedip = ip;
// }
