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
 
#include "UserAcct.h"
#include "radiusplugin.h"

/** The constructor calls the super constructor of the class User and the variables
 * sessionid, bytesin, bytesout, nextupdate and starttime are set to 0.*/
UserAcct::UserAcct():User()
{
	gigain=0;
	gigaout=0;
	bytesin=0;
	bytesout=0;
	nextupdate=0;
	starttime=0;
}

/** The destructor. Nothing happens here.*/
UserAcct::~UserAcct()
{
}

/** The assignment-operator.
 * @param u A refernece to a UserAcct.*/
UserAcct & UserAcct::operator=(const UserAcct &u)
{
	
	if (this!=&u)
	{
		this->User::operator=(u);
		this->gigain=u.gigain;
		this->gigaout=u.gigaout;
		this->bytesin=u.bytesin;
		this->bytesout=u.bytesout;
		this->nextupdate=u.nextupdate;
		this->starttime=u.starttime;
	}
	return *this;
}




/**The copy constructor, it calls first the copy constructor
 * of the User class.
 * @param UserAcct u : A reference to an UserAcct object.*/
UserAcct::UserAcct(const UserAcct &u):User(u)
{
	this->gigain=u.gigain;
	this->gigaout=u.gigaout;
	this->bytesin=u.bytesin;
	this->bytesout=u.bytesout;
	this->nextupdate=u.nextupdate;
	this->starttime=u.starttime;
	
}

/** The method sends an accounting update packet for the user to the radius server.
 * The accounting information are read from the OpenVpn
 * status file. The following attributes are sent to the radius server:
 * - User_Name, 
 * - Framed_IP_Address,
 * - NAS_Port,
 * - Calling_Station_Id,
 * - NAS_Identifier,
 * - NAS_IP_Address,
 * - NAS_Port_Type,
 * - Service_Type,
 * - Acct_Session_ID,
 * - Acct_Status_Type,
 * - Framed_Protocol,
 * - Acct_Input_Octets,
 * - Acct_Output_Octets,
 * - Acct_Session_Time,
 * - Acct_Input_Gigawords,
 * - Acct_Output_Gigawords
 * @param context The context of the plugin.
 * @return An integer, 0 is everything is ok, else 1.*/
