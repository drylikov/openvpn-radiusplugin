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

#include "RadiusVendorSpecificAttribute.h"
#include <stdlib.h>
#include "error.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/** The constructor sets the type,id and length to 0 and the value to NULL.*/
RadiusVendorSpecificAttribute::RadiusVendorSpecificAttribute(void)
{
	memset(this->id, 0, 4);
	this->type=0;
	this->length=0;
	this->value=NULL;
}



/** The destructor of the class.
 * It frees the allocated memory for the value, if the pointer is not NULL.
 */
RadiusVendorSpecificAttribute::~RadiusVendorSpecificAttribute(void)
{
	if (this->value)
	{
		delete [] this->value;
	}
}

/** Creates a dump of an attribute. 
 */
void RadiusVendorSpecificAttribute::dumpRadiusAttrib(void)
{
	int		i;
	fprintf(stdout,"\tid\t\t:\t%d%d%d%d\t|",this->id[0],this->id[1],this->id[2],this->id[3]);
	fprintf(stdout,"\ttype\t\t:\t%d\t|",this->type);
	fprintf(stdout,"\tlength\t:\t%d\t|",this->getLength());
	fprintf(stdout,"\tvalue\t:\t ->");
	for(i=0;i<((this->getLength())-6);i++)
		fputc(this->value[i],stdout);
	
	fprintf(stdout,"<-\n");
}


/**	The getter method for the length of the attribute
 * @return The length as an integer.
 */
int RadiusVendorSpecificAttribute::getLength(void)
{
	return (this->length);
}

/**	The getter method for the length of the attribute
 * @return The length as a pointer.
 */
Octet * RadiusVendorSpecificAttribute::getLength_Octet(void)
{
	return (&this->length);
}

/**	The setter method for the length of the attribut.
 * Normally it calculated automatically.
 * @param len The length as datatype unsigned char (=Octet). 
 */
void RadiusVendorSpecificAttribute::setLength(Octet len)
{
	this->length=len;
}

/** The getter method for the id of the attribute.
 * @return An integer with the id.
 */
int	RadiusVendorSpecificAttribute::getId(void)
{
	return ntohl(*(int*)this->id);	
}

/** The getter method for the id of the attribute.
 * @return An pointer to an Octet value. (still in network byte order).
 */
Octet *	RadiusVendorSpecificAttribute::getId_Octet(void)
{
	return (this->id);	
}

/** The setter method for the id of the attribute.
 * @param id The vendor id as integer.
 */
void RadiusVendorSpecificAttribute::setId(int id)
{
	int tmp_id=htonl(id);
	memcpy(this->id,&tmp_id,4);
}


/** The getter method for the type of the attribute.
 * @return An integer with the type.
 */
int	RadiusVendorSpecificAttribute::getType(void)
{
	return (this->type);	
}

/** The getter method for the type of the attribute.
 * @return A pointer to the value.
 */
Octet *	RadiusVendorSpecificAttribute::getType_Octet(void)
{
	return (&this->type);	
}

/** The setter method for the type of the attribute.
 * @param type The type as Octet.
 */
void RadiusVendorSpecificAttribute::setType(Octet type)
{
	this->type=type;
}


/** The getter method for the value.
 * @return The value as an Octet.*/
Octet * RadiusVendorSpecificAttribute::getValue(void)
{
	return (this->value);	
}


/** Decodes a vendor specific attribute from a buffer.
 * @param value A pointer to the a buffer which keeps a vendor specific attribute.
 * @return An integer which indicates errors, 0 if everthing is ok,
 * else a number defined in the error.h.
 */
int RadiusVendorSpecificAttribute::decodeRecvAttribute(Octet * v)
{
	memcpy(this->id, v, 4);
	this->type=v[4];
	this->length=v[5];
	if(!(this->value=new Octet[int(this->length)-2]))
	{
		return ALLOC_ERROR;
	}
	memcpy(this->value, v+6, (int(this->length)-2));
	return 0;
}

/** Transform a attribute value to an integer, this makes only sense
 * if the datatype is an integer. This dependents on the definition
 * in the radius RFC or can be locked up in the file radius.h of this 
 * source code.
 * @return The transformed integer.
 */
int RadiusVendorSpecificAttribute::intFromBuf(void)
{
	return (ntohl(*(int*)this->value));
}

/**The overloading of the assignment operator.*/
RadiusVendorSpecificAttribute & RadiusVendorSpecificAttribute::operator=(const RadiusVendorSpecificAttribute &ra)
{
	memcpy(this->id, ra.id, 4);
	this->value=new Octet[ra.length-2];
	this->type=ra.type;		
	this->length=ra.length;			
	memcpy(this->value,ra.value,ra.length-2);
	return *this;
}

/**The copy constructor.*/
RadiusVendorSpecificAttribute::RadiusVendorSpecificAttribute(const RadiusVendorSpecificAttribute &ra)
{
	this->value=new Octet[ra.length-2];
	memcpy(this->id, ra.id, 4);
	this->type=ra.type;		
	this->length=ra.length;			
	memcpy(this->value,ra.value,ra.length-2);
}

/**The method sets the value and the length.
 * @param value A string.
 * @return An integer. 0 if everything is ok, else !=0.
 */
int RadiusVendorSpecificAttribute::setValue(const char * value)
{
	int length=strlen(value);
	if(!(this->value=new Octet[length]))
	{
		return ALLOC_ERROR;
	}
	this->length=length+2;
	memcpy(this->value,value,length);
	return 0;
}

/**The method sets the value and the length.
 * @param value An integer.
 * @return An integer. 0 if everything is ok, else !=0.
 */
int RadiusVendorSpecificAttribute::setValue(int value)
{
	int tmp_value=htonl(value);
	if(!(this->value=new Octet[4]))
	{
		return ALLOC_ERROR;
	}
	this->length=6;
	memcpy(this->value,&tmp_value,4);
	return 0;
}


/** The method converts the value into an ip.
 * The attribute must have the right datatype IPADDRESS.
 * @return The ip address as a string.
 */
string RadiusVendorSpecificAttribute::ipFromBuf(void)
{
	int num,i;
	char ip2[4],ip3[16];
	memset(ip3,0,16);
	for (i=0;i<(this->length-2);i++)
	{
		num=(int)this->value[i];
		if(i==0)
		{
			sprintf(ip3,"%i",num);
			strcat(ip3,".");
		}
		else if (i<3)
		{
			sprintf(ip2,"%i",num);
			strcat(ip3,ip2);
			strcat(ip3,".");
		}
		else
		{
			sprintf(ip2,"%i",num);
			strcat(ip3,ip2);
		}
	}
	return string(ip3);			 
}  

/** The method converts the value into a strung.
 * @return The value as a string.
 */
string RadiusVendorSpecificAttribute::stringFromBuf(void)
{
	char * tmp_str = new char[this->length-1];
	memcpy(tmp_str, this->value, this->length-2);
	tmp_str[this->length-2]=0;
	return string(tmp_str);	 
}

/** The method copies id, type, length an value in 
 * an array Octet * rvsa for sending.
 * @param rvsa A pointer to an array for whole attribute, it must be have the right length.
 */
void RadiusVendorSpecificAttribute::getShapedAttribute(Octet * rvsa)
{
	memcpy(rvsa,this->id,4);
	memcpy(rvsa+4,&(this->type),1);
	memcpy(rvsa+5,&(this->length),1);
	memcpy(rvsa+6, this->value,this->length-2);
}
