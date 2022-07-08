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

#include "RadiusAttribute.h"
#include <stdlib.h>
#include "error.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define NEED_LIBGCRYPT_VERSION "1.2.0"
GCRY_THREAD_OPTION_PTHREAD_IMPL;

/** The constructor sets the type to 0 and the value to NULL.*/
RadiusAttribute::RadiusAttribute(void)
{
	this->type=0;
	this->length=0;
	this->value=NULL;
}

/** The constructor creates an attribute.
 * The type and the value can be set. 
 * @param Octet type : The type of the attribute.
 * @param char *value : A pointer to a value for the attribut.
 */
RadiusAttribute::RadiusAttribute(Octet ty, const char *value)
{
	this->type=ty;
	this->value=NULL;
	//Only set the value if there is something in.
	if (value!=NULL)
	{
		this->setValue(value);
	}
}

/**The construcotr sets the type. The value is set to NULL.
 * @param Octet typ :  The type of the attribute.*/
RadiusAttribute::RadiusAttribute(Octet typ)
{
	this->type=typ;
	this->length=0;
	this->value=NULL;
}

/**The constructor sets the type and the value.
 * @param Octet typ : The type of the attribute.
 * @param string str : The value as a string.
 */
RadiusAttribute::RadiusAttribute(Octet typ, string str)
{
	this->type=typ;
	this->value=NULL;
	this->setValue(str);
}

/** The constructor sets the type and the value. The type must 
 * have the datatype integer as it is defined in the RFC of the 
 * radius protocol.
 * @param Octet type : The type of the packet.
 * @param int value : The value as an integer.
 */
RadiusAttribute::RadiusAttribute(Octet typ, uint32_t value)
{
	this->type=typ;
	this->value=NULL;
	this->setValue(value);
}


/** The destructor of the class.
 * It frees the allocated memory for the value, if the pointer is not NULL.
 */
RadiusAttribute::~RadiusAttribute(void)
{
	if (this->value)
	{
		delete [] this->value;
	}
}

/** Creates a dump of an attribute. 
 */
void RadiusAttribute::dumpRadiusAttrib(void)
{
	int		i;

	fprintf(stdout,"\ttype\t\t:\t%d\t|",this->type);
	fprintf(stdout,"\tlength\t:\t%d\t|",this->getLength());
	fprintf(stdout,"\tvalue\t:\t'");
	for(i=0;i<((this->getLength())-2);i++)
		fputc(this->value[i],stdout);
	
	fprintf(stdout,"'\n");
}


/**	The getter method for the length of the attribute
 * @return The length as an integer.
 */
int RadiusAttribute::getLength(void)
{
	return (this->length);
}

Octet * RadiusAttribute::getLength_Octet(void)
{
	return (&this->length);
}

/**	The setter method for the length of the attribut.
 * Normally it calculated automatically.
 * @param len The length as datatype unsigned char (=Octet). 
 */
void RadiusAttribute::setLength(Octet len)
{
	this->length=len;
}

/** Creates a password buffer with MD5/xOR hashing for the 
 * ATTRIB_User_Password. The password filed must be have a
 * length of 16 Octets or a multiple of 16 Octets.
 * If the password is longer than 16 characters, the XOR-hash is
 * build of the first 16 chars, than a new XOR-hash is build
 * over the first XOR-hash and the shared secret and so on.
 * It if defined in the radius RFC.
 * @param password The User password.
 * @param hpassword A char array for the hashed password. It must have the
 * same length as the password filed (=this->length-2).
 * @param sharedSecret The sharedsecret of the server.
 * @param authenticator String of the authenticator field.
 * @return A pointer to the hpassword array, so the function can
 * be used directly in a function/method.
 */
