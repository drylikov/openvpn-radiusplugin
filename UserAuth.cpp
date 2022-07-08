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
 
#include "UserAuth.h"



/** The constructor. Nothing happens here.*/
UserAuth::UserAuth():User()
{
  
}
/** The constructor. Nothing happens here.*/
UserAuth::~UserAuth()
{
}

/**The method send an authentication packet to the radius server and
 * calls the method parseResponsePacket(). The following attributes are in the packet:
 * - User_Name,
 * - User_Password
 * - NAS_PortCalling_Station_Id,
 * - NAS_Identifier,
 * - NAS_IP_Address, 
 * - NAS_Port_Type
 * - Service_Type.
 * @param context The context of the background process.
 * @return An integer, 0 if the authentication succeeded, else 1.*/
int UserAuth::sendAcceptRequestPacket(PluginContext * context)
{
	list<RadiusServer> * serverlist;
	list<RadiusServer>::iterator server;
	RadiusPacket		packet(ACCESS_REQUEST);
	RadiusAttribute		ra1(ATTRIB_User_Name,this->getUsername().c_str()),
				ra2(ATTRIB_User_Password),
				ra3(ATTRIB_NAS_Port,this->getPortnumber()),
				ra4(ATTRIB_Calling_Station_Id,this->getCallingStationId()),
				ra5(ATTRIB_NAS_Identifier),
				ra6(ATTRIB_NAS_IP_Address),
				ra7(ATTRIB_NAS_Port_Type),
				ra8(ATTRIB_Service_Type),
				ra9(ATTRIB_Framed_IP_Address),
				ra10(ATTRIB_Acct_Session_ID, this->getSessionId());
	
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: radius_server().\n";
		
	//get the server list
	serverlist=context->radiusconf.getRadiusServer();
	//set server to the first server
	server=serverlist->begin();
	
	
	if (DEBUG (context->getVerbosity()))
		cerr << getTime() << "RADIUS-PLUGIN: Build password packet:  password: *****, sharedSecret: *****.\n";
	
	//add the attributes
	ra2.setValue(this->password);
	if(packet.addRadiusAttribute(&ra1))
	{
		cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_User_Name.\n";
	}
	
	if (packet.addRadiusAttribute(&ra2))
	{
		cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_User_Password.\n";
	}
	if (packet.addRadiusAttribute(&ra3))
	{
		cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_NAS_Port.\n";
	}
	if (packet.addRadiusAttribute(&ra4))
	{
		cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_Calling_Station_Id.\n";
	}
	//get information from the config and add it to the packet
	if(strcmp(context->radiusconf.getNASIdentifier(),""))
	{
			ra5.setValue(context->radiusconf.getNASIdentifier());
			if (packet.addRadiusAttribute(&ra5))
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_NAS_Identifier.\n";
			}
	}
	
	if(strcmp(context->radiusconf.getNASIpAddress(),""))
	{
			if(ra6.setValue(context->radiusconf.getNASIpAddress())!=0)
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to set value ATTRIB_NAS_Ip_Address.\n";
			}
			else
			if (packet.addRadiusAttribute(&ra6))
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_NAS_Ip_Address.\n";
			}
	}
	if(strcmp(context->radiusconf.getNASPortType(),""))
	{
			ra7.setValue(context->radiusconf.getNASPortType());
			if (packet.addRadiusAttribute(&ra7))
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_NAS_Port_Type.\n";
			}
	}
	
	if (packet.addRadiusAttribute(&ra10))
	{
		cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_Acct_Session_ID.\n";
	}
	
	if(strcmp(context->radiusconf.getServiceType(),""))
	{
			ra8.setValue(context->radiusconf.getServiceType());
			if (packet.addRadiusAttribute(&ra8))
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute ATTRIB_Service_Type.\n";
			}
	}
	
	if(this->getFramedIp().compare("") != 0)
	{
		if (DEBUG (context->getVerbosity()))
			cerr << getTime() << "RADIUS-PLUGIN: Send packet Re-Auth packet for framedIP="<< this->getFramedIp().c_str() << ".\n";
			ra9.setValue(this->getFramedIp());
			if (packet.addRadiusAttribute(&ra9))
			{
				cerr << getTime() << "RADIUS-PLUGIN: Fail to add attribute Framed-IP-Address.\n";
			}
	}
	
	
	
	if (DEBUG (context->getVerbosity()))
		cerr << getTime() << "RADIUS-PLUGIN: Send packet to " << server->getName().c_str() <<".\n";
	//send the packet
	if (packet.radiusSend(server)<0)
	{
		cerr << getTime() << "RADIUS-PLUGIN: Packet was not sent.\n";
	}
	//receive the packet
	int rc=packet.radiusReceive(serverlist);
	if (rc==0)
	{
		//is it a accept?
		if(packet.getCode()==ACCESS_ACCEPT)
		{
			if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: Get ACCESS_ACCEPT-Packet.\n";

			//parse the attributes for framedip, framedroutes and
			//acctinteriminterval
			this->parseResponsePacket(&packet, context);
			return 0;
			
		}
		else if(packet.getCode()==ACCESS_REJECT)
		{
		      if (DEBUG (context->getVerbosity()))
				cerr << getTime() << "RADIUS-PLUGIN: Get ACCESS_REJECT-Packet.\n";

			//parse the attributes for replay message
			this->parseResponsePacket(&packet, context);
			return 1;
		}
		else
		{
			cerr << getTime() << "RADIUS-PLUGIN: Get ACCESS_REJECT or ACCESS_CHALLENGE-Packet.->ACCESS-DENIED.\n";
			return 1;
		}
		
	}
	else
	{
		cerr << getTime() << "RADIUS-PLUGIN: Got no response from radius server, return code:" << rc << endl;
	}
	
	return 1;
		
}

/** The method parse the authentication response packet for
 * the attributes framed ip, framed routes and accinteriminterval 
 * and saves the values in the UserAuth object. The there is no acctinteriminterval
 * it is set to 0.
 * @param packet A pointer to the radius packet to parse.
 * @param context The plugin context.
 */

void UserAuth::parseResponsePacket(RadiusPacket *packet, PluginContext * context)
{
	pair <multimap<Octet,RadiusAttribute>::iterator,multimap<Octet,RadiusAttribute>::iterator> range;
	multimap<Octet,RadiusAttribute>::iterator iter1, iter2;
	RadiusVendorSpecificAttribute vsa;
		
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: parse_response_packet().\n";
	
	
	
	range=packet->findAttributes(22);
	iter1=range.first;
	iter2=range.second;	
	string froutes;
	while (iter1!=iter2)
	{
		
		froutes.append((char *) iter1->second.getValue(),iter1->second.getLength()-2);
		froutes.append(";");
		iter1++;
	
	}
	this->setFramedRoutes(froutes);
	
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: routes: " << this->getFramedRoutes() <<".\n";
	
	
	range=packet->findAttributes(8);
	iter1=range.first;
	iter2=range.second;	
	
	
	if (iter1!=iter2)
	{
		this->setFramedIp(iter1->second.ipFromBuf());
	}
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: framed ip: " << this->getFramedIp() <<".\n";
	
	
	
	range=packet->findAttributes(99);
	iter1=range.first;
	iter2=range.second;	
	string froutes6;
	
	while (iter1!=iter2)
	{
		
		froutes6.append((char *) iter1->second.getValue(), iter1->second.getLength()-2);
		froutes6.append(";");
		iter1++;
	}
	this->setFramedRoutes6(froutes6);
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: framed ipv6 route: " << this->getFramedRoutes6() <<".\n";
	
	
	range=packet->findAttributes(168);
	iter1=range.first;
	iter2=range.second;	
	
	
	if (iter1!=iter2)
	{
		this->setFramedIp6(iter1->second.ip6FromBuf());
	}
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: framed IPv6: " << this->getFramedIp6() <<".\n";
	
	
	range=packet->findAttributes(85);
	iter1=range.first;
	iter2=range.second;		
	if (iter1!=iter2)
	{
		this->setAcctInterimInterval(iter1->second.intFromBuf());
	}
	else
	{
		cerr << getTime() <<"RADIUS-PLUGIN: No attributes Acct Interim Interval or bad length.\n";
	}
	
	if (DEBUG (context->getVerbosity()))
    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Acct Interim Interval: " << this->getAcctInterimInterval() << ".\n";
	
	range=packet->findAttributes(26);
	iter1=range.first;
	iter2=range.second;		
	while (iter1!=iter2)
	{
		this->appendVsaBuf(iter1->second.getValue(), iter1->second.getLength()-2);
		iter1++;
	}
	
	range=packet->findAttributes(18);
	iter1=range.first;
	iter2=range.second;		
	string msg;
	while (iter1!=iter2)
	{
		msg.append((char*)iter1->second.getValue(),iter1->second.getLength()-2);
		cerr << getTime() <<"RADIUS-PLUGIN: BACKGROUND AUTH: Reply-Message:" << msg << "\n";
		iter1++;
	}
}



