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
 
#include "RadiusPacket.h"
#define NEED_LIBGCRYPT_VERSION "1.2.0"
GCRY_THREAD_OPTION_PTHREAD_IMPL;

using namespace std;

/** The destructur frees the dynamic allocated memory of the buffers,
 * closes the socket and clears the attribute multimap.
 */

RadiusPacket::~RadiusPacket()
{
	
	if (this->sendbuffer)
	{
		delete [] (this->sendbuffer);
	}
	if (this->recvbuffer)
	{
		delete [] (this->recvbuffer);
	}
	
	
	if (this->sock)
	{
		close (this->sock);
	}
	this->attribs.clear();
	
}

/** The constructur sets the code and generate random numbers 
 * for the identifier. The socket and the buffer length are set to 0, the pointer 
 * to the buffers is set to NULL. The length is set to 20 Bytes, this is the length without 
 * attributes. 
 * @param code The code of the packet.
 */
RadiusPacket::RadiusPacket(Octet code)
{
	this->code=code;
	this->getRandom(RADIUS_PACKET_IDENTIFIER_LEN,&(this->identifier));
	memset(this->authenticator,0,16);
	memset(this->req_authenticator,0,16);
	this->length=sizeof(Octet)*(RADIUS_PACKET_AUTHENTICATOR_LEN+4);
	this->sendbuffer=NULL;
	this->sendbufferlen=0;
	this->recvbuffer=NULL;
	this->recvbufferlen=0;
	this->sock=0;
	
}

/** The constructur generates random numbers 
 * for the identifier. The socket, the code and the buffer length are set to 0, the pointer 
 * to the buffers is set to NULL. The length is set to 20 Bytes, this is the length without 
 * attributes. 
 */
RadiusPacket::RadiusPacket(void)
{
	this->code=0;
	this->getRandom(RADIUS_PACKET_IDENTIFIER_LEN,&(this->identifier));
	memset(this->authenticator,0,16);
	memset(this->req_authenticator,0,16);
	this->length=sizeof(Octet)*(RADIUS_PACKET_AUTHENTICATOR_LEN+4);
	this->sendbuffer=NULL;
	this->sendbufferlen=0;
	this->recvbuffer=NULL;
	this->recvbufferlen=0;
	this->sock=0;
	
}


/** Create a dump of the radius packet
 */
void RadiusPacket::dumpRadiusPacket(void)
{
	

	fprintf(stdout,"\n-- RadiusPacket -----------------\n");
	fprintf(stdout,"\tcode\t\t:\t%d\n",this->code);
	fprintf(stdout,"\tidentifier\t:\t%d\n",this->identifier);
	fprintf(stdout,"\tlength\t\t:\t%d\n",this->length);
	fprintf(stdout,"---------------------------------\n");
	for (multimap<Octet, RadiusAttribute>::iterator it = attribs.begin(); it != attribs.end(); ++it)
	{
		it->second.dumpRadiusAttrib();
	}
		
	fprintf(stdout,"---------------------------------\n");

}


/**	Returns the number of attributes in the given radiusPacket.
 * @return An integer with the number of the attributes.
 */
int RadiusPacket::getRadiusAttribNumber(void)
{
	int i=0;
	for (multimap<Octet, RadiusAttribute>::iterator it = attribs.begin(); it != attribs.end(); it++)
	{
		
		i++;
	}
	return i;
}


/**	Links a radiusAttrib structure to a radiusPacket.
 * @param ra The radius attribute to add.
 *	@return Returns 0 if everything is ok, 
 * NO_VALUE_IN_ATTRIBUTE if the attribut value length is 0.
 * Return -1 if attribute value length is 0.
 */ 
int RadiusPacket::addRadiusAttribute(RadiusAttribute *ra)
{
	if (ra->getLength()<1)
	{
		cerr << "No value in the Attribute!\n";
		return NO_VALUE_IN_ATTRIBUTE;
	}
	
	//insert the attribute in the list
	attribs.insert(pair<Octet,RadiusAttribute>((Octet)ra->getType(), *ra));
	
	//add the length of the attribute to the the packet length
	this->length=this->length+ra->getLength();
	return 0;
}


/**	Formats a radiusPacket structure into a buffer that can be sent to a radius server via UDP.
 *	The destination buffer is put into sendbuffer while its length is put into sendbufferlen.
 *  @param sharedsecret The sharedsecret in plaintext.
 *	@return Returns 0 if everything is ok, ALLOC_ERROR in case of error.
 */
