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


 
/*! \mainpage RadiusClass
 *
 *  
 * The RadiusClass is a library for RADIUS authentication
 * and accounting.
 * 
 * \section Features 
 * - Sending and receiving RADIUS packets.
 * - Generates password and authentication fields at sending automaticly, 
 * 		you only need to set the plain text password of the user for ACCESS_REQUEST packets.
 * - optional password length 
 * - timeouts for waiting on response packets
 * - sending retries if no response from server
 * - sending to optional number of servers 
 * 		- one after the other, if a server isn't reachable
 * 		- the order is the same as defined in the configfile
 * - extract attributes from the response packet, e.g. FramedIp or FramedRoutes
 * - functions to convert values from the response packets for integers and ip address as string (see function parseResponsePacket())
 *
 * 
 *
 * \section Installation
 * - Requirements: gcrypt library
 * - Configure the configfile for the library or set the parameters otherwise (see ./exampleconfig).
 * - Comments not allowed in configfile at the moment!
 * - For testing compile files with:
 * 		g++ -Wall -o main main.cpp RadiusAttribute.cpp RadiusPacket.cpp RadiusConfig.cpp RadiusServer.cpp RadiusVendorSpecificAttribute.cpp -lgcrypt 
 * - Integrate the library in your code (example implementation: main.cpp).
 * 
 * \section TODO
 * - debug - class
 * - improve the parsing of the configfile (caseinsensitive, comments, ...), datatype string for config
 * - create a method which returns a representation of the buffer dependent on the type (enum, ipaddr, string, integer)
 * - get the NAS ip address automatically from the system
 * - improve the parsing of framed routes and netmask
 * - check response packets authenticator field from the radius server
 * - exceptionhandling with try and catch
 * - create a routing and ip class with correctness checking
 * - MAKEfile

 * \section Limts 
 * Maximum characters for the parameters in the configfile:
 * - serviceType=1 			
 * - framedProtocol=1	
 * - nasPortType=1		
 * - nasIdentifier=128 		
 * - nasIpAddress=16 	
 * 
 * \section History
 * The RadiusClass was developed during my diploma thesis for the EWETEL GmbH (www.ewetel.net). 
 * They main idea was to create a virtualized SSL-VPN (OpenVPN) with RADIUS support. 
 * The virtualization was done by XEN. <br>
 * At this place I would like to thank the people from EWETEL GmbH and EWE AG (www.ewe.de) 
 * who supported me with the required equipment and hardware
 * and helped me with all my questions.
 * 
 * \section Memoryleaks
 * I testes the RadiusClass on memory leaks with valgrind. A output can be found in the file 
 * valgrind. There are no leaks, but some blocks are still
 * reachable. This is no problem, it is a feature of the C++ STL.
 * See Chapter 4.2  at http://valgrind.org/docs/FAQ/ .
 * 
 * \section Contact
 * Please report bugs and suggestions of improvement to me ralfluebben@gmx.de.    
 */

#include "RadiusAttribute.h"
#include "RadiusVendorSpecificAttribute.h"
#include "RadiusPacket.h"
#include "RadiusServer.h"
#include "RadiusConfig.h"
#include "radius.h"
#include <iostream>

void parseResponsePacket(RadiusPacket *packet);

/* Tested with freeradius and vendor specific attribute:

 !This is no official vendor number for OpenVPN!
 Configuration vendor specific attributes, example for OpenVPN iroute parameter:
 add in /etc/freeradius/dictionary following lines:
 
  	VENDOR          OpenVPN                 111
 	ATTRIBUTE       OpenVPN_iroute          1       string OpenVPN

 user configuration:
	
	user1   Auth-Type := Local, User-Password == "testing"
        Service-Type = Framed-User,
        Framed-Protocol = PPP,
        Framed-IP-Address = 10.8.0.20,
        Framed-IP-Netmask = 255.255.255.0,
        Framed-Routing = Broadcast-Listen,
        Framed-Compression = Van-Jacobsen-TCP-IP,
        Framed-Route += "192.168.101.0/26 10.8.0.1/32 1",
        Framed-Route += "192.168.111.0/24 10.8.0.1/32 1",
        Framed-Route += "192.168.112.0/24 10.8.0.1/32 1",
        Acct-Interim-Interval=7,
        OpenVPN_iroute="192.168.100.0 255.255.0.0"
*/