/** The getter method for the password.
 * @return The password as a string.
 */
string UserAuth::getPassword(void)
{
	return this->password;
}
/**The setter method for the password.
 * @param passwd The password.
 */
void UserAuth::setPassword(string passwd)
{
	this->password=passwd;
}

string UserAuth::valueToString(RadiusVendorSpecificAttribute *vsa)
{
	int id=vsa->getId();
	int type=vsa->getType();
	char buffer[50];
	
	
	/* File was generated from dictionary file of freeradius 1.0.2. */
    /* IF-statement was generated from dictionary file of freeradius 1.0.2. */
	/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
	if (
	(id == VENDOR_ACC && type == ATTRIBUTE_ACC_REASON_CODE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CCP_OPTION)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_INPUT_ERRORS)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_OUTPUT_ERRORS)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ROUTE_POLICY)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ML_MLX_ADMIN_STATE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ML_CALL_THRESHOLD)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ML_CLEAR_THRESHOLD)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ML_DAMPING_FACTOR)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CLEARING_CAUSE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CLEARING_LOCATION)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_REQUEST_TYPE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_BRIDGING_SUPPORT)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_APSM_OVERSUBSCRIBED)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ACCT_ON_OFF_REASON)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_TUNNEL_PORT)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DIAL_PORT_INDEX)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IP_COMPRESSION)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IPX_COMPRESSION)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CONNECT_TX_SPEED)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CONNECT_RX_SPEED)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CALLBACK_DELAY)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CALLBACK_MODE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CALLBACK_CBCP_TYPE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DIALOUT_AUTH_MODE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ACCESS_COMMUNITY)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_VPSM_REJECT_CAUSE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ACE_TOKEN_TTL)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IGMP_ADMIN_STATE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IGMP_VERSION)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_MULTILINK_ID)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_NUM_IN_MULTILINK)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PRE_INPUT_OCTETS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PRE_OUTPUT_OCTETS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PRE_INPUT_PACKETS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PRE_OUTPUT_PACKETS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_MAXIMUM_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_DISCONNECT_CAUSE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_DATA_RATE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PRESESSION_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PW_LIFETIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_IP_DIRECT)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PPP_VJ_SLOT_COMP)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_PPP_ASYNC_MAP)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_IP_POOL_DEFINITION)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_ASSIGN_IP_POOL)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_ROUTE_IP)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_LINK_COMPRESSION)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_TARGET_UTIL)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_MAXIMUM_CHANNELS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_DATA_FILTER)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_CALL_FILTER)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_IDLE_LIMIT)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_XMIT_RATE)
	|| (id == VENDOR_CABLETRON && type == ATTRIBUTE_CABLETRON_PROTOCOL_ENABLE)
	|| (id == VENDOR_CABLETRON && type == ATTRIBUTE_CABLETRON_PROTOCOL_CALLABLE)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_TYPE_OF_SERVICE)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_LINK_SPEED)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_LINKS_IN_BUNDLE)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_COMPRESSION_TYPE)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_LINK_PROTOCOL)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_NETWORK_PROTOCOLS)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_SESSION_ID)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_DISCONNECT_REASON)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_EVENT_FLAGS)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_FUNCTION)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_CONNECT_REASON)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_TUNNEL_THROUGHPUT)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_ECHO)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_CLIENT_ASSIGNED_IPX)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IPSEC_LOG_OPTIONS)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IPSEC_DENY_ACTION)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_TCP_SESSION_TIMEOUT)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_OTHER_SESSION_TIMEOUT)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_LOG_OPTIONS)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_SESS_DIR_FAIL_ACTION)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_MULTICAST_CLIENT)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_RAS_VENDOR)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_BAP_USAGE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_LINK_UTILIZATION_THRESHOLD)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_LINK_DROP_TIME_LIMIT)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_ARAP_PW_CHANGE_REASON)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_ACCT_AUTH_TYPE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_ACCT_EAP_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DTE_DATA_IDLE_TIMOUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DEFAULT_DTE_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SYNC_ASYNC_MODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ORIGINATE_ANSWER_MODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FAILURE_TO_CONNECT_REASON)
	|| (id == VENDOR_USR && type == ATTRIBUTE_INITIAL_TX_LINK_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FINAL_TX_LINK_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MODULATION_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_EQUALIZATION_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FALLBACK_ENABLED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHARACTERS_SENT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHARACTERS_RECEIVED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BLOCKS_SENT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BLOCKS_RECEIVED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BLOCKS_RESENT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RETRAINS_REQUESTED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RETRAINS_GRANTED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LINE_REVERSALS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_CHARACTERS_LOST)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BACK_CHANNEL_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_BLERS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_LINK_TIMEOUTS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_FALLBACKS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_UPSHIFTS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_LINK_NAKS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SIMPLIFIED_MNP_LEVELS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CONNECT_TERM_REASON)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DTR_FALSE_TIMEOUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FALLBACK_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BLOCK_ERROR_COUNT_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SIMPLIFIED_V42BIS_USAGE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DTR_TRUE_TIMEOUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CDMA_CALL_REFERENCE_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MBI_CT_PRI_CARD_SLOT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MBI_CT_TDM_TIME_SLOT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MBI_CT_PRI_CARD_SPAN_LINE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MBI_CT_BCHANNEL_USED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_STATUS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_NUM_OF_UPDATES)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_MANUFACTURER_ID)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IWF_CALL_IDENTIFIER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SERVICE_OPTION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DISCONNECT_CAUSE_INDICATOR)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MOBILE_NUMBYTES_TXED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MOBILE_NUMBYTES_RXED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUM_FAX_PAGES_PROCESSED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_COMPRESSION_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_ERROR_CODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MODEM_SETUP_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_CONNECTING_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CONNECT_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_LAST_UPDATE_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_LAST_UPDATE_EVENT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_RCV_TOT_PWRLVL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_RCV_PWRLVL_3300HZ)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_RCV_PWRLVL_3750HZ)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PWRLVL_NEARECHO_CANC)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PWRLVL_FARECHO_CANC)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PWRLVL_NOISE_LVL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PWRLVL_XMIT_LVL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_X2_STATUS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PLANNED_DISCONNECT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_INITIAL_MODULATION_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SYSLOG_TAP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_CALL_SLOT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_CALL_SPAN)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_CALL_CHANNEL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_KEYPRESS_TIMEOUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_UNAUTHENTICATED_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_VPN_ENCRYPTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RE_CHAP_TIMEOUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CCP_ALGORITHM)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ACCM_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CONNECT_SPEED)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BEARER_CAPABILITIES)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SPEED_OF_CONNECTION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MAX_CHANNELS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHANNEL_EXPANSION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHANNEL_DECREMENT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_EXPANSION_ALGORITHM)
	|| (id == VENDOR_USR && type == ATTRIBUTE_COMPRESSION_ALGORITHM)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RECEIVE_ACC_MAP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TRANSMIT_ACC_MAP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_COMPRESSION_RESET_MODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MIN_COMPRESSION_SIZE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FILTER_ZONES)
	|| (id == VENDOR_USR && type == ATTRIBUTE_APPLETALK)
	|| (id == VENDOR_USR && type == ATTRIBUTE_BRIDGING)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SPOOFING)
	|| (id == VENDOR_USR && type == ATTRIBUTE_HOST_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_START_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_END_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_APPLETALK_NETWORK_RANGE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ROUTING_PROTOCOL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MODEM_GROUP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_ROUTING)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_WAN)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_RIP_POLICIES)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MP_MRRU)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_DEFAULT_ROUTE_OPTION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MODEM_TRAINING_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_INTERFACE_INDEX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TUNNEL_SECURITY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP_FORMAT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP_OUTPUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP_FACILITY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP_PRIORITY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TUNNELED_MLPP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MULTICAST_PROXY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MULTICAST_RECEIVE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MULTICAST_FORWARDING)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IGMP_QUERY_INTERVAL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IGMP_MAXIMUM_RESPONSE_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IGMP_ROBUSTNESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IGMP_VERSION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IGMP_ROUTING)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_ARRIVAL_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_END_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_MULTICAST_ROUTING_TTL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_MULTICAST_ROUTING_RTLIM)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_MULTICAST_ROUTING_PROTO)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_DVMRP_METRIC)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_LOCATION_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_OSPF_ADDRESSLESS_INDEX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALLBACK_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ACCT_REASON_CODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_SAA_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DNIS_REAUTHENTICATION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SUPPORTS_TAGS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_HARC_DISCONNECT_CODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IDS0_CALL_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHANNEL_CONNECTED_TO)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SLOT_CONNECTED_TO)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DEVICE_CONNECTED_TO)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NFAS_ID)
	|| (id == VENDOR_USR && type == ATTRIBUTE_Q931_CALL_REFERENCE_VALUE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_EVENT_CODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DS0)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PHYSICAL_STATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_REFERENCE_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_TEMP_THRESHOLD)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CARD_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SECURITY_LOGIN_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SECURITY_RESP_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PACKET_BUS_SESSION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DTE_RING_NO_ANSWER_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FINAL_RX_LINK_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_INITIAL_RX_LINK_DATA_RATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_TEMPERATURE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ACTUAL_VOLTAGE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_EXPECTED_VOLTAGE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_POWER_SUPPLY_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHANNEL)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHASSIS_SLOT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_EVENT_ID)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NUMBER_OF_RINGS_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CONNECT_TIME_LIMIT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REQUEST_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_NAS_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AUTH_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MAX_SHARED_USERS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CIR_TIMER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_08_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DESTINATION_NAS_PORT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_NAS_PORT_FORMAT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_FAULT_MANAGEMENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_LOOPBACK_CELL_LOSS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CKT_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SVC_ENABLED)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SESSION_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_H323_CONFERENCE_ID)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_H323_DIALED_TIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_INTER_ARRIVAL_JITTER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DROPPED_OCTETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DROPPED_PACKETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_AUTH_DELAY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_X3_PROFILE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_REVERSE_CHARGING)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BI_DIRECTIONAL_AUTH)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MTU)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALL_DIRECTION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SERVICE_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FILTER_REQUIRED)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TRAFFIC_SHAPER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRIVATE_ROUTE_REQUIRED)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CACHE_REFRESH)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CACHE_TIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_EGRESS_ENABLED)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_CONNECT_VPI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_CONNECT_VCI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_CONNECT_GROUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_GROUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPX_HEADER_COMPRESSION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLING_ID_TYPE_OF_NUM)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLING_ID_NUMBER_PLAN)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLING_ID_PRESENTATN)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLING_ID_SCREENING)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BIR_ENABLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BIR_PROXY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BIR_BRIDGE_GROUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PPPOE_ENABLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BRIDGE_NON_PPPOE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_DIRECT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_ASSIGN_WINS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_AUTH_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PORT_REDIR_PROTOCOL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PORT_REDIR_PORTNUM)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_POOL_CHAINING)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_TOS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_TOS_PRECEDENCE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_TOS_APPLY_TO)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_RATE_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_VPI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_VCI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SOURCE_IP_CHECK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_RATE_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_UPSTREAM_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_DOWNSTREAM_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_CIR_RECV_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DSL_CIR_XMIT_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_NUMBERING_PLAN_ID)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_LINK_STATUS_DLCI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLBACK_DELAY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MULTICAST_GLEAVE_DELAY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CBCP_ENABLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CBCP_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CBCP_DELAY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CBCP_TRUNK_GROUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_APPLETALK_PEER_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ROUTE_APPLETALK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MODEM_PORTNO)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MODEM_SLOTNO)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MODEM_SHELFNO)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALL_ATTEMPT_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALL_BLOCK_DURATION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MAXIMUM_CALL_DURATION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TEMPORARY_RTES)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TUNNELING_PROTOCOL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SHARED_PROFILE_ENABLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DIALOUT_ALLOWED)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BACP_ENABLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DHCP_MAXIMUM_LEASES)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_ASSIGN_DNS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_PORT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_BASE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_TIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DHCP_REPLY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DHCP_POOL_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_EXPECT_CALLBACK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_EVENT_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MULTICAST_RATE_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MULTICAST_CLIENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_LINKUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_NAILED_GRP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_LINK_MGT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_N391)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DCE_N392)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DTE_N392)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DCE_N393)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DTE_N393)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_T391)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_T392)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TS_IDLE_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TS_IDLE_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DBA_MONITOR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BASE_CHANNEL_COUNT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MINIMUM_CHANNELS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FT1_CALLER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALL_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DLCI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HOME_AGENT_UDP_PORT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MULTILINK_ID)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_NUM_IN_MULTILINK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRE_INPUT_OCTETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRE_OUTPUT_OCTETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRE_INPUT_PACKETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRE_OUTPUT_PACKETS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MAXIMUM_TIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DISCONNECT_CAUSE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CONNECT_PROGRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DATA_RATE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRESESSION_TIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TOKEN_IDLE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TOKEN_IMMEDIATE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_REQUIRE_AUTH)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TOKEN_EXPIRY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PW_WARNTIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PW_LIFETIME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PPP_VJ_SLOT_COMP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PPP_VJ_1172)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PPP_ASYNC_MAP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPX_PEER_MODE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ASSIGN_IP_POOL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DIRECT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DIRECT_DLCI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HANDLE_IPX)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_NETWARE_TIMEOUT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPX_ALIAS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_METRIC)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRI_NUMBER_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ROUTE_IP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ROUTE_IPX)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BRIDGE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SEND_AUTH)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_LINK_COMPRESSION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TARGET_UTIL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MAXIMUM_CHANNELS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_INC_CHANNEL_COUNT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DEC_CHANNEL_COUNT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SECONDS_OF_HISTORY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HISTORY_WEIGH_TYPE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ADD_SECONDS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_REMOVE_SECONDS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IDLE_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PREEMPT_LIMIT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLBACK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DATA_SVC)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FORCE_56)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALL_BY_CALL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MPP_IDLE_PERCENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_XMIT_RATE)
	|| (id == VENDOR_KARLNET && type == ATTRIBUTE_KARLNET_TURBOCELL_TXRATE)
	|| (id == VENDOR_KARLNET && type == ATTRIBUTE_KARLNET_TURBOCELL_OPSTATE)
	|| (id == VENDOR_KARLNET && type == ATTRIBUTE_KARLNET_TURBOCELL_OPMODE)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_PPP_ECHO_INTERVAL)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_SSH_PRIVILEGES)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_AUTH_SERV_PROT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PROVIDER_ID)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_USERGROUP)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_IP_POOL)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_TUNNEL_PROT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_ACCT_SERV_PROT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_CHANNEL_BINDING)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_START_DELAY)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_ISDN_PROT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PPP_AUTH_TYPE)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_DIALOUT_TYPE)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_MODEM_POOL_ID)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PPP_CLIENT_SERVER_MODE)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_CALLBACK_PORTLIST)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SEC_PROFILE_INDEX)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_TUNNEL_AUTHEN_TYPE)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_TUNNEL_AUTHEN_MODE)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_USER_SERVER_LOCATION)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SYSTEM_DISC_REASON)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_MODEM_DISC_REASON)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_DISCONNECT_REASON)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_ADDR_RESOLUTION_PROTOCOL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_TRANSMIT_SPEED)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RECEIVE_SPEED)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SYSLOG_TAP)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_KEYPRESS_TIMEOUT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_UNAUTHENTICATED_TIME)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RE_CHAP_TIMEOUT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_MRRU)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PPP_TRACE_LEVEL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRE_INPUT_OCTETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRE_OUTPUT_OCTETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRE_INPUT_PACKETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRE_OUTPUT_PACKETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_CONNECT_PROGRESS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_MULTICAST_RATE_LIMIT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_MAXIMUM_CALL_DURATION)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_MULTILINK_ID)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_NUM_IN_MULTILINK)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_LOGICAL_CHANNEL_NUMBER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_WAN_NUMBER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PORT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_POOL_ID)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_TRANSMITTED_PACKETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RETRANSMITTED_PACKETS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SIGNAL_TO_NOISE_RATIO)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RETRAIN_REQUESTS_SENT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RETRAIN_REQUESTS_RCVD)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RATE_RENEG_REQ_SENT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_RATE_RENEG_REQ_RCVD)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_BEGIN_RECEIVE_LINE_LEVEL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_END_RECEIVE_LINE_LEVEL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_USER_LEVEL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_AUDIT_LEVEL)
	|| (id == VENDOR_ALTEON && type == ATTRIBUTE_ALTEON_SERVICE_TYPE)
	|| (id == VENDOR_FOUNDRY && type == ATTRIBUTE_FOUNDRY_PRIVILEGE_LEVEL)
	|| (id == VENDOR_FOUNDRY && type == ATTRIBUTE_FOUNDRY_COMMAND_EXCEPTION_FLAG)
	|| (id == VENDOR_VERSANET && type == ATTRIBUTE_VERSANET_TERMINATION_CAUSE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_DHCP_MAX_LEASES)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_RATE_LIMIT_RATE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_RATE_LIMIT_BURST)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_POLICE_RATE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_POLICE_BURST)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_SOURCE_VALIDATION)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_DOMAIN)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_FUNCTION)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_MAX_SESSIONS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_MAX_TUNNELS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_SESSION_AUTH)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_WINDOW)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_RETRANSMIT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_CMD_TIMEOUT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_GROUP)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_ALGORITHM)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_DEADTIME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_MCAST_SEND)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_MCAST_RECEIVE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_MCAST_MAXGROUPS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_DNIS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_MEDIUM_TYPE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_PVC_ENCAPSULATION_TYPE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_PVC_CIRCUIT_PADDING)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_TYPE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_AUTH_PROTOCOL)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_AUTH_MAX_SESSIONS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_DOT1Q_SLOT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_DOT1Q_PORT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_DOT1Q_VLAN_TAG_ID)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_L2TP_FLOW_CONTROL)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_IP_TOS_FIELD)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_NAS_REAL_PORT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_RATE_LIMIT_RATE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_RATE_LIMIT_BURST)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_POLICE_RATE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_POLICE_BURST)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_MCAST_IN_OCTETS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_MCAST_OUT_OCTETS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_MCAST_IN_PACKETS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_MCAST_OUT_PACKETS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_LAC_PORT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_LAC_REAL_PORT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_LAC_PORT_TYPE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_LAC_REAL_PORT_TYPE)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_SESSION_ERROR_CODE)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_VPOP_ID)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_SS7_SESSION_ID_TYPE)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_RADIUS_REDIRECT)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_IPSVC_AZNLVL)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_IPSVC_MASK)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MULTILINK_MATCH_INFO)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MULTILINK_GROUP_NUMBER)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_PPP_LOG_MASK)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_TX_PACKETS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_RETX_PACKETS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_SNR)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_LOCAL_RETRAINS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_REMOTE_RETRAINS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_LOCAL_RATE_NEGS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_REMOTE_RATE_NEGS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_BEGIN_RECV_LINE_LVL)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_END_RECV_LINE_LVL)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_CLIENT_ASSIGN_DNS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MULTICAST_RATE_LIMIT)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MULTICAST_CLIENT)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_DISCONNECT_CAUSE)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_DATA_RATE)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_PRESESSION_TIME)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_ASSIGN_IP_POOL)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MAXIMUM_CHANNELS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_IDLE_LIMIT)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_XMIT_RATE)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_IP_TOS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_IP_TOS_PRECEDENCE)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_IP_TOS_APPLY_TO)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_MCAST_CLIENT)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_REQUIRE_AUTH)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_ASSIGN_IP_POOL)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_SOURCE_IP_CHECK)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_ATM_VPI)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_ATM_VCI)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_INPUT_OCTETS_DIFF)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_OUTPUT_OCTETS_DIFF)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_SIMULTANEOUS_LOGINS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_MIN_PASSWORD_LENGTH_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_ALLOW_ALPHA_ONLY_PASSWORDS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_TUNNELING_PROTOCOLS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_AUTHENTICATION_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_ALLOW_PASSWD_STORE)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_USE_CLIENT_ADDRESS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_PPTP_ENCRYPTION_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_L2TP_ENCRYPTION_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_L2L_KEEPALIVES_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_TUNNEL_TYPE_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_MODE_CONFIG_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_USER_GROUP_LOCK_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_OVER_NAT_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_OVER_NAT_PORT_NUM_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_PPTP_MPPC_COMPRESSION)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_L2TP_MPPC_COMPRESSION)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_IP_COMPRESSION)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_IKE_PEER_ID_CHECK)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IKE_KEEP_ALIVES)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_AUTH_ON_REKEY)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_VENDOR_CODE)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_PRODUCT_CODE)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_REQUIRE_HW_CLIENT_AUTH)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_REQUIRE_INDIVIDUAL_USER_AUTH)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_AUTHD_USER_IDLE_TIMEOUT)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_CISCO_IP_PHONE_BYPASS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_PORT)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_SPLIT_TUNNELING_POLICY)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_REQRD_CLIENT_FW_CAP)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_CLIENT_FW_FILTER_OPT)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_BACKUP_SERVERS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_MS_CLIENT_ICPT_DHCP_CONF_MSG)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_ALLOW_NETWORK_EXTENSION_MODE)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_STRIP_REALM)
	|| (id == VENDOR_SHASTA && type == ATTRIBUTE_SHASTA_USER_PRIVILEGE)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_ADMIN_PRIVILEGE)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_BW_UP)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_BW_DOWN)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_IP_UPSELL)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_MAXBYTESUP)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_MAXBYTESDOWN)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_ENDOFSESSION)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_SERVICE_DOMAIN)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ATM_SERVICE_CATEGORY)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ATM_PCR)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ATM_SCR)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ATM_MBS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_CLI_ALLOW_ALL_VR_ACCESS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_SA_VALIDATE)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_IGMP_ENABLE)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_PPPOE_MAX_SESSIONS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_QOS_PROFILE_INTERFACE_TYPE)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_TUNNEL_NAS_PORT_METHOD)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_TUNNEL_TOS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_TUNNEL_MAXIMUM_SESSIONS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_INPUT_GIGAPKTS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_OUTPUT_GIGAPKTS)
	|| (id == VENDOR_CISCO_BBSM && type == ATTRIBUTE_CBBSM_BANDWIDTH)
	|| (id == VENDOR_3COM && type == ATTRIBUTE_SS3_FIREWALL_USER_PRIVILEGE)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_BANDWIDTH_MIN_UP)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_BANDWIDTH_MIN_DOWN)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_BANDWIDTH_MAX_UP)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_BANDWIDTH_MAX_DOWN)
	)
	{
	 sprintf(buffer, "%d", vsa->intFromBuf());
	 return 	string(buffer);
	}
	/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
	else if (
	(id == VENDOR_USR && type == ATTRIBUTE_CALL_TERMINATE_IN_GMT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_CONNECT_IN_GMT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_ARRIVAL_IN_GMT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_EVENT_DATE_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_END_DATE_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALL_START_DATE_TIME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SERVER_TIME)
	)
	{
	 sprintf(buffer, "%d", vsa->intFromBuf());
	 return 	string(buffer);
	}
	/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
	else if (
	(id == VENDOR_ACC && type == ATTRIBUTE_ACC_ACCESS_PARTITION)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CUSTOMER_ID)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_TUNNEL_SECRET)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_SERVICE_PROFILE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_MODEM_MODULATION_TYPE)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_MODEM_ERROR_PROTOCOL)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_CALLBACK_NUM_VALID)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DIALOUT_AUTH_PASSWORD)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DIALOUT_AUTH_USERNAME)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_ACE_TOKEN)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IP_POOL_NAME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_AVPAIR)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_NAS_PORT)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_REMOTE_ADDRESS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CONF_ID)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_SETUP_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CALL_ORIGIN)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CALL_TYPE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CONNECT_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_DISCONNECT_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_DISCONNECT_CAUSE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_VOICE_QUALITY)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_GW_ID)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_INCOMING_CONF_ID)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CREDIT_AMOUNT)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CREDIT_TIME)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_RETURN_CODE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_PROMPT_ID)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_TIME_AND_DAY)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_REDIRECT_NUMBER)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_PREFERRED_LANG)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_REDIRECT_IP_ADDRESS)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_BILLING_MODEL)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_H323_CURRENCY)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_ACCOUNT_INFO)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_SERVICE_INFO)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_COMMAND_CODE)
	|| (id == VENDOR_CISCO && type == ATTRIBUTE_CISCO_CONTROL_INFO)
	|| (id == VENDOR_TELEBIT && type == ATTRIBUTE_TELEBIT_LOGIN_COMMAND)
	|| (id == VENDOR_TELEBIT && type == ATTRIBUTE_TELEBIT_PORT_NAME)
	|| (id == VENDOR_TELEBIT && type == ATTRIBUTE_TELEBIT_ACTIVATE_COMMAND)
	|| (id == VENDOR_TELEBIT && type == ATTRIBUTE_TELEBIT_ACCOUNTING_INFO)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_USER_ATTRIBUTES)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_CALLED_NUMBER)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_CALLING_NUMBER)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_CUSTOMER_ID)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_CLIENT_ASSIGNED_IP)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_CLIENT_REAL_IP)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_VPN_GROUPINFO)
	|| (id == VENDOR_CISCO_VPN5000 && type == ATTRIBUTE_CVPN5000_VPN_PASSWORD)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_BIBOPPPTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_BIBODIALTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPEXTIFTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPROUTETABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPEXTRTTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPNATPRESETTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPXCIRCTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_RIPCIRCTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_SAPCIRCTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPXSTATICROUTETABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPXSTATICSERVTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_OSPFIFTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_PPPEXTIFTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPFILTERTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_IPQOSTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_QOSIFTABLE)
	|| (id == VENDOR_BINTEC && type == ATTRIBUTE_BINTEC_QOSPOLICYTABLE)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_TERMINATE_DETAIL)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_ADVICE_OF_CHARGE)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_CONNECT_DETAIL)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IP_POOL)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_MODEM_INFO)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IPSEC_ACTIVE_PROFILE)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IPSEC_OUTSOURCE_PROFILE)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IPSEC_PASSIVE_PROFILE)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_INMAP)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_OUTMAP)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_OUTSOURCE_INMAP)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_NAT_OUTSOURCE_OUTMAP)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_ADMIN_GROUP)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_RESPONSE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_ERROR)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_CPW_1)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_CPW_2)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_LM_ENC_PW)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_NT_ENC_PW)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_MPPE_ENCRYPTION_POLICY)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_MPPE_ENCRYPTION_TYPE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_DOMAIN)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_CHALLENGE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP_MPPE_KEYS)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_MPPE_SEND_KEY)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_MPPE_RECV_KEY)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_RAS_VERSION)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_OLD_ARAP_PASSWORD)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_NEW_ARAP_PASSWORD)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_FILTER)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP2_RESPONSE)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP2_SUCCESS)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_CHAP2_CPW)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LAST_NUMBER_DIALED_OUT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LAST_NUMBER_DIALED_IN_DNIS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LAST_CALLERS_NUMBER_ANI)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_PRODUCT_CODE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_SERIAL_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_FIRMWARE_VERSION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RMMIE_FIRMWARE_BUILD_DATE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALLING_PARTY_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CALLED_PARTY_NUMBER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ESN)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IMSI)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_USR_IFILTER_IP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_USR_IFILTER_IPX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SAP_FILTER_IN)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_USR_OFILTER_IP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_USR_OFILTER_IPX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_USR_OFILTER_SAP)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_VPN_ID)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_VPN_NAME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_VPN_NEIGHBOR)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_FRAMED_ROUTING_V2)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_VPN_GATEWAY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_TUNNEL_AUTHENTICATION)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_INDEX)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_CUTOFF)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PW_PACKET)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MIC)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LOG_FILTER_PACKETS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_VPN_GW_LOCATION_ID)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FRAMED_IP_ADDRESS_POOL_NAME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MP_EDO)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_NAME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_PASSWORD)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT1)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT1)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT2)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT2)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT3)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT3)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT4)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT4)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT5)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT5)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SEND_SCRIPT6)
	|| (id == VENDOR_USR && type == ATTRIBUTE_REPLY_SCRIPT6)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TERMINAL_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LOCAL_IP_ADDRESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_RIP_SIMPLE_AUTH_PASSWORD)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_RIP_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_CALL_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_RIP_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_CALL_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_RTMP_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_ZIP_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_CALL_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ET_BRIDGE_INPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_RIP_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IP_CALL_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_RIP_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IPX_CALL_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_RTMP_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_ZIP_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_AT_CALL_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ET_BRIDGE_OUTPUT_FILTER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ET_BRIDGE_CALL_OUTPUT_FILTE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MP_EDO_HIPER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_VTS_SESSION_KEY)
	|| (id == VENDOR_USR && type == ATTRIBUTE_ORIG_NAS_TYPE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_RAD_MULTICAST_ROUTING_BOUND)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHAT_SCRIPT_NAME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_CHAT_SCRIPT_RULES)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TUNNEL_SWITCH_ENDPOINT)
	|| (id == VENDOR_USR && type == ATTRIBUTE_TUNNEL_AUTH_HOSTNAME)
	|| (id == VENDOR_USR && type == ATTRIBUTE_DS0S)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_UU_INFO)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_SVC_ADDR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_GLOBAL_CALL_ID)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DIALED_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_X3_PARAMETERS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TUNNEL_VROUTER_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_NUI_PROMPT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_NUI_PASSWORD_PROMPT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_CUG)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_ALIAS_1)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_ALIAS_2)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_ALIAS_3)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_X121_ADDRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_NUI)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_RPOA)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_PROMPT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PAD_BANNER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_X25_PROFILE_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_RECV_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ACCESS_INTERCEPT_LEA)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ACCESS_INTERCEPT_LOG)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRIVATE_ROUTE_TABLE_ID)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_QOS_UPSTREAM)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_QOS_DOWNSTREAM)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPSEC_PROFILE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ATM_DIRECT_PROFILE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FILTER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TELNET_PROFILE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_REDIRECT_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_VROUTER_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SOURCE_AUTH)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRIVATE_ROUTE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CALLING_SUBADDRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ENDPOINT_DISC)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_REMOTE_FW)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_APPLETALK_ROUTE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FCP_PARAMETER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PRIMARY_HOME_AGENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SECONDARY_HOME_AGENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_KEY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ASSIGN_IP_GLOBAL_POOL)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SESSION_SVR_KEY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_CIRCUIT_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BRIDGE_ADDRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPX_ROUTE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BACKUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_GROUP)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_PROFILE_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ARA_PW)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IPX_NODE_ADDR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HOME_AGENT_PASSWORD)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HOME_NETWORK_NAME)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_NUMBER_SESSIONS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_AUTHEN_ALIAS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MENU_SELECTOR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_MENU_ITEM)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_THIRD_PROMPT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SEND_SECRET)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_RECEIVE_SECRET)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_POOL_DEFINITION)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FR_DIRECT_PROFILE)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_DIAL_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_SEND_PASSWD)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_BILLING_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_TRANSIT_NUMBER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HOST_INFO)
	|| (id == VENDOR_KARLNET && type == ATTRIBUTE_KARLNET_TURBOCELL_NAME)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_ADDRESS_POOL)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_CLIENT_ACCESS_NETWORK)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_BANNER)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_USERNAME_PROMPT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PASSWORD_PROMPT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_WELCOME_MESSAGE)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PROMPT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_FILTER_RULE)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_NAS_NAME)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_USERS_DEFAULT_ENTRY)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_USERS_DEFAULT_PW)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_AUTH_REQ_TYPE)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_MODEM_INIT_STRING)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_PPP_COMPRESSION_PROT)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_USERNAME)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_DEST_NO)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_DDI)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_FILTER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_CLI_COMMAND)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_CLI_FILTER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_HOST_RESTRICT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_HOST_ALLOW)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRODUCT_NAME)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SW_VERSION)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_AUTHEN_SERVERS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_ACCT_SERVERS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_LOCAL_USERNAME)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_ADDR_RESOLUTION_SERVERS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_DOMAIN_NAME)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_INPUT_FILTER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_OUTPUT_FILTER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_EDO)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_COMPRESSION_PROTOCOL)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_BEGIN_MODULATION)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_ERROR_CORRECTION_PROT)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_END_MODULATION)
	|| (id == VENDOR_EXTREME && type == ATTRIBUTE_EXTREME_NETLOGIN_VLAN)
	|| (id == VENDOR_EXTREME && type == ATTRIBUTE_EXTREME_NETLOGIN_URL)
	|| (id == VENDOR_EXTREME && type == ATTRIBUTE_EXTREME_NETLOGIN_URL_DESC)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_DNS_SERVER)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_WINS_SERVER1)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_WINS_SERVER2)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_HOSTNAME)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_DOMAINNAME)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_SEARCH_LIST)
	|| (id == VENDOR_FOUNDRY && type == ATTRIBUTE_FOUNDRY_COMMAND_STRING)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_CONTEXT_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BRIDGE_GROUP)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BG_AGING_TIME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BG_PATH_COST)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BG_SPAN_DIS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BG_TRANS_BPDU)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_LOCAL_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_REMOTE_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_PPPOE_URL)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_PPPOE_MOTM)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_IP_ADDRESS_POOL_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_PVC_PROFILE_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_BYPASS_BYPASS)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_AUTH_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_AUTH_SERVICE_GRP)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_BYPASS_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_INT_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_TUN_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_SES_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_INT_INTERFACE_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_L2TP_TUNNEL_NAME)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_SUB_USER_AT_CONTEXT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_BIND_SUB_PASSWORD)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_IP_HOST_ADDR)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_SESSION_AUTH_CTX)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_SESSION_AUTH_SERVICE_GRP)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_TUNNEL_L2F_SECOND_PASSWORD)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_INPUT_OCTETS_64)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_OUTPUT_OCTETS_64)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_INPUT_PACKETS_64)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_OUTPUT_PACKETS_64)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ACCT_DYN_AC_ENT)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_SESSION_ERROR_MSG)
	|| (id == VENDOR_JUNIPER && type == ATTRIBUTE_JUNIPER_LOCAL_USER_NAME)
	|| (id == VENDOR_JUNIPER && type == ATTRIBUTE_JUNIPER_ALLOW_COMMANDS)
	|| (id == VENDOR_JUNIPER && type == ATTRIBUTE_JUNIPER_DENY_COMMANDS)
	|| (id == VENDOR_JUNIPER && type == ATTRIBUTE_JUNIPER_ALLOW_CONFIGURATION)
	|| (id == VENDOR_JUNIPER && type == ATTRIBUTE_JUNIPER_DENY_CONFIGURATION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_IDENTIFICATION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_BEGIN_MODULATION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_END_MODULATION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_ERROR_CORRECTION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_MODEM_DATA_COMPRESSION)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_DATA_FILTER)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_ATM_DIRECT)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_VROUTER_NAME)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_IP_POOL_DEFINITION)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_DATA_FILTER)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_USER_MAC_ADDRESS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_ATM_TRAFFIC_PROFILE)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_ACCESS_HOURS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_SEC_ASSOCIATION)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_BANNER_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_SPLIT_TUNNEL_LIST_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_DEFAULT_DOMAIN_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_IPSEC_SECONDARY_DOMAINS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_BANNER2)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_DESCRIPTION)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_NAME)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_SECRET)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_CLIENT_FW_FILTER_NAME)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_IPSEC_BACKUP_SERVER_LIST)
	|| (id == VENDOR_SHASTA && type == ATTRIBUTE_SHASTA_SERVICE_PROFILE)
	|| (id == VENDOR_SHASTA && type == ATTRIBUTE_SHASTA_VPN_NAME)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_VSYS_NAME)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_USER_GROUP)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_URL_REDIRECTION)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_EXPIRATION)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_SUBNET)
	|| (id == VENDOR_NOMADIX && type == ATTRIBUTE_NOMADIX_LOGOFF_URL)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_ACCT_VC_CONNECTION_ID)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_SERVICE_NAME)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_POLICY_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_VIRTUAL_ROUTER_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ADDRESS_POOL_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_LOCAL_LOOPBACK_INTERFACE)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_TUNNEL_VIRTUAL_ROUTER)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_TUNNEL_PASSWORD)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_INGRESS_POLICY_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_EGRESS_POLICY_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_INGRESS_STATISTICS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_EGRESS_STATISTICS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_CLI_INITIAL_ACCESS_LEVEL)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ALTERNATE_CLI_ACCESS_LEVEL)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_ALTERNATE_CLI_VROUTER_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_PPPOE_DESCRIPTION)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_REDIRECT_VR_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_QOS_PROFILE_NAME)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_PPPOE_URL)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_SERVICE_BUNDLE)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_FRAMED_IP_ROUTE_TAG)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_AVPAIR)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_NAS_PORT)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_REMOTE_ADDRESS)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CONF_ID)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_SETUP_TIME)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CALL_ORIGIN)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CALL_TYPE)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CONNECT_TIME)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_DISCONNECT_TIME)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_DISCONNECT_CAUSE)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_VOICE_QUALITY)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_GW_ID)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_INCOMING_CONF_ID)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CREDIT_AMOUNT)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CREDIT_TIME)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_RETURN_CODE)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_PROMPT_ID)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_TIME_AND_DAY)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_REDIRECT_NUMBER)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_PREFERRED_LANG)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_REDIRECT_IP_ADDRESS)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_BILLING_MODEL)
	|| (id == VENDOR_QUINTUM && type == ATTRIBUTE_QUINTUM_H323_CURRENCY_TYPE)
	|| (id == VENDOR_COLUBRIS && type == ATTRIBUTE_COLUBRIS_AVPAIR)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_LOCATION_ID)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_LOCATION_NAME)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_LOGOFF_URL)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_REDIRECTION_URL)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_SESSION_TERMINATE_TIME)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_SESSION_TERMINATE_END_OF_DAY)
	|| (id == VENDOR_WISPR && type == ATTRIBUTE_WISPR_BILLING_CLASS_OF_SERVICE)
	)
	{
	 return vsa->stringFromBuf();
	}
	/* IF-statement was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
	else if (
	(id == VENDOR_ACC && type == ATTRIBUTE_ACC_IP_GATEWAY_PRI)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_IP_GATEWAY_SEC)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DNS_SERVER_PRI)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_DNS_SERVER_SEC)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_NBNS_SERVER_PRI)
	|| (id == VENDOR_ACC && type == ATTRIBUTE_ACC_NBNS_SERVER_SEC)
	|| (id == VENDOR_SHIVA && type == ATTRIBUTE_SHIVA_ACCT_SERV_SWITCH)
	|| (id == VENDOR_LIVINGSTON && type == ATTRIBUTE_LE_IP_GATEWAY)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_PRIMARY_DNS_SERVER)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_SECONDARY_DNS_SERVER)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_PRIMARY_NBNS_SERVER)
	|| (id == VENDOR_MICROSOFT && type == ATTRIBUTE_MS_SECONDARY_NBNS_SERVER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_IWF_IP_ADDRESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MOBILE_IP_ADDRESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PRIMARY_DNS_SERVER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SECONDARY_DNS_SERVER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PRIMARY_NBNS_SERVER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_SECONDARY_NBNS_SERVER)
	|| (id == VENDOR_USR && type == ATTRIBUTE_LOCAL_FRAMED_IP_ADDR)
	|| (id == VENDOR_USR && type == ATTRIBUTE_FRAMED_IPX_ROUTE)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MPIP_TUNNEL_ORIGINATOR)
	|| (id == VENDOR_USR && type == ATTRIBUTE_PORT_TAP_ADDRESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_MOBILEIP_HOME_AGENT_ADDRESS)
	|| (id == VENDOR_USR && type == ATTRIBUTE_GATEWAY_IP_ADDRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_H323_GATEKEEPER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_H323_FEGW_ADDRESS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_PRIMARY_WINS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_SECONDARY_WINS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PORT_REDIR_SERVER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_OWNER_IP_ADDR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_GATEWAY)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_PRIMARY_DNS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_CLIENT_SECONDARY_DNS)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_USER_ACCT_HOST)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ASSIGN_IP_CLIENT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_ASSIGN_IP_SERVER)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IF_NETMASK)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_REMOTE_ADDR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_HOME_AGENT_IP_ADDR)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_FIRST_DEST)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_IP_DIRECT)
	|| (id == VENDOR_ASCEND && type == ATTRIBUTE_ASCEND_PPP_ADDRESS)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_DNS_SERVER)
	|| (id == VENDOR_XEDIA && type == ATTRIBUTE_XEDIA_NETBIOS_SERVER)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_AUTH_SERV_IP)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_TUNNEL_IP)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_ACCT_SERV_IP)
	|| (id == VENDOR_ITK && type == ATTRIBUTE_ITK_FTP_AUTH_IP)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_LOCAL_IP_ADDRESS)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRIMARY_DNS_SERVER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SECONDARY_DNS_SERVER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_PRIMARY_NBNS_SERVER)
	|| (id == VENDOR_BAY_NETWORKS && type == ATTRIBUTE_ANNEX_SECONDARY_NBNS_SERVER)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_IP_ADDR)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_IP_NETMASK)
	|| (id == VENDOR_REDCREEK && type == ATTRIBUTE_REDCREEK_TUNNELED_GATEWAY)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_CLIENT_DNS_PRI)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_CLIENT_DNS_SEC)
	|| (id == VENDOR_REDBACK && type == ATTRIBUTE_ASSIGNED_IP_ADDRESS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_PRIMARY_DNS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_SECONDARY_DNS)
	|| (id == VENDOR_APTIS && type == ATTRIBUTE_CVX_PPP_ADDRESS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_CLIENT_PRIMARY_DNS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_CLIENT_PRIMARY_WINS_NBNS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_CLIENT_SECONDARY_WINS_NBNS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_CLIENT_SECONDARY_DNS)
	|| (id == VENDOR_ALCATEL && type == ATTRIBUTE_AAT_PPP_ADDRESS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_PRIMARY_DNS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_SECONDARY_DNS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_PRIMARY_WINS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_ALTIGA_SECONDARY_WINS_G)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_SECONDARY_WINS)
	|| (id == VENDOR_ALTIGA && type == ATTRIBUTE_CVPN3000_MS_CLIENT_SUBNET_MASK)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_PRIMARY_DNS)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_SECONDARY_DNS)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_PRIMARY_WINS)
	|| (id == VENDOR_NETSCREEN && type == ATTRIBUTE_NS_SECONDARY_WINS)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_PRIMARY_DNS_SERVER)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_SECONDARY_DNS_SERVER)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_PRIMARY_NBNS_SERVER)
	|| (id == VENDOR_SPRINGTIDE && type == ATTRIBUTE_ST_SECONDARY_NBNS_SERVER)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_PRIMARY_DNS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_PRIMARY_WINS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_SECONDARY_DNS)
	|| (id == VENDOR_ERX && type == ATTRIBUTE_ERX_SECONDARY_WINS)
	)
	{
	 return vsa->ipFromBuf();
	}
	else
	{
	 cerr << getTime() << "Vendor Specific Attribute (Id: " << vsa->getId() << " Type: " << vsa->getType() << " not implemented, treated as string.";
	 return vsa->stringFromBuf();
	}

	
}

/** The method creates the client config file in the client config dir (ccd).
 * The path is set in the radiusplugin config file.
 * Radius attributes which written to the file are FramedIP as ifconfig-push option and FramedRoutes as iroute option.
 * @param context : The plugin context.
 * @return An integer, if everything is ok 0, else 1.
 */