int RadiusPacket::shapeRadiusPacket(const char * sharedsecret)
{
	int				i,j;
	Octet *			value;
	char * 			hashedpassword ;
	
	//fill the authenticator with random data
	this->getRandom(RADIUS_PACKET_AUTHENTICATOR_LEN,this->authenticator);
	
	//free the buffer if it is not empty, for ex. if is send again
	if(this->sendbuffer!=NULL)
	{
		delete [] this->sendbuffer;
	}
	//allocate memory for the packet
	if(!(this->sendbuffer=new Octet [this->length]))
	{
		return (ALLOC_ERROR);
	}
	
	this->sendbufferlen=0;
	
	//add the code and increment the length
	sendbuffer[(this->sendbufferlen)++]=this->code;
	
	//add the identifier and increment the length
	sendbuffer[(this->sendbufferlen)++]=this->identifier;
	int nlength=htonl(this->length);
	//add the two octets for the length and increment the length twice
	sendbuffer[(this->sendbufferlen)++]=((char*)&(nlength))[2];
	sendbuffer[(this->sendbufferlen)++]=((char*)&(nlength))[3];
	
	//add the authenticator to the buffer
	for(i=0;i<RADIUS_PACKET_AUTHENTICATOR_LEN;i++)
		sendbuffer[(this->sendbufferlen)++]=this->authenticator[i];
	
	//add the attributes to the buffer
	for (multimap<Octet, RadiusAttribute>::iterator it = attribs.begin(); it != attribs.end(); it++)
	{
		//if the attribute is a password, build the hashedpassword
		if (it->second.getType()==ATTRIB_User_Password)
		{
			
			this->sendbuffer[(this->sendbufferlen)++]=it->second.getType();
			this->sendbuffer[(this->sendbufferlen)++]=it->second.getLength();
						
			if (it->second.getLength()-2<=16)
			{
				hashedpassword=new char[16]; 
				it->second.makePasswordHash((char *)it->second.getValue(),hashedpassword,sharedsecret,this->getAuthenticator());
				for(j=0;j<16;j++)
					this->sendbuffer[(this->sendbufferlen)++]=(Octet)hashedpassword[j];
			
			}
			else
			{
				
				
				hashedpassword = new char [it->second.getLength()-2];
				it->second.makePasswordHash((char *)it->second.getValue(), hashedpassword, sharedsecret, this->getAuthenticator());
				
				for(j=0;j<(it->second.getLength()-2);j++)
				{
					this->sendbuffer[(this->sendbufferlen)++]=(Octet)hashedpassword[j];
			
				}
				
			
			}
			delete [] hashedpassword;
			
		}
		//normal attributes
		else
		{
			this->sendbuffer[(this->sendbufferlen)++]=it->second.getType();
			this->sendbuffer[(this->sendbufferlen)++]=it->second.getLength();
			value=it->second.getValue();
			for(j=0;j<(it->second.getLength()-2);j++)
				this->sendbuffer[(this->sendbufferlen)++]=value[j];
		}
	}
	return 0;
}


/**	Dumps a shaped RADIUS packet previously created with shapeRadiusPacket. 
 */
