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
 
#ifndef _RADIUSATTRIB_H_
#define _RADIUSATTRIB_H_
#include <gcrypt.h>
#include <string>
#include "radius.h"
#include <iostream>
using namespace std;

/**This class represents a radius attribute */

class RadiusAttribute
{
private:
	Octet		type;		/**< The attibute type, see in radius.h*/
	Octet		length;		/**< The attribute length, of the value*/
	Octet		*value;		/**< A pointer to the value*/
	
	
public:
					
					RadiusAttribute();
					RadiusAttribute(Octet);
					RadiusAttribute(Octet, const char * );
					RadiusAttribute(Octet, string);
					RadiusAttribute(Octet, uint32_t);
					~RadiusAttribute(void);
					
					RadiusAttribute & operator=(const RadiusAttribute &);
					
					RadiusAttribute(const RadiusAttribute &);
		
	int				getLength(void);
	Octet *			getLength_Octet(void);
	void			setLength(Octet);
		
	int				getType(void);
	Octet *			getType_Octet(void);
	void			setType(Octet);
	
	Octet *			getValue(void);
	int			    setValue(char *);
	int			    setValue(string);
	int			    setValue(uint32_t);
		
	int 			setRecvValue(char *value);
	
	int				intFromBuf(void);
	 
	string			ipFromBuf(void); 
	string			ip6FromBuf(void); 
		
	void			dumpRadiusAttrib(void);
	
	char *			makePasswordHash(const char *password,char * hpassword, const char *sharedSecret, const char *authenticator);
	
};




#endif //_RADIUSATTRIB_H_
