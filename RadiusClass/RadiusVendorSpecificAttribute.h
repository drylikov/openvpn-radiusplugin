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
 
#ifndef _RADIUSVENDORSPECIFICATTRIB_H_
#define _RADIUSVENDORSPECIFICATTRIB_H_
#include <string>
#include "radius.h"
#include <iostream>
using namespace std;

/**This class represents a radius vendor specific attribute as defined in RFC 2865. */

class RadiusVendorSpecificAttribute
{
private:
	Octet		id[4];		/**< The attribute length, of the value*/
	Octet		type;		/**< The vendor specific attibute type.*/
	Octet		length;		/**< The attribute length, of the value*/
	Octet		*value;		/**< A pointer to the value*/
	
	
public:
					
					RadiusVendorSpecificAttribute();
					~RadiusVendorSpecificAttribute(void);
					
					RadiusVendorSpecificAttribute & operator=(const RadiusVendorSpecificAttribute &);
					
					RadiusVendorSpecificAttribute(const RadiusVendorSpecificAttribute &);
		
	int				getLength(void);
	Octet *			getLength_Octet(void);
	void			setLength(Octet);
		
	int				getId(void);
	Octet *			getId_Octet(void);
	void			setId(int);	
		
	int				getType(void);
	Octet *			getType_Octet(void);
	void			setType(Octet);
	
	Octet *			getValue(void);
	int			    setValue(const char *);
	int			    setValue(int);
	
		
	int 			decodeRecvAttribute(Octet *);
	
	void			getShapedAttribute(Octet *);	
	
	int				intFromBuf(void);
	 
	string			ipFromBuf(void); 
		
	string			stringFromBuf(void);
	
	void			dumpRadiusAttrib(void);
	
	
};




#endif //_RADIUSVENDORSPECIFICATTRIB_H_