void	RadiusPacket::dumpShapedRadiusPacket(void)
{
	int		i,j,attr,attrLen;
	
	if(this->sendbuffer)
	{
		i=0;
		fprintf(stdout,"-- sendbuffer --");
		fprintf(stdout,"-- shapedRadiusPacket - header --");
		
		fprintf(stdout,"\n\tcode\t\t:\t%02x",(this->sendbuffer)[i++]);
		fprintf(stdout,"\n\tidentifier\t:\t%02x",(this->sendbuffer)[i++]);
		Octet length1=(this->recvbuffer)[i++];
		Octet length2=(this->recvbuffer)[i++];
		fprintf(stdout,"\n\tlength\t\t:\t%02x %02x",length1,length2);
		fprintf(stdout,"\n\tauthenticator\t:\t");
		for(j=0;j<RADIUS_PACKET_AUTHENTICATOR_LEN;j++)
			fprintf(stdout,"%02x ",(this->sendbuffer)[i++]);
	
		attr=0;
		do
		{
			fprintf(stdout,"\n-- attribute %02x ------------",attr);
			fprintf(stdout,"\n\ttype\t\t:\t%02x",(this->sendbuffer[i++]));
			fprintf(stdout,"\n\tlength\t\t:\t%02x",attrLen=(this->sendbuffer)[i++]);
			fprintf(stdout,"\n\tvalue\t\t:\t");
			for(j=0;j<attrLen-2;j++)
				fprintf(stdout,"%02x ",(this->sendbuffer)[i++]);
		}
		while(i<(this->sendbufferlen));
			
		fprintf(stdout,"\n---------------------------------\n");
	}
	if(this->recvbuffer)
	{
		i=0;
		fprintf(stdout,"-- recvbuffer --");
		fprintf(stdout,"-- shapedRadiusPacket - header --");
		fprintf(stdout,"\n\tcode\t\t:\t%02x",(this->recvbuffer)[i++]);
		fprintf(stdout,"\n\tidentifier\t:\t%02x",(this->recvbuffer)[i++]);
		Octet length1=(this->recvbuffer)[i++];
		Octet length2=(this->recvbuffer)[i++];
		fprintf(stdout,"\n\tlength\t\t:\t%02x %02x",length1,length2);
		fprintf(stdout,"\n\tauthenticator\t:\t");
		for(j=0;j<RADIUS_PACKET_AUTHENTICATOR_LEN;j++)
			fprintf(stdout,"%02x ",(this->recvbuffer)[i++]);
	
		attr=0;
		do
		{
			fprintf(stdout,"\n-- attribute %02x ------------",attr);
			fprintf(stdout,"\n\ttype\t\t:\t%02x",(this->recvbuffer[i++]));
			fprintf(stdout,"\n\tlength\t\t:\t%02x",attrLen=(this->recvbuffer)[i++]);
			fprintf(stdout,"\n\tvalue\t\t:\t");
			for(j=0;j<attrLen-2;j++)
				fprintf(stdout,"%02x ",(this->recvbuffer)[i++]);
		}
		while(i<(this->recvbufferlen));
			
		fprintf(stdout,"\n---------------------------------\n");
	}
		
}


/**	Formats a UDP-received buffer radiusPacket structure
 *	@return A error number. Returns 0 is everything is ok, NO_BUFFER_TO_UNSHAPE 
 * or ALLOC_ERROR or TO_BIG_ATTRIBUTE_LENGTH in case of error.
 */
int RadiusPacket::unShapeRadiusPacket(void)
{
	RadiusAttribute		*ra;
	int					pos,i;
	char				*value; 			
	
	//if the buffer is empty
	if(!this->recvbuffer||this->recvbufferlen<=0)
	{
		return NO_BUFFER_TO_UNSHAPE;
	}
		
	
	//	RADIUS packet header decoding
	this->code=this->recvbuffer[0];
	//cerr << getTime() << "\n\nCODE: %s\n\n", this->code);
	
	this->identifier=this->recvbuffer[1];
	memcpy(this->authenticator,recvbuffer+4,RADIUS_PACKET_AUTHENTICATOR_LEN);
	
	
	//	RADIUS packet attributes decoding
	pos=20;
			
	while(pos<this->recvbufferlen)
	{
		//for every turn create a new attribute
		if(!(ra=new RadiusAttribute))
		{
			return ALLOC_ERROR;
		}
				
		ra->setType(recvbuffer[pos++]);
		ra->setLength(recvbuffer[pos++]);
		
		//the maximum attribute size can be 
		//RADIUS_MAX_PACKET_LEN-20, 20: bytes of the
		//packet header.
		if(ra->getLength()>(RADIUS_MAX_PACKET_LEN-20))
		{
			return TO_BIG_ATTRIBUTE_LENGTH;
		}
		else
		{
				
			value=new char [ra->getLength()-2];
			for(i=0;i<(ra->getLength()-2);i++)
			{
				value[i]=recvbuffer[pos++];
			}
			ra->setRecvValue(value);		
			this->addRadiusAttribute(ra);
			this->length+=ra->getLength();
			delete [] value;
				
		}
		//free the attribute, it was inserted in the list
		delete ra;
	}
	//set the right length
	this->length=this->recvbufferlen;
	
	
	return 0;
}

/**	The method sends the packet to a radius server.
 * @param server A iterator to a server.
 * @return Returns the number of bytes successfully sent, 
 * SOCKET_ERROR or UNKNOWN_HOST in case of error.
 */
