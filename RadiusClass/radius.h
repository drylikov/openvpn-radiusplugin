/*
 *  RadiusClass -- An C++-Library for radius authentication 
 *					and accounting.
 * 
 *  Copyright (C) 2005 EWE TEL GmbH/Ralf Luebben <ralfluebben@gmx.de>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program (see the file COPYING included with this
 *  distribution); if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
#ifndef _RADIUS_H_
#define _RADIUS_H_


#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

/** The datatype for sending and receiving data to and from the network */ 
typedef	unsigned char	Octet;

/** Some length definitions */
#define	RADIUS_PACKET_AUTHENTICATOR_LEN	16
#define	RADIUS_MAX_PACKET_LEN			4096
#define RADIUS_PACKET_IDENTIFIER_LEN	1
#define MD5_DIGEST_LENGTH 16

/** The radius packet codes */

#define	ACCESS_REQUEST		1
#define	ACCESS_ACCEPT		2
#define	ACCESS_REJECT		3
#define	ACCOUNTING_REQUEST	4
#define	ACCOUNTING_RESPONSE	5
#define	ACCESS_CHALLENGE	11
#define	STATUS_SERVER		12	
#define	STATUS_CLIENT		13	
#define	RESERVED			255	

/**	The radius attribute types */

#define	ATTRIB_User_Name				1 //string
#define	ATTRIB_User_Password			2 //string
#define	ATTRIB_CHAP_Password			3 //string
#define	ATTRIB_NAS_IP_Address			4 //ipaddr
#define	ATTRIB_NAS_Port					5 //integer
#define	ATTRIB_Service_Type				6 //enum
#define	ATTRIB_Framed_Protocol			7 //enum
#define	ATTRIB_Framed_IP_Address		8 //ipaddr
#define	ATTRIB_Framed_IP_Netmask		9 //ipaddr
#define	ATTRIB_Framed_Routing			10 //enum
#define	ATTRIB_Filter_Id				11 //string
#define	ATTRIB_Framed_MTU				12 //integer
#define	ATTRIB_Framed_Compression		13 //enum
#define	ATTRIB_Login_IP_Host			14 //ipaddr
#define	ATTRIB_Login_Service			15 //enum
#define	ATTRIB_Login_TCP_Port			16 //integer
#define	ATTRIB_Reply_Message			18 //string
#define	ATTRIB_Callback_Number			19 //string
#define	ATTRIB_Callback_Id				20 //string
#define	ATTRIB_Framed_Route				22 //string
#define	ATTRIB_Framed_IPX_Network		23 //integer
#define	ATTRIB_State					24 //string
#define	ATTRIB_Class					25 //string
#define	ATTRIB_Vendor_Specific			26 //string -> vendor
#define	ATTRIB_Session_Timeout			27 //integer
#define	ATTRIB_Idle_Timeout				28 //enum
#define	ATTRIB_Termination_Action		29 //enum
#define	ATTRIB_Called_Station_Id		30 //string
#define	ATTRIB_Calling_Station_Id		31 //string
#define	ATTRIB_NAS_Identifier			32 //string
#define	ATTRIB_Proxy_State				33 //string
#define	ATTRIB_Login_LAT_Service		34 //string
#define	ATTRIB_Login_LAT_Node			35 //string
#define	ATTRIB_Login_LAT_Group			36 //string
#define	ATTRIB_Framed_AppleTalk_Link	37 //integer
#define	ATTRIB_Framed_AppleTalk_Network	38 //integer
#define	ATTRIB_Framed_AppleTalk_Zone	39 //string
#define ATTRIB_Acct_Status_Type			40 //enum
#define ATTRIB_Acct_Delay				41 //integer
#define ATTRIB_Acct_Input_Octets        42 //integer
#define ATTRIB_Acct_Output_Octets		43 //integer
#define ATTRIB_Acct_Session_ID			44 //string
#define ATTRIB_Acct_Authentic			45 //enum
#define ATTRIB_Acct_Session_Time		46 //integer
#define ATTRIB_Acct_Input_Packets		47 //integer
#define ATTRIB_Acct_Output_Packets		48 //integer
#define ATTRIB_Acct_Terminate_Cause		49 //enum
#define ATTRIB_Acct_Multi_Session_ID	50 //string
#define ATTRIB_Acct_Link_Count			51 //interger

#define ATTRIB_Acct_Input_Gigawords		52 //integer
#define ATTRIB_Acct_Output_Gigawords   	53 //integer
#define ATTRIB_Event_Timestamp         	55 //date


#define	ATTRIB_CHAP_Challenge			60 //string
#define	ATTRIB_NAS_Port_Type			61 //enum
#define	ATTRIB_Port_Limit				62 //interger
#define	ATTRIB_Login_LAT_Port			63 //enum

#define ATTRIB_Acct_Tunnel_Connection	68 //string

#define ATTRIB_ARAP_Password           	70 //  string
#define ATTRIB_ARAP_Features           	71 //string
#define ATTRIB_ARAP_Zone_Access        	72 //integer
#define ATTRIB_ARAP_Security           	73 //integer
#define ATTRIB_ARAP_Security_Data      	74 //string
#define ATTRIB_Password_Retry          	75 //integer
#define ATTRIB_Prompt                  	76 //integer
#define ATTRIB_Connect_Info				77 //string
#define ATTRIB_Configuration_Token		78 //string
#define ATTRIB_EAP_Message				79 //octets
#define ATTRIB_Message_Authenticator	80 //octets
#define ATTRIB_ARAP_Challenge_Response	84 //string	# 10 octets
#define ATTRIB_Acct_Interim_Interval   	85 //integer
#define ATTRIB_NAS_Port_Id				87 //string
#define ATTRIB_Framed_Pool				88 //string
#define ATTRIB_NAS_IPv6_Address			95 //ipv6addr
#define ATTRIB_Framed_Interface_Id		96 //ifid
#define ATTRIB_Framed_IPv6_Prefix		97 //octets # ipv6prefix
#define ATTRIB_Login_IPv6_Host			98 //ipv6addr
#define ATTRIB_Framed_IPv6_Route		99 //string
#define ATTRIB_Framed_IPv6_Pool			100//string


#define	VALUE_Service_Type_Call_Check	"10"
#define	VALUE_Service_Type_Framed_User	"2"





#endif //_RADIUS_H_