char * RadiusAttribute::makePasswordHash(const char *password,char * hpassword, const char *sharedSecret,const char *authenticator)
{
	
	unsigned char digest[MD5_DIGEST_LENGTH]; 	//The digest.
	gcry_md_hd_t context;					//the hash context
	int i,k,j,l,								//Some counters.
		passwordlen;							//The password length.
	
	memset(digest,0,MD5_DIGEST_LENGTH);
		
	//build the hash	
	if (!gcry_control (GCRYCTL_ANY_INITIALIZATION_P))
	{ /* No other library has already initialized libgcrypt. */

	  gcry_control(GCRYCTL_SET_THREAD_CBS,&gcry_threads_pthread);

	  if (!gcry_check_version (NEED_LIBGCRYPT_VERSION) )
	    {
		cerr << "libgcrypt is too old (need " << NEED_LIBGCRYPT_VERSION << ", have " << gcry_check_version (NULL) << ")\n";
	    }
	    /* Disable secure memory.  */
          gcry_control (GCRYCTL_DISABLE_SECMEM, 0);

	  gcry_control (GCRYCTL_INITIALIZATION_FINISHED);
	}

	gcry_md_open(&context, GCRY_MD_MD5, 0);
	gcry_md_write(context, sharedSecret, strlen(sharedSecret));
	gcry_md_write(context, authenticator, MD5_DIGEST_LENGTH);
	memcpy(digest, gcry_md_read(context, GCRY_MD_MD5), MD5_DIGEST_LENGTH);
	if (this->length<MD5_DIGEST_LENGTH)
	{
		//XOR the password and the digest
		for(i=0;i<MD5_DIGEST_LENGTH;i++) hpassword[i]=password[i]^digest[i];
	}
	else
	{
		passwordlen=this->length-2;	//get the length of the passwordfield
		
		//XOR the password and the digest
		//build the first xOR-hash
		for(i=0;i<MD5_DIGEST_LENGTH;i++)
		{
			hpassword[i]=password[i]^digest[i];
			
		}	
		passwordlen=passwordlen-MD5_DIGEST_LENGTH;	//the next 16 charakters
		k=0;						//the first loop
		while (passwordlen>0)
		{
			//build the next hash	
			memset(digest,0,MD5_DIGEST_LENGTH);
						
			//put the hash of the last XOR in the digest
			//build the hash	
			if (!gcry_control (GCRYCTL_ANY_INITIALIZATION_P))
			{ /* No other library has already initialized libgcrypt. */

			  gcry_control(GCRYCTL_SET_THREAD_CBS,&gcry_threads_pthread);

			  if (!gcry_check_version (NEED_LIBGCRYPT_VERSION) )
			    {
				cerr << "libgcrypt is too old (need " << NEED_LIBGCRYPT_VERSION << ", have " << gcry_check_version (NULL) << ")\n";
			    }
			  /* Disable secure memory.  */
			  gcry_control (GCRYCTL_DISABLE_SECMEM, 0);
			  gcry_control (GCRYCTL_INITIALIZATION_FINISHED);
			}
			gcry_md_open (&context, GCRY_MD_MD5, 0);
			gcry_md_write(context, sharedSecret, strlen(sharedSecret));
			gcry_md_write(context, hpassword+(k*MD5_DIGEST_LENGTH), MD5_DIGEST_LENGTH);
			memcpy(digest, gcry_md_read(context, GCRY_MD_MD5), MD5_DIGEST_LENGTH);
			
			
			j=0;
			l=i+MD5_DIGEST_LENGTH;
			for(;i<l;i++)
			{
				hpassword[i]=password[i]^digest[j];
				j++;
			
			}
			passwordlen=passwordlen-MD5_DIGEST_LENGTH;		//and the next 16 characters
			k++;							//and the next loop
			
		}
		
	}
	gcry_md_close(context);
	return hpassword;

}


/** The getter method for the type of the attribute.
 * @return An integer with the type.
 */
int	RadiusAttribute::getType(void)
{
	return (this->type);	
}
Octet *	RadiusAttribute::getType_Octet(void)
{
	return (&this->type);	
}

/** The setter method for the type of the attribute.
 * @param type The type as Octet.
 */
void RadiusAttribute::setType(Octet type)
{
	this->type=type;
}

/** The getter method for the value.
 * @return The value as an Octet.*/
Octet * RadiusAttribute::getValue(void)
{
	return (this->value);	
}


/**Set the value of the attribute. The representation of the value
 * is changed, so it is ready to send over the network.
 * The changes depend on the datatype
 * IPADRESS, INTEGER, String. The datatype enum can be treated as an integer.
 * A special attribut is the User password,
 * the length must be 16 octets or a multipe of 16 Octets.
 * Here it is only copied to the
 * value. The datatypes ipv6addr,ifid, ipv6prefix, ipv6addr are treated as
 * strings.
 * @param value : A pointer to the value.
 * @return An integer which indicates errors, 0 if everthing is ok,
 * else a number defined in the error.h
 */ 

