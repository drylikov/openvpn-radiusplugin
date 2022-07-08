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
 

#include "IpcSocket.h"


/** The constructor sets the socket to -1.*/
IpcSocket::IpcSocket()
{
	this->socket=-1;
}

/** The constructor sets the socket number.
 * @param int : The socket number.
 */
IpcSocket::IpcSocket(int s)
{
	this->socket=s;
}

/** The destructor closes the socket
 * if it is not equal -1.
 */
IpcSocket::~IpcSocket()
{
	if (socket != -1)
	{
		close (this->socket);
	}
	this->socket=-1;
}

/** The method sets the socket to s.
 * @param s The socket number.
 */
void IpcSocket::setSocket(int s)
{
	this->socket=s;
}

/**The method returns the socket number
 * @return The socket number.
 */
int IpcSocket::getSocket(void)
{
	return this->socket;
}


/**The method sends a string via the
 * socket. First the length of the string is sent
 * and then the string itself.
 * @param str The string to send.
 * @throws Exception::SOCKETSEND if the length or the string could not send
 * correctly.
 */
void IpcSocket::send(string str)
{
	ssize_t len = str.size();
  	ssize_t size=0;
  	//send the length of the string
        size = write(this->socket, &len, sizeof(ssize_t));
  	if (size != sizeof(ssize_t))
  	{
  		throw Exception(Exception::SOCKETSEND);
  	}
        if(len > 0)
        {
          //send the string
          size = write(this->socket, str.c_str(), len);
          if (size != len)
          {
            throw Exception(Exception::SOCKETSEND);
          }
        }
}

/**The method sends a buffer via the
 * socket. First the length of the buffer is sent
 * and then the buffer itself.
 * @param value The buffer to send.
 * @throws Exception::SOCKETSEND if the length or the buffer could not send
 * correctly.
 */
void IpcSocket::send(Octet * value, ssize_t len)
{
	ssize_t size=0;
  	//send the length of the string
  	size = write (this->socket, &len, sizeof(ssize_t));
  	if (size != sizeof(ssize_t))
  	{
  		throw Exception(Exception::SOCKETSEND);
  	}
        if (len > 0)
  	{
	  	//send the buffer
	  	size = write (this->socket, value, len);
	  	if (size != len)
	  	{
	  		throw Exception(Exception::SOCKETSEND);
	  	}
  	}
}

/**The method sends an integer via
 * the socket.
 * @param int : The integer to send.
 * @throws Exception::SOCKETSEND if the size of the
 * integer and the sent size are not equal.
 */ 
void IpcSocket::send(int num)
{
	
  	const ssize_t size = write (this->socket, &num, sizeof(int));
  	if (size != sizeof(int))
  	{
  		throw Exception(Exception::SOCKETSEND);
  	}
}


/**The method receives an integer from the socket.
 * @return The received integer.
 * @throws Exception::SOCKETRECV If the received size
 * is not the size of an integer.
 */

int IpcSocket::recvInt(void)
{
	int num;
	ssize_t size; 
        size = read(this->socket, &num, sizeof(int));
  	if (size != sizeof(int))
  	{
  	    
            throw Exception(Exception::SOCKETRECV);
  	}
  	return num;
}



/**The method receives a string from the socket.
 * First it receives the length, then
 * creates a buffer with the length and writes
 * the bytes from the socket into the buffer.
 * The buffer is copied in a string and the string is returned.
 * @return string : A string with the received value.
 * @throws Exception::SOCKETRECV If the received length
 * of the integer for the length or the length of the received string is wrong. 
 */
string IpcSocket::recvStr(void)
{
	ssize_t len;
	char * buffer;
	ssize_t size;
	string str;
	size = read(this->socket,&len,sizeof(ssize_t));
	if (size!=sizeof(ssize_t))
	{
	  throw Exception(Exception::SOCKETRECV);
	}
        if(len > 0)
        {
          try{
	    buffer=new char[len+1];
	  }
	  catch(...)
	  {
	    cerr << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for buffer in IpcSocket::recvStr." << endl;
	  }
          memset (buffer, 0, len+1);
          size = read (this->socket, buffer, len);
          if (size!=len)
          {
            throw Exception(Exception::SOCKETRECV);
          }
          str=buffer;
          delete [] buffer;
        }
    return str;
}

/**The method receives a buffer from the socket.
 * First it receives the length, then
 * creates a buffer with the length and writes
 * the bytes from the socket into the buffer.
 * @return unsigned int : Length of the buffer.
 * @throws Exception::SOCKETRECV If the received length
 * of the integer for the length or the length of the received buffer is wrong. 
 */
void IpcSocket::recvBuf(User * user)
{
	ssize_t len;
        ssize_t size;
	size = read (this->socket,&len,sizeof(ssize_t));
	if (size!=sizeof(ssize_t))
	{
	    throw Exception(Exception::SOCKETRECV);
	}
	user->setVsaBufLen(len);
	if (len > 0)
	{
	  try{ 
	    user->setVsaBuf(new Octet[len]);
	  }
	  catch(...)
	  {
	    cerr  << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for buffer in IpcSocket::recvBuf." << endl;
	  }
	    size = read (this->socket, user->getVsaBuf(), len);
	    if (size != len)
		{
		  
                  throw Exception(Exception::SOCKETRECV);
		}
	}
    
}

