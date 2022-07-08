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
 
#include "Exception.h"



/**The constructor of the class, it sets the exception number and if
 * the number is known the text for the number.
 * @param err The exception number.
 */
Exception::Exception(int err)
{
	errnum = err;
	switch(err)
	{
		case Exception::SOCKETRECV:
			this->errtext="Receiving data from internal socket failed!";
			break;
		
		case Exception::SOCKETSEND:
			this->errtext="Sending data via internal socket failed!";
			
		case Exception::ALREADYAUTHENTICATED:
			this->errtext="The User is already authenticated. He could not insert in user map. The client connect will fail. In case of rekeying this note is ok.";
	}
}

/**The constructor sets the text of the Exception.
 * @param txt The exception text.
 */
Exception::Exception(string txt)
{
	this->errnum=-1;
	this->errtext=txt;
}

/**The overloading of ostream for the exception class.
 */
ostream & operator <<(ostream& os, const Exception& e)
{
     os <<"Error: " << e.errtext << "\n";
     return os;
}

/**The method returns the exception number.
 * @return The exception number.
 */
int Exception::getErrnum(void)
{
	return this->errnum;
}
