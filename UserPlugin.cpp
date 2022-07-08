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
 
#include "UserPlugin.h"

/**The constructor sets the sessionid and sends the portnumber to the
 * constructor of the class User, where the portnumber is set. The flags 
 * authenticated and accounted are set to false.*/
UserPlugin::UserPlugin() : User()
{
	this->accounted=false;
	this->authenticated=false;
        this->authcontrolfile="";
        this->clientconnectdeferfile="";
}

/**The destructor, nothing happens here.*/
UserPlugin::~UserPlugin()
{
	
		
}

/**Overloading of the assignment operator.*/
UserPlugin & UserPlugin::operator=(const UserPlugin &u)
{
	if (this!=&u)
	{
		//call the assignment operator of the class User
		User::operator=(u);
		this->authenticated=u.authenticated;
		this->accounted=u.accounted;
		this->sessionid=u.sessionid;
		this->password=u.password;
		this->untrustedport=u.untrustedport;
                this->authcontrolfile=u.authcontrolfile;
                this->clientconnectdeferfile=u.clientconnectdeferfile;
	}
	return *this;
	
}


/*
bool UserPlugin::operator<(const UserPlugin & u)
{
	if (this->sessionid < u.sessionid)
	{
		return true;
	}
	return false;
}*/

/**The copy constructor. First the copy constructor of the
 * class User is called and than the sessionid, the password and the flags
 * authenticated and accounted are copied.*/
UserPlugin::UserPlugin(const UserPlugin &u) : User(u)
{
	this->sessionid=u.sessionid;
	this->password=u.password;
	this->authenticated=u.authenticated;
	this->accounted=u.accounted;
	this->untrustedport=u.untrustedport;
        this->authcontrolfile=u.authcontrolfile;
        this->clientconnectdeferfile=u.clientconnectdeferfile;
}

/**The getter method of the password.
 * @return The password as a string.*/
string UserPlugin::getPassword(void)
{
	return this->password;
}
/**The setter method of the password.
 * @param passwd The password.*/
void UserPlugin::setPassword(string passwd)
{
	this->password=passwd;
}

/** The getter method of the sessionid.
 * @return The sessionid as an integer.
 */
string UserPlugin::getSessionId(void)
{
	return this->sessionid;	
}
/** The setter method of the sessionid.
 * @param id The sessionid.*/
void UserPlugin::setSessionId(string id)
{
	this->sessionid=id;
}

/** The getter method for authenticated flag.
 * @return True if the user is authenticated, else false.
 */
bool UserPlugin::isAuthenticated(void)
{
	return this->authenticated;
}
/**The setter method for the authenticated flag.
 * @param The value for the authenticated flag.
 */
void UserPlugin::setAuthenticated(bool auth)
{
	this->authenticated=auth;
}

/** The getter method for accounted flag.
 * @return True if the user is accounted, else false.
 */
bool UserPlugin::isAccounted(void)
{
	return this->accounted;
}


/**The setter method for the accounted flag.
 * @param The value for the accounted flag.
 */
void UserPlugin::setAccounted(bool acct)
{
	this->accounted=acct;
}

string UserPlugin::getAuthControlFile(void )
{
  return authcontrolfile;
}

void UserPlugin::setAuthControlFile(string file)
{
  authcontrolfile=file;
}

string UserPlugin::getClientConnectDeferFile(void )
{
  return clientconnectdeferfile;
}

void UserPlugin::setClientConnectDeferFile(string file)
{
  clientconnectdeferfile=file;
}