int RadiusPacket::radiusSend(list<RadiusServer>::iterator server)
{
 
	int					socket2Radius;
    struct hostent		*h;
    struct sockaddr_in	cliAddr,remoteServAddr;
    
    //the packet is shaped here, the authenticator gets
    //a new random value and then the buffer must be shaped again
    //the password field depends on the authenticator field
	if(this->shapeRadiusPacket(server->getSharedSecret().c_str())!=0)
	{
		return SHAPE_ERROR;
	}
	
	//new Authenticator with hash over the 
	//packet and the shared secret, if the packet is a ACCOUNTING_REQUEST
	if (this->code==ACCOUNTING_REQUEST)
	{
		this->calcacctdigest(server->getSharedSecret().c_str());
	
	}
	
	//save the authenticator field for packet authentication on receiving a packet
	memcpy(this->authenticator, this->req_authenticator, 16);
		
	//	Get server IP address (no check if input is IP address or DNS name
    if(!(h=gethostbyname(server->getName().c_str())))
	{
		return UNKNOWN_HOST;
	}
    
    remoteServAddr.sin_family=h->h_addrtype;
    memcpy((char*)&(remoteServAddr.sin_addr.s_addr),h->h_addr_list[0],h->h_length);
    
    //set the port, they are differnt for accounting and authentication
    if (this->code==ACCOUNTING_REQUEST)
	{
    	remoteServAddr.sin_port=htons(server->getAcctPort());
	}
	else
	{
		remoteServAddr.sin_port=htons(server->getAuthPort());
	}
    
    //	Socket creation
    if((socket2Radius = socket(AF_INET, SOCK_DGRAM, 0))<0)
	{
		cerr <<  "Cannot open socket: "<< strerror(errno) <<"\n";
		return SOCKET_ERROR;
	}
    
	//	Bind any port
    cliAddr.sin_family=AF_INET;
    cliAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    cliAddr.sin_port=htons(0);
 	 	
	//Bind the socket port,
    if(bind(socket2Radius,(struct sockaddr*)&cliAddr,sizeof(struct sockaddr))<0)
	{
		cerr << "Cannot bind port: " << strerror(errno) << "\n";
		socket2Radius=-1;
		return BIND_ERROR;
	}
	
	//safe the socket for receiving packets
	this->sock=socket2Radius;
	//sent the buffer
	return sendto(socket2Radius,this->sendbuffer,this->sendbufferlen,0,(struct sockaddr*)&remoteServAddr,sizeof(struct sockaddr));
}


/**	Receives a packet from a radius server, and copies it into recvbuffer.
 * If there is no response the packet is send again if the server->retry 
 * is bigger than 0. 1 means the packet is send
 * one more time. If a packet is received the received data is write to the recvbuffer
 * and the length is written to recvbufferlen. 
 * The attributes are cleared if a packet is received.
 * @param serverlist : A list of radius server. 
 * @return Returns 0 if everything is ok, else ALLOC_ERROR,  UNKNOWN_HOST, WRONG_AUTHENTICATOR_IN_RECV_PACKET or NO_RESPONSE in case of error.
 */
int RadiusPacket::radiusReceive(list<RadiusServer> *serverlist)
{
	
	list<RadiusServer>::iterator server;
	
	int 			result, retries=1; //for the first try retries=1, because the first packet was send in radiusSend()
	socklen_t		len;
	struct hostent	*h;
	fd_set  		set; 
	struct timeval 	tv;
	struct sockaddr_in	remoteServAddr;
	int i_server=serverlist->size(),i=0;
	server=serverlist->begin();
	
	while (i<i_server)
	{		
		//	Get server IP address (no check if input is IP address or DNS name
	    if(!(h=gethostbyname(server->getName().c_str())))
		{
			return UNKNOWN_HOST;
		}
		
	    remoteServAddr.sin_family=h->h_addrtype;
	    
	    remoteServAddr.sin_port=htons(server->getAuthPort());
		
		
	    //retry the sending if there is no result
	    while (retries<=server->getRetry())
	    {
		    // wait for the specified time for a response
		    tv.tv_sec = server->getWait();  
		    tv.tv_usec = 0;
		    FD_ZERO(&set);				// clear out the set 
		    FD_SET(this->sock, &set);	// wait only for the RADIUS UDP socket 
			result = select(FD_SETSIZE, &set, NULL, NULL, &tv);
				
			if (result>0)
			{
				
				//clear the attributes
				attribs.clear();
		
				
				//allocate enough space for the buffer (RFC says maximum 4096=RADIUS_MAX_PACKET_LEN Bytes)
				if(!(this->recvbuffer=new Octet[RADIUS_MAX_PACKET_LEN]))
				{
					return (ALLOC_ERROR);
				}
				//set the buffer to 0
				memset(this->recvbuffer,0,RADIUS_MAX_PACKET_LEN); 	
				len=sizeof(struct sockaddr_in);
				this->recvbufferlen=recvfrom(this->sock,this->recvbuffer,RADIUS_MAX_PACKET_LEN,0,(struct sockaddr*)&remoteServAddr,&len);
				close(this->sock);
				this->sock=0;
				//unshape the packet
				if(this->unShapeRadiusPacket()!=0)
				{
					return UNSHAPE_ERROR;
				}
				
				if (this->authenticateReceivedPacket(server->getSharedSecret().c_str())!=0)
				{
					
					return WRONG_AUTHENTICATOR_IN_RECV_PACKET;
				}
				return 0;
			}
			else
			{
				close(this->sock);
				this->sock=0;
				//retry only if the retries are less than
				//the server retries
				if(retries <= server->getRetry())
				{
					this->radiusSend(server);
				}
			}
			retries++;
	    }
	    
		server++;
		i++;
		//set the retries=0, for the new server
		retries=0;
	}
	
	return NO_RESPONSE;
  	
}