int UserAcct::sendUpdatePacket(PluginContext *context)
{
	
	list<RadiusServer> * serverlist;
	list<RadiusServer>::iterator server;
	
	RadiusPacket		packet(ACCOUNTING_REQUEST);
	RadiusAttribute		ra1(ATTRIB_User_Name,this->getUsername()),
				ra2(ATTRIB_Framed_IP_Address,this->getFramedIp()),
				ra3(ATTRIB_NAS_Port,this->getPortnumber()),
				ra4(ATTRIB_Calling_Station_Id,this->getCallingStationId()),
				ra5(ATTRIB_NAS_Identifier),
				ra6(ATTRIB_NAS_IP_Address),
				ra7(ATTRIB_NAS_Port_Type),
				ra8(ATTRIB_Service_Type),
				ra9(ATTRIB_Acct_Session_ID, this->getSessionId()),
		                ra10(ATTRIB_Acct_Status_Type,string("3")), // "Alive"
				ra11(ATTRIB_Framed_Protocol),
				ra12(ATTRIB_Acct_Input_Octets, this->bytesin),
				ra13(ATTRIB_Acct_Output_Octets, this->bytesout),
				ra14(ATTRIB_Acct_Session_Time),
				ra15(ATTRIB_Acct_Input_Gigawords, this->gigain),
				ra16(ATTRIB_Acct_Output_Gigawords, this->gigaout);				
	
	
	
	//get the server list
	serverlist=context->radiusconf.getRadiusServer();
	
	//set server on the first server
	server=serverlist->begin();
	
	//add the attributes to the radius packet		
	if(packet.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Fail to add attribute ATTRIB_User_Name.\n";
	}
		
	if (packet.addRadiusAttribute(&ra2))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Password.\n";
	}
	
	if (packet.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	
	if (packet.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	//get the values from the config and add them to the packet
	if(strcmp(context->radiusconf.getNASIdentifier(),""))
	{
		ra5.setValue(context->radiusconf.getNASIdentifier());
		if (packet.addRadiusAttribute(&ra5))
		{
			cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
		}
	}
		
	if(strcmp(context->radiusconf.getNASIpAddress(),""))
	{
			if(ra6.setValue(context->radiusconf.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
			if (packet.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getNASPortType(),""))
	{
			ra7.setValue(context->radiusconf.getNASPortType());
			if (packet.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getServiceType(),""))
	{
			ra8.setValue(context->radiusconf.getServiceType());
			if (packet.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	
	if (packet.addRadiusAttribute(&ra9))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if (packet.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if(strcmp(context->radiusconf.getFramedProtocol(),""))
	{
			ra11.setValue(context->radiusconf.getFramedProtocol());
			if (packet.addRadiusAttribute(&ra11))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Framed_Protocol.\n";
			}
	}
	
	if (packet.addRadiusAttribute(&ra12))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Packets.\n";
	}
	
	if (packet.addRadiusAttribute(&ra13))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Packets.\n";
	}
	//calculate the session time
	ra14.setValue((time(NULL)-this->starttime));
	if (packet.addRadiusAttribute(&ra14)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_Time.\n";
	}

	if (packet.addRadiusAttribute(&ra15)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Gigawords.\n";
	}

	if (packet.addRadiusAttribute(&ra16)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Gigawords.\n";
	}
	
	//send the packet to the server
	if (packet.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//get the response
	if (packet.radiusReceive(serverlist)>=0)
	{
		//is the packet a ACCOUNTING_RESPONSE?
		if(packet.getCode()==ACCOUNTING_RESPONSE)
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: Get ACCOUNTING_RESPONSE-Packet.\n";

		
			return 0;
			
		}
		else
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT: No response on accounting request.\n";
			return 1;
		}
		
		
	}
	return 1;
}

/** The method sends an accounting start packet for the user to the radius server.
 *  The following attributes are sent to the radius server:
 * - User_Name, 
 * - Framed_IP_Address,
 * - NAS_Port,
 * - Calling_Station_Id,
 * - NAS_Identifier,
 * - NAS_IP_Address,
 * - NAS_Port_Type,
 * - Service_Type,
 * - Acct_Session_ID,
 * - Acct_Status_Type,
 * - Framed_Protocol,
 * @param  context The context of the plugin.
 * @return An integer, 0 is everything is ok, else 1.*/
int UserAcct::sendStartPacket(PluginContext * context)
{
	list<RadiusServer>* serverlist;
	list<RadiusServer>::iterator server;
	RadiusPacket		packet(ACCOUNTING_REQUEST);
	RadiusAttribute		ra1(ATTRIB_User_Name,this->getUsername()),
						ra2(ATTRIB_Framed_IP_Address,this->getFramedIp()),
						ra3(ATTRIB_NAS_Port,this->getPortnumber()),
						ra4(ATTRIB_Calling_Station_Id,this->getCallingStationId()),
						ra5(ATTRIB_NAS_Identifier),
						ra6(ATTRIB_NAS_IP_Address),
						ra7(ATTRIB_NAS_Port_Type),
						ra8(ATTRIB_Service_Type),
						ra9(ATTRIB_Acct_Session_ID, this->getSessionId()),
		                                ra10(ATTRIB_Acct_Status_Type,string("1")), // "Start"
						ra11(ATTRIB_Framed_Protocol);
				
	
	
	//get the radius server from the config
	serverlist=context->radiusconf.getRadiusServer();
	
	//set server to the first from the list
	server=serverlist->begin();
	
	//add the attributes to the packet
	if(packet.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	if (packet.addRadiusAttribute(&ra2))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Password.\n";
	}
	if (packet.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	//get information from the config and add the attributes to the packet
	if(strcmp(context->radiusconf.getNASIdentifier(),""))
	{
			ra5.setValue(context->radiusconf.getNASIdentifier());
			if (packet.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getNASIpAddress(),""))
	{
			if(ra6.setValue(context->radiusconf.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
	
			if (packet.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(context->radiusconf.getNASPortType(),""))
	{
			ra7.setValue(context->radiusconf.getNASPortType());
			if (packet.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getServiceType(),""))
	{
			ra8.setValue(context->radiusconf.getServiceType());
			if (packet.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	
	if (packet.addRadiusAttribute(&ra9)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if (packet.addRadiusAttribute(&ra10)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if(strcmp(context->radiusconf.getFramedProtocol(),""))
	{
			ra11.setValue(context->radiusconf.getFramedProtocol());
			if (packet.addRadiusAttribute(&ra11))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Framed_Protocol.\n";
			}
	}
	
	//send the packet	
	if (packet.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//receive the response
	int ret=packet.radiusReceive(serverlist);
	if (ret>=0)
	{
		//is is a accounting resopnse ?
		if(packet.getCode()==ACCOUNTING_RESPONSE)
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Get ACCOUNTING_RESPONSE-Packet.\n";

			return 0;
			
		}
		else
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Get no ACCOUNTING_RESPONSE-Packet.\n";
			return 1;
		}
		
	}
	else
	{
	  cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Error on receiving radius response, code: " <<  ret << endl;
	}
	
	return 1;
}



/** The method sends an accounting stop packet for the user to the radius server.
 * The accounting information are read from the OpenVpn
 * status file. The following attributes are sent to the radius server:
 * - User_Name, 
 * - Framed_IP_Address,
 * - NAS_Port,
 * - Calling_Station_Id,
 * - NAS_Identifier,
 * - NAS_IP_Address,
 * - NAS_Port_Type,
 * - Service_Type,
 * - Acct_Session_ID,
 * - Acct_Status_Type,
 * - Framed_Protocol,
 * - Acct_Input_Octets,
 * - Acct_Output_Octets,
 * - Acct_Session_Time
 * @param context The context of the plugin.
 * @return An integer, 0 is everything is ok, else 1.*/
int UserAcct::sendStopPacket(PluginContext * context)
{
	list<RadiusServer> * serverlist;
	list<RadiusServer>::iterator server;
	RadiusPacket		packet(ACCOUNTING_REQUEST);
	RadiusAttribute		ra1(ATTRIB_User_Name,this->getUsername()),
				ra2(ATTRIB_Framed_IP_Address,this->getFramedIp()),
				ra3(ATTRIB_NAS_Port,this->portnumber),
				ra4(ATTRIB_Calling_Station_Id,this->getCallingStationId()),
				ra5(ATTRIB_NAS_Identifier),
				ra6(ATTRIB_NAS_IP_Address),
				ra7(ATTRIB_NAS_Port_Type),
				ra8(ATTRIB_Service_Type),
				ra9(ATTRIB_Acct_Session_ID, this->getSessionId()),
		                ra10(ATTRIB_Acct_Status_Type,string("2")), // "Stop"
				ra11(ATTRIB_Framed_Protocol),
				ra12(ATTRIB_Acct_Input_Octets, this->bytesin),
				ra13(ATTRIB_Acct_Output_Octets, this->bytesout),
				ra14(ATTRIB_Acct_Session_Time),
				ra15(ATTRIB_Acct_Input_Gigawords, this->gigain),
				ra16(ATTRIB_Acct_Output_Gigawords, this->gigaout);				
	
	
		
	//get the server from the config
	serverlist=context->radiusconf.getRadiusServer();
	
	//set server to the first server
	server=serverlist->begin();
	
	//add the attributes to the packet
	if(packet.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	if (packet.addRadiusAttribute(&ra2))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_FramedIP_Address.\n";
	}
	if (packet.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	
	//get information from th config and ad it to the packet
	if(strcmp(context->radiusconf.getNASIdentifier(),""))
	{
			ra5.setValue(context->radiusconf.getNASIdentifier());
			if (packet.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getNASIpAddress(),""))
	{
			if(ra6.setValue(context->radiusconf.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
			else
			if (packet.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(context->radiusconf.getNASPortType(),""))
	{
			ra7.setValue(context->radiusconf.getNASPortType());
			if (packet.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getServiceType(),""))
	{
			ra8.setValue(context->radiusconf.getServiceType());
			if (packet.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	if (packet.addRadiusAttribute(&ra9))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	if (packet.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if(strcmp(context->radiusconf.getFramedProtocol(),""))
	{
			ra11.setValue(context->radiusconf.getFramedProtocol());
			if (packet.addRadiusAttribute(&ra11))
			{
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Framed_Protocol.\n";
			}
	}
	
	
	
	if (packet.addRadiusAttribute(&ra12))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Packets.\n";
	}
	if (packet.addRadiusAttribute(&ra13))
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Packets.\n";
	}
	
	//calculate the session time
	ra14.setValue(time(NULL)-this->starttime);
	if (packet.addRadiusAttribute(&ra14)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Session_Time.\n";
	}

	if (packet.addRadiusAttribute(&ra15)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Input_Gigawords.\n";
	}

	if (packet.addRadiusAttribute(&ra16)) {
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Fail to add attribute ATTRIB_Acct_Output_Gigawords.\n";
	}
	
	//send the packet
	if (packet.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Packet was not sent.\n";
	}
	
	//get the response
	if (packet.radiusReceive(serverlist)>=0)
	{
		//is it an accounting response
		if(packet.getCode()==ACCOUNTING_RESPONSE)
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Get ACCOUNTING_RESPONSE-Packet.\n";

			return 0;
			
		}
		else
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  No response on accounting request.\n";
			return 1;
		}
	}
		
	return 1;
}

/** The method deletes ths systemroutes of the user.
 * @param context The context of the plugin.
 */
void UserAcct::delSystemRoutes(PluginContext * context)
{
	char * route;
	char framedip[40];
	
	char routestring[200];
	char framednetmask_cidr[4]; 
	char framedgw[40];
	char framedmetric[5];  
	char * framedroutes, * framedroutes6;
	int j=0,k=0,len=0;
	
	//copy the framed route string to an char array, it is easier to
	//analyse
	try{
	  framedroutes=new char[this->getFramedRoutes().size()+1];
	}
	catch(...)
	{
	  cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for framedroutes." << endl;
	}
	memset(framedroutes,0,this->getFramedRoutes().size()+1);
	
	// copy in a temp-string, because strtok deletes the delimiter, if it used anywhere
	strncpy(framedroutes,this->getFramedRoutes().c_str(),this->getFramedRoutes().size());
	
	//are there framed routes
	if (framedroutes[0]!='\0')
	{
		//get the first route
		route=strtok(framedroutes,";");
		len=strlen(route);
		if (len > 50) //this is too big!! but the length is variable
		{
			cerr << getTime() <<"RADIUS-PLUGIN: BACKGROUND-ACCT:  Argument for Framed Route is too long (>50 Characters).\n";
		}
		else
		{
			while (route!=NULL)
			{		
				//set the arrays to 0
				memset(routestring,0,100);
				memset(framednetmask_cidr,0,3);
				memset(framedip,0,16);
				memset(framedgw,0,16);
				memset(framedmetric,0,5);
							
				j=0;k=0;
				//get ip address and add it to framedip
				while(route[j]!='/' && j<len)
				{
					if (route[j]!=' ')
					{
						framedip[k]=route[j];
						k++;
					}
					j++;
				}
				k=0;
				j++;
				//get the framednetmask and add it to framednetmack_cidr
				while(route[j]!=' ' && j<=len)
				{
					framednetmask_cidr[k]=route[j];
					k++;
					j++;
				}
				k=0;
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				//get the gateway
				while(route[j]!='/' && j<=len)
				{
					if (route[j]!=' ')
					{
						framedgw[k]=route[j];
						k++;
					}
					j++;
				}
				j++;
				//find gateway netmask (this isn't used
				//at the command route under linux)
				while(route[j]!=' ' && j<=len)
				{
					j++;
				}
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				k=0;
				if (j<=len) //is there a metric (optional)
				{
					k=0;
					//find the metric
					while(route[j]!=' ' && j<=len)
					{
							framedmetric[k]=route[j];
							k++;
							j++;
					}
				}
															
				//create system call
				strncat(routestring, "ip route del ",13);
				strncat(routestring, framedip ,16);
				strncat(routestring, "/" ,1);
				strncat(routestring, framednetmask_cidr, 2);
				if (framedgw[0]!='\0')
				{
					strncat(routestring, " via ", 5);
					strncat(routestring, framedgw, 16);
				}
				if (framedmetric[0]!='\0')
				{
					strncat(routestring, " metric ", 8);
					strncat(routestring, framedmetric , 5);
				}
				strncat(routestring," dev ",5);
				strcat(routestring,this->getDev().c_str());
				strncat(routestring," proto static",13);
				//redirect the output stderr to /dev/null
				strncat(routestring," 2> /dev/null",13);
				
						
				if (DEBUG (context->getVerbosity()))
	    			cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Create route string "<< routestring <<".\n";
				
				//system call
				if(system(routestring)!=0) 
				//if(1)//-> the debugg can't context system()
				{
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Route " << routestring << " could not set. Route already set or bad route string.\n";
				}
				else
				{
					if (DEBUG (context->getVerbosity()))
	    				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Add route to system routing table.\n";
					
				}
				//get the next route
				route=strtok(NULL,";");	
			}
		}
		
	}
	else
	{
		if (DEBUG (context->getVerbosity()))
    		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  No routes for user in AccessAcceptPacket.\n";
	}
	//free the char array
	delete [] framedroutes;
		

	//copy the framed route string to an char array, it is easier to
	//analyse
	framedroutes6=new char[this->getFramedRoutes6().size()+1];
	memset(framedroutes6,0,this->getFramedRoutes6().size()+1);
	
	// copy in a temp-string, because strtok deletes the delimiter, if it used anywhere
	strncpy(framedroutes6,this->getFramedRoutes6().c_str(),this->getFramedRoutes6().size());
	
	//are there framed routes
	if (framedroutes6[0]!='\0')
	{
		//get the first route
		route=strtok(framedroutes6,";");
		len=strlen(route);
		if (len > 150) //this is too big!! but the length is variable
		{
			cerr << getTime() <<"RADIUS-PLUGIN: BACKGROUND-ACCT:  Argument for Framed Route is too long (>150 Characters).\n";
		}
		else
		{
			while (route!=NULL)
			{		
				//set the arrays to 0
				memset(routestring,0,200);
				memset(framednetmask_cidr,0,4);
				memset(framedip,0,40);
				memset(framedgw,0,40);
				memset(framedmetric,0,5);
							
				j=0;k=0;
				//get ip address and add it to framedip
				while(route[j]!='/' && j<len)
				{
					if (route[j]!=' ')
					{
						framedip[k]=route[j];
						k++;
					}
					j++;
				}
				k=0;
				j++;
				//get the framednetmask and add it to framednetmack_cidr
				while(route[j]!=' ' && j<=len)
				{
					framednetmask_cidr[k]=route[j];
					k++;
					j++;
				}
				k=0;
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				//get the gateway
				while(route[j]!='/' && j<=len)
				{
					if (route[j]!=' ')
					{
						framedgw[k]=route[j];
						k++;
					}
					j++;
				}
				j++;
				//find gateway netmask (this isn't used
				//at the command route under linux)
				while(route[j]!=' ' && j<=len)
				{
					j++;
				}
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				k=0;
				if (j<=len) //is there a metric (optional)
				{
					k=0;
					//find the metric
					while(route[j]!=' ' && j<=len)
					{
							framedmetric[k]=route[j];
							k++;
							j++;
					}
				}
															
				//create system call
				strncat(routestring, "ip -6 route del ",16);
				strncat(routestring, framedip ,40);
				strncat(routestring, "/" ,1);
				strncat(routestring, framednetmask_cidr, 3);
				if (framedgw[0]!='\0')
				{
					strncat(routestring, " via ", 5);
					strncat(routestring, framedgw, 40);
				}
				if (framedmetric[0]!='\0')
				{
					strncat(routestring, " metric ", 8);
					strncat(routestring, framedmetric , 5);
				}
				strncat(routestring," dev ",5);
				strcat(routestring,this->getDev().c_str());
				strncat(routestring," proto static",13);
				//redirect the output stderr to /dev/null
				strncat(routestring," 2> /dev/null",13);
				
						
				if (DEBUG (context->getVerbosity()))
	    			cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Create IPv6 route string "<< routestring <<".\n";
				
				//system call
				if(system(routestring)!=0) 
				//if(1)//-> the debugg can't context system()
				{
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Route " << routestring << " could not set. Route already set or bad route string.\n";
				}
				else
				{
					if (DEBUG (context->getVerbosity()))
	    				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Add route to system routing table.\n";
					
				}
				//get the next route
				route=strtok(NULL,";");	
			}
		}
		
	}
	else
	{
		if (DEBUG (context->getVerbosity()))
    		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  No IPv6 routes for user in AccessAcceptPacket.\n";
	}
	//free the char array
	delete [] framedroutes6;
		
}

/** The method adds ths routes of the user to the system routing table.
 * @param context The context of the plugin.
 */
void UserAcct::addSystemRoutes(PluginContext * context)
{
	char * route;
	char framedip[40];
	
	char routestring[200];
	char framednetmask_cidr[4]; 
	char framedgw[40];
	char framedmetric[5];  
	char * framedroutes, * framedroutes6;
	int j=0,k=0,len=0;
	
	//copy the framed route string to an char array, it is easier to
	//analyse
	try{
	  framedroutes=new char[this->getFramedRoutes().size()+1];
	}
	catch(...)
	{
	  cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND ACCT: New failed for framedroutes." << endl;
	}
	memset(framedroutes,0,this->getFramedRoutes().size()+1);
	
	// copy in a temp-string, becaue strtok deletes the delimiter, if it used anywhere
	strncpy(framedroutes,this->getFramedRoutes().c_str(),this->getFramedRoutes().size());
	
	//are there framed routes
	if (framedroutes[0]!='\0')
	{
		//get the first route
		route=strtok(framedroutes,";");
		len=strlen(route);
		if (len > 50) //this is to big!! but the length is variable
		{
			cerr << getTime() <<"RADIUS-PLUGIN: BACKGROUND-ACCT:  Argument for Framed Route is to long (>50 Characters).\n";
		}
		else
		{
			while (route!=NULL)
			{		
				//set the arrays to 0
				memset(routestring,0,100);
				memset(framednetmask_cidr,0,3);
				memset(framedip,0,16);
				memset(framedgw,0,16);
				memset(framedmetric,0,5);
							
				j=0;k=0;
				//get ip address and add it to framedip
				while(route[j]!='/' && j<len)
				{
					if (route[j]!=' ')
					{
						framedip[k]=route[j];
						k++;
					}
					j++;
				}
				k=0;
				j++;
				//get the framednetmask and add it to framednetmask_cidr
				while(route[j]!=' ' && j<=len)
				{
					framednetmask_cidr[k]=route[j];
					k++;
					j++;
				}
				k=0;
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				//get the gateway
				while(route[j]!='/' && j<=len)
				{
					if (route[j]!=' ')
					{
						framedgw[k]=route[j];
						k++;
					}
					j++;
				}
				j++;
				//find gateway netmask (this isn't used
				//at the command route under linux)
				while(route[j]!=' ' && j<=len)
				{
					j++;
				}
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				k=0;
				if (j<=len) //is there a metric (optional)
				{
					k=0;
					//find the metric
					while(route[j]!=' ' && j<=len)
					{
							framedmetric[k]=route[j];
							k++;
							j++;
					}
				}
															
														
				//create system call
				strncat(routestring, "ip route add ",13);
				strncat(routestring, framedip ,16);
				strncat(routestring, "/" ,1);
				strncat(routestring, framednetmask_cidr, 2);
				if (framedgw[0]!='\0')
				{
					strncat(routestring, " via ", 5);
					strncat(routestring, framedgw, 16);
				}
				if (framedmetric[0]!='\0')
				{
					strncat(routestring, " metric ", 8);
					strncat(routestring, framedmetric , 5);
				}
				strncat(routestring," dev ",5);
				strcat(routestring,this->getDev().c_str());
				strncat(routestring," proto static",13);
				//redirect the output stderr to /dev/null
				strncat(routestring," 2> /dev/null",13);
				
						
				if (DEBUG (context->getVerbosity()))
	    			cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Create route string "<< routestring << ".\n";
				
				//system call route
				if(system(routestring)!=0) 
				//if(1)//-> the debugg can't context system()
				{
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Route " << routestring << " could not set. Route already set or bad route string.\n";
				}
				else
				{
					if (DEBUG (context->getVerbosity()))
	    				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Add route to system routing table.\n";
												
				}
				//get the next route
				route=strtok(NULL,";");	
			}
		}
	}
	else
	{
		if (DEBUG (context->getVerbosity()))
    		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  No routes for user.\n";
	}
	//free the char array
	delete [] framedroutes;
	
	//copy the framed route string to an char array, it is easier to
	//analyse
	framedroutes6=new char[this->getFramedRoutes6().size()+1];
	memset(framedroutes6,0,this->getFramedRoutes6().size()+1);
	
	// copy in a temp-string, becaue strtok deletes the delimiter, if it used anywhere
	strncpy(framedroutes6,this->getFramedRoutes6().c_str(),this->getFramedRoutes6().size());
	
	//are there framed routes
	if (framedroutes6[0]!='\0')
	{
		//get the first route
		route=strtok(framedroutes6,";");
		len=strlen(route);
		if (len > 150) //this is to big!! but the length is variable
		{
			cerr << getTime() <<"RADIUS-PLUGIN: BACKGROUND-ACCT:  Argument for Framed Route is to long (>150 Characters).\n";
		}
		else
		{
			while (route!=NULL)
			{		
				//set the arrays to 0
				memset(routestring,0,200);
				memset(framednetmask_cidr,0,4);
				memset(framedip,0,40);
				memset(framedgw,0,40);
				memset(framedmetric,0,5);
							
				j=0;k=0;
				//get ip address and add it to framedip
				while(route[j]!='/' && j<len)
				{
					if (route[j]!=' ')
					{
						framedip[k]=route[j];
						k++;
					}
					j++;
				}
				k=0;
				j++;
				//get the framednetmask and add it to framednetmask_cidr
				while(route[j]!=' ' && j<=len)
				{
					framednetmask_cidr[k]=route[j];
					k++;
					j++;
				}
				k=0;
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				//get the gateway
				while(route[j]!='/' && j<=len)
				{
					if (route[j]!=' ')
					{
						framedgw[k]=route[j];
						k++;
					}
					j++;
				}
				j++;
				//find gateway netmask (this isn't used
				//at the command route under linux)
				while(route[j]!=' ' && j<=len)
				{
					j++;
				}
				//jump spaces
				while(route[j]==' ' && j<=len)
				{
					j++;
				}
				k=0;
				if (j<=len) //is there a metric (optional)
				{
					k=0;
					//find the metric
					while(route[j]!=' ' && j<=len)
					{
							framedmetric[k]=route[j];
							k++;
							j++;
					}
				}
															
														
				//create system call
				strncat(routestring, "ip -6 route add ",21);
				strncat(routestring, framedip ,40);
				strncat(routestring, "/" ,1);
				strncat(routestring, framednetmask_cidr, 3);
				if (framedgw[0]!='\0')
				{
					strncat(routestring, " via ", 5);
					strncat(routestring, framedgw, 40);
				}
				if (framedmetric[0]!='\0')
				{
					strncat(routestring, " metric ", 8);
					strncat(routestring, framedmetric , 5);
				}
				strncat(routestring," dev ",5);
				strcat(routestring,this->getDev().c_str());
				strncat(routestring," proto static",13);
				//redirect the output stderr to /dev/null
				strncat(routestring," 2> /dev/null",13);
				
						
				if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Create IPv6 route string "<< routestring << " dev " << this->getDev() << ".\n";
				
				//system call route
				if(system(routestring)!=0) 
				//if(1)//-> the debugg can't context system()
				{
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Route " << routestring << " could not set. Route already set or bad route string.\n";
				}
				else
				{
					if (DEBUG (context->getVerbosity()))
	    				cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  Add route to system routing table.\n";
												
				}
				//get the next route
				route=strtok(NULL,";");	
			}
		}
	}
	else
	{
		if (DEBUG (context->getVerbosity()))
    		cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND-ACCT:  No IPv6 routes for user.\n";
	}
	//free the char array
	delete [] framedroutes6;
	
}




/** The getter method for the gigain variable.
 * @return The number of received giga.*/
uint32_t UserAcct::getGigaIn(void)
{
	return this->gigain;
}
/**The setter method for the gigain variable.
 * @param giga The received giga.*/
void UserAcct::setGigaIn(uint32_t giga)
{
	this->gigain=giga;
}

/** The getter method for the gigaout variable.
 * @return The number of sent giga.*/
uint32_t UserAcct::getGigaOut(void)
{
	return this->gigaout;
}
/**The setter method for the gigaout variable.
 * @param giga  The sended giga.*/
void UserAcct::setGigaOut(uint32_t giga)
{
	this->gigaout=giga;
}

/** The getter method for the bytesin variable.
 * @return The number of received bytes.*/
uint32_t UserAcct::getBytesIn(void)
{
	return this->bytesin;
}
/**The setter method for the bytesin variable.
 * @param bytes The received bytes.*/
void UserAcct::setBytesIn(uint32_t bytes)
{
	this->bytesin=bytes;
}

/** The getter method for the bytesout variable.
 * @return The number of sent bytes.*/
uint32_t UserAcct::getBytesOut(void)
{
	return this->bytesout;
}
/**The setter method for the bytesout variable.
 * @param bytes  The sended bytes.*/
void UserAcct::setBytesOut(uint32_t bytes)
{
	this->bytesout=bytes;
}

/** The getter method for the startime.
 * @return The starttime.*/
time_t UserAcct::getStarttime(void)
{
	return this->starttime;
}
/**The setter method for the nextupdate.
 * @param t The starttime*/
void UserAcct::setStarttime(time_t t)
{
	this->starttime=t;
}

/** The getter method for the nextupdate.
 * @return A struct of the nextupdate.*/
time_t UserAcct::getNextUpdate(void)
{
	return this->nextupdate;
}
/**The setter method for the nextupdate.
 * @param t The nextupdate.*/
void UserAcct::setNextUpdate(time_t t)
{
	this->nextupdate=t;
}

int UserAcct::deleteCcdFile(PluginContext * context)
{
	string filename;
	filename = context->conf.getCcdPath()+ this->getCommonname();
	if(context->conf.getOverWriteCCFiles()==true && (this->getFramedIp().length() > 0 || this->getFramedRoutes().length() > 0 || this->getFramedIp6().length() > 0 || this->getFramedRoutes6().length() > 0))
	{
		remove(filename.c_str());
	}
	else
	{
		cerr << getTime() << "RADIUS-PLUGIN: Client config file was not deleted, overwriteccfiles is false \n.";
	}
	return 0;
}