/** The RadiusClass is C++ library for RADIUS authentication and accounting.
 * Features:
 * - Sending and Receiving RADIUS packets.
 * - Generates password and authentication packet fields at sending, 
 * 		you only need to set the plain text password for the user for ACCESS_REQUEST packets
 * - password length optional
 * - timeouts for waiting on response packets
 * - sending retries if no response from server
 * - sending to optional number of servers:
 * 		- the first server from the config file is taken
 * 			- config parameter: e.g. wait=5 : wait 5s on a response
 * 			- config parameter: e.g. retry=2 : retry sending the packet 2 times after timeout
 * 		- if the first server do not response -> take the next server from config file
 * - extract attributes from the response packet, e.g. FramedIp or FramedRoutes
 * - functions to convert values from the response packets for integers and ip address as string (see function parseResponsePacket())
 **/
int main_test (void)
{
	
	list<RadiusServer> * serverlist;
	list<RadiusServer>::iterator server;
	//create RadiusPacket: you can already specify the type
	RadiusPacket		packet_access(ACCESS_REQUEST);
	
	//the packets for accounting (start,update,stop)
	RadiusPacket		packet_accounting_start(ACCOUNTING_REQUEST);
	RadiusPacket		packet_accounting_update(ACCOUNTING_REQUEST);
	RadiusPacket		packet_accounting_stop(ACCOUNTING_REQUEST);
	
	//create RadiusAttributes: you can specify type and value.
	RadiusAttribute		ra1(ATTRIB_User_Name,"user1"),
						ra2(ATTRIB_User_Password),
						ra3(ATTRIB_NAS_Port,55),
						ra4(ATTRIB_Calling_Station_Id,"127.0.0.1"),
						ra5(ATTRIB_NAS_Identifier),
						ra6(ATTRIB_NAS_IP_Address),
						ra7(ATTRIB_NAS_Port_Type),
						ra8(ATTRIB_Service_Type),
						ra9(ATTRIB_Framed_IP_Address),
						ra10(ATTRIB_Acct_Session_ID, 99),
						//for accounting packet type (start/update/stop)
						ra11(ATTRIB_Acct_Status_Type),
						ra12(ATTRIB_Framed_Protocol),
						
						//for accounting update and stop packets
						ra13(ATTRIB_Acct_Input_Octets, 99),
						ra14(ATTRIB_Acct_Output_Octets, 10),
						ra15(ATTRIB_Acct_Session_Time, 12345),
						ra16(ATTRIB_Vendor_Specific);
						
	RadiusVendorSpecificAttribute rvsa;
	
	//read in the config
	RadiusConfig config(string("./exampleconfig"));
	
	cout << "*** Sampleprogramm for the RadiusClass. ***\n";
	cout << "---- Print Config ----\n";
	cout << config;
	cout << "-----------------------\n";
	
	// Send a ACCEPT-REQUEST-PACKET
	cout << "-----------------------------------------------------\n";
	cout << "-------- Send a ACCESS-REQUEST-PACKET ---------------\n";
	cout << "-----------------------------------------------------\n";
	
	/*set password (the method setValue() detects which type
	 * the attribut is from, and converts the value correct for
	 * this type)
	 */
	ra2.setValue(string("testing"));
	if(packet_access.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_User_Name.\n";
	}
	if (packet_access.addRadiusAttribute(&ra2))
	{
		cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_User_Password.\n";
	}
	if (packet_access.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet_access.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	//get information from the config and add it to the packet
	if(strcmp(config.getNASIdentifier(),""))
	{
			ra5.setValue(config.getNASIdentifier());
			if (packet_access.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(config.getNASIpAddress(),""))
	{
			if(ra6.setValue(config.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-CLASS: Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
			else
			if (packet_access.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(config.getNASPortType(),""))
	{
			ra7.setValue(config.getNASPortType());
			if (packet_access.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(config.getServiceType(),""))
	{
			ra8.setValue(config.getServiceType());
			if (packet_access.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-CLASS: Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	
	//example for sending vendor specific attribute
	rvsa.setId(123);
	rvsa.setType(1);
	rvsa.setValue("Vendor Attribute");
	//integers can be set directly
	//rvsa.setValue(1981);
	Octet * tmp_rvsa=new Octet[rvsa.getLength()+4];
	
	rvsa.getShapedAttribute(tmp_rvsa);
	ra16.setValue((char *)tmp_rvsa);
	
	packet_access.addRadiusAttribute(&ra16);
	
	delete [] tmp_rvsa;
	
	
	//get the server list
	serverlist=config.getRadiusServer();
	
	//check if there are servers
	try
	{
		if(serverlist->empty())
		{
			throw(string("RADIUS-CLASS: No servers defined!"));
		}
	}
	catch(string)
	{
		cerr<< "No servers!";
		//stop the programm if there are no server(s) in config
		return 0;
	}
	
	//set server to the first server
	server=serverlist->begin();
	
	//send the packet to the first server from the list
	if (packet_access.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-CLASS: Packet was not sent.\n";
	}
	
	//receive the packet, if the server doesn't response send the packet to the next server in list.
	if (packet_access.radiusReceive(serverlist)==0)
	{
		//is it a accept?
		if(packet_access.getCode()==ACCESS_ACCEPT)
		{
			/*Parse the attributes for framedip, framedroutes and acctinteriminterval.
			This is only an example, so the function has no return values, the
			values are printed at stdout.*/
			parseResponsePacket(&packet_access);
				
		}
		//If the radius server denied the access or sends a ACCESS_CHALLENGE-packet.
		else
		{
			cerr << getTime() << "RADIUS-CLASS: Get ACCESS_REJECT or ACCESS_CHALLENGE-Packet.->ACCESS-DENIED.\n";
		}
		
	}
	else
	{
		cerr << getTime() << "RADIUS-CLASS: Got no or bad response from radius server.\n";
	}
	
	
	// Send a ACCOUNTING-REQUEST-PACKET, Status-Type:Start
	
	cout << "-----------------------------------------------------\n";
	cout << "-------- Send a ACCOUNTING-REQUEST-PACKET -----------\n";
	cout << "-----------------Status-Type: Start------------------\n";
	cout << "-----------------------------------------------------\n";
	
	
	//add the attributes to the packet
	if(packet_accounting_start.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	
	if (packet_accounting_start.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet_accounting_start.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	
	
	if (packet_accounting_start.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Session_Id.\n";
	}
	
	//set status type: start = 1 (see RADIUS RFC)
	ra11.setValue(string("1"));
	if (packet_accounting_start.addRadiusAttribute(&ra11))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Status_Type.\n";
	}
	
	
	//get information from the config and add the attributes to the packet
	if(strcmp(config.getNASIdentifier(),""))
	{
			ra5.setValue(config.getNASIdentifier());
			if (packet_accounting_start.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(config.getNASIpAddress(),""))
	{
			if(ra6.setValue(config.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
	
			if (packet_accounting_start.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(config.getNASPortType(),""))
	{
			ra7.setValue(config.getNASPortType());
			if (packet_accounting_start.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(config.getServiceType(),""))
	{
			ra8.setValue(config.getServiceType());
			if (packet_accounting_start.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	if(strcmp(config.getFramedProtocol(),""))
	{
			ra12.setValue(config.getFramedProtocol());
			if (packet_accounting_start.addRadiusAttribute(&ra12))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_FramedProtocol.\n";
			}
	}
	ra9.setValue(string("111.222.111.111"));
	if (packet_accounting_start.addRadiusAttribute(&ra9))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	
	
	//send the packet_accounting_start	
	if (packet_accounting_start.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//receive the response
	if (packet_accounting_start.radiusReceive(serverlist)>=0)
	{
		//is is a accounting resopnse ?
		if(packet_accounting_start.getCode()==ACCOUNTING_RESPONSE)
		{
			cerr << getTime() << "RADIUS-CLASS:  Get ACCOUNTING_RESPONSE-Packet.\n";

		}
	}	
	else
	{
		cerr << getTime() << "RADIUS-CLASS: Got no or bad response from radius server.\n";
	}
	
	// Send a ACCOUNTING-REQUEST-PACKET, Status-Type:Update
	
	cout << "-----------------------------------------------------\n";
	cout << "-------- Send a ACCOUNTING-REQUEST-PACKET -----------\n";
	cout << "-----------------Status-Type: Update-----------------\n";
	cout << "-----------------------------------------------------\n";
	
	//add the attributes to the packet
	if(packet_accounting_update.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	
	if (packet_accounting_update.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet_accounting_update.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	
	
	
	if (packet_accounting_update.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Session_Id.\n";
	}
	
	//set status type: update = 3(see RADIUS RFC)
	ra11.setValue(string("3"));
	if (packet_accounting_update.addRadiusAttribute(&ra11))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Status_Type.\n";
	}
	
	
	
	if (packet_accounting_update.addRadiusAttribute(&ra13))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Octets.\n";
	}
	if (packet_accounting_update.addRadiusAttribute(&ra14))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Octets.\n";
	}
	if (packet_accounting_update.addRadiusAttribute(&ra14))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_Time.\n";
	}
	
	//get information from the config and add the attributes to the packet
	if(strcmp(config.getNASIdentifier(),""))
	{
			ra5.setValue(config.getNASIdentifier());
			if (packet_accounting_update.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(config.getNASIpAddress(),""))
	{
			if(ra6.setValue(config.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
	
			if (packet_accounting_update.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(config.getNASPortType(),""))
	{
			ra7.setValue(config.getNASPortType());
			if (packet_accounting_update.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(config.getServiceType(),""))
	{
			ra8.setValue(config.getServiceType());
			if (packet_accounting_update.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	if(strcmp(config.getFramedProtocol(),""))
	{
			ra12.setValue(config.getFramedProtocol());
			if (packet_accounting_update.addRadiusAttribute(&ra12))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_FramedProtocol.\n";
			}
	}
	ra9.setValue(string("111.222.111.111"));
	if (packet_accounting_update.addRadiusAttribute(&ra9))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	
	
	//send the packet_accounting_update	
	if (packet_accounting_update.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//receive the response
	if (packet_accounting_update.radiusReceive(serverlist)>=0)
	{
		//is is a accounting resopnse ?
		if(packet_accounting_update.getCode()==ACCOUNTING_RESPONSE)
		{
			cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Get ACCOUNTING_RESPONSE-Packet.\n";

		}
		
		
	}
	else
	{
		cerr << getTime() << "RADIUS-CLASS: Got no or bad response from radius server.\n";
	}
	
	// Send a ACCOUNTING-REQUEST-PACKET, Status-Type:Stop
	
	cout << "-----------------------------------------------------\n";
	cout << "-------- Send a ACCOUNTING-REQUEST-PACKET -----------\n";
	cout << "-----------------Status-Type: Stop-------------------\n";
	cout << "-----------------------------------------------------\n";
	
	//add the attributes to the packet
	if(packet_accounting_stop.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	
	if (packet_accounting_stop.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet_accounting_stop.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	
	
	
	if (packet_accounting_stop.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Session_Id.\n";
	}
	
	//set status type: update = 2(see RADIUS RFC)
	ra11.setValue(string("2"));
	if (packet_accounting_stop.addRadiusAttribute(&ra11))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Status_Type.\n";
	}
	
	
	
	if (packet_accounting_stop.addRadiusAttribute(&ra13))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Octets.\n";
	}
	if (packet_accounting_stop.addRadiusAttribute(&ra14))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Octets.\n";
	}
	if (packet_accounting_stop.addRadiusAttribute(&ra14))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_Time.\n";
	}
	
	//get information from the config and add the attributes to the packet
	if(strcmp(config.getNASIdentifier(),""))
	{
			ra5.setValue(config.getNASIdentifier());
			if (packet_accounting_stop.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(config.getNASIpAddress(),""))
	{
			if(ra6.setValue(config.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
	
			if (packet_accounting_stop.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(config.getNASPortType(),""))
	{
			ra7.setValue(config.getNASPortType());
			if (packet_accounting_stop.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(config.getServiceType(),""))
	{
			ra8.setValue(config.getServiceType());
			if (packet_accounting_stop.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	if(strcmp(config.getFramedProtocol(),""))
	{
			ra12.setValue(config.getFramedProtocol());
			if (packet_accounting_stop.addRadiusAttribute(&ra12))
			{
				cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_FramedProtocol.\n";
			}
	}
	ra9.setValue(string("111.222.111.111"));
	if (packet_accounting_stop.addRadiusAttribute(&ra9))
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	
	
	//send the packet_accounting_stop	
	if (packet_accounting_stop.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//receive the response
	if (packet_accounting_stop.radiusReceive(serverlist)>=0)
	{
		//is is a accounting resopnse ?
		if(packet_accounting_stop.getCode()==ACCOUNTING_RESPONSE)
		{
			cerr << getTime() << "RADIUS-CLASS: BACKGROUND-ACCT:  Get ACCOUNTING_RESPONSE-Packet.\n";

		}
	}
	else
	{
		cerr << getTime() << "RADIUS-CLASS: Got no or bad response from radius server.\n";
	}
	
	cout << "\n---- End ----";
	return (0);


}


void parseResponsePacket(RadiusPacket *packet)
{
	cout << "\n ---- Parse Response Packet ----";
	
	pair <multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator> range;
	multimap<Octet,RadiusAttribute>::iterator iter1, iter2;
	
		
	range=packet->findAttributes(22);
	iter1=range.first;
	iter2=range.second;	
	string froutes;
	string ip;
	int acct_interval;
	RadiusVendorSpecificAttribute vsa;
	
	while (iter1!=iter2)
	{
		froutes.append((char *) iter1->second.getValue(),iter1->second.getLength()-2);
		froutes.append(";");
		iter1++;
	}
	cout << "\nFramed Routs: " << froutes;
		
	range=packet->findAttributes(ATTRIB_Framed_IP_Address);
	iter1=range.first;
	iter2=range.second;	
	if (iter1!=iter2)
	{
		ip=iter1->second.ipFromBuf();
	}
	cout << "\nFramed IP: " << ip;
		
	
	range=packet->findAttributes(85);
	iter1=range.first;
	iter2=range.second;		
	if (iter1!=iter2)
	{
		acct_interval=iter1->second.intFromBuf();
	}
	else
	{
		cerr << getTime() <<"RADIUS-CLASS: No attributes Acct Interim Interval or bad length.\n";
	}
	cout << "\nAcct-Interim-Interval: " << acct_interval;
	
	range=packet->findAttributes(26);
	iter1=range.first;
	iter2=range.second;		
	if (iter1!=iter2)
	{
		while(iter1!=iter2)
		{
			vsa.decodeRecvAttribute(iter1->second.getValue());
			if (vsa.getId() == 111 && vsa.getType()==1)
			{
				
				cout << "\nVendorSpecificAttribute OpenVPN IRoute: " << vsa.stringFromBuf() << " \n";
				iter1++;
				
			}
		}
	}
	else
	{
		cout << "RADIUS-CLASS: No vendor specific attributes.\n";
	}


}
