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
 
#ifndef _USER_AUTH_H_
#define _USER_AUTH_H_
#include <cmath>
#include "RadiusClass/RadiusPacket.h"
#include "RadiusClass/RadiusServer.h"
#include "RadiusClass/RadiusAttribute.h"
#include "RadiusClass/RadiusVendorSpecificAttribute.h"
#include "RadiusClass/error.h"
#include "RadiusClass/vsa.h"
#include "User.h"
#include "PluginContext.h"
#include "radiusplugin.h"
#include <string.h>
#include <fstream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



/**The class represents an user for the authentication process.**/
class UserAuth : public User
{
private:
	string password;				/**<The password of the user.*/

public:
  	  	
  	string getPassword(void);
  	void setPassword(string);
  	
  	
	UserAuth();
	~UserAuth();
  	
  	int sendAcceptRequestPacket(PluginContext *);
  	void parseResponsePacket(RadiusPacket *,  PluginContext *);
	int createCcdFile(PluginContext *);
	string valueToString(RadiusVendorSpecificAttribute *);
	
};




#endif //_USER_CONTEXT_AUTH_H_
