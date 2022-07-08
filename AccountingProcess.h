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
 
#ifndef _ACCOUNTINGPROCESS_H_
#define _ACCOUNTINGPROCESS_H_
#include <sys/types.h>
#include <sys/stat.h>
#include "PluginContext.h"
#include "UserAcct.h"
#include "AcctScheduler.h"
#include "radiusplugin.h"

/** The class represents the background process for accounting. */
class AccountingProcess
{
public:
	void Accounting(PluginContext *);
	int callVsaScript(PluginContext *, User *, unsigned int , unsigned int);
};

#endif //_ACCOUNTINGPROCESS_H_