/** Sets the authenticator field if the packet is
 * a accounting request. It is a MD5 hash over the whole packet 
 * (the authenticator field itself is set to 0) and the shared
 * secret.
 * The authenticator is updated in the field this->authenticator
 * and in the serialized packet.
 * @param secret The shared secret of the server in plaintext.
 */
void RadiusPacket::calcacctdigest(const char *secret)
{
	//Octet		digest[MD5_DIGEST_LENGTH];
	gcry_md_hd_t	context;

	//Zero out the auth_vector in the received packet.
	//Then append the shared secret to the received packet,
	//and calculate the MD5 sum. This must be the same
	//as the original MD5 sum (packet->vector).
	
	memset((this->sendbuffer+4), 0, 16);
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
	gcry_md_write(context, this->sendbuffer, this->length);
	gcry_md_write(context, secret, strlen(secret));
	//copy the digest to the paket
	memcpy(this->sendbuffer+4, gcry_md_read(context, GCRY_MD_MD5), 16);
	memcpy(this->authenticator, this->sendbuffer+4, 16);
	gcry_md_close(context);
}


/** Returns a pointer to the authenticator field.
 * @return A pointer to the authenticator field.
 */
char * RadiusPacket::getAuthenticator(void)
{
		return ((char *)this->authenticator);
}

/** The getter method of the packet code.
 * @return The code as an integer.
 */
int	RadiusPacket::getCode(void)
{
	return ((int)this->code);
}

/** Generates real random data with the device "/dev/random". 
 * Windows doesn'h have this device!. The method generates 
 * random data with the length len and copies it to the
 * field num. In the num field must be enough space!
 * @param len  The length of the random data.
 * @param num  A pointer to an array where the random data is written to.
 */
void RadiusPacket::getRandom(int len, Octet *num)
{

  int fd = open("/dev/urandom",O_RDONLY); 
  if (fd >= 0) 
  {
  	read(fd, num, len);		 
  }
  
  close(fd);
}

/**The method finds attributes with the given type in the packet and returns iterator pair.
 * This can be looped for the attributes.
 * @param type The attribute type to find.
 * @return A pair of the datatype pair<multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator>
 */
pair<multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator> RadiusPacket::findAttributes(int type)
{
	pair<multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator> p;
	p=attribs.equal_range((Octet) type);
	return p;
}

/**The method checks the authenticator field from a received packet,
 * so the radius server is authenticated against the client.
 * @param secret The shared secret.
 * @return A an integer, 0 if the authenticator field is ok, else WRONG_AUTHENTICATOR_IN_RECV_PACKET.
 */

int	RadiusPacket::authenticateReceivedPacket(const char *secret)
{
	gcry_md_hd_t	context;
	
	Octet * cpy_recvpacket;
	//make a copy of the received packet 
	cpy_recvpacket=new Octet [this->recvbufferlen];
	
	memcpy(cpy_recvpacket, this->recvbuffer, this->recvbufferlen);
	
	//copy the authenticator of the sent packet to the received packet 
	memcpy(cpy_recvpacket+4, this->sendbuffer+4, 16);
	
	//bulid the hash of the copy
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
	gcry_md_write(context, cpy_recvpacket, this->recvbufferlen);
	gcry_md_write(context, secret, strlen(secret));
	
	delete[] cpy_recvpacket;
	
	//compare the received and the built authenticator
	if (memcmp(this->recvbuffer+4, gcry_md_read(context, GCRY_MD_MD5), 16)!=0)
	{
		gcry_md_close(context);
		return WRONG_AUTHENTICATOR_IN_RECV_PACKET;
	}
	else
	{ 
		gcry_md_close(context);
		return 0;
	}
		
}