int RadiusAttribute::setValue(char *value)
{
	char			tmpStr[20];		//An array to convert the datatype.
	int				i,j,q,			//Some counter.
					passwordlen;	//The passwordlength.
	
	//If the attribute has already an value, clear it.
	if (this->value!=NULL)
	{
		delete [] this->value;
	}
	
	switch(this->type)
	{
		//for data type IPADDRESS
		case	ATTRIB_NAS_IP_Address:			  
		case   	ATTRIB_Framed_IP_Address:		 
		case	ATTRIB_Framed_IP_Netmask:		 
		case	ATTRIB_Login_IP_Host:
			//allocate memory
			if(!(this->value=new Octet[4]))
			{
				return ALLOC_ERROR;
			}
			//transform the number parted by the "." in network byte order
			i=0;j=0;
			while(value[i]!='.' && i<3)
				tmpStr[j++]=value[i++];
			tmpStr[j]=0;
			if (value[i]!='.')
			{
				return BAD_IP;
			}
			this->value[0]=(unsigned char)atoi(tmpStr);

			j=0;
			i++;
			while(value[i]!='.' && i<7)
				tmpStr[j++]=value[i++];
			tmpStr[j]=0;
			if (value[i]!='.')
			{
				return BAD_IP;
			}
			this->value[1]=(unsigned char)atoi(tmpStr);

			j=0;i++;
			while(value[i]!='.' && i<11)
				tmpStr[j++]=value[i++];
			tmpStr[j]=0;
			if (value[i]!='.')
			{
				return BAD_IP;
			}
			this->value[2]=(unsigned char)atoi(tmpStr);

			j=0;i++;
			while(value[i] && i<15)
				tmpStr[j++]=value[i++];
			tmpStr[j]=0;
			this->value[3]=(unsigned char)atoi(tmpStr);
		
			this->length=4;
			break;
		// User-Password
		case	ATTRIB_User_Password:
			//the minimum length is 16 Octets
			if (strlen(value)<16)
			{
				if(!(this->value=new Octet [16]))
				{
					return ALLOC_ERROR;
				}
				memset(this->value,0,16);
				memcpy(this->value, value, strlen(value));
				this->length=(Octet)16;
			}
			//find a multiple of 16 Octets where the password fits
			else
			{
				passwordlen=((strlen(value)-(strlen(value)%16))/16);
				//if it doesn't fit, get the next bigger array.
				if ((strlen(value)%16)!=0)
				{
					passwordlen++;
				}
				if(!(this->value=new Octet [passwordlen*16]))
				{
					return ALLOC_ERROR;
				}
				memset(this->value,0,(passwordlen*16));
				memcpy(this->value, value, strlen(value));
				this->length=(Octet)(passwordlen*16);
				
			}
			break;
			
		//for datatype integer/enum	
		case	ATTRIB_NAS_Port:					 
		case	ATTRIB_Framed_MTU:				  
		case	ATTRIB_Login_TCP_Port:			  
		case	ATTRIB_Framed_IPX_Network:		  
		case	ATTRIB_Session_Timeout:			  
		case	ATTRIB_Framed_AppleTalk_Link:	  
		case	ATTRIB_Framed_AppleTalk_Network:	  
		case	ATTRIB_Acct_Delay:				  
		case	ATTRIB_Acct_Input_Octets:          
		case	ATTRIB_Acct_Output_Octets:			  
		case	ATTRIB_Acct_Session_Time:		  
		case	ATTRIB_Acct_Input_Packets:		  
		case	ATTRIB_Acct_Output_Packets:		  
		case	ATTRIB_Acct_Link_Count:			
		case	ATTRIB_Port_Limit:				
		case	ATTRIB_Service_Type:				 
		case	ATTRIB_Framed_Protocol:			  
		case	ATTRIB_Framed_Routing:			  
		case	ATTRIB_Framed_Compression:		  
		case	ATTRIB_Login_Service:			  
		case	ATTRIB_Idle_Timeout:				  
		case	ATTRIB_Termination_Action:		  
		case	ATTRIB_Acct_Status_Type:			  
		case	ATTRIB_Acct_Authentic:			  
		case	ATTRIB_Acct_Terminate_Cause:		  
		case	ATTRIB_NAS_Port_Type:			  
		case	ATTRIB_Login_LAT_Port:
		case	ATTRIB_ARAP_Zone_Access:        	
		case	ATTRIB_ARAP_Security:        	
		case	ATTRIB_Password_Retry:          	
		case	ATTRIB_Prompt:                  	
		case	ATTRIB_Acct_Interim_Interval:   
		case	ATTRIB_Acct_Input_Gigawords:		
		case	ATTRIB_Acct_Output_Gigawords:   	
		case	ATTRIB_Event_Timestamp:  
			if(!(this->value=new Octet [4]))
			{
				return ALLOC_ERROR;
			}
			//transform the integer in the right network byte order
			q=htonl(strtoul(value,NULL,10));
			memcpy(this->value,&q,4);
			this->length=4;
			
			break;
		
		//Special case vender specific, at the moment it is treated as a string.
		case ATTRIB_Vendor_Specific:
			if(!(this->value=new Octet [int(value[5])+4]))
			{
				return ALLOC_ERROR;
			}
			memcpy(this->value, value, int(value[5])+4);
			this->length=int(value[5])+4;
			break;
		
		//String: They need only copied in a new char array. 		
		default:
			if(!(this->value=new Octet [strlen(value)]))
			{
				return ALLOC_ERROR;
			}
			memcpy(this->value, value, strlen(value));
			this->length=strlen(value);
	}
	
	this->length+=sizeof(Octet)+sizeof(Octet);
	return 0;
}