int UserAuth::createCcdFile(PluginContext *context)
{
	ofstream ccdfile;
	
	char * route;
	char framedip[40];
	char ipstring[100];
	in_addr_t ip2;
	in_addr ip3;
	string filename;
	char framedroutes[4096];
	char framedroutes6[4096];
	char framednetmask_cidr[4]; // ->/128
	char framednetmask[16]; // ->255.255.255.0
	char framedgw[40];
	char framedmetric[5]; //what is the biggest metric? 
	
	unsigned long d1,d2;
	
	int j=0,k=0;
	int len=0;
	
	
	if(context->conf.getOverWriteCCFiles()==true && (this->getFramedIp().length() > 0 || this->getFramedRoutes().length() > 0 || this->getFramedIp6().length() > 0 || this->getFramedRoutes6().length() > 0))
	{
		memset(ipstring,0,100);
		memset(framedip,0,16);
		memset(framedroutes,0,4096);
		memset(framedroutes6,0,4096);
			
		//create the filename, ccd-path + commonname
		filename=context->conf.getCcdPath()+this->getCommonname();
		
				
		if (DEBUG (context->getVerbosity()))
	    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Try to open ccd file.\n";
		
		//open the file
		ccdfile.open(filename.c_str(),ios::out);
		
		if (DEBUG (context->getVerbosity()))
	    	cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Opened ccd file.\n";
		
		
		// copy in a temp-string, becaue strtok deletes the delimiter, if it is used anywhere
		strncpy(framedroutes,this->getFramedRoutes().c_str(),4095);
		
		// copy in a temp-string, becaue strtok deletes the delimiter, if it is used anywhere
		strncpy(framedroutes6,this->getFramedRoutes6().c_str(),4095);
		
		
		if (ccdfile.is_open())
		{
			
			//set the ip address in the file
			if (this->framedip[0]!='\0')
			{
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Write framed ip to ccd-file.\n";
			
				//build the ifconfig
				strncat(ipstring, "ifconfig-push ",14);
				strncat(ipstring, this->getFramedIp().c_str() , 15);
				strncat(ipstring, " ", 1);
				
				
				if(context->conf.getSubnet()[0]!='\0')
				{
					strncat(ipstring, context->conf.getSubnet() , 15);
					if (DEBUG (context->getVerbosity()))
						cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Create ifconfig-push for topology subnet.\n";
			
				}
				else if(context->conf.getP2p()[0]!='\0')
				{
					strncat(ipstring, context->conf.getP2p() , 15);
					if (DEBUG (context->getVerbosity()))
						cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Create ifconfig-push for topology p2p.\n";
			
				}
				else
				{
					//increment the last byte of the ip address
					//in interface needs two addresses because it is a 
					//convert from string to integer in network byte order
					ip2=inet_addr(this->getFramedIp().c_str());
					//convert from network byte order to host byte order
					ip2=ntohl(ip2);
					//increment
					ip2++;
					//convert from host byte order to network byte order
					ip2=htonl(ip2);
					//copy from one unsigned int to another (casting don't work with these struct!?)
					memcpy(&ip3, &ip2, 4);
					// append the new ip address to the string
					strncat(ipstring, inet_ntoa(ip3), 15);
					if (DEBUG (context->getVerbosity()))
						cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Create ifconfig-push for topology net30.\n";
			
				}
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: Write " << ipstring << " ccd-file.\n";
				
				
				ccdfile << ipstring <<"\n";
			}
			
			//set the framed routes in the file for the openvpn process
			if (framedroutes[0]!='\0')
			{
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Write framed routes to ccd-file.\n";
			
				route=strtok(framedroutes,";");
				len=strlen(route);
				if (len > 50) //this is too big! but the length is variable
				{
					cerr << getTime() <<"RADIUS-PLUGIN: Argument for Framed Route is to long (>50 Characters).\n";
					return 1;
				}
				else
				{
					while (route!=NULL)
					{
						j=0;k=0;
						//set everything back for the next route entry
						memset(framednetmask_cidr,0,3);
						memset(framedip,0,16);
						memset(framednetmask,0,16);
						memset(framedgw,0,16);
						memset(framedmetric,0,5);
						
						//add ip address to string
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
							//add netmask
							while(route[j]!=' ' && j<=len)
							{
								framednetmask_cidr[k]=route[j];
								k++;
								j++;
							}
							k=0;
							//jump spaces
							while(route[j]==' ' && j<len)
							{
								j++;
							}
							//find gateway
							while(route[j]!='/' && j<len)
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
							while(route[j]!=' ' && j<len)
							{
								j++;
							}
							//jump spaces
							
							while(route[j]==' ' && j<len )
							{
								j++;
							}
							k=0;
							if (j<=len)
							{
							
								k=0;
								//find the metric
								while(route[j]!=' ' && j<len)
								{
									framedmetric[k]=route[j];
									k++;
									j++;
								}
							}
																								
							//create string for client config file
							//transform framednetmask_cidr
							memset(framednetmask,0,16);
							d2=atoi(framednetmask_cidr);
							if (d2>32)
							{
								cerr << getTime() << "RADIUS-PLUGIN: Bad net CIDR netmask.\n";
							}
							else
							{
								if (d2==32)
								{
									d1=0xffffffffUL;
								}
								else if (d2==0)
								{
									d1=0x00000000UL;
								}
								else
								{
									d1=((1UL<<d2)-1UL)<<(32-d2);
								}
								snprintf(framednetmask, 16, "%lu.%lu.%lu.%lu",
										(d1 >> 24) & 0xff,
										(d1 >> 16) & 0xff,
										(d1 >>  8) & 0xff,
										(d1      ) & 0xff);
							}
							
							if (DEBUG (context->getVerbosity()))
		    						cerr << getTime() << "RADIUS-PLUGIN: Write route string: iroute " << framedip << framednetmask << " to ccd-file.\n";
			
							//write iroute to client file
							ccdfile << "iroute " << framedip << " "<< framednetmask << "\n";
						
							route=strtok(NULL,";");
					}
				}
			}
			
			//set the IPv6 address in the file
			if (this->framedip6[0]!='\0')
			{
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Write framed IPv6 to ccd-file.\n";
			
				//build the ifconfig
				ipstring[0] = 0;
				strncat(ipstring, "ifconfig-ipv6-push ",19);
				strncat(ipstring, this->getFramedIp6().c_str() , 39);
				strncat(ipstring, " ", 1);
				
				if(context->conf.getP2p6()[0]!='\0')
				{
					strncat(ipstring, context->conf.getP2p6() , 39);
					if (DEBUG (context->getVerbosity()))
						cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Create ifconfig-ipv6-push for topology p2p.\n";
				}
				
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: Write " << ipstring << " ccd-file.\n";
				
				
				ccdfile << ipstring <<"\n";
			}
			
			//set the IPv6 framed routes in the file for the openvpn process
			if (framedroutes6[0]!='\0')
			{
				if (DEBUG (context->getVerbosity()))
					cerr << getTime() << "RADIUS-PLUGIN: BACKGROUND AUTH: Write framed routes to ccd-file.\n";
			
				route=strtok(framedroutes6,";");
				len=strlen(route);
				if (len > 150) //this is too big! but the length is variable
				{
					cerr << getTime() <<"RADIUS-PLUGIN: Argument for Framed Route is to long (>50 Characters).\n";
					return 1;
				}
				else
				{
					while (route!=NULL)
					{
						j=0;k=0;
						//set everything back for the next route entry
						memset(framednetmask_cidr,0,4);
						memset(framedip,0,40);
						memset(framednetmask,0,40);
						memset(framedgw,0,40);
						memset(framedmetric,0,5);
						
						//add ip address to string
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
							//add netmask
							while(route[j]!=' ' && j<=len)
							{
								framednetmask_cidr[k]=route[j];
								k++;
								j++;
							}
							k=0;
							//jump spaces
							while(route[j]==' ' && j<len)
							{
								j++;
							}
							//find gateway
							while(route[j]!='/' && j<len)
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
							while(route[j]!=' ' && j<len)
							{
								j++;
							}
							//jump spaces
							
							while(route[j]==' ' && j<len )
							{
								j++;
							}
							k=0;
							if (j<=len)
							{
							
								k=0;
								//find the metric
								while(route[j]!=' ' && j<len)
								{
									framedmetric[k]=route[j];
									k++;
									j++;
								}
							}
																								
							if (DEBUG (context->getVerbosity()))
		    						cerr << getTime() << "RADIUS-PLUGIN: Write route string: iroute-ipv6 " << framedip << "/" << framednetmask_cidr << " " << framedgw << " " << framedmetric << " to ccd-file.\n";
			
							//write iroute to client file
							ccdfile << "iroute-ipv6 " << framedip << "/"<< framednetmask_cidr << "\n";
						
							route=strtok(NULL,";");
					}
				}
			}
		
		ccdfile.close();
		}
		else
		{
			cerr << getTime() << "RADIUS-PLUGIN: Could not open file "<< filename << ".\n";
			return 1;
		}
	}
	else
	{
		cerr << getTime() << "RADIUS-PLUGIN: Client config file was not written, overwriteccfiles is false \n.";
	}
	
	return 0;
}


