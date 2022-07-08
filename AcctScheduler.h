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
 
#ifndef _ACCT_SCHEDULER_H_
#define _ACCT_SCHEDULER_H_

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include <iostream>
#include <map>
#include <fstream>
#include "UserAcct.h"

using std::map;

/**The class is a scheduler for accounting radius users. It calculates the 
 * accounting interval if the ACCT-INTERIM-INTERVAL was present in the
 * authentication response from the radius server. 
 * The start and stop accounting ticket are always sent for a user
 * which is added to the scheduler.
 * For the update and stop accounting ticket the sent and received bytes 
 * are read out of the OpenVpn status file.
 */


class AcctScheduler
{
	
private:
	map<string, UserAcct> activeuserlist; 	/**<The map for user with a acct interim interval.*/
	map<string, UserAcct> passiveuserlist;  /**<The map for user without a acct interim interval.*/
	
public:
	AcctScheduler();
	~AcctScheduler();
	 
	void addUser(UserAcct *user);
	void delUser(PluginContext * context, UserAcct *user);
	void delallUsers(PluginContext * context);
	
	UserAcct * findUser(string);
	 
	void doAccounting(PluginContext *);
	
	void parseStatusFile(PluginContext *, uint64_t *, uint64_t *,string);
};
#endif //_ACCT_SCHEDULER_H_