/** Extract the value of an received attribute in the buffer to
 * the value field of an attribute. The order is still in network
 * order. If you want to get it maybe as a char or integer you
 * must to know which type it is. So you know the datatype and you
 * can convert it. But this done in another method.
 * @param value A pointer to the value which is copied to the value of the attribute.
 * @return An integer which indicates errors, 0 if everthing is ok,
 * else a number defined in the error.h.
 */


int RadiusAttribute::setRecvValue(char *value)
{
	
	if(!(this->value=new Octet[this->length-2]))
	{
		return ALLOC_ERROR;
	}
	memcpy(this->value, value, (this->length-2));
	return 0;
}

/** Transform a attribute value to an integer, this makes only sense
 * if the datatype is an integer. This dependents on the definition
 * in the radius RFC or can be locked up in the file radius.h of this 
 * source code.
 * @return The transformed integer.
 */

int RadiusAttribute::intFromBuf(void)
{
	return (ntohl(*(int*)this->value));
}

/**The overloading of the assignment operator.*/
RadiusAttribute & RadiusAttribute::operator=(const RadiusAttribute &ra)
{
	this->value=new Octet[ra.length-2];
	this->type=ra.type;		
	this->length=ra.length;			
	memcpy(this->value,ra.value,ra.length-2);
	return *this;
}

/**The copy constructor.*/
RadiusAttribute::RadiusAttribute(const RadiusAttribute &ra)
{
	this->value=new Octet[ra.length-2];
	this->type=ra.type;		
	this->length=ra.length;			
	memcpy(this->value,ra.value,ra.length-2);
}

/**The method sets the value. Internal it converts the string
 * into a char array and calls setValue(char *).
 * @param s The value as a string.
 * @return An integer. 0 if everything is ok, else !=0.
 */
int RadiusAttribute::setValue(string s)
{
	int ret;
	char * value=new char[s.size()+1];
	memset (value,0,s.size()+1);
	strncpy(value,s.c_str(),s.size());
	ret=setValue(value);
	delete [] value;
	return ret;
}

/** The method sets the value for an integer. The method
 * writes the integer in a string and calls the method
 * setValue(char *).
 * @param value The value as an integer.
 * @return An integer, 0 if everything is ok, else !=0.
 */
int RadiusAttribute::setValue(uint32_t value)
{
	char num[11];
	memset(num,0,11);
	sprintf(num,"%u",value);
	return setValue(num);
}

/** The method converts the value into an ip.
 * The attribute must have the right datatype IPADDRESS.
 * @return The ip address as a string.
 */
string RadiusAttribute::ipFromBuf(void)
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

/** The method converts the value into an IPv6.
 * The attribute must have the right datatype IPADDRESS6.
 * @return The ip address as a string.
 */
string RadiusAttribute::ip6FromBuf(void)
{
	int num,i,len;
	char ip2[3],ip3[40];
	memset(ip3,0,40);
	len=(this->length-2);
	if(len>16)
		len=16;
	for (i=0;i<len;i++)
	{
		num=(int)this->value[i];
		sprintf(ip2,"%02x",num);
		strcat(ip3,ip2);
		if((i%2)==1 && i<len-1)
			strcat(ip3,":");
	}
	return string(ip3);
}  
