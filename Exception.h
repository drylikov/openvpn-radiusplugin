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
 
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <string>
#include <iostream>
//#include "radiusplugin.h"

using namespace std;

/**This class represents exceptions. An exception
 * can be thrown by using the constructer, like:
 * Exception(Exception::SOCKETSEND) or
 * Exception(errortext)
 */
class Exception
{
private:
	short int errnum; 	/**<The exception number.*/
    string errtext; 	/**<The exception text.*/

	
public:
     enum {SOCKETSEND, SOCKETRECV, ALREADYAUTHENTICATED};
     Exception(int);
     Exception(string);
     friend ostream& operator << (ostream& os, const Exception& e);
	 int getErrnum(void);
	
};

#endif //_EXCEPTION_H_
