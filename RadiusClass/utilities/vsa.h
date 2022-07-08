/* File was generated from dictionary file of freeradius 1.0.2 with vsahelper.pl */
        #ifndef _VSA_H_  
#define _VSA_H_  
#define 	 VENDOR_3COM 	8741
  	//VENDOR	3com				8741
#define 	 VENDOR_ACC 	5
  	//VENDOR	Acc				5
#define 	 VENDOR_ALCATEL 	3041
  	//VENDOR	Alcatel				3041
#define 	 VENDOR_ALTEON 	1872
  	//VENDOR	Alteon				1872
#define 	 VENDOR_ALTIGA 	3076
  	//VENDOR	Altiga				3076
#define 	 VENDOR_APTIS 	2637
  	//VENDOR	Aptis				2637
#define 	 VENDOR_ASCEND 	529
  	//VENDOR	Ascend				529
#define 	 VENDOR_BAY_NETWORKS 	1584
  	//VENDOR	Bay-Networks			1584
#define 	 VENDOR_BINTEC 	272
  	//VENDOR	BinTec				272
#define 	 VENDOR_CABLETRON 	52
  	//VENDOR	Cabletron			52
#define 	 VENDOR_CISCO 	9
  	//VENDOR	Cisco				9
#define 	 VENDOR_CISCO_BBSM 	5263
  	//VENDOR	Cisco-BBSM			5263
#define 	 VENDOR_CISCO_VPN5000 	255
  	//VENDOR	Cisco-VPN5000			255
#define 	 VENDOR_COLUBRIS 	8744
  	//VENDOR	Colubris			8744
#define 	 VENDOR_ERX 	4874
  	//VENDOR	ERX				4874
#define 	 VENDOR_EXTREME 	1916
  	//VENDOR	Extreme				1916
#define 	 VENDOR_FOUNDRY 	1991
  	//VENDOR	Foundry				1991
#define 	 VENDOR_ITK 	1195
  	//VENDOR	ITK				1195
#define 	 VENDOR_JUNIPER 	2636
  	//VENDOR	Juniper				2636
#define 	 VENDOR_KARLNET 	762
  	//VENDOR	KarlNet				762
#define 	 VENDOR_LIVINGSTON 	307
  	//VENDOR	Livingston			307
#define 	 VENDOR_MICROSOFT 	311
  	//VENDOR	Microsoft			311
#define 	 VENDOR_NETSCREEN 	3224
  	//VENDOR	Netscreen			3224
#define 	 VENDOR_NOMADIX 	3309
  	//VENDOR	Nomadix				3309
#define 	 VENDOR_QUINTUM 	6618
  	//VENDOR	Quintum				6618
#define 	 VENDOR_REDBACK 	2352
  	//VENDOR	Redback				2352
#define 	 VENDOR_REDCREEK 	1958
  	//VENDOR	RedCreek			1958
#define 	 VENDOR_SHASTA 	3199
  	//VENDOR	Shasta				3199
#define 	 VENDOR_SHIVA 	166
  	//VENDOR	Shiva				166
#define 	 VENDOR_SPRINGTIDE 	3551
  	//VENDOR	SpringTide			3551
#define 	 VENDOR_TELEBIT 	117
  	//VENDOR	Telebit				117
#define 	 VENDOR_USR 	429
  	//VENDOR	USR				429
#define 	 VENDOR_VERSANET 	2180
  	//VENDOR	Versanet			2180
#define 	 VENDOR_WISPR 	14122
  	//VENDOR	WISPr				14122
#define 	 VENDOR_XEDIA 	838
  	//VENDOR	Xedia				838
  	//
  	//ATTRIBUTE	User-Name			1	string	
  	//ATTRIBUTE	Password			2	string	
  	//ATTRIBUTE	Challenge-Response		3	string	
  	//ATTRIBUTE	NAS-Identifier			4	ipaddr	
  	//ATTRIBUTE	NAS-Port			5	integer	
  	//ATTRIBUTE	User-Service			6	integer	
  	//ATTRIBUTE	Framed-Protocol			7	integer	
  	//ATTRIBUTE	Framed-Address			8	ipaddr	
  	//ATTRIBUTE	Framed-Netmask			9	ipaddr	
  	//ATTRIBUTE	Framed-Routing			10	integer	
  	//ATTRIBUTE	Framed-Filter			11	string	
  	//ATTRIBUTE	Framed-MTU			12	integer	
  	//ATTRIBUTE	Framed-Compression		13	integer	
  	//ATTRIBUTE	Login-Host			14	ipaddr	
  	//ATTRIBUTE	Login-Service			15	integer	
  	//ATTRIBUTE	Login-TCP-Port			16	integer	
  	//ATTRIBUTE	Change-Password			17	string	
  	//ATTRIBUTE	Reply-Message			18	string	
  	//ATTRIBUTE	Callback-Number			19	string	
  	//ATTRIBUTE	Callback-Name			20	string	
  	//ATTRIBUTE	Expiration			21	date	
  	//ATTRIBUTE	Framed-Route			22	string	
  	//ATTRIBUTE	Framed-IPX-Network		23	integer	
  	//ATTRIBUTE	State				24	string	
  	//ATTRIBUTE	Class				25	string	
  	//ATTRIBUTE	Vendor-Specific			26	string	
  	//ATTRIBUTE	Session-Timeout			27	integer	
  	//ATTRIBUTE	Idle-Timeout			28	integer	
  	//ATTRIBUTE	Termination-Action		29	integer	
  	//ATTRIBUTE	NAS-Port-DNIS			30	string	
  	//ATTRIBUTE	Caller-Id			31	string	
  	//ATTRIBUTE	NAS-Identifier			32	string	
  	//ATTRIBUTE	Proxy-State			33	string	
  	//ATTRIBUTE	Login-LAT-Service		34	string	
  	//ATTRIBUTE	Login-LAT-Node			35	string	
  	//ATTRIBUTE	Login-LAT-Group			36	string	
  	//ATTRIBUTE	Framed-AppleTalk-Link		37	integer	
  	//ATTRIBUTE	Framed-AppleTalk-Network	38	integer	
  	//ATTRIBUTE	Framed-AppleTalk-Zone		39	string	
  	//ATTRIBUTE	Acct-Status-Type		40	integer	
  	//ATTRIBUTE	Acct-Delay-Time			41	integer	
  	//ATTRIBUTE	Acct-Input-Octets		42	integer	
  	//ATTRIBUTE	Acct-Output-Octets		43	integer	
  	//ATTRIBUTE	Acct-Session-Id			44	string	
  	//ATTRIBUTE	Acct-Authentic			45	integer	
  	//ATTRIBUTE	Acct-Session-Time		46	integer	
  	//ATTRIBUTE	Acct-Input-Packets		47	integer	
  	//ATTRIBUTE	Acct-Output-Packets		48	integer	
  	//ATTRIBUTE	Acct-Terminate-Cause		49	integer	
  	//ATTRIBUTE	Acct-Multi-Session-ID		50	string	
  	//ATTRIBUTE	Acct-Link-Count			51	integer	
  	//ATTRIBUTE	Acct-Input-Gigawords		52	integer	
  	//ATTRIBUTE	Acct-Output-Gigawords		53	integer	
  	//ATTRIBUTE	Event-Time			55	date	
  	//ATTRIBUTE	CHAP-Challenge			60	string	
  	//ATTRIBUTE	NAS-Port-Type			61	integer	
  	//ATTRIBUTE	Port-Limit			62	integer	
  	//ATTRIBUTE	Login-LAT-Port			63	string	
  	//ATTRIBUTE	Tunnel-Type			64	tag_integer	
  	//ATTRIBUTE	Tunnel-Medium-Type		65	tag_integer	
  	//ATTRIBUTE	Tunnel-Client-Endpoint		66	tag_string	
  	//ATTRIBUTE	Tunnel-Server-Endpoirt		67	tag_string	
  	//ATTRIBUTE	Tunnel-Connection		68	string	
  	//ATTRIBUTE	Tunnel-Password			69	tag_string	
  	//ATTRIBUTE	ARAP-Password			70	string	
  	//ATTRIBUTE	ARAP-Features			71	string	
  	//ATTRIBUTE	ARAP-Zone-Access		72	integer	
  	//ATTRIBUTE	ARAP-Security			73	integer	
  	//ATTRIBUTE	ARAP-Security-Data		74	string	
  	//ATTRIBUTE	Password-Retry			75	integer	
  	//ATTRIBUTE	Prompt				76	integer	
  	//ATTRIBUTE	Connect-Info			77	string	
  	//ATTRIBUTE	Configuration-Token		78	string	
  	//ATTRIBUTE	EAP-Message			79	string	
  	//ATTRIBUTE	Signature			80	string	
  	//ATTRIBUTE	Tunnel-Private-Group-ID		81	tag_string	
  	//ATTRIBUTE	Tunnel-Assignment-ID		82	tag_string	
  	//ATTRIBUTE	Tunnel-Preference		83	tag_integer	
  	//ATTRIBUTE	ARAP-Challenge-Response		84	string	
  	//ATTRIBUTE	Acct-Interim-Interval		85	string	
  	//ATTRIBUTE	Acct-Tunnel-Packets-Lost	86	integer	
  	//ATTRIBUTE	NAS-Port-Id			87	string	
  	//ATTRIBUTE	Framed-Pool			88	string	
  	//ATTRIBUTE	Ascend-Filter			90	string	
  	//ATTRIBUTE	Ascend-Telnet-Profile		91	string	
  	//ATTRIBUTE	NAS-IPv6-Address		95	ipaddr6	
  	//ATTRIBUTE	Login-IPv6-Host			98	ipaddr6	
  	//ATTRIBUTE	Framed-IPv6-Route		99	string	
  	//ATTRIBUTE	Framed-IPv6-Pool		100	string	
  	//ATTRIBUTE	Framed-IPv6-Address		168	ipaddr6	
  	//
  	//ATTRIBUTE	X-Ascend-FCP-Parameter		119	string	
  	//ATTRIBUTE	Ascend-Modem-PortNo		120	integer	
  	//ATTRIBUTE	Ascend-Modem-SlotNo		121	integer	
  	//ATTRIBUTE	Ascend-Modem-ShelfNo		122	integer	
  	//ATTRIBUTE	X-Ascend-Call-Attempt-Limit	123	integer	
  	//ATTRIBUTE	X-Ascend-Call-Block-Duration	124	integer	
  	//ATTRIBUTE	X-Ascend-Maximum-Call-Duration	125	integer	
  	//ATTRIBUTE	X-Ascend-Temporary-Rtes		126	integer	
  	//ATTRIBUTE	X-Ascend-Tunneling-Protocol	127	integer	
  	//ATTRIBUTE	Ascend-Shared-Profile-Enable	128	integer	
  	//ATTRIBUTE	X-Ascend-Primary-Home-Agent	129	string	
  	//ATTRIBUTE	X-Ascend-Secondary-Home-Agent	130	string	
  	//ATTRIBUTE	X-Ascend-Dialout-Allowed	131	integer	
  	//ATTRIBUTE	X-Ascend-Client-Gateway		132	ipaddr	
  	//ATTRIBUTE	Ascend-BACP-Enable		133	integer	
  	//ATTRIBUTE	X-Ascend-DHCP-Maximum-Leases	134	integer	
  	//ATTRIBUTE	X-Ascend-Client-Primary-DNS	135	ipaddr	
  	//ATTRIBUTE	X-Ascend-Client-Secondary-DNS	136	ipaddr	
  	//ATTRIBUTE	X-Ascend-Client-Assign-DNS	137	integer	
  	//ATTRIBUTE	X-Ascend-User-Acct-Type		138	integer	
  	//ATTRIBUTE	X-Ascend-User-Acct-Host		139	ipaddr	
  	//ATTRIBUTE	X-Ascend-User-Acct-Port		140	integer	
  	//ATTRIBUTE	X-Ascend-User-Acct-Key		141	string	
  	//ATTRIBUTE	X-Ascend-User-Acct-Base		142	integer	
  	//ATTRIBUTE	X-Ascend-User-Acct-Time		143	integer	
  	//ATTRIBUTE	X-Ascend-Assign-IP-Client	144	ipaddr	
  	//ATTRIBUTE	X-Ascend-Assign-IP-Server	145	ipaddr	
  	//ATTRIBUTE	X-Ascend-Assign-IP-Global-Pool	146	string	
  	//ATTRIBUTE	X-Ascend-DHCP-Reply		147	integer	
  	//ATTRIBUTE	X-Ascend-DHCP-Pool-Number	148	integer	
  	//ATTRIBUTE	X-Ascend-Expect-Callback	149	integer	
  	//ATTRIBUTE	X-Ascend-Event-Type		150	integer	
  	//ATTRIBUTE	X-Ascend-Session-Svr-Key	151	string	
  	//ATTRIBUTE	X-Ascend-Multicast-Rate-Limit	152	integer	
  	//ATTRIBUTE	X-Ascend-IF-Netmask		153	ipaddr	
  	//ATTRIBUTE	X-Ascend-Remote-Addr		154	ipaddr	
  	//ATTRIBUTE	X-Ascend-Multicast-Client	155	integer	
  	//ATTRIBUTE	X-Ascend-FR-Circuit-Name	156	string	
  	//ATTRIBUTE	X-Ascend-FR-LinkUp		157	integer	
  	//ATTRIBUTE	X-Ascend-FR-Nailed-Grp		158	integer	
  	//ATTRIBUTE	X-Ascend-FR-Type		159	integer	
  	//ATTRIBUTE	X-Ascend-FR-Link-Mgt		160	integer	
  	//ATTRIBUTE	X-Ascend-FR-N391		161	integer	
  	//ATTRIBUTE	X-Ascend-FR-DCE-N392		162	integer	
  	//ATTRIBUTE	X-Ascend-FR-DTE-N392		163	integer	
  	//ATTRIBUTE	X-Ascend-FR-DCE-N393		164	integer	
  	//ATTRIBUTE	X-Ascend-FR-DTE-N393		165	integer	
  	//ATTRIBUTE	X-Ascend-FR-T391		166	integer	
  	//ATTRIBUTE	X-Ascend-FR-T392		167	integer	
  	//ATTRIBUTE	X-Ascend-Bridge-Address		168	string	
  	//ATTRIBUTE	X-Ascend-TS-Idle-Limit		169	integer	
  	//ATTRIBUTE	X-Ascend-TS-Idle-Mode		170	integer	
  	//ATTRIBUTE	X-Ascend-DBA-Monitor		171	integer	
  	//ATTRIBUTE	Ascend-Base-Channel-Count	172	integer	
  	//ATTRIBUTE	X-Ascend-Minimum-Channels	173	integer	
  	//ATTRIBUTE	X-Ascend-IPX-Route		174	string	
  	//ATTRIBUTE	X-Ascend-FT1-Caller		175	integer	
  	//ATTRIBUTE	Ascend-Backup			176	string	
  	//ATTRIBUTE	X-Ascend-Call-Type		177	integer	
  	//ATTRIBUTE	X-Ascend-Group			178	string	
  	//ATTRIBUTE	X-Ascend-FR-DLCI		179	integer	
  	//ATTRIBUTE	X-Ascend-FR-Profile-Name	180	string	
  	//ATTRIBUTE	X-Ascend-Ara-PW			181	string	
  	//ATTRIBUTE	X-Ascend-IPX-Node-Addr		182	string	
  	//ATTRIBUTE	X-Ascend-Home-Agent-IP-Addr	183	ipaddr	
  	//ATTRIBUTE	X-Ascend-Home-Agent-Password	184	string	
  	//ATTRIBUTE	X-Ascend-Home-Network-Name	185	string	
  	//ATTRIBUTE	X-Ascend-Home-Agent-UDP-Port	186	integer	
  	//ATTRIBUTE	Ascend-Multilink-ID		187	integer	
  	//ATTRIBUTE	Ascend-Num-In-Multilink		188	integer	
  	//ATTRIBUTE	Ascend-First-Dest		189	ipaddr	
  	//ATTRIBUTE	Ascend-Pre-Input-Octets		190	integer	
  	//ATTRIBUTE	Ascend-Pre-Output-Octets	191	integer	
  	//ATTRIBUTE	Ascend-Pre-Input-Packets	192	integer	
  	//ATTRIBUTE	Ascend-Pre-Output-Packets	193	integer	
  	//ATTRIBUTE	Ascend-Maximum-Time		194	integer	
  	//ATTRIBUTE	Ascend-Disconnect-Cause		195	integer	
  	//ATTRIBUTE	Ascend-Connect-Progress		196	integer	
  	//ATTRIBUTE	Ascend-Data-Rate		197	integer	
  	//ATTRIBUTE	Ascend-PreSession-Time		198	integer	
  	//ATTRIBUTE	Ascend-Token-Idle		199	integer	
  	//ATTRIBUTE	Ascend-Token-Immediate		200	integer	
  	//ATTRIBUTE	Ascend-Require-Auth		201	integer	
  	//ATTRIBUTE	Ascend-Number-Sessions		202	string	
  	//ATTRIBUTE	Ascend-Authen-Alias		203	string	
  	//ATTRIBUTE	Ascend-Token-Expiry		204	integer	
  	//ATTRIBUTE	Ascend-Menu-Selector		205	string	
  	//ATTRIBUTE	Ascend-Menu-Item		206	string	
  	//ATTRIBUTE	Ascend-PW-Warntime		207	integer	
  	//ATTRIBUTE	Ascend-PW-Lifetime		208	integer	
  	//ATTRIBUTE	Ascend-IP-Direct		209	ipaddr	
  	//ATTRIBUTE	Ascend-PPP-VJ-Slot-Comp		210	integer	
  	//ATTRIBUTE	Ascend-PPP-VJ-1172		211	integer	
  	//ATTRIBUTE	Ascend-PPP-Async-Map		212	integer	
  	//ATTRIBUTE	Ascend-Third-Prompt		213	string	
  	//ATTRIBUTE	Ascend-Send-Secret		214	string	
  	//ATTRIBUTE	Ascend-Receive-Secret		215	string	
  	//ATTRIBUTE	Ascend-IPX-Peer-Mode		216	integer	
  	//ATTRIBUTE	Ascend-IP-Pool-Definition	217	string	
  	//ATTRIBUTE	Ascend-Assign-IP-Pool		218	integer	
  	//ATTRIBUTE	Ascend-FR-Direct		219	integer	
  	//ATTRIBUTE	Ascend-FR-Direct-Profile	220	string	
  	//ATTRIBUTE	Ascend-FR-Direct-DLCI		221	integer	
  	//ATTRIBUTE	Ascend-Handle-IPX		222	integer	
  	//ATTRIBUTE	Ascend-Netware-timeout		223	integer	
  	//ATTRIBUTE	Ascend-IPX-Alias		224	integer	
  	//ATTRIBUTE	Ascend-Metric			225	integer	
  	//ATTRIBUTE	Ascend-PRI-Number-Type		226	integer	
  	//ATTRIBUTE	Ascend-Dial-Number		227	string	
  	//ATTRIBUTE	Ascend-Route-IP			228	integer	
  	//ATTRIBUTE	Ascend-Route-IPX		229	integer	
  	//ATTRIBUTE	Ascend-Bridge			230	integer	
  	//ATTRIBUTE	Ascend-Send-Auth		231	integer	
  	//ATTRIBUTE	Ascend-Send-Passwd		232	string	
  	//ATTRIBUTE	Ascend-Link-Compression		233	integer	
  	//ATTRIBUTE	Ascend-Target-Util		234	integer	
  	//ATTRIBUTE	Ascend-Maximum-Channels		235	integer	
  	//ATTRIBUTE	Ascend-Inc-Channel-Count	236	integer	
  	//ATTRIBUTE	Ascend-Dec-Channel-Count	237	integer	
  	//ATTRIBUTE	Ascend-Seconds-Of-History	238	integer	
  	//ATTRIBUTE	Ascend-History-Weigh-Type	239	integer	
  	//ATTRIBUTE	Ascend-Add-Seconds		240	integer	
  	//ATTRIBUTE	Ascend-Remove-Seconds		241	integer	
  	//ATTRIBUTE	Ascend-Idle-Limit		244	integer	
  	//ATTRIBUTE	Ascend-Preempt-Limit		245	integer	
  	//ATTRIBUTE	Ascend-Callback			246	integer	
  	//ATTRIBUTE	Ascend-Data-Svc			247	integer	
  	//ATTRIBUTE	Ascend-Force-56			248	integer	
  	//ATTRIBUTE	Ascend-Billing-Number		249	string	
  	//ATTRIBUTE	Ascend-Call-By-Call		250	integer	
  	//ATTRIBUTE	Ascend-Transit-Number		251	string	
  	//ATTRIBUTE	Ascend-Host-Info		252	string	
  	//ATTRIBUTE	Ascend-PPP-Address		253	ipaddr	
  	//ATTRIBUTE	Ascend-MPP-Idle-Percent		254	integer	
  	//ATTRIBUTE	Ascend-Xmit-Rate		255	integer	
#define 	 ATTRIBUTE_ACC_REASON_CODE 	1  	//ATTRIBUTE	Acc-Reason-Code			1	integer	Acc
#define 	 ATTRIBUTE_ACC_CCP_OPTION 	2  	//ATTRIBUTE	Acc-Ccp-Option			2	integer	Acc
#define 	 ATTRIBUTE_ACC_INPUT_ERRORS 	3  	//ATTRIBUTE	Acc-Input-Errors		3	integer	Acc
#define 	 ATTRIBUTE_ACC_OUTPUT_ERRORS 	4  	//ATTRIBUTE	Acc-Output-Errors		4	integer	Acc
#define 	 ATTRIBUTE_ACC_ACCESS_PARTITION 	5  	//ATTRIBUTE	Acc-Access-Partition		5	string	Acc
#define 	 ATTRIBUTE_ACC_CUSTOMER_ID 	6  	//ATTRIBUTE	Acc-Customer-Id			6	string	Acc
#define 	 ATTRIBUTE_ACC_IP_GATEWAY_PRI 	7  	//ATTRIBUTE	Acc-Ip-Gateway-Pri		7	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_IP_GATEWAY_SEC 	8  	//ATTRIBUTE	Acc-Ip-Gateway-Sec		8	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_ROUTE_POLICY 	9  	//ATTRIBUTE	Acc-Route-Policy		9	integer	Acc
#define 	 ATTRIBUTE_ACC_ML_MLX_ADMIN_STATE 	10  	//ATTRIBUTE	Acc-ML-MLX-Admin-State		10	integer	Acc
#define 	 ATTRIBUTE_ACC_ML_CALL_THRESHOLD 	11  	//ATTRIBUTE	Acc-ML-Call-Threshold		11	integer	Acc
#define 	 ATTRIBUTE_ACC_ML_CLEAR_THRESHOLD 	12  	//ATTRIBUTE	Acc-ML-Clear-Threshold		12	integer	Acc
#define 	 ATTRIBUTE_ACC_ML_DAMPING_FACTOR 	13  	//ATTRIBUTE	Acc-ML-Damping-Factor		13	integer	Acc
#define 	 ATTRIBUTE_ACC_TUNNEL_SECRET 	14  	//ATTRIBUTE	Acc-Tunnel-Secret		14	string	Acc
#define 	 ATTRIBUTE_ACC_CLEARING_CAUSE 	15  	//ATTRIBUTE	Acc-Clearing-Cause		15	integer	Acc
#define 	 ATTRIBUTE_ACC_CLEARING_LOCATION 	16  	//ATTRIBUTE	Acc-Clearing-Location		16	integer	Acc
#define 	 ATTRIBUTE_ACC_SERVICE_PROFILE 	17  	//ATTRIBUTE	Acc-Service-Profile		17	string	Acc
#define 	 ATTRIBUTE_ACC_REQUEST_TYPE 	18  	//ATTRIBUTE	Acc-Request-Type		18	integer	Acc
#define 	 ATTRIBUTE_ACC_BRIDGING_SUPPORT 	19  	//ATTRIBUTE	Acc-Bridging-Support		19	integer	Acc
#define 	 ATTRIBUTE_ACC_APSM_OVERSUBSCRIBED 	20  	//ATTRIBUTE	Acc-Apsm-Oversubscribed		20	integer	Acc
#define 	 ATTRIBUTE_ACC_ACCT_ON_OFF_REASON 	21  	//ATTRIBUTE	Acc-Acct-On-Off-Reason		21	integer	Acc
#define 	 ATTRIBUTE_ACC_TUNNEL_PORT 	22  	//ATTRIBUTE	Acc-Tunnel-Port			22	integer	Acc
#define 	 ATTRIBUTE_ACC_DNS_SERVER_PRI 	23  	//ATTRIBUTE	Acc-Dns-Server-Pri		23	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_DNS_SERVER_SEC 	24  	//ATTRIBUTE	Acc-Dns-Server-Sec		24	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_NBNS_SERVER_PRI 	25  	//ATTRIBUTE	Acc-Nbns-Server-Pri		25	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_NBNS_SERVER_SEC 	26  	//ATTRIBUTE	Acc-Nbns-Server-Sec		26	ipaddr	Acc
#define 	 ATTRIBUTE_ACC_DIAL_PORT_INDEX 	27  	//ATTRIBUTE	Acc-Dial-Port-Index		27	integer	Acc
#define 	 ATTRIBUTE_ACC_IP_COMPRESSION 	28  	//ATTRIBUTE	Acc-Ip-Compression		28	integer	Acc
#define 	 ATTRIBUTE_ACC_IPX_COMPRESSION 	29  	//ATTRIBUTE	Acc-Ipx-Compression		29	integer	Acc
#define 	 ATTRIBUTE_ACC_CONNECT_TX_SPEED 	30  	//ATTRIBUTE	Acc-Connect-Tx-Speed		30	integer	Acc
#define 	 ATTRIBUTE_ACC_CONNECT_RX_SPEED 	31  	//ATTRIBUTE	Acc-Connect-Rx-Speed		31	integer	Acc
#define 	 ATTRIBUTE_ACC_MODEM_MODULATION_TYPE 	32  	//ATTRIBUTE	Acc-Modem-Modulation-Type	32	string	Acc
#define 	 ATTRIBUTE_ACC_MODEM_ERROR_PROTOCOL 	33  	//ATTRIBUTE	Acc-Modem-Error-Protocol	33	string	Acc
#define 	 ATTRIBUTE_ACC_CALLBACK_DELAY 	34  	//ATTRIBUTE	Acc-Callback-Delay		34	integer	Acc
#define 	 ATTRIBUTE_ACC_CALLBACK_NUM_VALID 	35  	//ATTRIBUTE	Acc-Callback-Num-Valid		35	string	Acc
#define 	 ATTRIBUTE_ACC_CALLBACK_MODE 	36  	//ATTRIBUTE	Acc-Callback-Mode		36	integer	Acc
#define 	 ATTRIBUTE_ACC_CALLBACK_CBCP_TYPE 	37  	//ATTRIBUTE	Acc-Callback-CBCP-Type		37	integer	Acc
#define 	 ATTRIBUTE_ACC_DIALOUT_AUTH_MODE 	38  	//ATTRIBUTE	Acc-Dialout-Auth-Mode		38	integer	Acc
#define 	 ATTRIBUTE_ACC_DIALOUT_AUTH_PASSWORD 	39  	//ATTRIBUTE	Acc-Dialout-Auth-Password	39	string	Acc
#define 	 ATTRIBUTE_ACC_DIALOUT_AUTH_USERNAME 	40  	//ATTRIBUTE	Acc-Dialout-Auth-Username	40	string	Acc
#define 	 ATTRIBUTE_ACC_ACCESS_COMMUNITY 	42  	//ATTRIBUTE	Acc-Access-Community		42	integer	Acc
#define 	 ATTRIBUTE_ACC_VPSM_REJECT_CAUSE 	43  	//ATTRIBUTE	Acc-Vpsm-Reject-Cause		43	integer	Acc
#define 	 ATTRIBUTE_ACC_ACE_TOKEN 	44  	//ATTRIBUTE	Acc-Ace-Token			44	string	Acc
#define 	 ATTRIBUTE_ACC_ACE_TOKEN_TTL 	45  	//ATTRIBUTE	Acc-Ace-Token-Ttl		45	integer	Acc
#define 	 ATTRIBUTE_ACC_IP_POOL_NAME 	46  	//ATTRIBUTE	Acc-Ip-Pool-Name		46	string	Acc
#define 	 ATTRIBUTE_ACC_IGMP_ADMIN_STATE 	47  	//ATTRIBUTE	Acc-Igmp-Admin-State		47	integer	Acc
#define 	 ATTRIBUTE_ACC_IGMP_VERSION 	48  	//ATTRIBUTE	Acc-Igmp-Version		48	integer	Acc
#define 	 ATTRIBUTE_CISCO_AVPAIR 	1  	//ATTRIBUTE	Cisco-AVPair			1	string	Cisco
#define 	 ATTRIBUTE_CISCO_NAS_PORT 	2  	//ATTRIBUTE	Cisco-NAS-Port			2	string	Cisco
#define 	 ATTRIBUTE_H323_REMOTE_ADDRESS 	23  	//ATTRIBUTE	h323-remote-address		23	string	Cisco
#define 	 ATTRIBUTE_H323_CONF_ID 	24  	//ATTRIBUTE	h323-conf-id			24	string	Cisco
#define 	 ATTRIBUTE_H323_SETUP_TIME 	25  	//ATTRIBUTE	h323-setup-time			25	string	Cisco
#define 	 ATTRIBUTE_H323_CALL_ORIGIN 	26  	//ATTRIBUTE	h323-call-origin		26	string	Cisco
#define 	 ATTRIBUTE_H323_CALL_TYPE 	27  	//ATTRIBUTE	h323-call-type			27	string	Cisco
#define 	 ATTRIBUTE_H323_CONNECT_TIME 	28  	//ATTRIBUTE	h323-connect-time		28	string	Cisco
#define 	 ATTRIBUTE_H323_DISCONNECT_TIME 	29  	//ATTRIBUTE	h323-disconnect-time		29	string	Cisco
#define 	 ATTRIBUTE_H323_DISCONNECT_CAUSE 	30  	//ATTRIBUTE	h323-disconnect-cause		30	string	Cisco
#define 	 ATTRIBUTE_H323_VOICE_QUALITY 	31  	//ATTRIBUTE	h323-voice-quality		31	string	Cisco
#define 	 ATTRIBUTE_H323_GW_ID 	33  	//ATTRIBUTE	h323-gw-id			33	string	Cisco
#define 	 ATTRIBUTE_H323_INCOMING_CONF_ID 	35  	//ATTRIBUTE	h323-incoming-conf-id		35	string	Cisco
#define 	 ATTRIBUTE_H323_CREDIT_AMOUNT 	101  	//ATTRIBUTE	h323-credit-amount		101	string	Cisco
#define 	 ATTRIBUTE_H323_CREDIT_TIME 	102  	//ATTRIBUTE	h323-credit-time		102	string	Cisco
#define 	 ATTRIBUTE_H323_RETURN_CODE 	103  	//ATTRIBUTE	h323-return-code		103	string	Cisco
#define 	 ATTRIBUTE_H323_PROMPT_ID 	104  	//ATTRIBUTE	h323-prompt-id			104	string	Cisco
#define 	 ATTRIBUTE_H323_TIME_AND_DAY 	105  	//ATTRIBUTE	h323-time-and-day		105	string	Cisco
#define 	 ATTRIBUTE_H323_REDIRECT_NUMBER 	106  	//ATTRIBUTE	h323-redirect-number		106	string	Cisco
#define 	 ATTRIBUTE_H323_PREFERRED_LANG 	107  	//ATTRIBUTE	h323-preferred-lang		107	string	Cisco
#define 	 ATTRIBUTE_H323_REDIRECT_IP_ADDRESS 	108  	//ATTRIBUTE	h323-redirect-ip-address	108	string	Cisco
#define 	 ATTRIBUTE_H323_BILLING_MODEL 	109  	//ATTRIBUTE	h323-billing-model		109	string	Cisco
#define 	 ATTRIBUTE_H323_CURRENCY 	110  	//ATTRIBUTE	h323-currency			110	string	Cisco
#define 	 ATTRIBUTE_CISCO_MULTILINK_ID 	187  	//ATTRIBUTE	Cisco-Multilink-ID		187	integer	Cisco
#define 	 ATTRIBUTE_CISCO_NUM_IN_MULTILINK 	188  	//ATTRIBUTE	Cisco-Num-In-Multilink		188	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PRE_INPUT_OCTETS 	190  	//ATTRIBUTE	Cisco-Pre-Input-Octets		190	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PRE_OUTPUT_OCTETS 	191  	//ATTRIBUTE	Cisco-Pre-Output-Octets		191	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PRE_INPUT_PACKETS 	192  	//ATTRIBUTE	Cisco-Pre-Input-Packets		192	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PRE_OUTPUT_PACKETS 	193  	//ATTRIBUTE	Cisco-Pre-Output-Packets	193	integer	Cisco
#define 	 ATTRIBUTE_CISCO_MAXIMUM_TIME 	194  	//ATTRIBUTE	Cisco-Maximum-Time		194	integer	Cisco
#define 	 ATTRIBUTE_CISCO_DISCONNECT_CAUSE 	195  	//ATTRIBUTE	Cisco-Disconnect-Cause		195	integer	Cisco
#define 	 ATTRIBUTE_CISCO_DATA_RATE 	197  	//ATTRIBUTE	Cisco-Data-Rate			197	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PRESESSION_TIME 	198  	//ATTRIBUTE	Cisco-PreSession-Time		198	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PW_LIFETIME 	208  	//ATTRIBUTE	Cisco-PW-Lifetime		208	integer	Cisco
#define 	 ATTRIBUTE_CISCO_IP_DIRECT 	209  	//ATTRIBUTE	Cisco-IP-Direct			209	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PPP_VJ_SLOT_COMP 	210  	//ATTRIBUTE	Cisco-PPP-VJ-Slot-Comp		210	integer	Cisco
#define 	 ATTRIBUTE_CISCO_PPP_ASYNC_MAP 	212  	//ATTRIBUTE	Cisco-PPP-Async-Map		212	integer	Cisco
#define 	 ATTRIBUTE_CISCO_IP_POOL_DEFINITION 	217  	//ATTRIBUTE	Cisco-IP-Pool-Definition	217	integer	Cisco
#define 	 ATTRIBUTE_CISCO_ASSIGN_IP_POOL 	218  	//ATTRIBUTE	Cisco-Assign-IP-Pool		218	integer	Cisco
#define 	 ATTRIBUTE_CISCO_ROUTE_IP 	228  	//ATTRIBUTE	Cisco-Route-IP			228	integer	Cisco
#define 	 ATTRIBUTE_CISCO_LINK_COMPRESSION 	233  	//ATTRIBUTE	Cisco-Link-Compression		233	integer	Cisco
#define 	 ATTRIBUTE_CISCO_TARGET_UTIL 	234  	//ATTRIBUTE	Cisco-Target-Util		234	integer	Cisco
#define 	 ATTRIBUTE_CISCO_MAXIMUM_CHANNELS 	235  	//ATTRIBUTE	Cisco-Maximum-Channels		235	integer	Cisco
#define 	 ATTRIBUTE_CISCO_DATA_FILTER 	242  	//ATTRIBUTE	Cisco-Data-Filter		242	integer	Cisco
#define 	 ATTRIBUTE_CISCO_CALL_FILTER 	243  	//ATTRIBUTE	Cisco-Call-Filter		243	integer	Cisco
#define 	 ATTRIBUTE_CISCO_IDLE_LIMIT 	244  	//ATTRIBUTE	Cisco-Idle-Limit		244	integer	Cisco
#define 	 ATTRIBUTE_CISCO_ACCOUNT_INFO 	250  	//ATTRIBUTE	Cisco-Account-Info		250	string	Cisco
#define 	 ATTRIBUTE_CISCO_SERVICE_INFO 	251  	//ATTRIBUTE	Cisco-Service-Info		251	string	Cisco
#define 	 ATTRIBUTE_CISCO_COMMAND_CODE 	252  	//ATTRIBUTE	Cisco-Command-Code		252	string	Cisco
#define 	 ATTRIBUTE_CISCO_CONTROL_INFO 	253  	//ATTRIBUTE	Cisco-Control-Info		253	string	Cisco
#define 	 ATTRIBUTE_CISCO_XMIT_RATE 	255  	//ATTRIBUTE	Cisco-Xmit-Rate			255	integer	Cisco
#define 	 ATTRIBUTE_CABLETRON_PROTOCOL_ENABLE 	201  	//ATTRIBUTE	Cabletron-Protocol-Enable	201	integer	Cabletron
#define 	 ATTRIBUTE_CABLETRON_PROTOCOL_CALLABLE 	202  	//ATTRIBUTE	Cabletron-Protocol-Callable	202	integer	Cabletron
#define 	 ATTRIBUTE_TELEBIT_LOGIN_COMMAND 	1  	//ATTRIBUTE	Telebit-Login-Command		1	string	Telebit
#define 	 ATTRIBUTE_TELEBIT_PORT_NAME 	2  	//ATTRIBUTE	Telebit-Port-Name		2	string	Telebit
#define 	 ATTRIBUTE_TELEBIT_ACTIVATE_COMMAND 	3  	//ATTRIBUTE	Telebit-Activate-Command	3	string	Telebit
#define 	 ATTRIBUTE_TELEBIT_ACCOUNTING_INFO 	4  	//ATTRIBUTE	Telebit-Accounting-Info		4	string	Telebit
#define 	 ATTRIBUTE_SHIVA_USER_ATTRIBUTES 	1  	//ATTRIBUTE	Shiva-User-Attributes		1	string	Shiva
#define 	 ATTRIBUTE_SHIVA_CALLED_NUMBER 	90  	//ATTRIBUTE	Shiva-Called-Number		90	string	Shiva
#define 	 ATTRIBUTE_SHIVA_CALLING_NUMBER 	91  	//ATTRIBUTE	Shiva-Calling-Number		91	string	Shiva
#define 	 ATTRIBUTE_SHIVA_CUSTOMER_ID 	92  	//ATTRIBUTE	Shiva-Customer-Id		92	string	Shiva
#define 	 ATTRIBUTE_SHIVA_TYPE_OF_SERVICE 	93  	//ATTRIBUTE	Shiva-Type-Of-Service		93	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_LINK_SPEED 	94  	//ATTRIBUTE	Shiva-Link-Speed		94	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_LINKS_IN_BUNDLE 	95  	//ATTRIBUTE	Shiva-Links-In-Bundle		95	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_COMPRESSION_TYPE 	96  	//ATTRIBUTE	Shiva-Compression-Type		96	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_LINK_PROTOCOL 	97  	//ATTRIBUTE	Shiva-Link-Protocol		97	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_NETWORK_PROTOCOLS 	98  	//ATTRIBUTE	Shiva-Network-Protocols		98	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_SESSION_ID 	99  	//ATTRIBUTE	Shiva-Session-Id		99	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_DISCONNECT_REASON 	100  	//ATTRIBUTE	Shiva-Disconnect-Reason		100	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_ACCT_SERV_SWITCH 	101  	//ATTRIBUTE	Shiva-Acct-Serv-Switch		101	ipaddr	Shiva
#define 	 ATTRIBUTE_SHIVA_EVENT_FLAGS 	102  	//ATTRIBUTE	Shiva-Event-Flags		102	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_FUNCTION 	103  	//ATTRIBUTE	Shiva-Function			103	integer	Shiva
#define 	 ATTRIBUTE_SHIVA_CONNECT_REASON 	104  	//ATTRIBUTE	Shiva-Connect-Reason		104	integer	Shiva
#define 	 ATTRIBUTE_CVPN5000_TUNNEL_THROUGHPUT 	1  	//ATTRIBUTE	CVPN5000-Tunnel-Throughput	1	integer	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_CLIENT_ASSIGNED_IP 	2  	//ATTRIBUTE	CVPN5000-Client-Assigned-IP	2	string	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_CLIENT_REAL_IP 	3  	//ATTRIBUTE	CVPN5000-Client-Real-IP		3	string	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_VPN_GROUPINFO 	4  	//ATTRIBUTE	CVPN5000-VPN-GroupInfo		4	string	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_VPN_PASSWORD 	5  	//ATTRIBUTE	CVPN5000-VPN-Password		5	string	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_ECHO 	6  	//ATTRIBUTE	CVPN5000-Echo			6	integer	Cisco-VPN5000
#define 	 ATTRIBUTE_CVPN5000_CLIENT_ASSIGNED_IPX 	7  	//ATTRIBUTE	CVPN5000-Client-Assigned-IPX	7	integer	Cisco-VPN5000
#define 	 ATTRIBUTE_BINTEC_BIBOPPPTABLE 	224  	//ATTRIBUTE	BinTec-biboPPPTable		224	string	BinTec
#define 	 ATTRIBUTE_BINTEC_BIBODIALTABLE 	225  	//ATTRIBUTE	BinTec-biboDialTable		225	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPEXTIFTABLE 	226  	//ATTRIBUTE	BinTec-ipExtIfTable		226	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPROUTETABLE 	227  	//ATTRIBUTE	BinTec-ipRouteTable		227	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPEXTRTTABLE 	228  	//ATTRIBUTE	BinTec-ipExtRtTable		228	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPNATPRESETTABLE 	229  	//ATTRIBUTE	BinTec-ipNatPresetTable		229	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPXCIRCTABLE 	230  	//ATTRIBUTE	BinTec-ipxCircTable		230	string	BinTec
#define 	 ATTRIBUTE_BINTEC_RIPCIRCTABLE 	231  	//ATTRIBUTE	BinTec-ripCircTable		231	string	BinTec
#define 	 ATTRIBUTE_BINTEC_SAPCIRCTABLE 	232  	//ATTRIBUTE	BinTec-sapCircTable		232	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPXSTATICROUTETABLE 	233  	//ATTRIBUTE	BinTec-ipxStaticRouteTable	233	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPXSTATICSERVTABLE 	234  	//ATTRIBUTE	BinTec-ipxStaticServTable	234	string	BinTec
#define 	 ATTRIBUTE_BINTEC_OSPFIFTABLE 	235  	//ATTRIBUTE	BinTec-ospfIfTable		235	string	BinTec
#define 	 ATTRIBUTE_BINTEC_PPPEXTIFTABLE 	236  	//ATTRIBUTE	BinTec-pppExtIfTable		236	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPFILTERTABLE 	237  	//ATTRIBUTE	BinTec-ipFilterTable		237	string	BinTec
#define 	 ATTRIBUTE_BINTEC_IPQOSTABLE 	238  	//ATTRIBUTE	BinTec-ipQoSTable		238	string	BinTec
#define 	 ATTRIBUTE_BINTEC_QOSIFTABLE 	239  	//ATTRIBUTE	BinTec-qosIfTable		239	string	BinTec
#define 	 ATTRIBUTE_BINTEC_QOSPOLICYTABLE 	240  	//ATTRIBUTE	BinTec-qosPolicyTable		240	string	BinTec
#define 	 ATTRIBUTE_LE_TERMINATE_DETAIL 	2  	//ATTRIBUTE	LE-Terminate-Detail		2	string	Livingston
#define 	 ATTRIBUTE_LE_ADVICE_OF_CHARGE 	3  	//ATTRIBUTE	LE-Advice-of-Charge		3	string	Livingston
#define 	 ATTRIBUTE_LE_CONNECT_DETAIL 	4  	//ATTRIBUTE	LE-Connect-Detail		4	string	Livingston
#define 	 ATTRIBUTE_LE_IP_POOL 	6  	//ATTRIBUTE	LE-IP-Pool			6	string	Livingston
#define 	 ATTRIBUTE_LE_IP_GATEWAY 	7  	//ATTRIBUTE	LE-IP-Gateway			7	ipaddr	Livingston
#define 	 ATTRIBUTE_LE_MODEM_INFO 	8  	//ATTRIBUTE	LE-Modem-Info			8	string	Livingston
#define 	 ATTRIBUTE_LE_IPSEC_LOG_OPTIONS 	9  	//ATTRIBUTE	LE-IPSec-Log-Options		9	integer	Livingston
#define 	 ATTRIBUTE_LE_IPSEC_DENY_ACTION 	10  	//ATTRIBUTE	LE-IPSec-Deny-Action		10	integer	Livingston
#define 	 ATTRIBUTE_LE_IPSEC_ACTIVE_PROFILE 	11  	//ATTRIBUTE	LE-IPSec-Active-Profile		11	string	Livingston
#define 	 ATTRIBUTE_LE_IPSEC_OUTSOURCE_PROFILE 	12  	//ATTRIBUTE	LE-IPSec-Outsource-Profile	12	string	Livingston
#define 	 ATTRIBUTE_LE_IPSEC_PASSIVE_PROFILE 	13  	//ATTRIBUTE	LE-IPSec-Passive-Profile	13	string	Livingston
#define 	 ATTRIBUTE_LE_NAT_TCP_SESSION_TIMEOUT 	14  	//ATTRIBUTE	LE-NAT-TCP-Session-Timeout	14	integer	Livingston
#define 	 ATTRIBUTE_LE_NAT_OTHER_SESSION_TIMEOUT 	15  	//ATTRIBUTE	LE-NAT-Other-Session-Timeout	15	integer	Livingston
#define 	 ATTRIBUTE_LE_NAT_LOG_OPTIONS 	16  	//ATTRIBUTE	LE-NAT-Log-Options		16	integer	Livingston
#define 	 ATTRIBUTE_LE_NAT_SESS_DIR_FAIL_ACTION 	17  	//ATTRIBUTE	LE-NAT-Sess-Dir-Fail-Action	17	integer	Livingston
#define 	 ATTRIBUTE_LE_NAT_INMAP 	18  	//ATTRIBUTE	LE-NAT-Inmap			18	string	Livingston
#define 	 ATTRIBUTE_LE_NAT_OUTMAP 	19  	//ATTRIBUTE	LE-NAT-Outmap			19	string	Livingston
#define 	 ATTRIBUTE_LE_NAT_OUTSOURCE_INMAP 	20  	//ATTRIBUTE	LE-NAT-Outsource-Inmap		20	string	Livingston
#define 	 ATTRIBUTE_LE_NAT_OUTSOURCE_OUTMAP 	21  	//ATTRIBUTE	LE-NAT-Outsource-Outmap		21	string	Livingston
#define 	 ATTRIBUTE_LE_ADMIN_GROUP 	22  	//ATTRIBUTE	LE-Admin-Group			22	string	Livingston
#define 	 ATTRIBUTE_LE_MULTICAST_CLIENT 	23  	//ATTRIBUTE	LE-Multicast-Client		23	integer	Livingston
#define 	 ATTRIBUTE_MS_CHAP_RESPONSE 	1  	//ATTRIBUTE	MS-CHAP-Response		1	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_ERROR 	2  	//ATTRIBUTE	MS-CHAP-Error			2	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_CPW_1 	3  	//ATTRIBUTE	MS-CHAP-CPW-1			3	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_CPW_2 	4  	//ATTRIBUTE	MS-CHAP-CPW-2			4	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_LM_ENC_PW 	5  	//ATTRIBUTE	MS-CHAP-LM-Enc-PW		5	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_NT_ENC_PW 	6  	//ATTRIBUTE	MS-CHAP-NT-Enc-PW		6	string	Microsoft
#define 	 ATTRIBUTE_MS_MPPE_ENCRYPTION_POLICY 	7  	//ATTRIBUTE	MS-MPPE-Encryption-Policy	7	string	Microsoft
#define 	 ATTRIBUTE_MS_MPPE_ENCRYPTION_TYPE 	8  	//ATTRIBUTE	MS-MPPE-Encryption-Type		8	string	Microsoft
#define 	 ATTRIBUTE_MS_RAS_VENDOR 	9  	//ATTRIBUTE	MS-RAS-Vendor			9	integer	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_DOMAIN 	10  	//ATTRIBUTE	MS-CHAP-Domain			10	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_CHALLENGE 	11  	//ATTRIBUTE	MS-CHAP-Challenge		11	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP_MPPE_KEYS 	12  	//ATTRIBUTE	MS-CHAP-MPPE-Keys		12	string	Microsoft
#define 	 ATTRIBUTE_MS_BAP_USAGE 	13  	//ATTRIBUTE	MS-BAP-Usage			13	integer	Microsoft
#define 	 ATTRIBUTE_MS_LINK_UTILIZATION_THRESHOLD 	14  	//ATTRIBUTE	MS-Link-Utilization-Threshold	14	integer	Microsoft
#define 	 ATTRIBUTE_MS_LINK_DROP_TIME_LIMIT 	15  	//ATTRIBUTE	MS-Link-Drop-Time-Limit		15	integer	Microsoft
#define 	 ATTRIBUTE_MS_MPPE_SEND_KEY 	16  	//ATTRIBUTE	MS-MPPE-Send-Key		16	string	Microsoft
#define 	 ATTRIBUTE_MS_MPPE_RECV_KEY 	17  	//ATTRIBUTE	MS-MPPE-Recv-Key		17	string	Microsoft
#define 	 ATTRIBUTE_MS_RAS_VERSION 	18  	//ATTRIBUTE	MS-RAS-Version			18	string	Microsoft
#define 	 ATTRIBUTE_MS_OLD_ARAP_PASSWORD 	19  	//ATTRIBUTE	MS-Old-ARAP-Password		19	string	Microsoft
#define 	 ATTRIBUTE_MS_NEW_ARAP_PASSWORD 	20  	//ATTRIBUTE	MS-New-ARAP-Password		20	string	Microsoft
#define 	 ATTRIBUTE_MS_ARAP_PW_CHANGE_REASON 	21  	//ATTRIBUTE	MS-ARAP-PW-Change-Reason	21	integer	Microsoft
#define 	 ATTRIBUTE_MS_FILTER 	22  	//ATTRIBUTE	MS-Filter			22	string	Microsoft
#define 	 ATTRIBUTE_MS_ACCT_AUTH_TYPE 	23  	//ATTRIBUTE	MS-Acct-Auth-Type		23	integer	Microsoft
#define 	 ATTRIBUTE_MS_ACCT_EAP_TYPE 	24  	//ATTRIBUTE	MS-Acct-EAP-Type		24	integer	Microsoft
#define 	 ATTRIBUTE_MS_CHAP2_RESPONSE 	25  	//ATTRIBUTE	MS-CHAP2-Response		25	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP2_SUCCESS 	26  	//ATTRIBUTE	MS-CHAP2-Success		26	string	Microsoft
#define 	 ATTRIBUTE_MS_CHAP2_CPW 	27  	//ATTRIBUTE	MS-CHAP2-CPW			27	string	Microsoft
#define 	 ATTRIBUTE_MS_PRIMARY_DNS_SERVER 	28  	//ATTRIBUTE	MS-Primary-DNS-Server		28	ipaddr	Microsoft
#define 	 ATTRIBUTE_MS_SECONDARY_DNS_SERVER 	29  	//ATTRIBUTE	MS-Secondary-DNS-Server		29	ipaddr	Microsoft
#define 	 ATTRIBUTE_MS_PRIMARY_NBNS_SERVER 	30  	//ATTRIBUTE	MS-Primary-NBNS-Server		30	ipaddr	Microsoft
#define 	 ATTRIBUTE_MS_SECONDARY_NBNS_SERVER 	31  	//ATTRIBUTE	MS-Secondary-NBNS-Server	31	ipaddr	Microsoft
#define 	 ATTRIBUTE_DTE_DATA_IDLE_TIMOUT 	72  	//ATTRIBUTE	DTE-Data-Idle-Timout		72	integer	USR
#define 	 ATTRIBUTE_DEFAULT_DTE_DATA_RATE 	94  	//ATTRIBUTE	Default-DTE-Data-Rate		94	integer	USR
#define 	 ATTRIBUTE_LAST_NUMBER_DIALED_OUT 	102  	//ATTRIBUTE	Last-Number-Dialed-Out		102	string	USR
#define 	 ATTRIBUTE_SYNC_ASYNC_MODE 	103  	//ATTRIBUTE	Sync-Async-Mode			103	integer	USR
#define 	 ATTRIBUTE_ORIGINATE_ANSWER_MODE 	104  	//ATTRIBUTE	Originate-Answer-Mode		104	integer	USR
#define 	 ATTRIBUTE_FAILURE_TO_CONNECT_REASON 	105  	//ATTRIBUTE	Failure-to-Connect-Reason	105	integer	USR
#define 	 ATTRIBUTE_INITIAL_TX_LINK_DATA_RATE 	106  	//ATTRIBUTE	Initial-Tx-Link-Data-Rate	106	integer	USR
#define 	 ATTRIBUTE_FINAL_TX_LINK_DATA_RATE 	107  	//ATTRIBUTE	Final-Tx-Link-Data-Rate		107	integer	USR
#define 	 ATTRIBUTE_MODULATION_TYPE 	108  	//ATTRIBUTE	Modulation-Type			108	integer	USR
#define 	 ATTRIBUTE_EQUALIZATION_TYPE 	111  	//ATTRIBUTE	Equalization-Type		111	integer	USR
#define 	 ATTRIBUTE_FALLBACK_ENABLED 	112  	//ATTRIBUTE	Fallback-Enabled		112	integer	USR
#define 	 ATTRIBUTE_CHARACTERS_SENT 	113  	//ATTRIBUTE	Characters-Sent			113	integer	USR
#define 	 ATTRIBUTE_CHARACTERS_RECEIVED 	114  	//ATTRIBUTE	Characters-Received		114	integer	USR
#define 	 ATTRIBUTE_BLOCKS_SENT 	117  	//ATTRIBUTE	Blocks-Sent			117	integer	USR
#define 	 ATTRIBUTE_BLOCKS_RECEIVED 	118  	//ATTRIBUTE	Blocks-Received			118	integer	USR
#define 	 ATTRIBUTE_BLOCKS_RESENT 	119  	//ATTRIBUTE	Blocks-Resent			119	integer	USR
#define 	 ATTRIBUTE_RETRAINS_REQUESTED 	120  	//ATTRIBUTE	Retrains-Requested		120	integer	USR
#define 	 ATTRIBUTE_RETRAINS_GRANTED 	121  	//ATTRIBUTE	Retrains-Granted		121	integer	USR
#define 	 ATTRIBUTE_LINE_REVERSALS 	122  	//ATTRIBUTE	Line-Reversals			122	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_CHARACTERS_LOST 	123  	//ATTRIBUTE	Number-Of-Characters-Lost	123	integer	USR
#define 	 ATTRIBUTE_BACK_CHANNEL_DATA_RATE 	124  	//ATTRIBUTE	Back-Channel-Data-Rate		124	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_BLERS 	125  	//ATTRIBUTE	Number-of-Blers			125	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_LINK_TIMEOUTS 	126  	//ATTRIBUTE	Number-of-Link-Timeouts		126	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_FALLBACKS 	127  	//ATTRIBUTE	Number-of-Fallbacks		127	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_UPSHIFTS 	128  	//ATTRIBUTE	Number-of-Upshifts		128	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_LINK_NAKS 	129  	//ATTRIBUTE	Number-of-Link-NAKs		129	integer	USR
#define 	 ATTRIBUTE_SIMPLIFIED_MNP_LEVELS 	153  	//ATTRIBUTE	Simplified-MNP-Levels		153	integer	USR
#define 	 ATTRIBUTE_CONNECT_TERM_REASON 	155  	//ATTRIBUTE	Connect-Term-Reason		155	integer	USR
#define 	 ATTRIBUTE_DTR_FALSE_TIMEOUT 	190  	//ATTRIBUTE	DTR-False-Timeout		190	integer	USR
#define 	 ATTRIBUTE_FALLBACK_LIMIT 	191  	//ATTRIBUTE	Fallback-Limit			191	integer	USR
#define 	 ATTRIBUTE_BLOCK_ERROR_COUNT_LIMIT 	192  	//ATTRIBUTE	Block-Error-Count-Limit		192	integer	USR
#define 	 ATTRIBUTE_SIMPLIFIED_V42BIS_USAGE 	199  	//ATTRIBUTE	Simplified-V42bis-Usage		199	integer	USR
#define 	 ATTRIBUTE_DTR_TRUE_TIMEOUT 	218  	//ATTRIBUTE	DTR-True-Timeout		218	integer	USR
#define 	 ATTRIBUTE_LAST_NUMBER_DIALED_IN_DNIS 	232  	//ATTRIBUTE	Last-Number-Dialed-In-DNIS	232	string	USR
#define 	 ATTRIBUTE_LAST_CALLERS_NUMBER_ANI 	233  	//ATTRIBUTE	Last-Callers-Number-ANI		233	string	USR
#define 	 ATTRIBUTE_CDMA_CALL_REFERENCE_NUMBER 	387  	//ATTRIBUTE	CDMA-Call-Reference-Number	387	integer	USR
#define 	 ATTRIBUTE_MBI_CT_PRI_CARD_SLOT 	388  	//ATTRIBUTE	Mbi_Ct_PRI_Card_Slot		388	integer	USR
#define 	 ATTRIBUTE_MBI_CT_TDM_TIME_SLOT 	389  	//ATTRIBUTE	Mbi_Ct_TDM_Time_Slot		389	integer	USR
#define 	 ATTRIBUTE_MBI_CT_PRI_CARD_SPAN_LINE 	390  	//ATTRIBUTE	Mbi_Ct_PRI_Card_Span_Line	390	integer	USR
#define 	 ATTRIBUTE_MBI_CT_BCHANNEL_USED 	391  	//ATTRIBUTE	Mbi_Ct_BChannel_Used		391	integer	USR
#define 	 ATTRIBUTE_RMMIE_STATUS 	461  	//ATTRIBUTE	RMMIE-Status			461	integer	USR
#define 	 ATTRIBUTE_RMMIE_NUM_OF_UPDATES 	462  	//ATTRIBUTE	RMMIE-Num-Of-Updates		462	integer	USR
#define 	 ATTRIBUTE_RMMIE_MANUFACTURER_ID 	479  	//ATTRIBUTE	RMMIE-Manufacturer-ID		479	integer	USR
#define 	 ATTRIBUTE_RMMIE_PRODUCT_CODE 	480  	//ATTRIBUTE	RMMIE-Product-Code		480	string	USR
#define 	 ATTRIBUTE_RMMIE_SERIAL_NUMBER 	481  	//ATTRIBUTE	RMMIE-Serial-Number		481	string	USR
#define 	 ATTRIBUTE_RMMIE_FIRMWARE_VERSION 	482  	//ATTRIBUTE	RMMIE-Firmware-Version		482	string	USR
#define 	 ATTRIBUTE_RMMIE_FIRMWARE_BUILD_DATE 	483  	//ATTRIBUTE	RMMIE-Firmware-Build-Date	483	string	USR
#define 	 ATTRIBUTE_IWF_IP_ADDRESS 	1012  	//ATTRIBUTE	IWF-IP-Address			1012	ipaddr	USR
#define 	 ATTRIBUTE_MOBILE_IP_ADDRESS 	2190  	//ATTRIBUTE	Mobile-IP-Address		2190	ipaddr	USR
#define 	 ATTRIBUTE_CALLING_PARTY_NUMBER 	2191  	//ATTRIBUTE	Calling-Party-Number		2191	string	USR
#define 	 ATTRIBUTE_CALLED_PARTY_NUMBER 	2192  	//ATTRIBUTE	Called-Party-Number		2192	string	USR
#define 	 ATTRIBUTE_CALL_TYPE 	2193  	//ATTRIBUTE	Call-Type			2193	integer	USR
#define 	 ATTRIBUTE_ESN 	2194  	//ATTRIBUTE	ESN				2194	string	USR
#define 	 ATTRIBUTE_IWF_CALL_IDENTIFIER 	2195  	//ATTRIBUTE	IWF-Call-Identifier		2195	integer	USR
#define 	 ATTRIBUTE_IMSI 	2196  	//ATTRIBUTE	IMSI				2196	string	USR
#define 	 ATTRIBUTE_SERVICE_OPTION 	2197  	//ATTRIBUTE	Service-Option			2197	integer	USR
#define 	 ATTRIBUTE_DISCONNECT_CAUSE_INDICATOR 	2198  	//ATTRIBUTE	Disconnect-Cause-Indicator	2198	integer	USR
#define 	 ATTRIBUTE_MOBILE_NUMBYTES_TXED 	2199  	//ATTRIBUTE	Mobile-NumBytes-Txed		2199	integer	USR
#define 	 ATTRIBUTE_MOBILE_NUMBYTES_RXED 	2200  	//ATTRIBUTE	Mobile-NumBytes-Rxed		2200	integer	USR
#define 	 ATTRIBUTE_NUM_FAX_PAGES_PROCESSED 	2201  	//ATTRIBUTE	Num-Fax-Pages-Processed		2201	integer	USR
#define 	 ATTRIBUTE_COMPRESSION_TYPE 	2202  	//ATTRIBUTE	Compression-Type		2202	integer	USR
#define 	 ATTRIBUTE_CALL_ERROR_CODE 	2203  	//ATTRIBUTE	Call-Error-Code			2203	integer	USR
#define 	 ATTRIBUTE_MODEM_SETUP_TIME 	2204  	//ATTRIBUTE	Modem-Setup-Time		2204	integer	USR
#define 	 ATTRIBUTE_CALL_CONNECTING_TIME 	2205  	//ATTRIBUTE	Call-Connecting-Time		2205	integer	USR
#define 	 ATTRIBUTE_CONNECT_TIME 	2206  	//ATTRIBUTE	Connect-Time			2206	integer	USR
#define 	 ATTRIBUTE_RMMIE_LAST_UPDATE_TIME 	2304  	//ATTRIBUTE	RMMIE-Last-Update-Time		2304	integer	USR
#define 	 ATTRIBUTE_RMMIE_LAST_UPDATE_EVENT 	2305  	//ATTRIBUTE	RMMIE-Last-Update-Event		2305	integer	USR
#define 	 ATTRIBUTE_RMMIE_RCV_TOT_PWRLVL 	2306  	//ATTRIBUTE	RMMIE-Rcv-Tot-PwrLvl		2306	integer	USR
#define 	 ATTRIBUTE_RMMIE_RCV_PWRLVL_3300HZ 	2307  	//ATTRIBUTE	RMMIE-Rcv-PwrLvl-3300Hz		2307	integer	USR
#define 	 ATTRIBUTE_RMMIE_RCV_PWRLVL_3750HZ 	2308  	//ATTRIBUTE	RMMIE-Rcv-PwrLvl-3750Hz		2308	integer	USR
#define 	 ATTRIBUTE_RMMIE_PWRLVL_NEARECHO_CANC 	2309  	//ATTRIBUTE	RMMIE-PwrLvl-NearEcho-Canc	2309	integer	USR
#define 	 ATTRIBUTE_RMMIE_PWRLVL_FARECHO_CANC 	2310  	//ATTRIBUTE	RMMIE-PwrLvl-FarEcho-Canc	2310	integer	USR
#define 	 ATTRIBUTE_RMMIE_PWRLVL_NOISE_LVL 	2311  	//ATTRIBUTE	RMMIE-PwrLvl-Noise-Lvl		2311	integer	USR
#define 	 ATTRIBUTE_RMMIE_PWRLVL_XMIT_LVL 	2312  	//ATTRIBUTE	RMMIE-PwrLvl-Xmit-Lvl		2312	integer	USR
#define 	 ATTRIBUTE_RMMIE_X2_STATUS 	2313  	//ATTRIBUTE	RMMIE-x2-Status			2313	integer	USR
#define 	 ATTRIBUTE_RMMIE_PLANNED_DISCONNECT 	2314  	//ATTRIBUTE	RMMIE-Planned-Disconnect	2314	integer	USR
#define 	 ATTRIBUTE_INITIAL_MODULATION_TYPE 	2339  	//ATTRIBUTE	Initial-Modulation-Type		2339	integer	USR
#define 	 ATTRIBUTE_PW_USR_IFILTER_IP 	36864  	//ATTRIBUTE	PW_USR_IFilter_IP		36864	string	USR
#define 	 ATTRIBUTE_PW_USR_IFILTER_IPX 	36865  	//ATTRIBUTE	PW_USR_IFilter_IPX		36865	string	USR
#define 	 ATTRIBUTE_SAP_FILTER_IN 	36866  	//ATTRIBUTE	SAP-Filter-In			36866	string	USR
#define 	 ATTRIBUTE_PW_USR_OFILTER_IP 	36867  	//ATTRIBUTE	PW_USR_OFilter_IP		36867	string	USR
#define 	 ATTRIBUTE_PW_USR_OFILTER_IPX 	36868  	//ATTRIBUTE	PW_USR_OFilter_IPX		36868	string	USR
#define 	 ATTRIBUTE_PW_USR_OFILTER_SAP 	36869  	//ATTRIBUTE	PW_USR_OFilter_SAP		36869	string	USR
#define 	 ATTRIBUTE_PW_VPN_ID 	36870  	//ATTRIBUTE	PW_VPN_ID			36870	string	USR
#define 	 ATTRIBUTE_PW_VPN_NAME 	36871  	//ATTRIBUTE	PW_VPN_Name			36871	string	USR
#define 	 ATTRIBUTE_PW_VPN_NEIGHBOR 	36872  	//ATTRIBUTE	PW_VPN_Neighbor			36872	string	USR
#define 	 ATTRIBUTE_PW_FRAMED_ROUTING_V2 	36873  	//ATTRIBUTE	PW_Framed_Routing_V2		36873	string	USR
#define 	 ATTRIBUTE_PW_VPN_GATEWAY 	36874  	//ATTRIBUTE	PW_VPN_Gateway			36874	string	USR
#define 	 ATTRIBUTE_PW_TUNNEL_AUTHENTICATION 	36875  	//ATTRIBUTE	PW_Tunnel_Authentication	36875	string	USR
#define 	 ATTRIBUTE_PW_INDEX 	36876  	//ATTRIBUTE	PW_Index			36876	string	USR
#define 	 ATTRIBUTE_PW_CUTOFF 	36877  	//ATTRIBUTE	PW_Cutoff			36877	string	USR
#define 	 ATTRIBUTE_PW_PACKET 	36878  	//ATTRIBUTE	PW_Packet			36878	string	USR
#define 	 ATTRIBUTE_PRIMARY_DNS_SERVER 	36879  	//ATTRIBUTE	Primary_DNS_Server		36879	ipaddr	USR
#define 	 ATTRIBUTE_SECONDARY_DNS_SERVER 	36880  	//ATTRIBUTE	Secondary_DNS_Server		36880	ipaddr	USR
#define 	 ATTRIBUTE_PRIMARY_NBNS_SERVER 	36881  	//ATTRIBUTE	Primary_NBNS_Server		36881	ipaddr	USR
#define 	 ATTRIBUTE_SECONDARY_NBNS_SERVER 	36882  	//ATTRIBUTE	Secondary_NBNS_Server		36882	ipaddr	USR
#define 	 ATTRIBUTE_SYSLOG_TAP 	36883  	//ATTRIBUTE	Syslog-Tap			36883	integer	USR
#define 	 ATTRIBUTE_MIC 	36884  	//ATTRIBUTE	MIC				36884	string	USR
#define 	 ATTRIBUTE_LOG_FILTER_PACKETS 	36887  	//ATTRIBUTE	Log-Filter-Packets		36887	string	USR
#define 	 ATTRIBUTE_CHASSIS_CALL_SLOT 	36889  	//ATTRIBUTE	Chassis-Call-Slot		36889	integer	USR
#define 	 ATTRIBUTE_CHASSIS_CALL_SPAN 	36890  	//ATTRIBUTE	Chassis-Call-Span		36890	integer	USR
#define 	 ATTRIBUTE_CHASSIS_CALL_CHANNEL 	36891  	//ATTRIBUTE	Chassis-Call-Channel		36891	integer	USR
#define 	 ATTRIBUTE_KEYPRESS_TIMEOUT 	36892  	//ATTRIBUTE	Keypress-Timeout		36892	integer	USR
#define 	 ATTRIBUTE_UNAUTHENTICATED_TIME 	36893  	//ATTRIBUTE	Unauthenticated-Time		36893	integer	USR
#define 	 ATTRIBUTE_VPN_ENCRYPTER 	36894  	//ATTRIBUTE	VPN-Encrypter			36894	integer	USR
#define 	 ATTRIBUTE_VPN_GW_LOCATION_ID 	36895  	//ATTRIBUTE	VPN-GW-Location-Id		36895	string	USR
#define 	 ATTRIBUTE_RE_CHAP_TIMEOUT 	36896  	//ATTRIBUTE	Re-Chap-Timeout			36896	integer	USR
#define 	 ATTRIBUTE_CCP_ALGORITHM 	36897  	//ATTRIBUTE	CCP-Algorithm			36897	integer	USR
#define 	 ATTRIBUTE_ACCM_TYPE 	36898  	//ATTRIBUTE	ACCM-Type			36898	integer	USR
#define 	 ATTRIBUTE_CONNECT_SPEED 	36899  	//ATTRIBUTE	Connect-Speed			36899	integer	USR
#define 	 ATTRIBUTE_FRAMED_IP_ADDRESS_POOL_NAME 	36900  	//ATTRIBUTE	Framed_IP_Address_Pool_Name	36900	string	USR
#define 	 ATTRIBUTE_MP_EDO 	36901  	//ATTRIBUTE	MP-EDO				36901	string	USR
#define 	 ATTRIBUTE_LOCAL_FRAMED_IP_ADDR 	36902  	//ATTRIBUTE	Local-Framed-IP-Addr		36902	ipaddr	USR
#define 	 ATTRIBUTE_FRAMED_IPX_ROUTE 	36903  	//ATTRIBUTE	Framed-IPX-Route		36903	ipaddr	USR
#define 	 ATTRIBUTE_MPIP_TUNNEL_ORIGINATOR 	36904  	//ATTRIBUTE	MPIP-Tunnel-Originator		36904	ipaddr	USR
#define 	 ATTRIBUTE_BEARER_CAPABILITIES 	38912  	//ATTRIBUTE	Bearer-Capabilities		38912	integer	USR
#define 	 ATTRIBUTE_SPEED_OF_CONNECTION 	38913  	//ATTRIBUTE	Speed-Of-Connection		38913	integer	USR
#define 	 ATTRIBUTE_MAX_CHANNELS 	38914  	//ATTRIBUTE	Max-Channels			38914	integer	USR
#define 	 ATTRIBUTE_CHANNEL_EXPANSION 	38915  	//ATTRIBUTE	Channel-Expansion		38915	integer	USR
#define 	 ATTRIBUTE_CHANNEL_DECREMENT 	38916  	//ATTRIBUTE	Channel-Decrement		38916	integer	USR
#define 	 ATTRIBUTE_EXPANSION_ALGORITHM 	38917  	//ATTRIBUTE	Expansion-Algorithm		38917	integer	USR
#define 	 ATTRIBUTE_COMPRESSION_ALGORITHM 	38918  	//ATTRIBUTE	Compression-Algorithm		38918	integer	USR
#define 	 ATTRIBUTE_RECEIVE_ACC_MAP 	38919  	//ATTRIBUTE	Receive-Acc-Map			38919	integer	USR
#define 	 ATTRIBUTE_TRANSMIT_ACC_MAP 	38920  	//ATTRIBUTE	Transmit-Acc-Map		38920	integer	USR
#define 	 ATTRIBUTE_COMPRESSION_RESET_MODE 	38922  	//ATTRIBUTE	Compression-Reset-Mode		38922	integer	USR
#define 	 ATTRIBUTE_MIN_COMPRESSION_SIZE 	38923  	//ATTRIBUTE	Min-Compression-Size		38923	integer	USR
#define 	 ATTRIBUTE_IP 	38924  	//ATTRIBUTE	IP				38924	integer	USR
#define 	 ATTRIBUTE_IPX 	38925  	//ATTRIBUTE	IPX				38925	integer	USR
#define 	 ATTRIBUTE_FILTER_ZONES 	38926  	//ATTRIBUTE	Filter-Zones			38926	integer	USR
#define 	 ATTRIBUTE_APPLETALK 	38927  	//ATTRIBUTE	Appletalk			38927	integer	USR
#define 	 ATTRIBUTE_BRIDGING 	38928  	//ATTRIBUTE	Bridging			38928	integer	USR
#define 	 ATTRIBUTE_SPOOFING 	38929  	//ATTRIBUTE	Spoofing			38929	integer	USR
#define 	 ATTRIBUTE_HOST_TYPE 	38930  	//ATTRIBUTE	Host-Type			38930	integer	USR
#define 	 ATTRIBUTE_SEND_NAME 	38931  	//ATTRIBUTE	Send-Name			38931	string	USR
#define 	 ATTRIBUTE_SEND_PASSWORD 	38932  	//ATTRIBUTE	Send-Password			38932	string	USR
#define 	 ATTRIBUTE_START_TIME 	38933  	//ATTRIBUTE	Start-Time			38933	integer	USR
#define 	 ATTRIBUTE_END_TIME 	38934  	//ATTRIBUTE	End-Time			38934	integer	USR
#define 	 ATTRIBUTE_SEND_SCRIPT1 	38935  	//ATTRIBUTE	Send-Script1			38935	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT1 	38936  	//ATTRIBUTE	Reply-Script1			38936	string	USR
#define 	 ATTRIBUTE_SEND_SCRIPT2 	38937  	//ATTRIBUTE	Send-Script2			38937	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT2 	38938  	//ATTRIBUTE	Reply-Script2			38938	string	USR
#define 	 ATTRIBUTE_SEND_SCRIPT3 	38939  	//ATTRIBUTE	Send-Script3			38939	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT3 	38940  	//ATTRIBUTE	Reply-Script3			38940	string	USR
#define 	 ATTRIBUTE_SEND_SCRIPT4 	38941  	//ATTRIBUTE	Send-Script4			38941	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT4 	38942  	//ATTRIBUTE	Reply-Script4			38942	string	USR
#define 	 ATTRIBUTE_SEND_SCRIPT5 	38943  	//ATTRIBUTE	Send-Script5			38943	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT5 	38944  	//ATTRIBUTE	Reply-Script5			38944	string	USR
#define 	 ATTRIBUTE_SEND_SCRIPT6 	38945  	//ATTRIBUTE	Send-Script6			38945	string	USR
#define 	 ATTRIBUTE_REPLY_SCRIPT6 	38946  	//ATTRIBUTE	Reply-Script6			38946	string	USR
#define 	 ATTRIBUTE_TERMINAL_TYPE 	38947  	//ATTRIBUTE	Terminal-Type			38947	string	USR
#define 	 ATTRIBUTE_APPLETALK_NETWORK_RANGE 	38948  	//ATTRIBUTE	Appletalk-Network-Range		38948	integer	USR
#define 	 ATTRIBUTE_LOCAL_IP_ADDRESS 	38949  	//ATTRIBUTE	Local-IP-Address		38949	string	USR
#define 	 ATTRIBUTE_ROUTING_PROTOCOL 	38950  	//ATTRIBUTE	Routing-Protocol		38950	integer	USR
#define 	 ATTRIBUTE_MODEM_GROUP 	38951  	//ATTRIBUTE	Modem-Group			38951	integer	USR
#define 	 ATTRIBUTE_IPX_ROUTING 	38952  	//ATTRIBUTE	IPX-Routing			38952	integer	USR
#define 	 ATTRIBUTE_IPX_WAN 	38953  	//ATTRIBUTE	IPX-WAN				38953	integer	USR
#define 	 ATTRIBUTE_IP_RIP_POLICIES 	38954  	//ATTRIBUTE	IP-RIP-Policies			38954	integer	USR
#define 	 ATTRIBUTE_IP_RIP_SIMPLE_AUTH_PASSWORD 	38955  	//ATTRIBUTE	IP-RIP-Simple-Auth-Password	38955	string	USR
#define 	 ATTRIBUTE_IP_RIP_INPUT_FILTER 	38956  	//ATTRIBUTE	IP-RIP-Input-Filter		38956	string	USR
#define 	 ATTRIBUTE_IP_CALL_INPUT_FILTER 	38957  	//ATTRIBUTE	IP-Call-Input-Filter		38957	string	USR
#define 	 ATTRIBUTE_IPX_RIP_INPUT_FILTER 	38958  	//ATTRIBUTE	IPX-RIP-Input-Filter		38958	string	USR
#define 	 ATTRIBUTE_MP_MRRU 	38959  	//ATTRIBUTE	MP-MRRU				38959	integer	USR
#define 	 ATTRIBUTE_IPX_CALL_INPUT_FILTER 	38960  	//ATTRIBUTE	IPX-Call-Input-Filter		38960	string	USR
#define 	 ATTRIBUTE_AT_INPUT_FILTER 	38961  	//ATTRIBUTE	AT-Input-Filter			38961	string	USR
#define 	 ATTRIBUTE_AT_RTMP_INPUT_FILTER 	38962  	//ATTRIBUTE	AT-RTMP-Input-Filter		38962	string	USR
#define 	 ATTRIBUTE_AT_ZIP_INPUT_FILTER 	38963  	//ATTRIBUTE	AT-Zip-Input-Filter		38963	string	USR
#define 	 ATTRIBUTE_AT_CALL_INPUT_FILTER 	38964  	//ATTRIBUTE	AT-Call-Input-Filter		38964	string	USR
#define 	 ATTRIBUTE_ET_BRIDGE_INPUT_FILTER 	38965  	//ATTRIBUTE	ET-Bridge-Input-Filter		38965	string	USR
#define 	 ATTRIBUTE_IP_RIP_OUTPUT_FILTER 	38966  	//ATTRIBUTE	IP-RIP-Output-Filter		38966	string	USR
#define 	 ATTRIBUTE_IP_CALL_OUTPUT_FILTER 	38967  	//ATTRIBUTE	IP-Call-Output-Filter		38967	string	USR
#define 	 ATTRIBUTE_IPX_RIP_OUTPUT_FILTER 	38968  	//ATTRIBUTE	IPX-RIP-Output-Filter		38968	string	USR
#define 	 ATTRIBUTE_IPX_CALL_OUTPUT_FILTER 	38969  	//ATTRIBUTE	IPX-Call-Output-Filter		38969	string	USR
#define 	 ATTRIBUTE_AT_OUTPUT_FILTER 	38970  	//ATTRIBUTE	AT-Output-Filter		38970	string	USR
#define 	 ATTRIBUTE_AT_RTMP_OUTPUT_FILTER 	38971  	//ATTRIBUTE	AT-RTMP-Output-Filter		38971	string	USR
#define 	 ATTRIBUTE_AT_ZIP_OUTPUT_FILTER 	38972  	//ATTRIBUTE	AT-Zip-Output-Filter		38972	string	USR
#define 	 ATTRIBUTE_AT_CALL_OUTPUT_FILTER 	38973  	//ATTRIBUTE	AT-Call-Output-Filter		38973	string	USR
#define 	 ATTRIBUTE_ET_BRIDGE_OUTPUT_FILTER 	38974  	//ATTRIBUTE	ET-Bridge-Output-Filter		38974	string	USR
#define 	 ATTRIBUTE_ET_BRIDGE_CALL_OUTPUT_FILTE 	38975  	//ATTRIBUTE	ET-Bridge-Call-Output-Filte	38975	string	USR
#define 	 ATTRIBUTE_IP_DEFAULT_ROUTE_OPTION 	38976  	//ATTRIBUTE	IP-Default-Route-Option		38976	integer	USR
#define 	 ATTRIBUTE_MP_EDO_HIPER 	38977  	//ATTRIBUTE	MP-EDO-HIPER			38977	string	USR
#define 	 ATTRIBUTE_MODEM_TRAINING_TIME 	38978  	//ATTRIBUTE	Modem-Training-Time		38978	integer	USR
#define 	 ATTRIBUTE_INTERFACE_INDEX 	38979  	//ATTRIBUTE	Interface-Index			38979	integer	USR
#define 	 ATTRIBUTE_TUNNEL_SECURITY 	38980  	//ATTRIBUTE	Tunnel-Security			38980	integer	USR
#define 	 ATTRIBUTE_PORT_TAP 	38981  	//ATTRIBUTE	Port-Tap			38981	integer	USR
#define 	 ATTRIBUTE_PORT_TAP_FORMAT 	38982  	//ATTRIBUTE	Port-Tap-Format			38982	integer	USR
#define 	 ATTRIBUTE_PORT_TAP_OUTPUT 	38983  	//ATTRIBUTE	Port-Tap-Output			38983	integer	USR
#define 	 ATTRIBUTE_PORT_TAP_FACILITY 	38984  	//ATTRIBUTE	Port-Tap-Facility		38984	integer	USR
#define 	 ATTRIBUTE_PORT_TAP_PRIORITY 	38985  	//ATTRIBUTE	Port-Tap-Priority		38985	integer	USR
#define 	 ATTRIBUTE_PORT_TAP_ADDRESS 	38986  	//ATTRIBUTE	Port-Tap-Address		38986	ipaddr	USR
#define 	 ATTRIBUTE_MOBILEIP_HOME_AGENT_ADDRESS 	38987  	//ATTRIBUTE	MobileIP-Home-Agent-Address	38987	ipaddr	USR
#define 	 ATTRIBUTE_TUNNELED_MLPP 	38988  	//ATTRIBUTE	Tunneled-MLPP			38988	integer	USR
#define 	 ATTRIBUTE_MULTICAST_PROXY 	38989  	//ATTRIBUTE	Multicast-Proxy			38989	integer	USR
#define 	 ATTRIBUTE_MULTICAST_RECEIVE 	38990  	//ATTRIBUTE	Multicast-Receive		38990	integer	USR
#define 	 ATTRIBUTE_MULTICAST_FORWARDING 	38992  	//ATTRIBUTE	Multicast-Forwarding		38992	integer	USR
#define 	 ATTRIBUTE_IGMP_QUERY_INTERVAL 	38993  	//ATTRIBUTE	IGMP-Query-Interval		38993	integer	USR
#define 	 ATTRIBUTE_IGMP_MAXIMUM_RESPONSE_TIME 	38994  	//ATTRIBUTE	IGMP-Maximum-Response-Time	38994	integer	USR
#define 	 ATTRIBUTE_IGMP_ROBUSTNESS 	38995  	//ATTRIBUTE	IGMP-Robustness			38995	integer	USR
#define 	 ATTRIBUTE_IGMP_VERSION 	38996  	//ATTRIBUTE	IGMP-Version			38996	integer	USR
#define 	 ATTRIBUTE_IGMP_ROUTING 	38997  	//ATTRIBUTE	IGMP-Routing			38997	integer	USR
#define 	 ATTRIBUTE_VTS_SESSION_KEY 	38998  	//ATTRIBUTE	VTS-Session-Key			38998	string	USR
#define 	 ATTRIBUTE_ORIG_NAS_TYPE 	38999  	//ATTRIBUTE	Orig-NAS-Type			38999	string	USR
#define 	 ATTRIBUTE_CALL_ARRIVAL_TIME 	39000  	//ATTRIBUTE	Call-Arrival-Time		39000	integer	USR
#define 	 ATTRIBUTE_CALL_END_TIME 	39001  	//ATTRIBUTE	Call-End-Time			39001	integer	USR
#define 	 ATTRIBUTE_RAD_MULTICAST_ROUTING_TTL 	39008  	//ATTRIBUTE	Rad-Multicast-Routing-Ttl	39008	integer	USR
#define 	 ATTRIBUTE_RAD_MULTICAST_ROUTING_RTLIM 	39009  	//ATTRIBUTE	Rad-Multicast-Routing-RtLim	39009	integer	USR
#define 	 ATTRIBUTE_RAD_MULTICAST_ROUTING_PROTO 	39010  	//ATTRIBUTE	Rad-Multicast-Routing-Proto	39010	integer	USR
#define 	 ATTRIBUTE_RAD_MULTICAST_ROUTING_BOUND 	39011  	//ATTRIBUTE	Rad-Multicast-Routing-Bound	39011	string	USR
#define 	 ATTRIBUTE_RAD_DVMRP_METRIC 	39012  	//ATTRIBUTE	Rad-Dvmrp-Metric		39012	integer	USR
#define 	 ATTRIBUTE_CHAT_SCRIPT_NAME 	39013  	//ATTRIBUTE	Chat-Script-Name		39013	string	USR
#define 	 ATTRIBUTE_CHAT_SCRIPT_RULES 	39014  	//ATTRIBUTE	Chat-Script-Rules		39014	string	USR
#define 	 ATTRIBUTE_RAD_LOCATION_TYPE 	39015  	//ATTRIBUTE	Rad-Location-Type		39015	integer	USR
#define 	 ATTRIBUTE_TUNNEL_SWITCH_ENDPOINT 	39016  	//ATTRIBUTE	Tunnel-Switch-Endpoint		39016	string	USR
#define 	 ATTRIBUTE_OSPF_ADDRESSLESS_INDEX 	39017  	//ATTRIBUTE	OSPF-Addressless-Index		39017	integer	USR
#define 	 ATTRIBUTE_CALLBACK_TYPE 	39018  	//ATTRIBUTE	Callback-Type			39018	integer	USR
#define 	 ATTRIBUTE_TUNNEL_AUTH_HOSTNAME 	39019  	//ATTRIBUTE	Tunnel-Auth-Hostname		39019	string	USR
#define 	 ATTRIBUTE_ACCT_REASON_CODE 	39020  	//ATTRIBUTE	Acct-Reason-Code		39020	integer	USR
#define 	 ATTRIBUTE_IP_SAA_FILTER 	39024  	//ATTRIBUTE	IP-SAA-Filter			39024	integer	USR
#define 	 ATTRIBUTE_DNIS_REAUTHENTICATION 	39029  	//ATTRIBUTE	DNIS-ReAuthentication		39029	integer	USR
#define 	 ATTRIBUTE_SUPPORTS_TAGS 	39049  	//ATTRIBUTE	Supports-Tags			39049	integer	USR
#define 	 ATTRIBUTE_HARC_DISCONNECT_CODE 	39051  	//ATTRIBUTE	HARC-Disconnect-Code		39051	integer	USR
#define 	 ATTRIBUTE_IDS0_CALL_TYPE 	48719  	//ATTRIBUTE	IDS0-Call-Type			48719	integer	USR
#define 	 ATTRIBUTE_CALL_TERMINATE_IN_GMT 	48720  	//ATTRIBUTE	Call-Terminate-in-GMT		48720	date	USR
#define 	 ATTRIBUTE_CALL_CONNECT_IN_GMT 	48721  	//ATTRIBUTE	Call-Connect-in-GMT		48721	date	USR
#define 	 ATTRIBUTE_CALL_ARRIVAL_IN_GMT 	48722  	//ATTRIBUTE	Call-Arrival-in-GMT		48722	date	USR
#define 	 ATTRIBUTE_CHANNEL_CONNECTED_TO 	48733  	//ATTRIBUTE	Channel-Connected-To		48733	integer	USR
#define 	 ATTRIBUTE_SLOT_CONNECTED_TO 	48734  	//ATTRIBUTE	Slot-Connected-To		48734	integer	USR
#define 	 ATTRIBUTE_DEVICE_CONNECTED_TO 	48735  	//ATTRIBUTE	Device-Connected-To		48735	integer	USR
#define 	 ATTRIBUTE_NFAS_ID 	48736  	//ATTRIBUTE	NFAS-ID				48736	integer	USR
#define 	 ATTRIBUTE_Q931_CALL_REFERENCE_VALUE 	48737  	//ATTRIBUTE	Q931-Call-Reference-Value	48737	integer	USR
#define 	 ATTRIBUTE_CALL_EVENT_CODE 	48738  	//ATTRIBUTE	Call-Event-Code			48738	integer	USR
#define 	 ATTRIBUTE_DS0 	48739  	//ATTRIBUTE	DS0				48739	integer	USR
#define 	 ATTRIBUTE_DS0S 	48740  	//ATTRIBUTE	DS0s				48740	string	USR
#define 	 ATTRIBUTE_GATEWAY_IP_ADDRESS 	48742  	//ATTRIBUTE	Gateway-IP-Address		48742	ipaddr	USR
#define 	 ATTRIBUTE_PHYSICAL_STATE 	48759  	//ATTRIBUTE	Physical-State			48759	integer	USR
#define 	 ATTRIBUTE_CALL_REFERENCE_NUMBER 	48765  	//ATTRIBUTE	Call-Reference-Number		48765	integer	USR
#define 	 ATTRIBUTE_CHASSIS_TEMP_THRESHOLD 	48772  	//ATTRIBUTE	Chassis-Temp-Threshold		48772	integer	USR
#define 	 ATTRIBUTE_CARD_TYPE 	48773  	//ATTRIBUTE	Card-Type			48773	integer	USR
#define 	 ATTRIBUTE_SECURITY_LOGIN_LIMIT 	48862  	//ATTRIBUTE	Security-Login-Limit		48862	integer	USR
#define 	 ATTRIBUTE_SECURITY_RESP_LIMIT 	48890  	//ATTRIBUTE	Security-Resp-Limit		48890	integer	USR
#define 	 ATTRIBUTE_PACKET_BUS_SESSION 	48916  	//ATTRIBUTE	Packet-Bus-Session		48916	integer	USR
#define 	 ATTRIBUTE_DTE_RING_NO_ANSWER_LIMIT 	48919  	//ATTRIBUTE	DTE-Ring-No-Answer-Limit	48919	integer	USR
#define 	 ATTRIBUTE_FINAL_RX_LINK_DATA_RATE 	48940  	//ATTRIBUTE	Final-Rx-Link-Data-Rate		48940	integer	USR
#define 	 ATTRIBUTE_INITIAL_RX_LINK_DATA_RATE 	48941  	//ATTRIBUTE	Initial-Rx-Link-Data-Rate	48941	integer	USR
#define 	 ATTRIBUTE_EVENT_DATE_TIME 	48943  	//ATTRIBUTE	Event-Date-Time			48943	date	USR
#define 	 ATTRIBUTE_CHASSIS_TEMPERATURE 	48945  	//ATTRIBUTE	Chassis-Temperature		48945	integer	USR
#define 	 ATTRIBUTE_ACTUAL_VOLTAGE 	48946  	//ATTRIBUTE	Actual-Voltage			48946	integer	USR
#define 	 ATTRIBUTE_EXPECTED_VOLTAGE 	48947  	//ATTRIBUTE	Expected-Voltage		48947	integer	USR
#define 	 ATTRIBUTE_POWER_SUPPLY_NUMBER 	48948  	//ATTRIBUTE	Power-Supply-Number		48948	integer	USR
#define 	 ATTRIBUTE_CHANNEL 	48952  	//ATTRIBUTE	Channel				48952	integer	USR
#define 	 ATTRIBUTE_CHASSIS_SLOT 	48953  	//ATTRIBUTE	Chassis-Slot			48953	integer	USR
#define 	 ATTRIBUTE_EVENT_ID 	49086  	//ATTRIBUTE	Event-Id			49086	integer	USR
#define 	 ATTRIBUTE_NUMBER_OF_RINGS_LIMIT 	49126  	//ATTRIBUTE	Number-of-Rings-Limit		49126	integer	USR
#define 	 ATTRIBUTE_CONNECT_TIME_LIMIT 	49127  	//ATTRIBUTE	Connect-Time-Limit		49127	integer	USR
#define 	 ATTRIBUTE_CALL_END_DATE_TIME 	49142  	//ATTRIBUTE	Call-End-Date-Time		49142	date	USR
#define 	 ATTRIBUTE_CALL_START_DATE_TIME 	49143  	//ATTRIBUTE	Call-Start-Date-Time		49143	date	USR
#define 	 ATTRIBUTE_SERVER_TIME 	61440  	//ATTRIBUTE	Server-Time			61440	date	USR
#define 	 ATTRIBUTE_REQUEST_TYPE 	61441  	//ATTRIBUTE	Request-Type			61441	integer	USR
#define 	 ATTRIBUTE_NAS_TYPE 	61442  	//ATTRIBUTE	NAS-Type			61442	integer	USR
#define 	 ATTRIBUTE_AUTH_MODE 	61443  	//ATTRIBUTE	Auth-Mode			61443	integer	USR
#define 	 ATTRIBUTE_ASCEND_MAX_SHARED_USERS 	2  	//ATTRIBUTE	Ascend-Max-Shared-Users		2	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_UU_INFO 	7  	//ATTRIBUTE	Ascend-UU-Info			7	string	Ascend
#define 	 ATTRIBUTE_ASCEND_CIR_TIMER 	9  	//ATTRIBUTE	Ascend-CIR-Timer		9	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_08_MODE 	10  	//ATTRIBUTE	Ascend-FR-08-Mode		10	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DESTINATION_NAS_PORT 	11  	//ATTRIBUTE	Ascend-Destination-Nas-Port	11	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_SVC_ADDR 	12  	//ATTRIBUTE	Ascend-FR-SVC-Addr		12	string	Ascend
#define 	 ATTRIBUTE_ASCEND_NAS_PORT_FORMAT 	13  	//ATTRIBUTE	Ascend-NAS-Port-Format		13	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_FAULT_MANAGEMENT 	14  	//ATTRIBUTE	Ascend-ATM-Fault-Management	14	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_LOOPBACK_CELL_LOSS 	15  	//ATTRIBUTE	Ascend-ATM-Loopback-Cell-Loss	15	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CKT_TYPE 	16  	//ATTRIBUTE	Ascend-Ckt-Type			16	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SVC_ENABLED 	17  	//ATTRIBUTE	Ascend-SVC-Enabled		17	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SESSION_TYPE 	18  	//ATTRIBUTE	Ascend-Session-Type		18	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_H323_GATEKEEPER 	19  	//ATTRIBUTE	Ascend-H323-Gatekeeper		19	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_GLOBAL_CALL_ID 	20  	//ATTRIBUTE	Ascend-Global-Call-Id		20	string	Ascend
#define 	 ATTRIBUTE_ASCEND_H323_CONFERENCE_ID 	21  	//ATTRIBUTE	Ascend-H323-Conference-Id	21	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_H323_FEGW_ADDRESS 	22  	//ATTRIBUTE	Ascend-H323-Fegw-Address	22	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_H323_DIALED_TIME 	23  	//ATTRIBUTE	Ascend-H323-Dialed-Time		23	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DIALED_NUMBER 	24  	//ATTRIBUTE	Ascend-Dialed-Number		24	string	Ascend
#define 	 ATTRIBUTE_ASCEND_INTER_ARRIVAL_JITTER 	25  	//ATTRIBUTE	Ascend-Inter-Arrival-Jitter	25	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DROPPED_OCTETS 	26  	//ATTRIBUTE	Ascend-Dropped-Octets		26	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DROPPED_PACKETS 	27  	//ATTRIBUTE	Ascend-Dropped-Packets		27	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_AUTH_DELAY 	28  	//ATTRIBUTE	Ascend-Auth-Delay		28	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_X3_PROFILE 	29  	//ATTRIBUTE	Ascend-X25-Pad-X3-Profile	29	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_X3_PARAMETERS 	30  	//ATTRIBUTE	Ascend-X25-Pad-X3-Parameters	30	string	Ascend
#define 	 ATTRIBUTE_ASCEND_TUNNEL_VROUTER_NAME 	31  	//ATTRIBUTE	Ascend-Tunnel-VRouter-Name	31	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_REVERSE_CHARGING 	32  	//ATTRIBUTE	Ascend-X25-Reverse-Charging	32	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_NUI_PROMPT 	33  	//ATTRIBUTE	Ascend-X25-Nui-Prompt		33	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_NUI_PASSWORD_PROMPT 	34  	//ATTRIBUTE	Ascend-X25-Nui-Password-Prompt	34	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_CUG 	35  	//ATTRIBUTE	Ascend-X25-Cug			35	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_ALIAS_1 	36  	//ATTRIBUTE	Ascend-X25-Pad-Alias-1		36	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_ALIAS_2 	37  	//ATTRIBUTE	Ascend-X25-Pad-Alias-2		37	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_ALIAS_3 	38  	//ATTRIBUTE	Ascend-X25-Pad-Alias-3		38	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_X121_ADDRESS 	39  	//ATTRIBUTE	Ascend-X25-X121-Address		39	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_NUI 	40  	//ATTRIBUTE	Ascend-X25-Nui			40	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_RPOA 	41  	//ATTRIBUTE	Ascend-X25-Rpoa			41	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_PROMPT 	42  	//ATTRIBUTE	Ascend-X25-Pad-Prompt		42	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PAD_BANNER 	43  	//ATTRIBUTE	Ascend-X25-Pad-Banner		43	string	Ascend
#define 	 ATTRIBUTE_ASCEND_X25_PROFILE_NAME 	44  	//ATTRIBUTE	Ascend-X25-Profile-Name		44	string	Ascend
#define 	 ATTRIBUTE_ASCEND_RECV_NAME 	45  	//ATTRIBUTE	Ascend-Recv-Name		45	string	Ascend
#define 	 ATTRIBUTE_ASCEND_BI_DIRECTIONAL_AUTH 	46  	//ATTRIBUTE	Ascend-Bi-Directional-Auth	46	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MTU 	47  	//ATTRIBUTE	Ascend-MTU			47	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALL_DIRECTION 	48  	//ATTRIBUTE	Ascend-Call-Direction		48	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SERVICE_TYPE 	49  	//ATTRIBUTE	Ascend-Service-Type		49	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FILTER_REQUIRED 	50  	//ATTRIBUTE	Ascend-Filter-Required		50	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TRAFFIC_SHAPER 	51  	//ATTRIBUTE	Ascend-Traffic-Shaper		51	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ACCESS_INTERCEPT_LEA 	52  	//ATTRIBUTE	Ascend-Access-Intercept-LEA	52	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ACCESS_INTERCEPT_LOG 	53  	//ATTRIBUTE	Ascend-Access-Intercept-Log	53	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PRIVATE_ROUTE_TABLE_ID 	54  	//ATTRIBUTE	Ascend-Private-Route-Table-ID	54	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PRIVATE_ROUTE_REQUIRED 	55  	//ATTRIBUTE	Ascend-Private-Route-Required	55	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CACHE_REFRESH 	56  	//ATTRIBUTE	Ascend-Cache-Refresh		56	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CACHE_TIME 	57  	//ATTRIBUTE	Ascend-Cache-Time		57	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_EGRESS_ENABLED 	58  	//ATTRIBUTE	Ascend-Egress-Enabled		58	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_QOS_UPSTREAM 	59  	//ATTRIBUTE	Ascend-QOS-Upstream		59	string	Ascend
#define 	 ATTRIBUTE_ASCEND_QOS_DOWNSTREAM 	60  	//ATTRIBUTE	Ascend-QOS-Downstream		60	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_CONNECT_VPI 	61  	//ATTRIBUTE	Ascend-ATM-Connect-Vpi		61	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_CONNECT_VCI 	62  	//ATTRIBUTE	Ascend-ATM-Connect-Vci		62	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_CONNECT_GROUP 	63  	//ATTRIBUTE	Ascend-ATM-Connect-Group	63	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_GROUP 	64  	//ATTRIBUTE	Ascend-ATM-Group		64	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IPX_HEADER_COMPRESSION 	65  	//ATTRIBUTE	Ascend-IPX-Header-Compression	65	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLING_ID_TYPE_OF_NUM 	66  	//ATTRIBUTE	Ascend-Calling-Id-Type-Of-Num	66	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLING_ID_NUMBER_PLAN 	67  	//ATTRIBUTE	Ascend-Calling-Id-Number-Plan	67	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLING_ID_PRESENTATN 	68  	//ATTRIBUTE	Ascend-Calling-Id-Presentatn	68	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLING_ID_SCREENING 	69  	//ATTRIBUTE	Ascend-Calling-Id-Screening	69	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BIR_ENABLE 	70  	//ATTRIBUTE	Ascend-BIR-Enable		70	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BIR_PROXY 	71  	//ATTRIBUTE	Ascend-BIR-Proxy		71	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BIR_BRIDGE_GROUP 	72  	//ATTRIBUTE	Ascend-BIR-Bridge-Group		72	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IPSEC_PROFILE 	73  	//ATTRIBUTE	Ascend-IPSEC-Profile		73	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PPPOE_ENABLE 	74  	//ATTRIBUTE	Ascend-PPPoE-Enable		74	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BRIDGE_NON_PPPOE 	75  	//ATTRIBUTE	Ascend-Bridge-Non-PPPoE		75	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_DIRECT 	76  	//ATTRIBUTE	Ascend-ATM-Direct		76	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_DIRECT_PROFILE 	77  	//ATTRIBUTE	Ascend-ATM-Direct-Profile	77	string	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_PRIMARY_WINS 	78  	//ATTRIBUTE	Ascend-Client-Primary-WINS	78	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_SECONDARY_WINS 	79  	//ATTRIBUTE	Ascend-Client-Secondary-WINS	79	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_ASSIGN_WINS 	80  	//ATTRIBUTE	Ascend-Client-Assign-WINS	80	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_AUTH_TYPE 	81  	//ATTRIBUTE	Ascend-Auth-Type		81	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PORT_REDIR_PROTOCOL 	82  	//ATTRIBUTE	Ascend-Port-Redir-Protocol	82	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PORT_REDIR_PORTNUM 	83  	//ATTRIBUTE	Ascend-Port-Redir-Portnum	83	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PORT_REDIR_SERVER 	84  	//ATTRIBUTE	Ascend-Port-Redir-Server	84	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_POOL_CHAINING 	85  	//ATTRIBUTE	Ascend-IP-Pool-Chaining		85	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_OWNER_IP_ADDR 	86  	//ATTRIBUTE	Ascend-Owner-IP-Addr		86	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_TOS 	87  	//ATTRIBUTE	Ascend-IP-TOS			87	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_TOS_PRECEDENCE 	88  	//ATTRIBUTE	Ascend-IP-TOS-Precedence	88	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_TOS_APPLY_TO 	89  	//ATTRIBUTE	Ascend-IP-TOS-Apply-To		89	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FILTER 	90  	//ATTRIBUTE	Ascend-Filter			90	string	Ascend
#define 	 ATTRIBUTE_ASCEND_TELNET_PROFILE 	91  	//ATTRIBUTE	Ascend-Telnet-Profile		91	string	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_RATE_TYPE 	92  	//ATTRIBUTE	Ascend-Dsl-Rate-Type		92	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_REDIRECT_NUMBER 	93  	//ATTRIBUTE	Ascend-Redirect-Number		93	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_VPI 	94  	//ATTRIBUTE	Ascend-ATM-Vpi			94	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ATM_VCI 	95  	//ATTRIBUTE	Ascend-ATM-Vci			95	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SOURCE_IP_CHECK 	96  	//ATTRIBUTE	Ascend-Source-IP-Check		96	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_RATE_MODE 	97  	//ATTRIBUTE	Ascend-Dsl-Rate-Mode		97	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_UPSTREAM_LIMIT 	98  	//ATTRIBUTE	Ascend-Dsl-Upstream-Limit	98	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_DOWNSTREAM_LIMIT 	99  	//ATTRIBUTE	Ascend-Dsl-Downstream-Limit	99	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_CIR_RECV_LIMIT 	100  	//ATTRIBUTE	Ascend-Dsl-CIR-Recv-Limit	100	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DSL_CIR_XMIT_LIMIT 	101  	//ATTRIBUTE	Ascend-Dsl-CIR-Xmit-Limit	101	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_VROUTER_NAME 	102  	//ATTRIBUTE	Ascend-VRouter-Name		102	string	Ascend
#define 	 ATTRIBUTE_ASCEND_SOURCE_AUTH 	103  	//ATTRIBUTE	Ascend-Source-Auth		103	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PRIVATE_ROUTE 	104  	//ATTRIBUTE	Ascend-Private-Route		104	string	Ascend
#define 	 ATTRIBUTE_ASCEND_NUMBERING_PLAN_ID 	105  	//ATTRIBUTE	Ascend-Numbering-Plan-ID	105	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_LINK_STATUS_DLCI 	106  	//ATTRIBUTE	Ascend-FR-Link-Status-DLCI	106	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLING_SUBADDRESS 	107  	//ATTRIBUTE	Ascend-Calling-Subaddress	107	string	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLBACK_DELAY 	108  	//ATTRIBUTE	Ascend-Callback-Delay		108	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ENDPOINT_DISC 	109  	//ATTRIBUTE	Ascend-Endpoint-Disc		109	string	Ascend
#define 	 ATTRIBUTE_ASCEND_REMOTE_FW 	110  	//ATTRIBUTE	Ascend-Remote-FW		110	string	Ascend
#define 	 ATTRIBUTE_ASCEND_MULTICAST_GLEAVE_DELAY 	111  	//ATTRIBUTE	Ascend-Multicast-GLeave-Delay	111	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CBCP_ENABLE 	112  	//ATTRIBUTE	Ascend-CBCP-Enable		112	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CBCP_MODE 	113  	//ATTRIBUTE	Ascend-CBCP-Mode		113	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CBCP_DELAY 	114  	//ATTRIBUTE	Ascend-CBCP-Delay		114	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CBCP_TRUNK_GROUP 	115  	//ATTRIBUTE	Ascend-CBCP-Trunk-Group		115	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_APPLETALK_ROUTE 	116  	//ATTRIBUTE	Ascend-Appletalk-Route		116	string	Ascend
#define 	 ATTRIBUTE_ASCEND_APPLETALK_PEER_MODE 	117  	//ATTRIBUTE	Ascend-Appletalk-Peer-Mode	117	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ROUTE_APPLETALK 	118  	//ATTRIBUTE	Ascend-Route-Appletalk		118	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FCP_PARAMETER 	119  	//ATTRIBUTE	Ascend-FCP-Parameter		119	string	Ascend
#define 	 ATTRIBUTE_ASCEND_MODEM_PORTNO 	120  	//ATTRIBUTE	Ascend-Modem-PortNo		120	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MODEM_SLOTNO 	121  	//ATTRIBUTE	Ascend-Modem-SlotNo		121	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MODEM_SHELFNO 	122  	//ATTRIBUTE	Ascend-Modem-ShelfNo		122	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALL_ATTEMPT_LIMIT 	123  	//ATTRIBUTE	Ascend-Call-Attempt-Limit	123	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALL_BLOCK_DURATION 	124  	//ATTRIBUTE	Ascend-Call-Block-Duration	124	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MAXIMUM_CALL_DURATION 	125  	//ATTRIBUTE	Ascend-Maximum-Call-Duration	125	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TEMPORARY_RTES 	126  	//ATTRIBUTE	Ascend-Temporary-Rtes		126	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TUNNELING_PROTOCOL 	127  	//ATTRIBUTE	Ascend-Tunneling-Protocol	127	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SHARED_PROFILE_ENABLE 	128  	//ATTRIBUTE	Ascend-Shared-Profile-Enable	128	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRIMARY_HOME_AGENT 	129  	//ATTRIBUTE	Ascend-Primary-Home-Agent	129	string	Ascend
#define 	 ATTRIBUTE_ASCEND_SECONDARY_HOME_AGENT 	130  	//ATTRIBUTE	Ascend-Secondary-Home-Agent	130	string	Ascend
#define 	 ATTRIBUTE_ASCEND_DIALOUT_ALLOWED 	131  	//ATTRIBUTE	Ascend-Dialout-Allowed		131	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_GATEWAY 	132  	//ATTRIBUTE	Ascend-Client-Gateway		132	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_BACP_ENABLE 	133  	//ATTRIBUTE	Ascend-BACP-Enable		133	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DHCP_MAXIMUM_LEASES 	134  	//ATTRIBUTE	Ascend-DHCP-Maximum-Leases	134	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_PRIMARY_DNS 	135  	//ATTRIBUTE	Ascend-Client-Primary-DNS	135	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_SECONDARY_DNS 	136  	//ATTRIBUTE	Ascend-Client-Secondary-DNS	136	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_CLIENT_ASSIGN_DNS 	137  	//ATTRIBUTE	Ascend-Client-Assign-DNS	137	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_TYPE 	138  	//ATTRIBUTE	Ascend-User-Acct-Type		138	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_HOST 	139  	//ATTRIBUTE	Ascend-User-Acct-Host		139	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_PORT 	140  	//ATTRIBUTE	Ascend-User-Acct-Port		140	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_KEY 	141  	//ATTRIBUTE	Ascend-User-Acct-Key		141	string	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_BASE 	142  	//ATTRIBUTE	Ascend-User-Acct-Base		142	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_USER_ACCT_TIME 	143  	//ATTRIBUTE	Ascend-User-Acct-Time		143	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ASSIGN_IP_CLIENT 	144  	//ATTRIBUTE	Ascend-Assign-IP-Client		144	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_ASSIGN_IP_SERVER 	145  	//ATTRIBUTE	Ascend-Assign-IP-Server		145	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_ASSIGN_IP_GLOBAL_POOL 	146  	//ATTRIBUTE	Ascend-Assign-IP-Global-Pool	146	string	Ascend
#define 	 ATTRIBUTE_ASCEND_DHCP_REPLY 	147  	//ATTRIBUTE	Ascend-DHCP-Reply		147	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DHCP_POOL_NUMBER 	148  	//ATTRIBUTE	Ascend-DHCP-Pool-Number		148	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_EXPECT_CALLBACK 	149  	//ATTRIBUTE	Ascend-Expect-Callback		149	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_EVENT_TYPE 	150  	//ATTRIBUTE	Ascend-Event-Type		150	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SESSION_SVR_KEY 	151  	//ATTRIBUTE	Ascend-Session-Svr-Key		151	string	Ascend
#define 	 ATTRIBUTE_ASCEND_MULTICAST_RATE_LIMIT 	152  	//ATTRIBUTE	Ascend-Multicast-Rate-Limit	152	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IF_NETMASK 	153  	//ATTRIBUTE	Ascend-IF-Netmask		153	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_REMOTE_ADDR 	154  	//ATTRIBUTE	Ascend-Remote-Addr		154	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_MULTICAST_CLIENT 	155  	//ATTRIBUTE	Ascend-Multicast-Client		155	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_CIRCUIT_NAME 	156  	//ATTRIBUTE	Ascend-FR-Circuit-Name		156	string	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_LINKUP 	157  	//ATTRIBUTE	Ascend-FR-LinkUp		157	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_NAILED_GRP 	158  	//ATTRIBUTE	Ascend-FR-Nailed-Grp		158	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_TYPE 	159  	//ATTRIBUTE	Ascend-FR-Type			159	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_LINK_MGT 	160  	//ATTRIBUTE	Ascend-FR-Link-Mgt		160	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_N391 	161  	//ATTRIBUTE	Ascend-FR-N391			161	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DCE_N392 	162  	//ATTRIBUTE	Ascend-FR-DCE-N392		162	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DTE_N392 	163  	//ATTRIBUTE	Ascend-FR-DTE-N392		163	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DCE_N393 	164  	//ATTRIBUTE	Ascend-FR-DCE-N393		164	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DTE_N393 	165  	//ATTRIBUTE	Ascend-FR-DTE-N393		165	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_T391 	166  	//ATTRIBUTE	Ascend-FR-T391			166	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_T392 	167  	//ATTRIBUTE	Ascend-FR-T392			167	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BRIDGE_ADDRESS 	168  	//ATTRIBUTE	Ascend-Bridge-Address		168	string	Ascend
#define 	 ATTRIBUTE_ASCEND_TS_IDLE_LIMIT 	169  	//ATTRIBUTE	Ascend-TS-Idle-Limit		169	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TS_IDLE_MODE 	170  	//ATTRIBUTE	Ascend-TS-Idle-Mode		170	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DBA_MONITOR 	171  	//ATTRIBUTE	Ascend-DBA-Monitor		171	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BASE_CHANNEL_COUNT 	172  	//ATTRIBUTE	Ascend-Base-Channel-Count	172	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MINIMUM_CHANNELS 	173  	//ATTRIBUTE	Ascend-Minimum-Channels		173	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IPX_ROUTE 	174  	//ATTRIBUTE	Ascend-IPX-Route		174	string	Ascend
#define 	 ATTRIBUTE_ASCEND_FT1_CALLER 	175  	//ATTRIBUTE	Ascend-FT1-Caller		175	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BACKUP 	176  	//ATTRIBUTE	Ascend-Backup			176	string	Ascend
#define 	 ATTRIBUTE_ASCEND_CALL_TYPE 	177  	//ATTRIBUTE	Ascend-Call-Type		177	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_GROUP 	178  	//ATTRIBUTE	Ascend-Group			178	string	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DLCI 	179  	//ATTRIBUTE	Ascend-FR-DLCI			179	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_PROFILE_NAME 	180  	//ATTRIBUTE	Ascend-FR-Profile-Name		180	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ARA_PW 	181  	//ATTRIBUTE	Ascend-Ara-PW			181	string	Ascend
#define 	 ATTRIBUTE_ASCEND_IPX_NODE_ADDR 	182  	//ATTRIBUTE	Ascend-IPX-Node-Addr		182	string	Ascend
#define 	 ATTRIBUTE_ASCEND_HOME_AGENT_IP_ADDR 	183  	//ATTRIBUTE	Ascend-Home-Agent-IP-Addr	183	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_HOME_AGENT_PASSWORD 	184  	//ATTRIBUTE	Ascend-Home-Agent-Password	184	string	Ascend
#define 	 ATTRIBUTE_ASCEND_HOME_NETWORK_NAME 	185  	//ATTRIBUTE	Ascend-Home-Network-Name	185	string	Ascend
#define 	 ATTRIBUTE_ASCEND_HOME_AGENT_UDP_PORT 	186  	//ATTRIBUTE	Ascend-Home-Agent-UDP-Port	186	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MULTILINK_ID 	187  	//ATTRIBUTE	Ascend-Multilink-ID		187	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_NUM_IN_MULTILINK 	188  	//ATTRIBUTE	Ascend-Num-In-Multilink		188	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FIRST_DEST 	189  	//ATTRIBUTE	Ascend-First-Dest		189	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_PRE_INPUT_OCTETS 	190  	//ATTRIBUTE	Ascend-Pre-Input-Octets		190	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRE_OUTPUT_OCTETS 	191  	//ATTRIBUTE	Ascend-Pre-Output-Octets	191	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRE_INPUT_PACKETS 	192  	//ATTRIBUTE	Ascend-Pre-Input-Packets	192	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRE_OUTPUT_PACKETS 	193  	//ATTRIBUTE	Ascend-Pre-Output-Packets	193	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MAXIMUM_TIME 	194  	//ATTRIBUTE	Ascend-Maximum-Time		194	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DISCONNECT_CAUSE 	195  	//ATTRIBUTE	Ascend-Disconnect-Cause		195	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CONNECT_PROGRESS 	196  	//ATTRIBUTE	Ascend-Connect-Progress		196	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DATA_RATE 	197  	//ATTRIBUTE	Ascend-Data-Rate		197	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRESESSION_TIME 	198  	//ATTRIBUTE	Ascend-PreSession-Time		198	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TOKEN_IDLE 	199  	//ATTRIBUTE	Ascend-Token-Idle		199	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TOKEN_IMMEDIATE 	200  	//ATTRIBUTE	Ascend-Token-Immediate		200	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_REQUIRE_AUTH 	201  	//ATTRIBUTE	Ascend-Require-Auth		201	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_NUMBER_SESSIONS 	202  	//ATTRIBUTE	Ascend-Number-Sessions		202	string	Ascend
#define 	 ATTRIBUTE_ASCEND_AUTHEN_ALIAS 	203  	//ATTRIBUTE	Ascend-Authen-Alias		203	string	Ascend
#define 	 ATTRIBUTE_ASCEND_TOKEN_EXPIRY 	204  	//ATTRIBUTE	Ascend-Token-Expiry		204	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MENU_SELECTOR 	205  	//ATTRIBUTE	Ascend-Menu-Selector		205	string	Ascend
#define 	 ATTRIBUTE_ASCEND_MENU_ITEM 	206  	//ATTRIBUTE	Ascend-Menu-Item		206	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PW_WARNTIME 	207  	//ATTRIBUTE	Ascend-PW-Warntime		207	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PW_LIFETIME 	208  	//ATTRIBUTE	Ascend-PW-Lifetime		208	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_DIRECT 	209  	//ATTRIBUTE	Ascend-IP-Direct		209	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_PPP_VJ_SLOT_COMP 	210  	//ATTRIBUTE	Ascend-PPP-VJ-Slot-Comp		210	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PPP_VJ_1172 	211  	//ATTRIBUTE	Ascend-PPP-VJ-1172		211	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PPP_ASYNC_MAP 	212  	//ATTRIBUTE	Ascend-PPP-Async-Map		212	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_THIRD_PROMPT 	213  	//ATTRIBUTE	Ascend-Third-Prompt		213	string	Ascend
#define 	 ATTRIBUTE_ASCEND_SEND_SECRET 	214  	//ATTRIBUTE	Ascend-Send-Secret		214	string	Ascend
#define 	 ATTRIBUTE_ASCEND_RECEIVE_SECRET 	215  	//ATTRIBUTE	Ascend-Receive-Secret		215	string	Ascend
#define 	 ATTRIBUTE_ASCEND_IPX_PEER_MODE 	216  	//ATTRIBUTE	Ascend-IPX-Peer-Mode		216	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IP_POOL_DEFINITION 	217  	//ATTRIBUTE	Ascend-IP-Pool-Definition	217	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ASSIGN_IP_POOL 	218  	//ATTRIBUTE	Ascend-Assign-IP-Pool		218	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DIRECT 	219  	//ATTRIBUTE	Ascend-FR-Direct		219	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DIRECT_PROFILE 	220  	//ATTRIBUTE	Ascend-FR-Direct-Profile	220	string	Ascend
#define 	 ATTRIBUTE_ASCEND_FR_DIRECT_DLCI 	221  	//ATTRIBUTE	Ascend-FR-Direct-DLCI		221	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_HANDLE_IPX 	222  	//ATTRIBUTE	Ascend-Handle-IPX		222	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_NETWARE_TIMEOUT 	223  	//ATTRIBUTE	Ascend-Netware-timeout		223	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IPX_ALIAS 	224  	//ATTRIBUTE	Ascend-IPX-Alias		224	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_METRIC 	225  	//ATTRIBUTE	Ascend-Metric			225	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PRI_NUMBER_TYPE 	226  	//ATTRIBUTE	Ascend-PRI-Number-Type		226	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DIAL_NUMBER 	227  	//ATTRIBUTE	Ascend-Dial-Number		227	string	Ascend
#define 	 ATTRIBUTE_ASCEND_ROUTE_IP 	228  	//ATTRIBUTE	Ascend-Route-IP			228	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ROUTE_IPX 	229  	//ATTRIBUTE	Ascend-Route-IPX		229	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BRIDGE 	230  	//ATTRIBUTE	Ascend-Bridge			230	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SEND_AUTH 	231  	//ATTRIBUTE	Ascend-Send-Auth		231	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SEND_PASSWD 	232  	//ATTRIBUTE	Ascend-Send-Passwd		232	string	Ascend
#define 	 ATTRIBUTE_ASCEND_LINK_COMPRESSION 	233  	//ATTRIBUTE	Ascend-Link-Compression		233	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TARGET_UTIL 	234  	//ATTRIBUTE	Ascend-Target-Util		234	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_MAXIMUM_CHANNELS 	235  	//ATTRIBUTE	Ascend-Maximum-Channels		235	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_INC_CHANNEL_COUNT 	236  	//ATTRIBUTE	Ascend-Inc-Channel-Count	236	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DEC_CHANNEL_COUNT 	237  	//ATTRIBUTE	Ascend-Dec-Channel-Count	237	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_SECONDS_OF_HISTORY 	238  	//ATTRIBUTE	Ascend-Seconds-Of-History	238	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_HISTORY_WEIGH_TYPE 	239  	//ATTRIBUTE	Ascend-History-Weigh-Type	239	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_ADD_SECONDS 	240  	//ATTRIBUTE	Ascend-Add-Seconds		240	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_REMOVE_SECONDS 	241  	//ATTRIBUTE	Ascend-Remove-Seconds		241	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_IDLE_LIMIT 	244  	//ATTRIBUTE	Ascend-Idle-Limit		244	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_PREEMPT_LIMIT 	245  	//ATTRIBUTE	Ascend-Preempt-Limit		245	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_CALLBACK 	246  	//ATTRIBUTE	Ascend-Callback			246	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_DATA_SVC 	247  	//ATTRIBUTE	Ascend-Data-Svc			247	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_FORCE_56 	248  	//ATTRIBUTE	Ascend-Force-56			248	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_BILLING_NUMBER 	249  	//ATTRIBUTE	Ascend-Billing-Number		249	string	Ascend
#define 	 ATTRIBUTE_ASCEND_CALL_BY_CALL 	250  	//ATTRIBUTE	Ascend-Call-By-Call		250	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_TRANSIT_NUMBER 	251  	//ATTRIBUTE	Ascend-Transit-Number		251	string	Ascend
#define 	 ATTRIBUTE_ASCEND_HOST_INFO 	252  	//ATTRIBUTE	Ascend-Host-Info		252	string	Ascend
#define 	 ATTRIBUTE_ASCEND_PPP_ADDRESS 	253  	//ATTRIBUTE	Ascend-PPP-Address		253	ipaddr	Ascend
#define 	 ATTRIBUTE_ASCEND_MPP_IDLE_PERCENT 	254  	//ATTRIBUTE	Ascend-MPP-Idle-Percent		254	integer	Ascend
#define 	 ATTRIBUTE_ASCEND_XMIT_RATE 	255  	//ATTRIBUTE	Ascend-Xmit-Rate		255	integer	Ascend
#define 	 ATTRIBUTE_KARLNET_TURBOCELL_NAME 	151  	//ATTRIBUTE	KarlNet-TurboCell-Name		151	string	KarlNet
#define 	 ATTRIBUTE_KARLNET_TURBOCELL_TXRATE 	152  	//ATTRIBUTE	KarlNet-TurboCell-TxRate	152	integer	KarlNet
#define 	 ATTRIBUTE_KARLNET_TURBOCELL_OPSTATE 	153  	//ATTRIBUTE	KarlNet-TurboCell-OpState	153	integer	KarlNet
#define 	 ATTRIBUTE_KARLNET_TURBOCELL_OPMODE 	154  	//ATTRIBUTE	KarlNet-TurboCell-OpMode	154	integer	KarlNet
#define 	 ATTRIBUTE_XEDIA_DNS_SERVER 	1  	//ATTRIBUTE	Xedia-DNS-Server		1	ipaddr	Xedia
#define 	 ATTRIBUTE_XEDIA_NETBIOS_SERVER 	2  	//ATTRIBUTE	Xedia-NetBios-Server		2	ipaddr	Xedia
#define 	 ATTRIBUTE_XEDIA_ADDRESS_POOL 	3  	//ATTRIBUTE	Xedia-Address-Pool		3	string	Xedia
#define 	 ATTRIBUTE_XEDIA_PPP_ECHO_INTERVAL 	4  	//ATTRIBUTE	Xedia-PPP-Echo-Interval		4	integer	Xedia
#define 	 ATTRIBUTE_XEDIA_SSH_PRIVILEGES 	5  	//ATTRIBUTE	Xedia-SSH-Privileges		5	integer	Xedia
#define 	 ATTRIBUTE_XEDIA_CLIENT_ACCESS_NETWORK 	6  	//ATTRIBUTE	Xedia-Client-Access-Network	6	string	Xedia
#define 	 ATTRIBUTE_ITK_AUTH_SERV_IP 	100  	//ATTRIBUTE	ITK-Auth-Serv-IP		100	ipaddr	ITK
#define 	 ATTRIBUTE_ITK_AUTH_SERV_PROT 	101  	//ATTRIBUTE	ITK-Auth-Serv-Prot		101	integer	ITK
#define 	 ATTRIBUTE_ITK_PROVIDER_ID 	102  	//ATTRIBUTE	ITK-Provider-Id			102	integer	ITK
#define 	 ATTRIBUTE_ITK_USERGROUP 	103  	//ATTRIBUTE	ITK-Usergroup			103	integer	ITK
#define 	 ATTRIBUTE_ITK_BANNER 	104  	//ATTRIBUTE	ITK-Banner			104	string	ITK
#define 	 ATTRIBUTE_ITK_USERNAME_PROMPT 	105  	//ATTRIBUTE	ITK-Username-Prompt		105	string	ITK
#define 	 ATTRIBUTE_ITK_PASSWORD_PROMPT 	106  	//ATTRIBUTE	ITK-Password-Prompt		106	string	ITK
#define 	 ATTRIBUTE_ITK_WELCOME_MESSAGE 	107  	//ATTRIBUTE	ITK-Welcome-Message		107	string	ITK
#define 	 ATTRIBUTE_ITK_PROMPT 	108  	//ATTRIBUTE	ITK-Prompt			108	string	ITK
#define 	 ATTRIBUTE_ITK_IP_POOL 	109  	//ATTRIBUTE	ITK-IP-Pool			109	integer	ITK
#define 	 ATTRIBUTE_ITK_TUNNEL_IP 	110  	//ATTRIBUTE	ITK-Tunnel-IP			110	ipaddr	ITK
#define 	 ATTRIBUTE_ITK_TUNNEL_PROT 	111  	//ATTRIBUTE	ITK-Tunnel-Prot			111	integer	ITK
#define 	 ATTRIBUTE_ITK_ACCT_SERV_IP 	112  	//ATTRIBUTE	ITK-Acct-Serv-IP		112	ipaddr	ITK
#define 	 ATTRIBUTE_ITK_ACCT_SERV_PROT 	113  	//ATTRIBUTE	ITK-Acct-Serv-Prot		113	integer	ITK
#define 	 ATTRIBUTE_ITK_FILTER_RULE 	114  	//ATTRIBUTE	ITK-Filter-Rule			114	string	ITK
#define 	 ATTRIBUTE_ITK_CHANNEL_BINDING 	115  	//ATTRIBUTE	ITK-Channel-Binding		115	integer	ITK
#define 	 ATTRIBUTE_ITK_START_DELAY 	116  	//ATTRIBUTE	ITK-Start-Delay			116	integer	ITK
#define 	 ATTRIBUTE_ITK_NAS_NAME 	117  	//ATTRIBUTE	ITK-NAS-Name			117	string	ITK
#define 	 ATTRIBUTE_ITK_ISDN_PROT 	118  	//ATTRIBUTE	ITK-ISDN-Prot			118	integer	ITK
#define 	 ATTRIBUTE_ITK_PPP_AUTH_TYPE 	119  	//ATTRIBUTE	ITK-PPP-Auth-Type		119	integer	ITK
#define 	 ATTRIBUTE_ITK_DIALOUT_TYPE 	120  	//ATTRIBUTE	ITK-Dialout-Type		120	integer	ITK
#define 	 ATTRIBUTE_ITK_FTP_AUTH_IP 	121  	//ATTRIBUTE	ITK-Ftp-Auth-IP			121	ipaddr	ITK
#define 	 ATTRIBUTE_ITK_USERS_DEFAULT_ENTRY 	122  	//ATTRIBUTE	ITK-Users-Default-Entry		122	string	ITK
#define 	 ATTRIBUTE_ITK_USERS_DEFAULT_PW 	123  	//ATTRIBUTE	ITK-Users-Default-Pw		123	string	ITK
#define 	 ATTRIBUTE_ITK_AUTH_REQ_TYPE 	124  	//ATTRIBUTE	ITK-Auth-Req-Type		124	string	ITK
#define 	 ATTRIBUTE_ITK_MODEM_POOL_ID 	125  	//ATTRIBUTE	ITK-Modem-Pool-Id		125	integer	ITK
#define 	 ATTRIBUTE_ITK_MODEM_INIT_STRING 	126  	//ATTRIBUTE	ITK-Modem-Init-String		126	string	ITK
#define 	 ATTRIBUTE_ITK_PPP_CLIENT_SERVER_MODE 	127  	//ATTRIBUTE	ITK-PPP-Client-Server-Mode	127	integer	ITK
#define 	 ATTRIBUTE_ITK_PPP_COMPRESSION_PROT 	128  	//ATTRIBUTE	ITK-PPP-Compression-Prot	128	string	ITK
#define 	 ATTRIBUTE_ITK_USERNAME 	129  	//ATTRIBUTE	ITK-Username			129	string	ITK
#define 	 ATTRIBUTE_ITK_DEST_NO 	130  	//ATTRIBUTE	ITK-Dest-No			130	string	ITK
#define 	 ATTRIBUTE_ITK_DDI 	131  	//ATTRIBUTE	ITK-DDI				131	string	ITK
#define 	 ATTRIBUTE_ANNEX_FILTER 	28  	//ATTRIBUTE	Annex-Filter			28	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_CLI_COMMAND 	29  	//ATTRIBUTE	Annex-CLI-Command		29	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_CLI_FILTER 	30  	//ATTRIBUTE	Annex-CLI-Filter		30	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_HOST_RESTRICT 	31  	//ATTRIBUTE	Annex-Host-Restrict		31	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_HOST_ALLOW 	32  	//ATTRIBUTE	Annex-Host-Allow		32	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRODUCT_NAME 	33  	//ATTRIBUTE	Annex-Product-Name		33	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SW_VERSION 	34  	//ATTRIBUTE	Annex-SW-Version		34	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_LOCAL_IP_ADDRESS 	35  	//ATTRIBUTE	Annex-Local-IP-Address		35	ipaddr	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_CALLBACK_PORTLIST 	36  	//ATTRIBUTE	Annex-Callback-Portlist		36	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SEC_PROFILE_INDEX 	37  	//ATTRIBUTE	Annex-Sec-Profile-Index		37	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_TUNNEL_AUTHEN_TYPE 	38  	//ATTRIBUTE	Annex-Tunnel-Authen-Type	38	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_TUNNEL_AUTHEN_MODE 	39  	//ATTRIBUTE	Annex-Tunnel-Authen-Mode	39	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_AUTHEN_SERVERS 	40  	//ATTRIBUTE	Annex-Authen-Servers		40	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_ACCT_SERVERS 	41  	//ATTRIBUTE	Annex-Acct-Servers		41	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_USER_SERVER_LOCATION 	42  	//ATTRIBUTE	Annex-User-Server-Location	42	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_LOCAL_USERNAME 	43  	//ATTRIBUTE	Annex-Local-Username		43	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SYSTEM_DISC_REASON 	44  	//ATTRIBUTE	Annex-System-Disc-Reason	44	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_MODEM_DISC_REASON 	45  	//ATTRIBUTE	Annex-Modem-Disc-Reason		45	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_DISCONNECT_REASON 	46  	//ATTRIBUTE	Annex-Disconnect-Reason		46	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_ADDR_RESOLUTION_PROTOCOL 	47  	//ATTRIBUTE	Annex-Addr-Resolution-Protocol	47	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_ADDR_RESOLUTION_SERVERS 	48  	//ATTRIBUTE	Annex-Addr-Resolution-Servers	48	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_DOMAIN_NAME 	49  	//ATTRIBUTE	Annex-Domain-Name		49	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_TRANSMIT_SPEED 	50  	//ATTRIBUTE	Annex-Transmit-Speed		50	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RECEIVE_SPEED 	51  	//ATTRIBUTE	Annex-Receive-Speed		51	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_INPUT_FILTER 	52  	//ATTRIBUTE	Annex-Input-Filter		52	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_OUTPUT_FILTER 	53  	//ATTRIBUTE	Annex-Output-Filter		53	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRIMARY_DNS_SERVER 	54  	//ATTRIBUTE	Annex-Primary-DNS-Server	54	ipaddr	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SECONDARY_DNS_SERVER 	55  	//ATTRIBUTE	Annex-Secondary-DNS-Server	55	ipaddr	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRIMARY_NBNS_SERVER 	56  	//ATTRIBUTE	Annex-Primary-NBNS-Server	56	ipaddr	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SECONDARY_NBNS_SERVER 	57  	//ATTRIBUTE	Annex-Secondary-NBNS-Server	57	ipaddr	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SYSLOG_TAP 	58  	//ATTRIBUTE	Annex-Syslog-Tap		58	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_KEYPRESS_TIMEOUT 	59  	//ATTRIBUTE	Annex-Keypress-Timeout		59	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_UNAUTHENTICATED_TIME 	60  	//ATTRIBUTE	Annex-Unauthenticated-Time	60	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RE_CHAP_TIMEOUT 	61  	//ATTRIBUTE	Annex-Re-CHAP-Timeout		61	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_MRRU 	62  	//ATTRIBUTE	Annex-MRRU			62	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_EDO 	63  	//ATTRIBUTE	Annex-EDO			63	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PPP_TRACE_LEVEL 	64  	//ATTRIBUTE	Annex-PPP-Trace-Level		64	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRE_INPUT_OCTETS 	65  	//ATTRIBUTE	Annex-Pre-Input-Octets		65	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRE_OUTPUT_OCTETS 	66  	//ATTRIBUTE	Annex-Pre-Output-Octets		66	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRE_INPUT_PACKETS 	67  	//ATTRIBUTE	Annex-Pre-Input-Packets		67	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PRE_OUTPUT_PACKETS 	68  	//ATTRIBUTE	Annex-Pre-Output-Packets	68	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_CONNECT_PROGRESS 	69  	//ATTRIBUTE	Annex-Connect-Progress		69	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_MULTICAST_RATE_LIMIT 	73  	//ATTRIBUTE	Annex-Multicast-Rate-Limit	73	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_MAXIMUM_CALL_DURATION 	74  	//ATTRIBUTE	Annex-Maximum-Call-Duration	74	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_MULTILINK_ID 	75  	//ATTRIBUTE	Annex-Multilink-Id		75	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_NUM_IN_MULTILINK 	76  	//ATTRIBUTE	Annex-Num-In-Multilink		76	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_LOGICAL_CHANNEL_NUMBER 	81  	//ATTRIBUTE	Annex-Logical-Channel-Number	81	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_WAN_NUMBER 	82  	//ATTRIBUTE	Annex-Wan-Number		82	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_PORT 	83  	//ATTRIBUTE	Annex-Port			83	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_POOL_ID 	85  	//ATTRIBUTE	Annex-Pool-Id			85	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_COMPRESSION_PROTOCOL 	86  	//ATTRIBUTE	Annex-Compression-Protocol	86	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_TRANSMITTED_PACKETS 	87  	//ATTRIBUTE	Annex-Transmitted-Packets	87	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RETRANSMITTED_PACKETS 	88  	//ATTRIBUTE	Annex-Retransmitted-Packets	88	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_SIGNAL_TO_NOISE_RATIO 	89  	//ATTRIBUTE	Annex-Signal-to-Noise-Ratio	89	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RETRAIN_REQUESTS_SENT 	90  	//ATTRIBUTE	Annex-Retrain-Requests-Sent	90	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RETRAIN_REQUESTS_RCVD 	91  	//ATTRIBUTE	Annex-Retrain-Requests-Rcvd	91	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RATE_RENEG_REQ_SENT 	92  	//ATTRIBUTE	Annex-Rate-Reneg-Req-Sent	92	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_RATE_RENEG_REQ_RCVD 	93  	//ATTRIBUTE	Annex-Rate-Reneg-Req-Rcvd	93	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_BEGIN_RECEIVE_LINE_LEVEL 	94  	//ATTRIBUTE	Annex-Begin-Receive-Line-Level	94	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_END_RECEIVE_LINE_LEVEL 	95  	//ATTRIBUTE	Annex-End-Receive-Line-Level	95	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_BEGIN_MODULATION 	96  	//ATTRIBUTE	Annex-Begin-Modulation		96	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_ERROR_CORRECTION_PROT 	97  	//ATTRIBUTE	Annex-Error-Correction-Prot	97	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_END_MODULATION 	98  	//ATTRIBUTE	Annex-End-Modulation		98	string	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_USER_LEVEL 	100  	//ATTRIBUTE	Annex-User-Level		100	integer	Bay-Networks
#define 	 ATTRIBUTE_ANNEX_AUDIT_LEVEL 	101  	//ATTRIBUTE	Annex-Audit-Level		101	integer	Bay-Networks
#define 	 ATTRIBUTE_ALTEON_SERVICE_TYPE 	26  	//ATTRIBUTE	Alteon-Service-Type		26	integer	Alteon
#define 	 ATTRIBUTE_EXTREME_NETLOGIN_VLAN 	203  	//ATTRIBUTE	Extreme-Netlogin-Vlan		203	string	Extreme
#define 	 ATTRIBUTE_EXTREME_NETLOGIN_URL 	204  	//ATTRIBUTE	Extreme-Netlogin-Url		204	string	Extreme
#define 	 ATTRIBUTE_EXTREME_NETLOGIN_URL_DESC 	205  	//ATTRIBUTE	Extreme-Netlogin-Url-Desc	205	string	Extreme
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_IP_ADDR 	5  	//ATTRIBUTE	RedCreek-Tunneled-IP-Addr	5	ipaddr	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_IP_NETMASK 	6  	//ATTRIBUTE	RedCreek-Tunneled-IP-Netmask	6	ipaddr	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_GATEWAY 	7  	//ATTRIBUTE	RedCreek-Tunneled-Gateway	7	ipaddr	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_DNS_SERVER 	8  	//ATTRIBUTE	RedCreek-Tunneled-DNS-Server	8	string	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_WINS_SERVER1 	9  	//ATTRIBUTE	RedCreek-Tunneled-WINS-Server1	9	string	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_WINS_SERVER2 	10  	//ATTRIBUTE	RedCreek-Tunneled-WINS-Server2	10	string	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_HOSTNAME 	11  	//ATTRIBUTE	RedCreek-Tunneled-HostName	11	string	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_DOMAINNAME 	12  	//ATTRIBUTE	RedCreek-Tunneled-DomainName	12	string	RedCreek
#define 	 ATTRIBUTE_REDCREEK_TUNNELED_SEARCH_LIST 	13  	//ATTRIBUTE	RedCreek-Tunneled-Search-List	13	string	RedCreek
#define 	 ATTRIBUTE_FOUNDRY_PRIVILEGE_LEVEL 	1  	//ATTRIBUTE	Foundry-Privilege-Level		1	integer	Foundry
#define 	 ATTRIBUTE_FOUNDRY_COMMAND_STRING 	2  	//ATTRIBUTE	Foundry-Command-String		2	string	Foundry
#define 	 ATTRIBUTE_FOUNDRY_COMMAND_EXCEPTION_FLAG 	3  	//ATTRIBUTE	Foundry-Command-Exception-Flag	3	integer	Foundry
#define 	 ATTRIBUTE_VERSANET_TERMINATION_CAUSE 	1  	//ATTRIBUTE	Versanet-Termination-Cause	1	integer	Versanet
#define 	 ATTRIBUTE_CLIENT_DNS_PRI 	1  	//ATTRIBUTE	Client-DNS-Pri			1	ipaddr	Redback
#define 	 ATTRIBUTE_CLIENT_DNS_SEC 	2  	//ATTRIBUTE	Client-DNS-Sec			2	ipaddr	Redback
#define 	 ATTRIBUTE_DHCP_MAX_LEASES 	3  	//ATTRIBUTE	DHCP-Max-Leases			3	integer	Redback
#define 	 ATTRIBUTE_CONTEXT_NAME 	4  	//ATTRIBUTE	Context-Name			4	string	Redback
#define 	 ATTRIBUTE_BRIDGE_GROUP 	5  	//ATTRIBUTE	Bridge-Group			5	string	Redback
#define 	 ATTRIBUTE_BG_AGING_TIME 	6  	//ATTRIBUTE	BG-Aging-Time			6	string	Redback
#define 	 ATTRIBUTE_BG_PATH_COST 	7  	//ATTRIBUTE	BG-Path-Cost			7	string	Redback
#define 	 ATTRIBUTE_BG_SPAN_DIS 	8  	//ATTRIBUTE	BG-Span-Dis			8	string	Redback
#define 	 ATTRIBUTE_BG_TRANS_BPDU 	9  	//ATTRIBUTE	BG-Trans-BPDU			9	string	Redback
#define 	 ATTRIBUTE_RATE_LIMIT_RATE 	10  	//ATTRIBUTE	Rate-Limit-Rate			10	integer	Redback
#define 	 ATTRIBUTE_RATE_LIMIT_BURST 	11  	//ATTRIBUTE	Rate-Limit-Burst		11	integer	Redback
#define 	 ATTRIBUTE_POLICE_RATE 	12  	//ATTRIBUTE	Police-Rate			12	integer	Redback
#define 	 ATTRIBUTE_POLICE_BURST 	13  	//ATTRIBUTE	Police-Burst			13	integer	Redback
#define 	 ATTRIBUTE_SOURCE_VALIDATION 	14  	//ATTRIBUTE	Source-Validation		14	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_DOMAIN 	15  	//ATTRIBUTE	Tunnel-Domain			15	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_LOCAL_NAME 	16  	//ATTRIBUTE	Tunnel-Local-Name		16	string	Redback
#define 	 ATTRIBUTE_TUNNEL_REMOTE_NAME 	17  	//ATTRIBUTE	Tunnel-Remote-Name		17	string	Redback
#define 	 ATTRIBUTE_TUNNEL_FUNCTION 	18  	//ATTRIBUTE	Tunnel-Function			18	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_MAX_SESSIONS 	21  	//ATTRIBUTE	Tunnel-Max-Sessions		21	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_MAX_TUNNELS 	22  	//ATTRIBUTE	Tunnel-Max-Tunnels		22	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_SESSION_AUTH 	23  	//ATTRIBUTE	Tunnel-Session-Auth		23	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_WINDOW 	24  	//ATTRIBUTE	Tunnel-Window			24	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_RETRANSMIT 	25  	//ATTRIBUTE	Tunnel-Retransmit		25	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_CMD_TIMEOUT 	26  	//ATTRIBUTE	Tunnel-Cmd-Timeout		26	integer	Redback
#define 	 ATTRIBUTE_PPPOE_URL 	27  	//ATTRIBUTE	PPPOE-URL			27	string	Redback
#define 	 ATTRIBUTE_PPPOE_MOTM 	28  	//ATTRIBUTE	PPPOE-MOTM			28	string	Redback
#define 	 ATTRIBUTE_TUNNEL_GROUP 	29  	//ATTRIBUTE	Tunnel-Group			29	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_CONTEXT 	30  	//ATTRIBUTE	Tunnel-Context			30	string	Redback
#define 	 ATTRIBUTE_TUNNEL_ALGORITHM 	31  	//ATTRIBUTE	Tunnel-Algorithm		31	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_DEADTIME 	32  	//ATTRIBUTE	Tunnel-Deadtime			32	integer	Redback
#define 	 ATTRIBUTE_MCAST_SEND 	33  	//ATTRIBUTE	Mcast-Send			33	integer	Redback
#define 	 ATTRIBUTE_MCAST_RECEIVE 	34  	//ATTRIBUTE	Mcast-Receive			34	integer	Redback
#define 	 ATTRIBUTE_MCAST_MAXGROUPS 	35  	//ATTRIBUTE	Mcast-MaxGroups			35	integer	Redback
#define 	 ATTRIBUTE_IP_ADDRESS_POOL_NAME 	36  	//ATTRIBUTE	Ip-Address-Pool-Name		36	string	Redback
#define 	 ATTRIBUTE_TUNNEL_DNIS 	37  	//ATTRIBUTE	Tunnel-DNIS			37	integer	Redback
#define 	 ATTRIBUTE_MEDIUM_TYPE 	38  	//ATTRIBUTE	Medium-Type			38	integer	Redback
#define 	 ATTRIBUTE_PVC_ENCAPSULATION_TYPE 	39  	//ATTRIBUTE	PVC-Encapsulation-Type		39	integer	Redback
#define 	 ATTRIBUTE_PVC_PROFILE_NAME 	40  	//ATTRIBUTE	PVC-Profile-Name		40	string	Redback
#define 	 ATTRIBUTE_PVC_CIRCUIT_PADDING 	41  	//ATTRIBUTE	PVC-Circuit-Padding		41	integer	Redback
#define 	 ATTRIBUTE_BIND_TYPE 	42  	//ATTRIBUTE	Bind-Type			42	integer	Redback
#define 	 ATTRIBUTE_BIND_AUTH_PROTOCOL 	43  	//ATTRIBUTE	Bind-Auth-Protocol		43	integer	Redback
#define 	 ATTRIBUTE_BIND_AUTH_MAX_SESSIONS 	44  	//ATTRIBUTE	Bind-Auth-Max-Sessions		44	integer	Redback
#define 	 ATTRIBUTE_BIND_BYPASS_BYPASS 	45  	//ATTRIBUTE	Bind-Bypass-Bypass		45	string	Redback
#define 	 ATTRIBUTE_BIND_AUTH_CONTEXT 	46  	//ATTRIBUTE	Bind-Auth-Context		46	string	Redback
#define 	 ATTRIBUTE_BIND_AUTH_SERVICE_GRP 	47  	//ATTRIBUTE	Bind-Auth-Service-Grp		47	string	Redback
#define 	 ATTRIBUTE_BIND_BYPASS_CONTEXT 	48  	//ATTRIBUTE	Bind-Bypass-Context		48	string	Redback
#define 	 ATTRIBUTE_BIND_INT_CONTEXT 	49  	//ATTRIBUTE	Bind-Int-Context		49	string	Redback
#define 	 ATTRIBUTE_BIND_TUN_CONTEXT 	50  	//ATTRIBUTE	Bind-Tun-Context		50	string	Redback
#define 	 ATTRIBUTE_BIND_SES_CONTEXT 	51  	//ATTRIBUTE	Bind-Ses-Context		51	string	Redback
#define 	 ATTRIBUTE_BIND_DOT1Q_SLOT 	52  	//ATTRIBUTE	Bind-Dot1q-Slot			52	integer	Redback
#define 	 ATTRIBUTE_BIND_DOT1Q_PORT 	53  	//ATTRIBUTE	Bind-Dot1q-Port			53	integer	Redback
#define 	 ATTRIBUTE_BIND_DOT1Q_VLAN_TAG_ID 	54  	//ATTRIBUTE	Bind-Dot1q-Vlan-Tag-Id		54	integer	Redback
#define 	 ATTRIBUTE_BIND_INT_INTERFACE_NAME 	55  	//ATTRIBUTE	Bind-Int-Interface-Name		55	string	Redback
#define 	 ATTRIBUTE_BIND_L2TP_TUNNEL_NAME 	56  	//ATTRIBUTE	Bind-L2TP-Tunnel-Name		56	string	Redback
#define 	 ATTRIBUTE_BIND_L2TP_FLOW_CONTROL 	57  	//ATTRIBUTE	Bind-L2TP-Flow-Control		57	integer	Redback
#define 	 ATTRIBUTE_BIND_SUB_USER_AT_CONTEXT 	58  	//ATTRIBUTE	Bind-Sub-User-At-Context	58	string	Redback
#define 	 ATTRIBUTE_BIND_SUB_PASSWORD 	59  	//ATTRIBUTE	Bind-Sub-Password		59	string	Redback
#define 	 ATTRIBUTE_IP_HOST_ADDR 	60  	//ATTRIBUTE	Ip-Host-Addr			60	string	Redback
#define 	 ATTRIBUTE_IP_TOS_FIELD 	61  	//ATTRIBUTE	IP-TOS-Field			61	integer	Redback
#define 	 ATTRIBUTE_NAS_REAL_PORT 	62  	//ATTRIBUTE	NAS-Real-Port			62	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_SESSION_AUTH_CTX 	63  	//ATTRIBUTE	Tunnel-Session-Auth-Ctx		63	string	Redback
#define 	 ATTRIBUTE_TUNNEL_SESSION_AUTH_SERVICE_GRP 	64  	//ATTRIBUTE	Tunnel-Session-Auth-Service-Grp	64	string	Redback
#define 	 ATTRIBUTE_TUNNEL_RATE_LIMIT_RATE 	65  	//ATTRIBUTE	Tunnel-Rate-Limit-Rate		65	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_RATE_LIMIT_BURST 	66  	//ATTRIBUTE	Tunnel-Rate-Limit-Burst		66	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_POLICE_RATE 	67  	//ATTRIBUTE	Tunnel-Police-Rate		67	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_POLICE_BURST 	68  	//ATTRIBUTE	Tunnel-Police-Burst		68	integer	Redback
#define 	 ATTRIBUTE_TUNNEL_L2F_SECOND_PASSWORD 	69  	//ATTRIBUTE	Tunnel-L2F-Second-Password	69	string	Redback
#define 	 ATTRIBUTE_ACCT_INPUT_OCTETS_64 	128  	//ATTRIBUTE	Acct-Input-Octets-64		128	string	Redback
#define 	 ATTRIBUTE_ACCT_OUTPUT_OCTETS_64 	129  	//ATTRIBUTE	Acct-Output-Octets-64		129	string	Redback
#define 	 ATTRIBUTE_ACCT_INPUT_PACKETS_64 	130  	//ATTRIBUTE	Acct-Input-Packets-64		130	string	Redback
#define 	 ATTRIBUTE_ACCT_OUTPUT_PACKETS_64 	131  	//ATTRIBUTE	Acct-Output-Packets-64		131	string	Redback
#define 	 ATTRIBUTE_ASSIGNED_IP_ADDRESS 	132  	//ATTRIBUTE	Assigned-IP-Address		132	ipaddr	Redback
#define 	 ATTRIBUTE_ACCT_MCAST_IN_OCTETS 	133  	//ATTRIBUTE	Acct-Mcast-In-Octets		133	integer	Redback
#define 	 ATTRIBUTE_ACCT_MCAST_OUT_OCTETS 	134  	//ATTRIBUTE	Acct-Mcast-Out-Octets		134	integer	Redback
#define 	 ATTRIBUTE_ACCT_MCAST_IN_PACKETS 	135  	//ATTRIBUTE	Acct-Mcast-In-Packets		135	integer	Redback
#define 	 ATTRIBUTE_ACCT_MCAST_OUT_PACKETS 	136  	//ATTRIBUTE	Acct-Mcast-Out-Packets		136	integer	Redback
#define 	 ATTRIBUTE_LAC_PORT 	137  	//ATTRIBUTE	LAC-Port			137	integer	Redback
#define 	 ATTRIBUTE_LAC_REAL_PORT 	138  	//ATTRIBUTE	LAC-Real-Port			138	integer	Redback
#define 	 ATTRIBUTE_LAC_PORT_TYPE 	139  	//ATTRIBUTE	LAC-Port-Type			139	integer	Redback
#define 	 ATTRIBUTE_LAC_REAL_PORT_TYPE 	140  	//ATTRIBUTE	LAC-Real-Port-Type		140	integer	Redback
#define 	 ATTRIBUTE_ACCT_DYN_AC_ENT 	141  	//ATTRIBUTE	Acct-Dyn-Ac-Ent			141	string	Redback
#define 	 ATTRIBUTE_SESSION_ERROR_CODE 	142  	//ATTRIBUTE	Session-Error-Code		142	integer	Redback
#define 	 ATTRIBUTE_SESSION_ERROR_MSG 	143  	//ATTRIBUTE	Session-Error-Msg		143	string	Redback
#define 	 ATTRIBUTE_JUNIPER_LOCAL_USER_NAME 	1  	//ATTRIBUTE	Juniper-Local-User-Name		1	string	Juniper
#define 	 ATTRIBUTE_JUNIPER_ALLOW_COMMANDS 	2  	//ATTRIBUTE	Juniper-Allow-Commands		2	string	Juniper
#define 	 ATTRIBUTE_JUNIPER_DENY_COMMANDS 	3  	//ATTRIBUTE	Juniper-Deny-Commands		3	string	Juniper
#define 	 ATTRIBUTE_JUNIPER_ALLOW_CONFIGURATION 	4  	//ATTRIBUTE	Juniper-Allow-Configuration	4	string	Juniper
#define 	 ATTRIBUTE_JUNIPER_DENY_CONFIGURATION 	5  	//ATTRIBUTE	Juniper-Deny-Configuration	5	string	Juniper
#define 	 ATTRIBUTE_CVX_IDENTIFICATION 	1  	//ATTRIBUTE	CVX-Identification		1	string	Aptis
#define 	 ATTRIBUTE_CVX_VPOP_ID 	2  	//ATTRIBUTE	CVX-VPOP-ID			2	integer	Aptis
#define 	 ATTRIBUTE_CVX_SS7_SESSION_ID_TYPE 	3  	//ATTRIBUTE	CVX-SS7-Session-ID-Type		3	integer	Aptis
#define 	 ATTRIBUTE_CVX_RADIUS_REDIRECT 	4  	//ATTRIBUTE	CVX-Radius-Redirect		4	integer	Aptis
#define 	 ATTRIBUTE_CVX_IPSVC_AZNLVL 	5  	//ATTRIBUTE	CVX-IPSVC-AZNLVL		5	integer	Aptis
#define 	 ATTRIBUTE_CVX_IPSVC_MASK 	6  	//ATTRIBUTE	CVX-IPSVC-Mask			6	integer	Aptis
#define 	 ATTRIBUTE_CVX_MULTILINK_MATCH_INFO 	7  	//ATTRIBUTE	CVX-Multilink-Match-Info	7	integer	Aptis
#define 	 ATTRIBUTE_CVX_MULTILINK_GROUP_NUMBER 	8  	//ATTRIBUTE	CVX-Multilink-Group-Number	8	integer	Aptis
#define 	 ATTRIBUTE_CVX_PPP_LOG_MASK 	9  	//ATTRIBUTE	CVX-PPP-Log-Mask		9	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_BEGIN_MODULATION 	10  	//ATTRIBUTE	CVX-Modem-Begin-Modulation	10	string	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_END_MODULATION 	11  	//ATTRIBUTE	CVX-Modem-End-Modulation	11	string	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_ERROR_CORRECTION 	12  	//ATTRIBUTE	CVX-Modem-Error-Correction	12	string	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_DATA_COMPRESSION 	13  	//ATTRIBUTE	CVX-Modem-Data-Compression	13	string	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_TX_PACKETS 	14  	//ATTRIBUTE	CVX-Modem-Tx-Packets		14	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_RETX_PACKETS 	15  	//ATTRIBUTE	CVX-Modem-ReTx-Packets		15	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_SNR 	16  	//ATTRIBUTE	CVX-Modem-SNR			16	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_LOCAL_RETRAINS 	17  	//ATTRIBUTE	CVX-Modem-Local-Retrains	17	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_REMOTE_RETRAINS 	18  	//ATTRIBUTE	CVX-Modem-Remote-Retrains	18	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_LOCAL_RATE_NEGS 	19  	//ATTRIBUTE	CVX-Modem-Local-Rate-Negs	19	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_REMOTE_RATE_NEGS 	20  	//ATTRIBUTE	CVX-Modem-Remote-Rate-Negs	20	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_BEGIN_RECV_LINE_LVL 	21  	//ATTRIBUTE	CVX-Modem-Begin-Recv-Line-Lvl	21	integer	Aptis
#define 	 ATTRIBUTE_CVX_MODEM_END_RECV_LINE_LVL 	22  	//ATTRIBUTE	CVX-Modem-End-Recv-Line-Lvl	22	integer	Aptis
#define 	 ATTRIBUTE_CVX_PRIMARY_DNS 	135  	//ATTRIBUTE	CVX-Primary-DNS			135	ipaddr	Aptis
#define 	 ATTRIBUTE_CVX_SECONDARY_DNS 	136  	//ATTRIBUTE	CVX-Secondary-DNS		136	ipaddr	Aptis
#define 	 ATTRIBUTE_CVX_CLIENT_ASSIGN_DNS 	137  	//ATTRIBUTE	CVX-Client-Assign-DNS		137	integer	Aptis
#define 	 ATTRIBUTE_CVX_MULTICAST_RATE_LIMIT 	152  	//ATTRIBUTE	CVX-Multicast-Rate-Limit	152	integer	Aptis
#define 	 ATTRIBUTE_CVX_MULTICAST_CLIENT 	155  	//ATTRIBUTE	CVX-Multicast-Client		155	integer	Aptis
#define 	 ATTRIBUTE_CVX_DISCONNECT_CAUSE 	195  	//ATTRIBUTE	CVX-Disconnect-Cause		195	integer	Aptis
#define 	 ATTRIBUTE_CVX_DATA_RATE 	197  	//ATTRIBUTE	CVX-Data-Rate			197	integer	Aptis
#define 	 ATTRIBUTE_CVX_PRESESSION_TIME 	198  	//ATTRIBUTE	CVX-PreSession-Time		198	integer	Aptis
#define 	 ATTRIBUTE_CVX_ASSIGN_IP_POOL 	218  	//ATTRIBUTE	CVX-Assign-IP-Pool		218	integer	Aptis
#define 	 ATTRIBUTE_CVX_MAXIMUM_CHANNELS 	235  	//ATTRIBUTE	CVX-Maximum-Channels		235	integer	Aptis
#define 	 ATTRIBUTE_CVX_DATA_FILTER 	242  	//ATTRIBUTE	CVX-Data-Filter			242	string	Aptis
#define 	 ATTRIBUTE_CVX_IDLE_LIMIT 	244  	//ATTRIBUTE	CVX-Idle-Limit			244	integer	Aptis
#define 	 ATTRIBUTE_CVX_PPP_ADDRESS 	253  	//ATTRIBUTE	CVX-PPP-Address			253	ipaddr	Aptis
#define 	 ATTRIBUTE_CVX_XMIT_RATE 	255  	//ATTRIBUTE	CVX-Xmit-Rate			255	integer	Aptis
#define 	 ATTRIBUTE_AAT_CLIENT_PRIMARY_DNS 	5  	//ATTRIBUTE	AAT-Client-Primary-DNS		5	ipaddr	Alcatel
#define 	 ATTRIBUTE_AAT_CLIENT_PRIMARY_WINS_NBNS 	6  	//ATTRIBUTE	AAT-Client-Primary-WINS-NBNS	6	ipaddr	Alcatel
#define 	 ATTRIBUTE_AAT_CLIENT_SECONDARY_WINS_NBNS 	7  	//ATTRIBUTE	AAT-Client-Secondary-WINS-NBNS	7	ipaddr	Alcatel
#define 	 ATTRIBUTE_AAT_CLIENT_SECONDARY_DNS 	8  	//ATTRIBUTE   AAT-Client-Secondary-DNS        8   ipaddr Alcatel
#define 	 ATTRIBUTE_AAT_PPP_ADDRESS 	9  	//ATTRIBUTE	AAT-PPP-Address			9	ipaddr	Alcatel
#define 	 ATTRIBUTE_AAT_ATM_DIRECT 	21  	//ATTRIBUTE	AAT-ATM-Direct			21	string	Alcatel
#define 	 ATTRIBUTE_AAT_IP_TOS 	22  	//ATTRIBUTE	AAT-IP-TOS			22	integer	Alcatel
#define 	 ATTRIBUTE_AAT_IP_TOS_PRECEDENCE 	23  	//ATTRIBUTE	AAT-IP-TOS-Precedence		23	integer	Alcatel
#define 	 ATTRIBUTE_AAT_IP_TOS_APPLY_TO 	24  	//ATTRIBUTE	AAT-IP-TOS-Apply-To		24	integer	Alcatel
#define 	 ATTRIBUTE_AAT_MCAST_CLIENT 	27  	//ATTRIBUTE	AAT-MCast-Client		27	integer	Alcatel
#define 	 ATTRIBUTE_AAT_VROUTER_NAME 	61  	//ATTRIBUTE	AAT-Vrouter-Name		61	string	Alcatel
#define 	 ATTRIBUTE_AAT_REQUIRE_AUTH 	62  	//ATTRIBUTE	AAT-Require-Auth		62	integer	Alcatel
#define 	 ATTRIBUTE_AAT_IP_POOL_DEFINITION 	63  	//ATTRIBUTE	AAT-IP-Pool-Definition		63	string	Alcatel
#define 	 ATTRIBUTE_AAT_ASSIGN_IP_POOL 	64  	//ATTRIBUTE	AAT-Assign-IP-Pool		64	integer	Alcatel
#define 	 ATTRIBUTE_AAT_DATA_FILTER 	65  	//ATTRIBUTE	AAT-Data-Filter			65	string	Alcatel
#define 	 ATTRIBUTE_AAT_SOURCE_IP_CHECK 	66  	//ATTRIBUTE	AAT-Source-IP-Check		66	integer	Alcatel
#define 	 ATTRIBUTE_AAT_ATM_VPI 	128  	//ATTRIBUTE	AAT-ATM-VPI			128	integer	Alcatel
#define 	 ATTRIBUTE_AAT_ATM_VCI 	129  	//ATTRIBUTE	AAT-ATM-VCI			129	integer	Alcatel
#define 	 ATTRIBUTE_AAT_INPUT_OCTETS_DIFF 	130  	//ATTRIBUTE	AAT-Input-Octets-Diff		130	integer	Alcatel
#define 	 ATTRIBUTE_AAT_OUTPUT_OCTETS_DIFF 	131  	//ATTRIBUTE	AAT-Output-Octets-Diff		131	integer	Alcatel
#define 	 ATTRIBUTE_AAT_USER_MAC_ADDRESS 	132  	//ATTRIBUTE	AAT-User-MAC-Address		132	string	Alcatel
#define 	 ATTRIBUTE_AAT_ATM_TRAFFIC_PROFILE 	133  	//ATTRIBUTE	AAT-ATM-Traffic-Profile		133	string	Alcatel
#define 	 ATTRIBUTE_CVPN3000_ACCESS_HOURS 	1  	//ATTRIBUTE	CVPN3000-Access-Hours		1	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_SIMULTANEOUS_LOGINS 	2  	//ATTRIBUTE	CVPN3000-Simultaneous-Logins	2	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_MIN_PASSWORD_LENGTH_G 	3  	//ATTRIBUTE	Altiga-Min-Password-Length-G	3	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_ALLOW_ALPHA_ONLY_PASSWORDS_G 	4  	//ATTRIBUTE	Altiga-Allow-Alpha-Only-Passwords-G	4	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_PRIMARY_DNS_G 	5  	//ATTRIBUTE	Altiga-Primary-DNS-G		5	ipaddr	Altiga
#define 	 ATTRIBUTE_ALTIGA_SECONDARY_DNS_G 	6  	//ATTRIBUTE	Altiga-Secondary-DNS-G		6	ipaddr	Altiga
#define 	 ATTRIBUTE_ALTIGA_PRIMARY_WINS_G 	7  	//ATTRIBUTE	Altiga-Primary-WINS-G		7	ipaddr	Altiga
#define 	 ATTRIBUTE_ALTIGA_SECONDARY_WINS_G 	8  	//ATTRIBUTE	Altiga-Secondary-WINS-G		8	ipaddr	Altiga
#define 	 ATTRIBUTE_CVPN3000_SECONDARY_WINS 	9  	//ATTRIBUTE	CVPN3000-Secondary-WINS		9	ipaddr	Altiga
#define 	 ATTRIBUTE_CVPN3000_TUNNELING_PROTOCOLS 	11  	//ATTRIBUTE	CVPN3000-Tunneling-Protocols	11	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_SEC_ASSOCIATION 	12  	//ATTRIBUTE	CVPN3000-IPSec-Sec-Association	12	string	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_AUTHENTICATION_G 	13  	//ATTRIBUTE	Altiga-IPSec-Authentication-G	13	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_BANNER_G 	15  	//ATTRIBUTE	Altiga-IPSec-Banner-G		15	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_ALLOW_PASSWD_STORE 	16  	//ATTRIBUTE	CVPN3000-IPSec-Allow-Passwd-Store	16	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_USE_CLIENT_ADDRESS 	17  	//ATTRIBUTE	CVPN3000-Use-Client-Address	17	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_PPTP_ENCRYPTION_G 	20  	//ATTRIBUTE	Altiga-PPTP-Encryption-G	20	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_L2TP_ENCRYPTION_G 	21  	//ATTRIBUTE	Altiga-L2TP-Encryption-G	21	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_L2L_KEEPALIVES_G 	25  	//ATTRIBUTE	Altiga-IPSec-L2L-Keepalives-G	25	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_SPLIT_TUNNEL_LIST_G 	27  	//ATTRIBUTE	Altiga-IPSec-Split-Tunnel-List-G	27	string	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_DEFAULT_DOMAIN_G 	28  	//ATTRIBUTE	Altiga-IPSec-Default-Domain-G	28	string	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_SECONDARY_DOMAINS_G 	29  	//ATTRIBUTE	Altiga-IPSec-Secondary-Domains-G	29	string	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_TUNNEL_TYPE_G 	30  	//ATTRIBUTE	Altiga-IPSec-Tunnel-Type-G	30	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_MODE_CONFIG_G 	31  	//ATTRIBUTE	Altiga-IPSec-Mode-Config-G	31	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_USER_GROUP_LOCK_G 	33  	//ATTRIBUTE	Altiga-IPSec-User-Group-Lock-G	33	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_OVER_NAT_G 	34  	//ATTRIBUTE	Altiga-IPSec-Over-NAT-G		34	integer	Altiga
#define 	 ATTRIBUTE_ALTIGA_IPSEC_OVER_NAT_PORT_NUM_G 	35  	//ATTRIBUTE	Altiga-IPSec-Over-NAT-Port-Num-G	35	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_BANNER2 	36  	//ATTRIBUTE	CVPN3000-IPSec-Banner2		36	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_PPTP_MPPC_COMPRESSION 	37  	//ATTRIBUTE	CVPN3000-PPTP-MPPC-Compression	37	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_L2TP_MPPC_COMPRESSION 	38  	//ATTRIBUTE	CVPN3000-L2TP-MPPC-Compression	38	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_IP_COMPRESSION 	39  	//ATTRIBUTE	CVPN3000-IPSec-IP-Compression	39	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_IKE_PEER_ID_CHECK 	40  	//ATTRIBUTE	CVPN3000-IPSec-IKE-Peer-ID-Check	40	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IKE_KEEP_ALIVES 	41  	//ATTRIBUTE	CVPN3000-IKE-Keep-Alives	41	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_AUTH_ON_REKEY 	42  	//ATTRIBUTE	CVPN3000-IPSec-Auth-On-Rekey	42	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_VENDOR_CODE 	45  	//ATTRIBUTE	CVPN3000-Reqrd-Client-Fw-Vendor-Code	45	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_PRODUCT_CODE 	46  	//ATTRIBUTE	CVPN3000-Reqrd-Client-Fw-Product-Code	46	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_REQRD_CLIENT_FW_DESCRIPTION 	47  	//ATTRIBUTE	CVPN3000-Reqrd-Client-Fw-Description	47	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_REQUIRE_HW_CLIENT_AUTH 	48  	//ATTRIBUTE	CVPN3000-Require-HW-Client-Auth	48	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_REQUIRE_INDIVIDUAL_USER_AUTH 	49  	//ATTRIBUTE	CVPN3000-Require-Individual-User-Auth	49	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_AUTHD_USER_IDLE_TIMEOUT 	50  	//ATTRIBUTE	CVPN3000-Authd-User-Idle-Timeout	50	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_CISCO_IP_PHONE_BYPASS 	51  	//ATTRIBUTE	CVPN3000-Cisco-IP-Phone-Bypass	51	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_NAME 	52  	//ATTRIBUTE	CVPN3000-User-Auth-Server-Name	52	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_PORT 	53  	//ATTRIBUTE	CVPN3000-User-Auth-Server-Port	53	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_USER_AUTH_SERVER_SECRET 	54  	//ATTRIBUTE	CVPN3000-User-Auth-Server-Secret	54	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_SPLIT_TUNNELING_POLICY 	55  	//ATTRIBUTE	CVPN3000-IPSec-Split-Tunneling-Policy	55	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_REQRD_CLIENT_FW_CAP 	56  	//ATTRIBUTE	CVPN3000-IPSec-Reqrd-Client-Fw-Cap	56	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_CLIENT_FW_FILTER_NAME 	57  	//ATTRIBUTE	CVPN3000-IPSec-Client-Fw-Filter-Name	57	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_CLIENT_FW_FILTER_OPT 	58  	//ATTRIBUTE	CVPN3000-IPSec-Client-Fw-Filter-Opt	58	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_BACKUP_SERVERS 	59  	//ATTRIBUTE	CVPN3000-IPSec-Backup-Servers	59	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_IPSEC_BACKUP_SERVER_LIST 	60  	//ATTRIBUTE	CVPN3000-IPSec-Backup-Server-List	60	string	Altiga
#define 	 ATTRIBUTE_CVPN3000_MS_CLIENT_ICPT_DHCP_CONF_MSG 	62  	//ATTRIBUTE	CVPN3000-MS-Client-Icpt-DHCP-Conf-Msg	62	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_MS_CLIENT_SUBNET_MASK 	63  	//ATTRIBUTE	CVPN3000-MS-Client-Subnet-Mask	63	ipaddr	Altiga
#define 	 ATTRIBUTE_CVPN3000_ALLOW_NETWORK_EXTENSION_MODE 	64  	//ATTRIBUTE	CVPN3000-Allow-Network-Extension-Mode	64	integer	Altiga
#define 	 ATTRIBUTE_CVPN3000_STRIP_REALM 	135  	//ATTRIBUTE	CVPN3000-Strip-Realm		135	integer	Altiga
#define 	 ATTRIBUTE_SHASTA_USER_PRIVILEGE 	1  	//ATTRIBUTE	Shasta-User-Privilege		1	integer	Shasta
#define 	 ATTRIBUTE_SHASTA_SERVICE_PROFILE 	2  	//ATTRIBUTE	Shasta-Service-Profile		2	string	Shasta
#define 	 ATTRIBUTE_SHASTA_VPN_NAME 	3  	//ATTRIBUTE	Shasta-VPN-Name			3	string	Shasta
#define 	 ATTRIBUTE_NS_ADMIN_PRIVILEGE 	1  	//ATTRIBUTE	NS-Admin-Privilege		1	integer	Netscreen
#define 	 ATTRIBUTE_NS_VSYS_NAME 	2  	//ATTRIBUTE	NS-VSYS-Name			2	string	Netscreen
#define 	 ATTRIBUTE_NS_USER_GROUP 	3  	//ATTRIBUTE	NS-User-Group			3	string	Netscreen
#define 	 ATTRIBUTE_NS_PRIMARY_DNS 	4  	//ATTRIBUTE	NS-Primary-DNS			4	ipaddr	Netscreen
#define 	 ATTRIBUTE_NS_SECONDARY_DNS 	5  	//ATTRIBUTE	NS-Secondary-DNS		5	ipaddr	Netscreen
#define 	 ATTRIBUTE_NS_PRIMARY_WINS 	6  	//ATTRIBUTE	NS-Primary-WINS			6	ipaddr	Netscreen
#define 	 ATTRIBUTE_NS_SECONDARY_WINS 	7  	//ATTRIBUTE	NS-Secondary-WINS		7	ipaddr	Netscreen
#define 	 ATTRIBUTE_NOMADIX_BW_UP 	1  	//ATTRIBUTE	Nomadix-Bw-Up			1	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_BW_DOWN 	2  	//ATTRIBUTE	Nomadix-Bw-Down			2	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_URL_REDIRECTION 	3  	//ATTRIBUTE	Nomadix-URL-Redirection		3	string	Nomadix
#define 	 ATTRIBUTE_NOMADIX_IP_UPSELL 	4  	//ATTRIBUTE	Nomadix-IP-Upsell		4	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_EXPIRATION 	5  	//ATTRIBUTE	Nomadix-Expiration		5	string	Nomadix
#define 	 ATTRIBUTE_NOMADIX_SUBNET 	6  	//ATTRIBUTE	Nomadix-Subnet			6	string	Nomadix
#define 	 ATTRIBUTE_NOMADIX_MAXBYTESUP 	7  	//ATTRIBUTE	Nomadix-MaxBytesUp		7	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_MAXBYTESDOWN 	8  	//ATTRIBUTE	Nomadix-MaxBytesDown		8	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_ENDOFSESSION 	9  	//ATTRIBUTE	Nomadix-EndofSession		9	integer	Nomadix
#define 	 ATTRIBUTE_NOMADIX_LOGOFF_URL 	10  	//ATTRIBUTE	Nomadix-Logoff-URL		10	string	Nomadix
#define 	 ATTRIBUTE_ST_ACCT_VC_CONNECTION_ID 	1  	//ATTRIBUTE	ST-Acct-VC-Connection-Id	1	string	SpringTide
#define 	 ATTRIBUTE_ST_SERVICE_NAME 	2  	//ATTRIBUTE	ST-Service-Name			2	string	SpringTide
#define 	 ATTRIBUTE_ST_SERVICE_DOMAIN 	3  	//ATTRIBUTE	ST-Service-Domain		3	integer	SpringTide
#define 	 ATTRIBUTE_ST_POLICY_NAME 	4  	//ATTRIBUTE	ST-Policy-Name			4	string	SpringTide
#define 	 ATTRIBUTE_ST_PRIMARY_DNS_SERVER 	5  	//ATTRIBUTE	ST-Primary-DNS-Server		5	ipaddr	SpringTide
#define 	 ATTRIBUTE_ST_SECONDARY_DNS_SERVER 	6  	//ATTRIBUTE	ST-Secondary-DNS-Server		6	ipaddr	SpringTide
#define 	 ATTRIBUTE_ST_PRIMARY_NBNS_SERVER 	7  	//ATTRIBUTE	ST-Primary-NBNS-Server		7	ipaddr	SpringTide
#define 	 ATTRIBUTE_ST_SECONDARY_NBNS_SERVER 	8  	//ATTRIBUTE	ST-Secondary-NBNS-Server	8	ipaddr	SpringTide
#define 	 ATTRIBUTE_ERX_VIRTUAL_ROUTER_NAME 	1  	//ATTRIBUTE	ERX-Virtual-Router-Name		1	string	ERX
#define 	 ATTRIBUTE_ERX_ADDRESS_POOL_NAME 	2  	//ATTRIBUTE	ERX-Address-Pool-Name		2	string	ERX
#define 	 ATTRIBUTE_ERX_LOCAL_LOOPBACK_INTERFACE 	3  	//ATTRIBUTE	ERX-Local-Loopback-Interface	3	string	ERX
#define 	 ATTRIBUTE_ERX_PRIMARY_DNS 	4  	//ATTRIBUTE	ERX-Primary-Dns			4	ipaddr	ERX
#define 	 ATTRIBUTE_ERX_PRIMARY_WINS 	5  	//ATTRIBUTE	ERX-Primary-Wins		5	ipaddr	ERX
#define 	 ATTRIBUTE_ERX_SECONDARY_DNS 	6  	//ATTRIBUTE	ERX-Secondary-Dns		6	ipaddr	ERX
#define 	 ATTRIBUTE_ERX_SECONDARY_WINS 	7  	//ATTRIBUTE	ERX-Secondary-Wins		7	ipaddr	ERX
#define 	 ATTRIBUTE_ERX_TUNNEL_VIRTUAL_ROUTER 	8  	//ATTRIBUTE	ERX-Tunnel-Virtual-Router	8	string	ERX
#define 	 ATTRIBUTE_ERX_TUNNEL_PASSWORD 	9  	//ATTRIBUTE	ERX-Tunnel-Password		9	string	ERX
#define 	 ATTRIBUTE_ERX_INGRESS_POLICY_NAME 	10  	//ATTRIBUTE	ERX-Ingress-Policy-Name		10	string	ERX
#define 	 ATTRIBUTE_ERX_EGRESS_POLICY_NAME 	11  	//ATTRIBUTE	ERX-Egress-Policy-Name		11	string	ERX
#define 	 ATTRIBUTE_ERX_INGRESS_STATISTICS 	12  	//ATTRIBUTE	ERX-Ingress-Statistics		12	string	ERX
#define 	 ATTRIBUTE_ERX_EGRESS_STATISTICS 	13  	//ATTRIBUTE	ERX-Egress-Statistics		13	string	ERX
#define 	 ATTRIBUTE_ERX_ATM_SERVICE_CATEGORY 	14  	//ATTRIBUTE	ERX-Atm-Service-Category	14	integer	ERX
#define 	 ATTRIBUTE_ERX_ATM_PCR 	15  	//ATTRIBUTE	ERX-Atm-PCR			15	integer	ERX
#define 	 ATTRIBUTE_ERX_ATM_SCR 	16  	//ATTRIBUTE	ERX-Atm-SCR			16	integer	ERX
#define 	 ATTRIBUTE_ERX_ATM_MBS 	17  	//ATTRIBUTE	ERX-Atm-MBS			17	integer	ERX
#define 	 ATTRIBUTE_ERX_CLI_INITIAL_ACCESS_LEVEL 	18  	//ATTRIBUTE	ERX-Cli-Initial-Access-Level	18	string	ERX
#define 	 ATTRIBUTE_ERX_CLI_ALLOW_ALL_VR_ACCESS 	19  	//ATTRIBUTE	ERX-Cli-Allow-All-VR-Access	19	integer	ERX
#define 	 ATTRIBUTE_ERX_ALTERNATE_CLI_ACCESS_LEVEL 	20  	//ATTRIBUTE	ERX-Alternate-Cli-Access-Level	20	string	ERX
#define 	 ATTRIBUTE_ERX_ALTERNATE_CLI_VROUTER_NAME 	21  	//ATTRIBUTE	ERX-Alternate-Cli-Vrouter-Name	21	string	ERX
#define 	 ATTRIBUTE_ERX_SA_VALIDATE 	22  	//ATTRIBUTE	ERX-Sa-Validate			22	integer	ERX
#define 	 ATTRIBUTE_ERX_IGMP_ENABLE 	23  	//ATTRIBUTE	ERX-Igmp-Enable			23	integer	ERX
#define 	 ATTRIBUTE_ERX_PPPOE_DESCRIPTION 	24  	//ATTRIBUTE	ERX-Pppoe-Description		24	string	ERX
#define 	 ATTRIBUTE_ERX_REDIRECT_VR_NAME 	25  	//ATTRIBUTE	ERX-Redirect-VR-Name		25	string	ERX
#define 	 ATTRIBUTE_ERX_QOS_PROFILE_NAME 	26  	//ATTRIBUTE	ERX-Qos-Profile-Name		26	string	ERX
#define 	 ATTRIBUTE_ERX_PPPOE_MAX_SESSIONS 	27  	//ATTRIBUTE	ERX-Pppoe-Max-Sessions		27	integer	ERX
#define 	 ATTRIBUTE_ERX_PPPOE_URL 	28  	//ATTRIBUTE	ERX-Pppoe-Url			28	string	ERX
#define 	 ATTRIBUTE_ERX_QOS_PROFILE_INTERFACE_TYPE 	29  	//ATTRIBUTE	ERX-Qos-Profile-Interface-Type	29	integer	ERX
#define 	 ATTRIBUTE_ERX_TUNNEL_NAS_PORT_METHOD 	30  	//ATTRIBUTE	ERX-Tunnel-Nas-Port-Method	30	integer	ERX
#define 	 ATTRIBUTE_ERX_SERVICE_BUNDLE 	31  	//ATTRIBUTE	ERX-Service-Bundle		31	string	ERX
#define 	 ATTRIBUTE_ERX_TUNNEL_TOS 	32  	//ATTRIBUTE	ERX-Tunnel-Tos			32	integer	ERX
#define 	 ATTRIBUTE_ERX_TUNNEL_MAXIMUM_SESSIONS 	33  	//ATTRIBUTE	ERX-Tunnel-Maximum-Sessions	33	integer	ERX
#define 	 ATTRIBUTE_ERX_FRAMED_IP_ROUTE_TAG 	34  	//ATTRIBUTE	ERX-Framed-Ip-Route-Tag		34	string	ERX
#define 	 ATTRIBUTE_ERX_INPUT_GIGAPKTS 	42  	//ATTRIBUTE	ERX-Input-Gigapkts		42	integer	ERX
#define 	 ATTRIBUTE_ERX_OUTPUT_GIGAPKTS 	43  	//ATTRIBUTE	ERX-Output-Gigapkts		43	integer	ERX
#define 	 ATTRIBUTE_CBBSM_BANDWIDTH 	1  	//ATTRIBUTE	CBBSM-Bandwidth			1	integer	Cisco-BBSM
#define 	 ATTRIBUTE_QUINTUM_AVPAIR 	1  	//ATTRIBUTE	Quintum-AVPair			1	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_NAS_PORT 	2  	//ATTRIBUTE	Quintum-NAS-Port		2	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_REMOTE_ADDRESS 	23  	//ATTRIBUTE	Quintum-h323-remote-address	23	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CONF_ID 	24  	//ATTRIBUTE	Quintum-h323-conf-id		24	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_SETUP_TIME 	25  	//ATTRIBUTE	Quintum-h323-setup-time		25	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CALL_ORIGIN 	26  	//ATTRIBUTE	Quintum-h323-call-origin	26	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CALL_TYPE 	27  	//ATTRIBUTE	Quintum-h323-call-type		27	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CONNECT_TIME 	28  	//ATTRIBUTE	Quintum-h323-connect-time	28	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_DISCONNECT_TIME 	29  	//ATTRIBUTE	Quintum-h323-disconnect-time	29	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_DISCONNECT_CAUSE 	30  	//ATTRIBUTE	Quintum-h323-disconnect-cause	30	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_VOICE_QUALITY 	31  	//ATTRIBUTE	Quintum-h323-voice-quality	31	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_GW_ID 	33  	//ATTRIBUTE	Quintum-h323-gw-id		33	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_INCOMING_CONF_ID 	35  	//ATTRIBUTE	Quintum-h323-incoming-conf-id	35	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CREDIT_AMOUNT 	101  	//ATTRIBUTE	Quintum-h323-credit-amount	101	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CREDIT_TIME 	102  	//ATTRIBUTE	Quintum-h323-credit-time	102	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_RETURN_CODE 	103  	//ATTRIBUTE	Quintum-h323-return-code	103	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_PROMPT_ID 	104  	//ATTRIBUTE	Quintum-h323-prompt-id		104	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_TIME_AND_DAY 	105  	//ATTRIBUTE	Quintum-h323-time-and-day	105	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_REDIRECT_NUMBER 	106  	//ATTRIBUTE	Quintum-h323-redirect-number	106	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_PREFERRED_LANG 	107  	//ATTRIBUTE	Quintum-h323-preferred-lang	107	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_REDIRECT_IP_ADDRESS 	108  	//ATTRIBUTE	Quintum-h323-redirect-ip-address	108	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_BILLING_MODEL 	109  	//ATTRIBUTE	Quintum-h323-billing-model	109	string	Quintum
#define 	 ATTRIBUTE_QUINTUM_H323_CURRENCY_TYPE 	110  	//ATTRIBUTE	Quintum-h323-currency-type	110	string	Quintum
#define 	 ATTRIBUTE_SS3_FIREWALL_USER_PRIVILEGE 	1  	//ATTRIBUTE	SS3-Firewall-User-Privilege	1	integer	3com
#define 	 ATTRIBUTE_COLUBRIS_AVPAIR 	0  	//ATTRIBUTE	Colubris-AVPair			0	string	Colubris
#define 	 ATTRIBUTE_WISPR_LOCATION_ID 	1  	//ATTRIBUTE	WISPr-Location-ID		1	string	WISPr
#define 	 ATTRIBUTE_WISPR_LOCATION_NAME 	2  	//ATTRIBUTE	WISPr-Location-Name		2	string	WISPr
#define 	 ATTRIBUTE_WISPR_LOGOFF_URL 	3  	//ATTRIBUTE	WISPr-Logoff-URL		3	string	WISPr
#define 	 ATTRIBUTE_WISPR_REDIRECTION_URL 	4  	//ATTRIBUTE	WISPr-Redirection-URL		4	string	WISPr
#define 	 ATTRIBUTE_WISPR_BANDWIDTH_MIN_UP 	5  	//ATTRIBUTE	WISPr-Bandwidth-Min-Up		5	integer	WISPr
#define 	 ATTRIBUTE_WISPR_BANDWIDTH_MIN_DOWN 	6  	//ATTRIBUTE	WISPr-Bandwidth-Min-Down	6	integer	WISPr
#define 	 ATTRIBUTE_WISPR_BANDWIDTH_MAX_UP 	7  	//ATTRIBUTE	WISPr-Bandwidth-Max-Up		7	integer	WISPr
#define 	 ATTRIBUTE_WISPR_BANDWIDTH_MAX_DOWN 	8  	//ATTRIBUTE	WISPr-Bandwidth-Max-Down	8	integer	WISPr
#define 	 ATTRIBUTE_WISPR_SESSION_TERMINATE_TIME 	9  	//ATTRIBUTE	WISPr-Session-Terminate-Time	9	string	WISPr
#define 	 ATTRIBUTE_WISPR_SESSION_TERMINATE_END_OF_DAY 	10  	//ATTRIBUTE	WISPr-Session-Terminate-End-Of-Day	10	string	WISPr
#define 	 ATTRIBUTE_WISPR_BILLING_CLASS_OF_SERVICE 	11  	//ATTRIBUTE	WISPr-Billing-Class-Of-Service	11	string	WISPr
  	//
  	//VALUE	AAT-IP-TOS			IP-TOS-Normal			0	Alcatel
  	//VALUE	AAT-IP-TOS			IP-TOS-Disabled			1	Alcatel
  	//VALUE	AAT-IP-TOS			IP-TOS-Cost			2	Alcatel
  	//VALUE	AAT-IP-TOS			IP-TOS-Reliability		4	Alcatel
  	//VALUE	AAT-IP-TOS			IP-TOS-Throughput		8	Alcatel
  	//VALUE	AAT-IP-TOS			IP-TOS-Latency			16	Alcatel
  	//VALUE	AAT-IP-TOS-Apply-To		IP-TOS-Apply-To-Incoming	1024	Alcatel
  	//VALUE	AAT-IP-TOS-Apply-To		IP-TOS-Apply-To-Outgoing	2048	Alcatel
  	//VALUE	AAT-IP-TOS-Apply-To		IP-TOS-Apply-To-Both		3072	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Normal	0	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-One	32	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Two	64	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Three	96	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Four	128	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Five	160	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Six	192	Alcatel
  	//VALUE	AAT-IP-TOS-Precedence		IP-TOS-Precedence-Pri-Seven	224	Alcatel
  	//VALUE	AAT-MCast-Client		Multicast-No			0	Alcatel
  	//VALUE	AAT-MCast-Client		Multicast-Yes			1	Alcatel
  	//VALUE	AAT-Require-Auth		Not-Require-Auth		0	Alcatel
  	//VALUE	AAT-Require-Auth		Require-Auth			1	Alcatel
  	//VALUE	AAT-Source-IP-Check		Source-IP-Check-No		0	Alcatel
  	//VALUE	AAT-Source-IP-Check		Source-IP-Check-Yes		1	Alcatel
  	//VALUE	Acc-Access-Community		PUBLIC				1	Acc
  	//VALUE	Acc-Access-Community		NETMAN				2	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		NAS-Reset			0	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		NAS-Reload			1	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		Configuration-Reset		2	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		Configuration-Reload		3	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		Enabled				4	Acc
  	//VALUE	Acc-Acct-On-Off-Reason		Disabled			5	Acc
  	//VALUE	Acc-Apsm-Oversubscribed		False				1	Acc
  	//VALUE	Acc-Apsm-Oversubscribed		True				2	Acc
  	//VALUE	Acc-Bridging-Support		Disabled			1	Acc
  	//VALUE	Acc-Bridging-Support		Enabled				2	Acc
  	//VALUE	Acc-Callback-CBCP-Type		CBCP-None			1	Acc
  	//VALUE	Acc-Callback-CBCP-Type		CBCP-User-Specified		2	Acc
  	//VALUE	Acc-Callback-CBCP-Type		CBCP-Pre-Specified		3	Acc
  	//VALUE	Acc-Callback-Mode		User-Auth			0	Acc
  	//VALUE	Acc-Callback-Mode		User-Specified-E-164		3	Acc
  	//VALUE	Acc-Callback-Mode		CBCP-Callback			6	Acc
  	//VALUE	Acc-Callback-Mode		CLI-Callback			7	Acc
  	//VALUE	Acc-Ccp-Option			Disabled			1	Acc
  	//VALUE	Acc-Ccp-Option			Enabled				2	Acc
  	//VALUE	Acc-Clearing-Cause		Cause-unspecified		0	Acc
  	//VALUE	Acc-Clearing-Cause		Unassigned-number		1	Acc
  	//VALUE	Acc-Clearing-Cause		No-route-to-transit-network	2	Acc
  	//VALUE	Acc-Clearing-Cause		No-route-to-destination		3	Acc
  	//VALUE	Acc-Clearing-Cause		Channel-unacceptable		6	Acc
  	//VALUE	Acc-Clearing-Cause		Call-awarded-being-delivered	7	Acc
  	//VALUE	Acc-Clearing-Cause		Normal-clearing			16	Acc
  	//VALUE	Acc-Clearing-Cause		User-busy			17	Acc
  	//VALUE	Acc-Clearing-Cause		No-user-responding		18	Acc
  	//VALUE	Acc-Clearing-Cause		User-alerted-no-answer		19	Acc
  	//VALUE	Acc-Clearing-Cause		Call-rejected			21	Acc
  	//VALUE	Acc-Clearing-Cause		Number-changed			22	Acc
  	//VALUE	Acc-Clearing-Cause		Non-selected-user-clearing	26	Acc
  	//VALUE	Acc-Clearing-Cause		Destination-out-of-order	27	Acc
  	//VALUE	Acc-Clearing-Cause		Invalid-or-incomplete-number	28	Acc
  	//VALUE	Acc-Clearing-Cause		Facility-rejected		29	Acc
  	//VALUE	Acc-Clearing-Cause		Response-to-status-inquiry	30	Acc
  	//VALUE	Acc-Clearing-Cause		Normal-unspecified-cause	31	Acc
  	//VALUE	Acc-Clearing-Cause		No-circuit-or-channel-available	34	Acc
  	//VALUE	Acc-Clearing-Cause		Network-out-of-order		38	Acc
  	//VALUE	Acc-Clearing-Cause		Temporary-failure		41	Acc
  	//VALUE	Acc-Clearing-Cause		Switching-equipment-congestion	42	Acc
  	//VALUE	Acc-Clearing-Cause		Access-information-discarded	43	Acc
  	//VALUE	Acc-Clearing-Cause		Circuit-or-channel-unavailable	44	Acc
  	//VALUE	Acc-Clearing-Cause		Circuit-or-channed-preempted	45	Acc
  	//VALUE	Acc-Clearing-Cause		Resources-unavailable		47	Acc
  	//VALUE	Acc-Clearing-Cause		Quality-of-service-unavailable	49	Acc
  	//VALUE	Acc-Clearing-Cause		Facility-not-subscribed		50	Acc
  	//VALUE	Acc-Clearing-Cause		Outgoing-calls-barred		52	Acc
  	//VALUE	Acc-Clearing-Cause		Incoming-calls-barred		54	Acc
  	//VALUE	Acc-Clearing-Cause		Bearer-capability-unauthorized	57	Acc
  	//VALUE	Acc-Clearing-Cause		Bearer-capability-not-available	58	Acc
  	//VALUE	Acc-Clearing-Cause		Service-not-available		63	Acc
  	//VALUE	Acc-Clearing-Cause		Bearer-capablity-not-implmented	65	Acc
  	//VALUE	Acc-Clearing-Cause		Channel-type-not-implemented	66	Acc
  	//VALUE	Acc-Clearing-Cause		Facility-not-implemented	69	Acc
  	//VALUE	Acc-Clearing-Cause		Restrcted-digtal-infrmtion-only	70	Acc
  	//VALUE	Acc-Clearing-Cause		Service-not-implemented		79	Acc
  	//VALUE	Acc-Clearing-Cause		Invalid-call-reference		81	Acc
  	//VALUE	Acc-Clearing-Cause		Identified-channel-doesnt-exist	82	Acc
  	//VALUE	Acc-Clearing-Cause		Call-identify-in-use		84	Acc
  	//VALUE	Acc-Clearing-Cause		No-call-suspended		85	Acc
  	//VALUE	Acc-Clearing-Cause		Suspended-call-cleared		86	Acc
  	//VALUE	Acc-Clearing-Cause		Incompatible-destination	88	Acc
  	//VALUE	Acc-Clearing-Cause		Invalid-transit-network-selctin	91	Acc
  	//VALUE	Acc-Clearing-Cause		Invalid-message			95	Acc
  	//VALUE	Acc-Clearing-Cause		Mandtory-infrmtion-elment-miss	96	Acc
  	//VALUE	Acc-Clearing-Cause		Message-not-implemented		97	Acc
  	//VALUE	Acc-Clearing-Cause		Inopportune-message		98	Acc
  	//VALUE	Acc-Clearing-Cause		Infrmtion-elemnt-not-implmented	99	Acc
  	//VALUE	Acc-Clearing-Cause		Invlid-infrmtion-element-contnt	100	Acc
  	//VALUE	Acc-Clearing-Cause		Message-incompatible-with-state	101	Acc
  	//VALUE	Acc-Clearing-Cause		Recovery-on-timer-expiration	102	Acc
  	//VALUE	Acc-Clearing-Cause		Mndtry-infrmtion-elmnt-lngt-err	103	Acc
  	//VALUE	Acc-Clearing-Cause		Protocol-error			111	Acc
  	//VALUE	Acc-Clearing-Cause		Interworking			127	Acc
  	//VALUE	Acc-Clearing-Location		Local-or-remote-user		0	Acc
  	//VALUE	Acc-Clearing-Location		Prvte-ntwork-serving-local-user	1	Acc
  	//VALUE	Acc-Clearing-Location		Pblic-ntwork-serving-local-user	2	Acc
  	//VALUE	Acc-Clearing-Location		Transit-network			3	Acc
  	//VALUE	Acc-Clearing-Location		Prvte-ntwork-serv-remote-user	4	Acc
  	//VALUE	Acc-Clearing-Location		Pblic-ntwork-serv-remote-user	5	Acc
  	//VALUE	Acc-Clearing-Location		International-network		6	Acc
  	//VALUE	Acc-Clearing-Location		Beyond-interworking-point	10	Acc
  	//VALUE	Acc-Dialout-Auth-Mode		PAP				1	Acc
  	//VALUE	Acc-Dialout-Auth-Mode		CHAP				2	Acc
  	//VALUE	Acc-Dialout-Auth-Mode		CHAP-PAP			3	Acc
  	//VALUE	Acc-Dialout-Auth-Mode		NONE				4	Acc
  	//VALUE	Acc-Igmp-Admin-State		Enabled				1	Acc
  	//VALUE	Acc-Igmp-Admin-State		Disabled			2	Acc
  	//VALUE	Acc-Igmp-Version		V1				1	Acc
  	//VALUE	Acc-Igmp-Version		V2				2	Acc
  	//VALUE	Acc-Ip-Compression		Disabled			1	Acc
  	//VALUE	Acc-Ip-Compression		Enabled				2	Acc
  	//VALUE	Acc-Ipx-Compression		Disabled			1	Acc
  	//VALUE	Acc-Ipx-Compression		Enabled				2	Acc
  	//VALUE	Acc-ML-MLX-Admin-State		Enabled				1	Acc
  	//VALUE	Acc-ML-MLX-Admin-State		Disabled			2	Acc
  	//VALUE	Acc-Reason-Code			No-reason-No-Failure		0	Acc
  	//VALUE	Acc-Reason-Code			Resource-shortage		1	Acc
  	//VALUE	Acc-Reason-Code			Session-already-open		2	Acc
  	//VALUE	Acc-Reason-Code			Too-many-RADIUS-users		3	Acc
  	//VALUE	Acc-Reason-Code			No-authentification-server	4	Acc
  	//VALUE	Acc-Reason-Code			No-authentification-response	5	Acc
  	//VALUE	Acc-Reason-Code			No-accounting-server		6	Acc
  	//VALUE	Acc-Reason-Code			No-accounting-response		7	Acc
  	//VALUE	Acc-Reason-Code			Access-Denied			8	Acc
  	//VALUE	Acc-Reason-Code			Temporary-buffer-shortage	9	Acc
  	//VALUE	Acc-Reason-Code			Protocol-error			10	Acc
  	//VALUE	Acc-Reason-Code			Invalid-attribute		11	Acc
  	//VALUE	Acc-Reason-Code			Invalid-service-type		12	Acc
  	//VALUE	Acc-Reason-Code			Invalid-framed-protocol		13	Acc
  	//VALUE	Acc-Reason-Code			Invalid-attribute-value		14	Acc
  	//VALUE	Acc-Reason-Code			Invalid-user-information	15	Acc
  	//VALUE	Acc-Reason-Code			Invalid-IP-address		16	Acc
  	//VALUE	Acc-Reason-Code			Invalid-integer-syntax		17	Acc
  	//VALUE	Acc-Reason-Code			Invalid-NAS-port		18	Acc
  	//VALUE	Acc-Reason-Code			Requested-by-user		19	Acc
  	//VALUE	Acc-Reason-Code			Network-disconnect		20	Acc
  	//VALUE	Acc-Reason-Code			Service-interruption		21	Acc
  	//VALUE	Acc-Reason-Code			Physical-port-error		22	Acc
  	//VALUE	Acc-Reason-Code			Idle-timeout			23	Acc
  	//VALUE	Acc-Reason-Code			Session-timeout			24	Acc
  	//VALUE	Acc-Reason-Code			Administrative-reset		25	Acc
  	//VALUE	Acc-Reason-Code			NAS-reload-or-reset		26	Acc
  	//VALUE	Acc-Reason-Code			NAS-error			27	Acc
  	//VALUE	Acc-Reason-Code			NAS-request			28	Acc
  	//VALUE	Acc-Reason-Code			Undefined-reason-given		29	Acc
  	//VALUE	Acc-Reason-Code			Conflicting-attributes		30	Acc
  	//VALUE	Acc-Reason-Code			Port-limit-exceeded		31	Acc
  	//VALUE	Acc-Reason-Code			Facility-not-available		32	Acc
  	//VALUE	Acc-Reason-Code			Internal-config-error		33	Acc
  	//VALUE	Acc-Reason-Code			Bad-route-specification		34	Acc
  	//VALUE	Acc-Reason-Code			Access-Partition-bind-failure	35	Acc
  	//VALUE	Acc-Reason-Code			Security-violation		36	Acc
  	//VALUE	Acc-Reason-Code			Request-type-conflict		37	Acc
  	//VALUE	Acc-Reason-Code			Configuration-disallowed	38	Acc
  	//VALUE	Acc-Reason-Code			Missing-attribute		39	Acc
  	//VALUE	Acc-Reason-Code			Invalid-request			40	Acc
  	//VALUE	Acc-Reason-Code			Missing-parameter		41	Acc
  	//VALUE	Acc-Reason-Code			Invalid-parameter		42	Acc
  	//VALUE	Acc-Reason-Code			Call-cleared-with-cause		43	Acc
  	//VALUE	Acc-Reason-Code			Inopportune-config-request	44	Acc
  	//VALUE	Acc-Reason-Code			Invalid-config-parameter	45	Acc
  	//VALUE	Acc-Reason-Code			Missing-config-parameter	46	Acc
  	//VALUE	Acc-Reason-Code			Incompatible-service-profile	47	Acc
  	//VALUE	Acc-Reason-Code			Administrative-reset		48	Acc
  	//VALUE	Acc-Reason-Code			Administrative-reload		49	Acc
  	//VALUE	Acc-Reason-Code			Port-unneeded			50	Acc
  	//VALUE	Acc-Reason-Code			Port-preempted			51	Acc
  	//VALUE	Acc-Reason-Code			Port-suspended			52	Acc
  	//VALUE	Acc-Reason-Code			Service-unavailable		53	Acc
  	//VALUE	Acc-Reason-Code			Callback			54	Acc
  	//VALUE	Acc-Reason-Code			User-error			55	Acc
  	//VALUE	Acc-Reason-Code			Host-request			56	Acc
  	//VALUE	Acc-Request-Type		Ring-Indication			1	Acc
  	//VALUE	Acc-Request-Type		Dial-Request			2	Acc
  	//VALUE	Acc-Request-Type		User-Authentification		3	Acc
  	//VALUE	Acc-Request-Type		Tunnel-Authentification		4	Acc
  	//VALUE	Acc-Route-Policy		Funnel				1	Acc
  	//VALUE	Acc-Route-Policy		Direct				2	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		No-Access-Partition		1	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		Access-Partition-Disabled	2	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		Partition-Portlimit-Exceeded	3	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		License-Portlimit-Exceeded	4	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		Home-Server-Down		5	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		Rejected-By-Home-Server		6	Acc
  	//VALUE	Acc-Vpsm-Reject-Cause		NAS-Administratively-Disabled	7	Acc
  	//VALUE	Acct-Authentic			None				0	
  	//VALUE	Acct-Authentic			RADIUS				1	
  	//VALUE	Acct-Authentic			Local				2	
  	//VALUE	Acct-Authentic			Remote				3	
  	//VALUE	Acct-Authentic			Diameter			4	
  	//VALUE	Acct-Status-Type		Annex-User-Reject		0	
  	//VALUE	Acct-Status-Type		Start				1	
  	//VALUE	Acct-Status-Type		Stop				2	
  	//VALUE	Acct-Status-Type		Alive				3	
  	//VALUE	Acct-Status-Type		Modem-Start			4	
  	//VALUE	Acct-Status-Type		Modem-Stop			5	
  	//VALUE	Acct-Status-Type		Cancel				6	
  	//VALUE	Acct-Status-Type		Accounting-On			7	
  	//VALUE	Acct-Status-Type		Accounting-Off			8	
  	//VALUE	Acct-Status-Type		Tunnel-Start			9	
  	//VALUE	Acct-Status-Type		Tunnel-Stop			10	
  	//VALUE	Acct-Status-Type		Tunnel-Reject			11	
  	//VALUE	Acct-Status-Type		Tunnel-Link-Start		12	
  	//VALUE	Acct-Status-Type		Tunnel-Link-Stop		13	
  	//VALUE	Acct-Status-Type		Tunnel-Link-Reject		14	
  	//VALUE	Acct-Status-Type		Failed				15	
  	//VALUE	Acct-Terminate-Cause		User-Request			1	
  	//VALUE	Acct-Terminate-Cause		Lost-Carrier			2	
  	//VALUE	Acct-Terminate-Cause		Lost-Service			3	
  	//VALUE	Acct-Terminate-Cause		Idle-Timeout			4	
  	//VALUE	Acct-Terminate-Cause		Session-Timeout			5	
  	//VALUE	Acct-Terminate-Cause		Admin-Reset			6	
  	//VALUE	Acct-Terminate-Cause		Admin-Reboot			7	
  	//VALUE	Acct-Terminate-Cause		Port-Error			8	
  	//VALUE	Acct-Terminate-Cause		NAS-Error			9	
  	//VALUE	Acct-Terminate-Cause		NAS-Request			10	
  	//VALUE	Acct-Terminate-Cause		NAS-Reboot			11	
  	//VALUE	Acct-Terminate-Cause		Port-Unneeded			12	
  	//VALUE	Acct-Terminate-Cause		Port-Preempted			13	
  	//VALUE	Acct-Terminate-Cause		Port-Suspended			14	
  	//VALUE	Acct-Terminate-Cause		Service-Unavailable		15	
  	//VALUE	Acct-Terminate-Cause		Callback			16	
  	//VALUE	Acct-Terminate-Cause		User-Error			17	
  	//VALUE	Acct-Terminate-Cause		Host-Request			18	
  	//VALUE	Acct-Terminate-Cause		Supplicant-Restart		19	
  	//VALUE	Acct-Terminate-Cause		Reauth-Failure			20	
  	//VALUE	Acct-Terminate-Cause		Port-Reinit			21	
  	//VALUE	Acct-Terminate-Cause		Port-Disabled			22	
  	//VALUE	Alteon-Service-Type		Alteon-L4admin			250	Alteon
  	//VALUE	Alteon-Service-Type		Alteon-Slbadmin			251	Alteon
  	//VALUE	Alteon-Service-Type		Alteon-Oper			252	Alteon
  	//VALUE	Alteon-Service-Type		Alteon-L4oper			253	Alteon
  	//VALUE	Alteon-Service-Type		Alteon-Slboper			254	Alteon
  	//VALUE	Alteon-Service-Type		Alteon-User			255	Alteon
  	//VALUE	Altiga-Allow-Alpha-Only-Passwords-G	Disallow			0	Altiga
  	//VALUE	Altiga-Allow-Alpha-Only-Passwords-G	Allow				1	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	None				0	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	RADIUS				1	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	LDAP				2	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	NTDomain			3	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	SDI				4	Altiga
  	//VALUE	Altiga-IPSec-Authentication-G	Internal			5	Altiga
  	//VALUE	Altiga-IPSec-L2L-Keepalives-G	OFF				0	Altiga
  	//VALUE	Altiga-IPSec-L2L-Keepalives-G	ON				1	Altiga
  	//VALUE	Altiga-IPSec-Mode-Config-G	OFF				0	Altiga
  	//VALUE	Altiga-IPSec-Mode-Config-G	ON				1	Altiga
  	//VALUE	Altiga-IPSec-Over-NAT-G		OFF				0	Altiga
  	//VALUE	Altiga-IPSec-Over-NAT-G		ON				1	Altiga
  	//VALUE	Altiga-IPSec-Tunnel-Type-G	LAN-to-LAN			1	Altiga
  	//VALUE	Altiga-IPSec-Tunnel-Type-G	Remote-Access			2	Altiga
  	//VALUE	Altiga-IPSec-User-Group-Lock-G	OFF				0	Altiga
  	//VALUE	Altiga-IPSec-User-Group-Lock-G	ON				1	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	40bit				2	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	40-Encryption-Req		3	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	128				4	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	128-Encryption-Req		5	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	40-or-128			6	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	40-or-128-Encry-Req		7	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	40-Stateless-Req		10	Altiga
  	//VALUE	Altiga-L2TP-Encryption-G	128-Stateless-Req		12	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	40bit				2	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	40-Encryption-Req		3	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	128				4	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	128-Encryption-Req		5	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	40-or-128			6	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	40-or-128-Encry-Req		7	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	40-Stateless-Req		10	Altiga
  	//VALUE	Altiga-PPTP-Encryption-G	128-Stateless-Req		12	Altiga
  	//VALUE	Annex-Addr-Resolution-Protocol	none				0	Bay-Networks
  	//VALUE	Annex-Addr-Resolution-Protocol	DHCP				1	Bay-Networks
  	//VALUE	Annex-Audit-Level		Manager				2	Bay-Networks
  	//VALUE	Annex-Audit-Level		User				4	Bay-Networks
  	//VALUE	Annex-Audit-Level		Operator			8	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Unknown				0	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Local-disconnect		1	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		CD-Timer-Expired		2	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Remote-protocol-disc		4	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Clear-down			5	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Long-Space-disconnect		6	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Carrier-Lost			7	Bay-Networks
  	//VALUE	Annex-Modem-Disc-Reason		Modem-Retrain-Timeout		8	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Unknown				0	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Line-disconnected		1	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Dial-failed			2	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	WAN-manager-error		3	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Disconnect-reset		4	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Error-from-adm_notify		5	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Modem-down-adm_notify		6	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-protocol-disconnect		7	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Inactivity-timer		8	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	CLI-Hangup-command		9	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	CLI-last-job			10	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Session-timeout			11	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Slave-termination		12	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Abnormal-termination		13	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	DCD-wait-failed			14	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	CLI-inactivity			15	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Admin-port-reset		16	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	CLI-auth-failed			17	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Slave-auth-failed		18	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PAP-auth-failed			19	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	CHAP-auth-failed		20	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Local-modem-reset		21	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	Modem-dead			22	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-LCP-failure			23	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-IPCP-failure		24	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-IPXCP-failure		25	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-ATCP-failure		26	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-CCP-failure			27	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-MP-failure			28	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-IPCP-timeout		29	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-IPXCP-timeout		30	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-ATCP-timeout		31	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-CCP-timeout			32	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-MP-timeout			33	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-init-failure		34	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Unknown			35	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Dialback-failed		36	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Address-In-Use		37	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-No-device			38	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Modem-hangup-rcvd		39	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Hangup-rcvd			40	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Termination-rcvd		41	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Kill-rcvd			42	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Time-rcvd			43	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-No-memory			44	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Connection-Abort		45	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-VPN-LCP-failure		46	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-VPN-Auth-failure		47	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-MP-invalid-port		48	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-Invalid-device		49	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	PPP-MMP-bundle-failure		50	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	DVS-Registration-failure	51	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	DVS-Home-agent-dereg		52	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	DVS-Tunnel-no-renew		53	Bay-Networks
  	//VALUE	Annex-System-Disc-Reason	DVS-Tunnel-expired		54	Bay-Networks
  	//VALUE	Annex-Tunnel-Authen-Mode	none				0	Bay-Networks
  	//VALUE	Annex-Tunnel-Authen-Mode	prefix-suffix			1	Bay-Networks
  	//VALUE	Annex-Tunnel-Authen-Type	none				0	Bay-Networks
  	//VALUE	Annex-Tunnel-Authen-Type	kmd5-128			1	Bay-Networks
  	//VALUE	Annex-User-Level		Manager				2	Bay-Networks
  	//VALUE	Annex-User-Level		User				4	Bay-Networks
  	//VALUE	Annex-User-Level		Operator			8	Bay-Networks
  	//VALUE	Annex-User-Server-Location	local				1	Bay-Networks
  	//VALUE	Annex-User-Server-Location	remote				2	Bay-Networks
  	//VALUE	ARAP-Zone-Access		Default-Zone			1	
  	//VALUE	ARAP-Zone-Access		Inclusive-Filter		2	
  	//VALUE	ARAP-Zone-Access		Exclusive-Filter		3	
  	//VALUE	Ascend-Appletalk-Peer-Mode	Appletalk-Peer-Router		0	Ascend
  	//VALUE	Ascend-Appletalk-Peer-Mode	Appletalk-Peer-Dialin		1	Ascend
  	//VALUE	Ascend-ATM-Direct		ATM-Direct-No			0	Ascend
  	//VALUE	Ascend-ATM-Direct		ATM-Direct-Yes			1	Ascend
  	//VALUE	Ascend-ATM-Fault-Management	VC-No-Loopback			0	Ascend
  	//VALUE	Ascend-ATM-Fault-Management	VC-Segment-Loopback		1	Ascend
  	//VALUE	Ascend-ATM-Fault-Management	VC-End-To-End-Loopback		2	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-None			0	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-Default			1	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-Any			2	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-PAP			3	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-CHAP			4	Ascend
  	//VALUE	Ascend-Auth-Type		Auth-MS-CHAP			5	Ascend
  	//VALUE	Ascend-BACP-Enable		BACP-No				0	
  	//VALUE	Ascend-BACP-Enable		BACP-No				0	Ascend
  	//VALUE	Ascend-BACP-Enable		BACP-Yes			1	Ascend
  	//VALUE	Ascend-BACP-Enable		BACP-Yes			1	
  	//VALUE	Ascend-Bi-Directional-Auth	Bi-Directional-Auth-None	0	Ascend
  	//VALUE	Ascend-Bi-Directional-Auth	Bi-Directional-Auth-Allowed	1	Ascend
  	//VALUE	Ascend-Bi-Directional-Auth	Bi-Directional-Auth-Required	2	Ascend
  	//VALUE	Ascend-BIR-Enable		BIR-Enable-No			0	Ascend
  	//VALUE	Ascend-BIR-Enable		BIR-Enable-Yes			1	Ascend
  	//VALUE	Ascend-BIR-Proxy		BIR-Proxy-No			0	Ascend
  	//VALUE	Ascend-BIR-Proxy		BIR-Proxy-Yes			1	Ascend
  	//VALUE	Ascend-Bridge			Bridge-No			0	Ascend
  	//VALUE	Ascend-Bridge			Bridge-No			0	
  	//VALUE	Ascend-Bridge			Bridge-Yes			1	
  	//VALUE	Ascend-Bridge			Bridge-Yes			1	Ascend
  	//VALUE	Ascend-Bridge-Non-PPPoE		Bridge-Non-PPPoE-No		0	Ascend
  	//VALUE	Ascend-Bridge-Non-PPPoE		Bridge-Non-PPPoE-Yes		1	Ascend
  	//VALUE	Ascend-Cache-Refresh		Refresh-No			0	Ascend
  	//VALUE	Ascend-Cache-Refresh		Refresh-Yes			1	Ascend
  	//VALUE	Ascend-Call-Direction		Ascend-Call-Direction-Incoming	0	Ascend
  	//VALUE	Ascend-Call-Direction		Ascend-Call-Direction-Outgoing	1	Ascend
  	//VALUE	Ascend-Call-Type		Switched			0	Ascend
  	//VALUE	Ascend-Call-Type		Nailed				1	Ascend
  	//VALUE	Ascend-Call-Type		MegaMax				7	Ascend
  	//VALUE	Ascend-Callback			Callback-No			0	Ascend
  	//VALUE	Ascend-Callback			Callback-No			0	
  	//VALUE	Ascend-Callback			Callback-Yes			1	
  	//VALUE	Ascend-Callback			Callback-Yes			1	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	Unknown				0	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	ISDN-Telephony			1	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	Data				3	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	Telex				4	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	National			8	Ascend
  	//VALUE	Ascend-Calling-Id-Number-Plan	Private				9	Ascend
  	//VALUE	Ascend-Calling-Id-Presentatn	Allowed				0	Ascend
  	//VALUE	Ascend-Calling-Id-Presentatn	Restricted			1	Ascend
  	//VALUE	Ascend-Calling-Id-Presentatn	Number-Not-Available		2	Ascend
  	//VALUE	Ascend-Calling-Id-Screening	User-Not-Screened		0	Ascend
  	//VALUE	Ascend-Calling-Id-Screening	User-Provided-Passed		1	Ascend
  	//VALUE	Ascend-Calling-Id-Screening	User-Provided-Failed		2	Ascend
  	//VALUE	Ascend-Calling-Id-Screening	Network-Provided		3	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	Unknown				0	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	International-Number		1	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	National-Number			2	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	Network-Specific		3	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	Subscriber-Number		4	Ascend
  	//VALUE	Ascend-Calling-Id-Type-Of-Num	Abbreviated-Number		6	Ascend
  	//VALUE	Ascend-CBCP-Enable		CBCP-Not-Enabled		0	Ascend
  	//VALUE	Ascend-CBCP-Enable		CBCP-Enabled			1	Ascend
  	//VALUE	Ascend-CBCP-Mode		CBCP-No-Callback		1	Ascend
  	//VALUE	Ascend-CBCP-Mode		CBCP-User-Callback		2	Ascend
  	//VALUE	Ascend-CBCP-Mode		CBCP-Profile-Callback		3	Ascend
  	//VALUE	Ascend-CBCP-Mode		CBCP-Any-Or-No			7	Ascend
  	//VALUE	Ascend-CBCP-Mode		CBCP-Off			8	Ascend
  	//VALUE	Ascend-Ckt-Type			Ascend-PVC			0	Ascend
  	//VALUE	Ascend-Ckt-Type			Ascend-SVC			1	Ascend
  	//VALUE	Ascend-Client-Assign-DNS	DNS-Assign-No			0	Ascend
  	//VALUE	Ascend-Client-Assign-DNS	DNS-Assign-Yes			1	Ascend
  	//VALUE	Ascend-Client-Assign-WINS	WINS-Assign-No			0	Ascend
  	//VALUE	Ascend-Client-Assign-WINS	WINS-Assign-Yes			1	Ascend
  	//VALUE	Ascend-Connect-Progress		No-Progress			0	Ascend
  	//VALUE	Ascend-Connect-Progress		Call-Up				10	Ascend
  	//VALUE	Ascend-Connect-Progress		Modem-Up			30	Ascend
  	//VALUE	Ascend-Connect-Progress		Modem-Awaiting-DCD		31	Ascend
  	//VALUE	Ascend-Connect-Progress		Modem-Awaiting-Codes		32	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Started			40	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Raw-TCP-Started		41	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Telnet-Started		42	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Raw-TCP-Connected	43	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Telnet-Connected	44	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Rlogin-Started		45	Ascend
  	//VALUE	Ascend-Connect-Progress		TermSrv-Rlogin-Connected	46	Ascend
  	//VALUE	Ascend-Connect-Progress		Modem-Outdial-Call-Up		50	Ascend
  	//VALUE	Ascend-Connect-Progress		LAN-Session-Up			60	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-Opening			61	Ascend
  	//VALUE	Ascend-Connect-Progress		CCP-Opening			62	Ascend
  	//VALUE	Ascend-Connect-Progress		IPNCP-Opening			63	Ascend
  	//VALUE	Ascend-Connect-Progress		BNCP-Opening			64	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-Opened			65	Ascend
  	//VALUE	Ascend-Connect-Progress		CCP-Opened			66	Ascend
  	//VALUE	Ascend-Connect-Progress		IPNCP-Opened			67	Ascend
  	//VALUE	Ascend-Connect-Progress		BNCP-Opened			68	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Initial		69	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Starting		70	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Closed		71	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Stopped		72	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Closing		73	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Stopping		74	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Request-Sent		75	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Ack-Received		76	Ascend
  	//VALUE	Ascend-Connect-Progress		LCP-State-Ack-Sent		77	Ascend
  	//VALUE	Ascend-Connect-Progress		IPXNCP-Opened			80	Ascend
  	//VALUE	Ascend-Connect-Progress		ATNCP-Opened			81	Ascend
  	//VALUE	Ascend-Connect-Progress		BACP-Opening			82	Ascend
  	//VALUE	Ascend-Connect-Progress		BACP-Opened			83	Ascend
  	//VALUE	Ascend-Connect-Progress		V110-Up				90	Ascend
  	//VALUE	Ascend-Connect-Progress		V110-State-Opened		91	Ascend
  	//VALUE	Ascend-Connect-Progress		V110-State-Carrier		92	Ascend
  	//VALUE	Ascend-Connect-Progress		V110-State-Reset		93	Ascend
  	//VALUE	Ascend-Connect-Progress		V110-State-Closed		94	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-Voice-Bearer		0	
  	//VALUE	Ascend-Data-Svc			Switched-Voice-Bearer		0	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-56KR			1	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-56KR			1	
  	//VALUE	Ascend-Data-Svc			Switched-64K			2	
  	//VALUE	Ascend-Data-Svc			Switched-64K			2	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-64KR			3	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-64KR			3	
  	//VALUE	Ascend-Data-Svc			Switched-56K			4	
  	//VALUE	Ascend-Data-Svc			Switched-56K			4	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-384KR			5	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-384KR			5	
  	//VALUE	Ascend-Data-Svc			Switched-384K			6	
  	//VALUE	Ascend-Data-Svc			Switched-384K			6	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1536K			7	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1536K			7	
  	//VALUE	Ascend-Data-Svc			Switched-1536KR			8	
  	//VALUE	Ascend-Data-Svc			Switched-1536KR			8	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-128K			9	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-128K			9	
  	//VALUE	Ascend-Data-Svc			Switched-192K			10	
  	//VALUE	Ascend-Data-Svc			Switched-192K			10	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-256K			11	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-256K			11	
  	//VALUE	Ascend-Data-Svc			Switched-320K			12	
  	//VALUE	Ascend-Data-Svc			Switched-320K			12	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-384K-MR		13	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-384K-MR		13	
  	//VALUE	Ascend-Data-Svc			Switched-448K			14	
  	//VALUE	Ascend-Data-Svc			Switched-448K			14	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-512K			15	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-512K			15	
  	//VALUE	Ascend-Data-Svc			Switched-576K			16	
  	//VALUE	Ascend-Data-Svc			Switched-576K			16	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-640K			17	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-640K			17	
  	//VALUE	Ascend-Data-Svc			Switched-704K			18	
  	//VALUE	Ascend-Data-Svc			Switched-704K			18	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-768K			19	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-768K			19	
  	//VALUE	Ascend-Data-Svc			Switched-832K			20	
  	//VALUE	Ascend-Data-Svc			Switched-832K			20	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-896K			21	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-896K			21	
  	//VALUE	Ascend-Data-Svc			Switched-960K			22	
  	//VALUE	Ascend-Data-Svc			Switched-960K			22	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1024K			23	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1024K			23	
  	//VALUE	Ascend-Data-Svc			Switched-1088K			24	
  	//VALUE	Ascend-Data-Svc			Switched-1088K			24	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1152K			25	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1152K			25	
  	//VALUE	Ascend-Data-Svc			Switched-1216K			26	
  	//VALUE	Ascend-Data-Svc			Switched-1216K			26	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1280K			27	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1280K			27	
  	//VALUE	Ascend-Data-Svc			Switched-1344K			28	
  	//VALUE	Ascend-Data-Svc			Switched-1344K			28	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1408K			29	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1408K			29	
  	//VALUE	Ascend-Data-Svc			Switched-1472K			30	
  	//VALUE	Ascend-Data-Svc			Switched-1472K			30	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1600K			31	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1600K			31	
  	//VALUE	Ascend-Data-Svc			Switched-1664K			32	
  	//VALUE	Ascend-Data-Svc			Switched-1664K			32	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1728K			33	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1728K			33	
  	//VALUE	Ascend-Data-Svc			Switched-1792K			34	
  	//VALUE	Ascend-Data-Svc			Switched-1792K			34	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1856K			35	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-1856K			35	
  	//VALUE	Ascend-Data-Svc			Switched-1920K			36	
  	//VALUE	Ascend-Data-Svc			Switched-1920K			36	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-inherited		37	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-restricted-bearer-x30	38	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-clear-bearer-v110	39	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-restricted-64-x30	40	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-clear-56-v110		41	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-modem			42	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-atmodem		43	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-24-56		45	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-48-56		46	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-96-56		47	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-192-56		48	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-384-56		49	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-24-56R		50	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-48-56R		51	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-96-56R		52	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-192-56R		53	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-384-56R		54	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-24-64		55	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-48-64		56	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-96-64		57	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-192-64		58	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-384-64		59	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-24-64R		60	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-48-64R		61	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-96-64R		62	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-192-64R		63	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-V110-384-64R		64	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-Pots			68	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-ATM			69	Ascend
  	//VALUE	Ascend-Data-Svc			Switched-FR			70	Ascend
  	//VALUE	Ascend-DBA-Monitor		DBA-Transmit			0	Ascend
  	//VALUE	Ascend-DBA-Monitor		DBA-Transmit-Recv		1	Ascend
  	//VALUE	Ascend-DBA-Monitor		DBA-None			2	Ascend
  	//VALUE	Ascend-DHCP-Reply		DHCP-Reply-No			0	Ascend
  	//VALUE	Ascend-DHCP-Reply		DHCP-Reply-Yes			1	Ascend
  	//VALUE	Ascend-Dialout-Allowed		Dialout-Not-Allowed		0	Ascend
  	//VALUE	Ascend-Dialout-Allowed		Dialout-Allowed			1	Ascend
  	//VALUE	Ascend-Disconnect-Cause		No-Reason			0	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Not-Applicable			1	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Unknown				2	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Call-Disconnected		3	Ascend
  	//VALUE	Ascend-Disconnect-Cause		CLID-Authentication-Failed	4	Ascend
  	//VALUE	Ascend-Disconnect-Cause		CLID-RADIUS-Timeout		5	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Modem-No-DCD			10	Ascend
  	//VALUE	Ascend-Disconnect-Cause		DCD-Detected-Then-Inactive	11	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Modem-Invalid-Result-Codes	12	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-User-Quit		20	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Idle-Timeout		21	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Exit-Telnet		22	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-No-IPaddr		23	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Exit-Raw-TCP		24	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Exit-Login-Failed	25	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Exit-Raw-TCP-Disabled	26	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-CTRL-C-In-Login		27	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Destroyed		28	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-User-Closed-VCon	29	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-VCon-Destroyed		30	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Exit-Rlogin		31	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Bad-Rlogin-Option	32	Ascend
  	//VALUE	Ascend-Disconnect-Cause		TermSrv-Not-Enough-Resources	33	Ascend
  	//VALUE	Ascend-Disconnect-Cause		MPP-No-NULL-Msg-Timeout		35	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-LCP-Timeout			40	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-LCP-Negotion-Failed		41	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-PAP-Auth-Failed		42	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-CHAP-Auth-Failed		43	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-Rmt-Auth-Failed		44	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-Rcv-Terminate-Req		45	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-Rcv-Close-Event		46	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-No-NCPs-Open		47	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-MP-Bundle-Unknown		48	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-LCP-Close-MP-Add-Fail	49	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Session-Table-Full		50	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Out-Of-Resources		51	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Invalid-IP-Address		52	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Hostname-Resolution-Failed	53	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Bad-Or-Missing-Port-Number	54	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Host-Reset			60	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Connection-Refused		61	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Connection-Timeout		62	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Connection-Closed		63	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Network-Unreachable		64	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Host-Unreachable		65	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Network-Unreachable-Admin	66	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Host-Unreachable-Admin		67	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Port-Unreachable		68	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Session-Timeout			100	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Invalid-Incoming-User		101	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Disconnect-Due-To-Callback	102	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Proto-Disabled-Or-Unsupported	120	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Disconnect-Req-By-RADIUS	150	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Disconnect-Req-By-Local-Admin	151	Ascend
  	//VALUE	Ascend-Disconnect-Cause		V110-Timeout-Sync-Retry-Exceed	160	Ascend
  	//VALUE	Ascend-Disconnect-Cause		PPP-Auth-Timeout-Exceeded	170	Ascend
  	//VALUE	Ascend-Disconnect-Cause		User-Executed-Do-Hangup		180	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Remote-End-Hung-Up		185	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Resource-Has-Been-Quiesced	190	Ascend
  	//VALUE	Ascend-Disconnect-Cause		Max-Call-Duration-Reached	195	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-7168000		0	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-6272000		1	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-5120000		2	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-4480000		3	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-3200000		4	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-2688000		5	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-2560000		6	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-2240000		7	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-1920000		8	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-1600000		9	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-1280000		10	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-960000		11	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adslcap-dn-640000		12	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-auto			100	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-9504000		101	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-8960000		102	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-8000000		103	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-7168000		104	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-6272000		105	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-5120000		106	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-4480000		107	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-3200000		108	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-2688000		109	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-2560000		110	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-2240000		111	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-1920000		112	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-1600000		113	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-1280000		114	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-960000		115	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-768000		116	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-640000		117	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-512000		118	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-384000		119	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-256000		120	Ascend
  	//VALUE	Ascend-Dsl-Downstream-Limit	adsldmt-dn-128000		121	Ascend
  	//VALUE	Ascend-Dsl-Rate-Mode		Rate-Mode-AutoBaud		1	Ascend
  	//VALUE	Ascend-Dsl-Rate-Mode		Rate-Mode-Single		2	Ascend
  	//VALUE	Ascend-Dsl-Rate-Type		Rate-Type-Disabled		0	Ascend
  	//VALUE	Ascend-Dsl-Rate-Type		Rate-Type-Sdsl			1	Ascend
  	//VALUE	Ascend-Dsl-Rate-Type		Rate-Type-AdslCap		2	Ascend
  	//VALUE	Ascend-Dsl-Rate-Type		Rate-Type-AdslDmtCell		3	Ascend
  	//VALUE	Ascend-Dsl-Rate-Type		Rate-Type-AdslDmt		4	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-144000			0	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-272000			1	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-400000			2	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-528000			3	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-784000			4	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-1168000			5	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-1552000			6	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	sdsl-2320000			7	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-1088000		50	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-952000		51	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-816000		52	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-680000		53	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-544000		54	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-408000		55	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adslcap-up-272000		56	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-auto			150	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-1088000		151	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-928000		152	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-896000		153	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-800000		154	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-768000		155	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-640000		156	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-512000		157	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-384000		158	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-256000		159	Ascend
  	//VALUE	Ascend-Dsl-Upstream-Limit	adsldmt-up-128000		160	Ascend
  	//VALUE	Ascend-Event-Type		Ascend-ColdStart		1	Ascend
  	//VALUE	Ascend-Event-Type		Ascend-Session-Event		2	Ascend
  	//VALUE	Ascend-Expect-Callback		Expect-Callback-No		0	Ascend
  	//VALUE	Ascend-Expect-Callback		Expect-Callback-Yes		1	Ascend
  	//VALUE	Ascend-Filter-Required		Required-No			0	Ascend
  	//VALUE	Ascend-Filter-Required		Required-Yes			1	Ascend
  	//VALUE	Ascend-Force-56			Force-56-No			0	
  	//VALUE	Ascend-Force-56			Force-56-No			0	Ascend
  	//VALUE	Ascend-Force-56			Force-56-Yes			1	Ascend
  	//VALUE	Ascend-Force-56			Force-56-Yes			1	
  	//VALUE	Ascend-FR-Direct		FR-Direct-No			0	
  	//VALUE	Ascend-FR-Direct		FR-Direct-No			0	Ascend
  	//VALUE	Ascend-FR-Direct		FR-Direct-Yes			1	Ascend
  	//VALUE	Ascend-FR-Direct		FR-Direct-Yes			1	
  	//VALUE	Ascend-FR-Link-Mgt		Ascend-FR-No-Link-Mgt		0	Ascend
  	//VALUE	Ascend-FR-Link-Mgt		Ascend-FR-T1-617D		1	Ascend
  	//VALUE	Ascend-FR-Link-Mgt		Ascend-FR-Q-933A		2	Ascend
  	//VALUE	Ascend-FR-LinkUp		Ascend-LinkUp-Default		0	Ascend
  	//VALUE	Ascend-FR-LinkUp		Ascend-LinkUp-AlwaysUp		1	Ascend
  	//VALUE	Ascend-FR-Type			Ascend-FR-DTE			0	Ascend
  	//VALUE	Ascend-FR-Type			Ascend-FR-DCE			1	Ascend
  	//VALUE	Ascend-FR-Type			Ascend-FR-NNI			2	Ascend
  	//VALUE	Ascend-FT1-Caller		FT1-No				0	Ascend
  	//VALUE	Ascend-FT1-Caller		FT1-Yes				1	Ascend
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-None			0	
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-None			0	Ascend
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-Client		1	Ascend
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-Client		1	
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-Server		2	
  	//VALUE	Ascend-Handle-IPX		Handle-IPX-Server		2	Ascend
  	//VALUE	Ascend-History-Weigh-Type	History-Constant		0	
  	//VALUE	Ascend-History-Weigh-Type	History-Constant		0	Ascend
  	//VALUE	Ascend-History-Weigh-Type	History-Linear			1	Ascend
  	//VALUE	Ascend-History-Weigh-Type	History-Linear			1	
  	//VALUE	Ascend-History-Weigh-Type	History-Quadratic		2	
  	//VALUE	Ascend-History-Weigh-Type	History-Quadratic		2	Ascend
  	//VALUE	Ascend-IP-Pool-Chaining		IP-Pool-Chaining-No		0	Ascend
  	//VALUE	Ascend-IP-Pool-Chaining		IP-Pool-Chaining-Yes		1	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Normal			0	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Disabled			1	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Cost			2	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Reliability		4	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Throughput		8	Ascend
  	//VALUE	Ascend-IP-TOS			IP-TOS-Latency			16	Ascend
  	//VALUE	Ascend-IP-TOS-Apply-To		IP-TOS-Apply-To-Incoming	1024	Ascend
  	//VALUE	Ascend-IP-TOS-Apply-To		IP-TOS-Apply-To-Outgoing	2048	Ascend
  	//VALUE	Ascend-IP-TOS-Apply-To		IP-TOS-Apply-To-Both		3072	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Normal	0	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-One	32	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Two	64	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Three	96	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Four	128	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Five	160	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Six	192	Ascend
  	//VALUE	Ascend-IP-TOS-Precedence	IP-TOS-Precedence-Pri-Seven	224	Ascend
  	//VALUE	Ascend-IPX-Header-Compression	IPX-Header-Compression-No	0	Ascend
  	//VALUE	Ascend-IPX-Header-Compression	IPX-Header-Compression-Yes	1	Ascend
  	//VALUE	Ascend-IPX-Peer-Mode		IPX-Peer-Router			0	
  	//VALUE	Ascend-IPX-Peer-Mode		IPX-Peer-Router			0	Ascend
  	//VALUE	Ascend-IPX-Peer-Mode		IPX-Peer-Dialin			1	Ascend
  	//VALUE	Ascend-IPX-Peer-Mode		IPX-Peer-Dialin			1	
  	//VALUE	Ascend-Link-Compression		Link-Comp-None			0	
  	//VALUE	Ascend-Link-Compression		Link-Comp-None			0	Ascend
  	//VALUE	Ascend-Link-Compression		Link-Comp-Stac			1	Ascend
  	//VALUE	Ascend-Link-Compression		Link-Comp-Stac			1	
  	//VALUE	Ascend-Link-Compression		Link-Comp-Stac-Draft-9		2	Ascend
  	//VALUE	Ascend-Link-Compression		Link-Comp-MS-Stac		3	Ascend
  	//VALUE	Ascend-Multicast-Client		Multicast-No			0	Ascend
  	//VALUE	Ascend-Multicast-Client		Multicast-Yes			1	Ascend
  	//VALUE	Ascend-NAS-Port-Format		Unknown				0	Ascend
  	//VALUE	Ascend-NAS-Port-Format		2_4_6_4				1	Ascend
  	//VALUE	Ascend-NAS-Port-Format		2_4_5_5				2	Ascend
  	//VALUE	Ascend-NAS-Port-Format		1_2_2				3	Ascend
  	//VALUE	Ascend-Numbering-Plan-ID	Unknown-Numbering-Plan		0	Ascend
  	//VALUE	Ascend-Numbering-Plan-ID	ISDN-Numbering-Plan		1	Ascend
  	//VALUE	Ascend-Numbering-Plan-ID	Private-Numbering-Plan		9	Ascend
  	//VALUE	Ascend-Port-Redir-Protocol	Ascend-Proto-TCP		6	Ascend
  	//VALUE	Ascend-Port-Redir-Protocol	Ascend-Proto-UDP		17	Ascend
  	//VALUE	Ascend-PPP-VJ-1172		PPP-VJ-1172			1	
  	//VALUE	Ascend-PPP-VJ-1172		PPP-VJ-1172			1	Ascend
  	//VALUE	Ascend-PPP-VJ-Slot-Comp		VJ-Slot-Comp-No			1	
  	//VALUE	Ascend-PPP-VJ-Slot-Comp		VJ-Slot-Comp-No			1	Ascend
  	//VALUE	Ascend-PPPoE-Enable		PPPoE-No			0	Ascend
  	//VALUE	Ascend-PPPoE-Enable		PPPoE-Yes			1	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Unknown-Number			0	
  	//VALUE	Ascend-PRI-Number-Type		Unknown-Number			0	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Intl-Number			1	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Intl-Number			1	
  	//VALUE	Ascend-PRI-Number-Type		National-Number			2	
  	//VALUE	Ascend-PRI-Number-Type		National-Number			2	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Net-Specific-Number		3	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Local-Number			4	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Local-Number			4	
  	//VALUE	Ascend-PRI-Number-Type		Abbrev-Number			5	
  	//VALUE	Ascend-PRI-Number-Type		Abbrev-Number			5	Ascend
  	//VALUE	Ascend-PRI-Number-Type		Abbrev-Number			6	Ascend
  	//VALUE	Ascend-Private-Route-Required	Required-No			0	Ascend
  	//VALUE	Ascend-Private-Route-Required	Required-Yes			1	Ascend
  	//VALUE	Ascend-PW-Lifetime		Lifetime-In-Days		0	
  	//VALUE	Ascend-PW-Lifetime		Lifetime-In-Days		0	Ascend
  	//VALUE	Ascend-PW-Warntime		Days-Of-Warning			0	
  	//VALUE	Ascend-PW-Warntime		Days-Of-Warning			0	Ascend
  	//VALUE	Ascend-Require-Auth		Not-Require-Auth		0	Ascend
  	//VALUE	Ascend-Require-Auth		Not-Require-Auth		0	
  	//VALUE	Ascend-Require-Auth		Require-Auth			1	
  	//VALUE	Ascend-Require-Auth		Require-Auth			1	Ascend
  	//VALUE	Ascend-Route-Appletalk		Route-Appletalk-No		0	Ascend
  	//VALUE	Ascend-Route-Appletalk		Route-Appletalk-Yes		1	Ascend
  	//VALUE	Ascend-Route-IP			Route-IP-No			0	
  	//VALUE	Ascend-Route-IP			Route-IP-No			0	Ascend
  	//VALUE	Ascend-Route-IP			Route-IP-Yes			1	Ascend
  	//VALUE	Ascend-Route-IP			Route-IP-Yes			1	
  	//VALUE	Ascend-Route-IPX		Route-IPX-No			0	
  	//VALUE	Ascend-Route-IPX		Route-IPX-No			0	Ascend
  	//VALUE	Ascend-Route-IPX		Route-IPX-Yes			1	Ascend
  	//VALUE	Ascend-Route-IPX		Route-IPX-Yes			1	
  	//VALUE	Ascend-Send-Auth		Send-Auth-None			0	
  	//VALUE	Ascend-Send-Auth		Send-Auth-None			0	Ascend
  	//VALUE	Ascend-Send-Auth		Send-Auth-PAP			1	Ascend
  	//VALUE	Ascend-Send-Auth		Send-Auth-PAP			1	
  	//VALUE	Ascend-Send-Auth		Send-Auth-CHAP			2	
  	//VALUE	Ascend-Send-Auth		Send-Auth-CHAP			2	Ascend
  	//VALUE	Ascend-Send-Auth		Send-Auth-MS-CHAP		3	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-NotUsed	0	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-None	1	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-Other	2	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-PPP		3	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-Slip	4	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-MPP		5	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-X25		6	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-Combinet	7	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-FR		8	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-EuRaw	9	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-EuUi	10	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-Telnet	11	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-TelnetBin	12	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-RawTcp	13	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-TermServer	14	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-MP		15	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-VirtualConn	16	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-X25DChan	17	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-PseuTunPPP	18	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-IpFax	19	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-ATM		20	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-HdlcNrm	21	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-VoIp	22	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-Visa2	23	Ascend
  	//VALUE	Ascend-Service-Type		Ascend-Service-Type-NetToNet	25	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-Unused		0	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-Unknown		1	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G711-Ulaw	2	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G711-Alaw	3	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G723		4	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G729		5	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G723-64KPS	6	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-G728		7	Ascend
  	//VALUE	Ascend-Session-Type		Ascend-Session-RT24		8	Ascend
  	//VALUE	Ascend-Shared-Profile-Enable	Shared-Profile-No		0	
  	//VALUE	Ascend-Shared-Profile-Enable	Shared-Profile-No		0	Ascend
  	//VALUE	Ascend-Shared-Profile-Enable	Shared-Profile-Yes		1	Ascend
  	//VALUE	Ascend-Shared-Profile-Enable	Shared-Profile-Yes		1	
  	//VALUE	Ascend-Source-IP-Check		Source-IP-Check-No		0	Ascend
  	//VALUE	Ascend-Source-IP-Check		Source-IP-Check-Yes		1	Ascend
  	//VALUE	Ascend-SVC-Enabled		Ascend-SVC-Enabled-No		0	Ascend
  	//VALUE	Ascend-SVC-Enabled		Ascend-SVC-Enabled-Yes		1	Ascend
  	//VALUE	Ascend-Temporary-Rtes		Temp-Rtes-No			0	Ascend
  	//VALUE	Ascend-Temporary-Rtes		Temp-Rtes-Yes			1	Ascend
  	//VALUE	Ascend-Token-Immediate		Tok-Imm-No			0	Ascend
  	//VALUE	Ascend-Token-Immediate		Tok-Imm-No			0	
  	//VALUE	Ascend-Token-Immediate		Tok-Imm-Yes			1	
  	//VALUE	Ascend-Token-Immediate		Tok-Imm-Yes			1	Ascend
  	//VALUE	Ascend-TS-Idle-Mode		TS-Idle-None			0	Ascend
  	//VALUE	Ascend-TS-Idle-Mode		TS-Idle-Input			1	Ascend
  	//VALUE	Ascend-TS-Idle-Mode		TS-Idle-Input-Output		2	Ascend
  	//VALUE	Ascend-Tunneling-Protocol	ATMP-Tunnel			0	Ascend
  	//VALUE	Ascend-Tunneling-Protocol	VTP-Tunnel			1	Ascend
  	//VALUE	Ascend-User-Acct-Base		Base-10				0	Ascend
  	//VALUE	Ascend-User-Acct-Base		Base-16				1	Ascend
  	//VALUE	Ascend-User-Acct-Type		Ascend-User-Acct-None		0	Ascend
  	//VALUE	Ascend-User-Acct-Type		Ascend-User-Acct-User		1	Ascend
  	//VALUE	Ascend-User-Acct-Type		Ascend-User-Acct-User-Default	2	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	CRT				0	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	INFONET				1	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	DEFAULT				2	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	SCEN				3	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	CC_SSP				4	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	CC_TSP				5	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	HARDCOPY			6	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	HDX				7	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	SHARK				8	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	POS				9	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	NULL				10	Ascend
  	//VALUE	Ascend-X25-Pad-X3-Profile	CUSTOM				11	Ascend
  	//VALUE	Ascend-X25-Reverse-Charging	Reverse-Charging-No		0	Ascend
  	//VALUE	Ascend-X25-Reverse-Charging	Reverse-Charging-Yes		1	Ascend
  	//VALUE	Bind-Auth-Protocol		AAA-PPP-PAP			1	Redback
  	//VALUE	Bind-Auth-Protocol		AAA-PPP-CHAP			2	Redback
  	//VALUE	Bind-Auth-Protocol		AAA-PPP-CHAP-WAIT		3	Redback
  	//VALUE	Bind-Auth-Protocol		AAA-PPP-CHAP-PAP		4	Redback
  	//VALUE	Bind-Auth-Protocol		AAA-PPP-CHAP-WAIT-PAP		5	Redback
  	//VALUE	Bind-Type			AAA-AUTH-BIND			1	Redback
  	//VALUE	Bind-Type			AAA-BYPASS-BIND			2	Redback
  	//VALUE	Bind-Type			AAA-INTERFACE-BIND		3	Redback
  	//VALUE	Bind-Type			AAA-SUBSCRIBE-BIND		4	Redback
  	//VALUE	Bind-Type			AAA-TUNNEL-BIND			5	Redback
  	//VALUE	Bind-Type			AAA-SESSION-BIND		6	Redback
  	//VALUE	Bind-Type			AAA-Q8021-BIND			7	Redback
  	//VALUE	Bind-Type			AAA-MULTI-BIND			8	Redback
  	//VALUE	Cabletron-Protocol-Callable	IP-Callable			1	Cabletron
  	//VALUE	Cabletron-Protocol-Callable	Bridge-Callable			2	Cabletron
  	//VALUE	Cabletron-Protocol-Callable	IP-BR-Callable			3	Cabletron
  	//VALUE	Cabletron-Protocol-Callable	BR-IPX-Callable			6	Cabletron
  	//VALUE	Cabletron-Protocol-Callable	IP-BR-IPX-Callable		7	Cabletron
  	//VALUE	Cabletron-Protocol-Enable	IP-Enable			1	Cabletron
  	//VALUE	Cabletron-Protocol-Enable	Bridge-Enable			2	Cabletron
  	//VALUE	Cabletron-Protocol-Enable	IP-BR-Enable			3	Cabletron
  	//VALUE	Cabletron-Protocol-Enable	BR-IPX-Enable			6	Cabletron
  	//VALUE	Cabletron-Protocol-Enable	IP-BR-IPX-Enable		7	Cabletron
  	//VALUE	Cisco-Disconnect-Cause		Unknown				2	Cisco
  	//VALUE	Cisco-Disconnect-Cause		CLID-Authentication-Failure	4	Cisco
  	//VALUE	Cisco-Disconnect-Cause		No-Carrier			10	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Lost-Carrier			11	Cisco
  	//VALUE	Cisco-Disconnect-Cause		No-Detected-Result-Codes	12	Cisco
  	//VALUE	Cisco-Disconnect-Cause		User-Ends-Session		20	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Idle-Timeout			21	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Exit-Telnet-Session		22	Cisco
  	//VALUE	Cisco-Disconnect-Cause		No-Remote-IP-Addr		23	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Exit-Raw-TCP			24	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Password-Fail			25	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Raw-TCP-Disabled		26	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Control-C-Detected		27	Cisco
  	//VALUE	Cisco-Disconnect-Cause		EXEC-Program-Destroyed		28	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Timeout-PPP-LCP			40	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Failed-PPP-LCP-Negotiation	41	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Failed-PPP-PAP-Auth-Fail	42	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Failed-PPP-CHAP-Auth		43	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Failed-PPP-Remote-Auth		44	Cisco
  	//VALUE	Cisco-Disconnect-Cause		PPP-Remote-Terminate		45	Cisco
  	//VALUE	Cisco-Disconnect-Cause		PPP-Closed-Event		46	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Session-Timeout			100	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Session-Failed-Security		101	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Session-End-Callback		102	Cisco
  	//VALUE	Cisco-Disconnect-Cause		Invalid-Protocol		120	Cisco
  	//VALUE	ERX-Atm-Service-Category	UBR				1	ERX
  	//VALUE	ERX-Atm-Service-Category	UBRPCR				2	ERX
  	//VALUE	ERX-Atm-Service-Category	nrtVBR				3	ERX
  	//VALUE	ERX-Atm-Service-Category	CBR				4	ERX
  	//VALUE	ERX-Egress-Statistics		disable				0	ERX
  	//VALUE	ERX-Egress-Statistics		enable				1	ERX
  	//VALUE	ERX-Igmp-Enable			disable				0	ERX
  	//VALUE	ERX-Igmp-Enable			enable				1	ERX
  	//VALUE	ERX-Ingress-Statistics		disable				0	ERX
  	//VALUE	ERX-Ingress-Statistics		enable				1	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	IP				1	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	ATM				2	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	HDLC				3	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	ETHERNET			4	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	SERVER-PORT			5	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	ATM-1483			6	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	FRAME-RELAY			7	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	MPLS-MINOR			8	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	CBF				9	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	IP-TUNNEL			10	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	VLAN-SUB			11	ERX
  	//VALUE	ERX-Qos-Profile-Interface-Type	PPPOE-SUB			12	ERX
  	//VALUE	ERX-Sa-Validate			disable				0	ERX
  	//VALUE	ERX-Sa-Validate			enable				1	ERX
  	//VALUE	ERX-Tunnel-Nas-Port-Method	None				0	ERX
  	//VALUE	ERX-Tunnel-Nas-Port-Method	CISCO-CLID			1	ERX
  	//VALUE	Framed-Compression		None				0	
  	//VALUE	Framed-Compression		Van-Jacobsen-TCP-IP		1	
  	//VALUE	Framed-Compression		IPX-Header-Compression		2	
  	//VALUE	Framed-Protocol			PPP				1	
  	//VALUE	Framed-Protocol			SLIP				2	
  	//VALUE	Framed-Protocol			ARA				3	
  	//VALUE	Framed-Protocol			Gandalf				4	
  	//VALUE	Framed-Protocol			Xylogics			5	
  	//VALUE	Framed-Protocol			GPRS-PDP-Context		7	
  	//VALUE	Framed-Protocol			PPTP				9	
  	//VALUE	Framed-Protocol			ARA				255	
  	//VALUE	Framed-Protocol			MPP				256	
  	//VALUE	Framed-Protocol			EURAW				257	
  	//VALUE	Framed-Protocol			EUUI				258	
  	//VALUE	Framed-Protocol			X25				259	
  	//VALUE	Framed-Protocol			COMB				260	
  	//VALUE	Framed-Protocol			FR				261	
  	//VALUE	Framed-Protocol			MP				262	
  	//VALUE	Framed-Protocol			FR-CIR				263	
  	//VALUE	Framed-Protocol			X25				17825794	
  	//VALUE	Framed-Protocol			X25-PPP				17825795	
  	//VALUE	Framed-Protocol			IP-LAPB				17825796	
  	//VALUE	Framed-Protocol			IP-HDLC				17825798	
  	//VALUE	Framed-Protocol			MPR-LAPB			17825799	
  	//VALUE	Framed-Protocol			MPR-HDLC			17825800	
  	//VALUE	Framed-Protocol			FRAME-RELAY			17825801	
  	//VALUE	Framed-Protocol			X31-BCHAN			17825802	
  	//VALUE	Framed-Protocol			X75-PPP				17825803	
  	//VALUE	Framed-Protocol			X75BTX-PPP			17825804	
  	//VALUE	Framed-Protocol			X25-NOSIG			17825805	
  	//VALUE	Framed-Protocol			X25-PPP-OPT			17825806	
  	//VALUE	Framed-Routing			None				0	
  	//VALUE	Framed-Routing			Broadcast			1	
  	//VALUE	Framed-Routing			Listen				2	
  	//VALUE	Framed-Routing			Broadcast-Listen		3	
  	//VALUE	KarlNet-TurboCell-OpMode	Peer-to-Peer			0	KarlNet
  	//VALUE	KarlNet-TurboCell-OpMode	Base				1	KarlNet
  	//VALUE	KarlNet-TurboCell-OpMode	Base-Polling			2	KarlNet
  	//VALUE	KarlNet-TurboCell-OpMode	Satellite-NT			3	KarlNet
  	//VALUE	KarlNet-TurboCell-OpState	Up				0	KarlNet
  	//VALUE	KarlNet-TurboCell-OpState	Down				1	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-Local			0	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-MaxSpeed			8	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-64k			16	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-128k			24	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-256k			32	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-512k			40	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-1Mbps			48	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-T1			56	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-2T1			64	KarlNet
  	//VALUE	KarlNet-TurboCell-TxRate	TxRate-3T1			72	KarlNet
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-10BT		40	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-100BT		41	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-DS3-FR		42	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-DS3-ATM		43	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-OC3		44	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-HSSI		45	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-EIA530		46	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-T1		47	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-CHAN-T3		48	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-DS1-FR		49	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-E3-ATM		50	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-IMA-ATM		51	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-DS3-ATM-2		52	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-OC3-ATM-2		53	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-1000BSX		54	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-E1-FR		55	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-E1-ATM		56	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-E3-FR		57	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-OC3-POS		58	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-OC12-POS		59	Redback
  	//VALUE	LAC-Port-Type			NAS-PORT-TYPE-PPPOE		60	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-10BT		40	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-100BT		41	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-DS3-FR		42	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-DS3-ATM		43	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-OC3		44	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-HSSI		45	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-EIA530		46	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-T1		47	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-CHAN-T3		48	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-DS1-FR		49	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-E3-ATM		50	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-IMA-ATM		51	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-DS3-ATM-2		52	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-OC3-ATM-2		53	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-1000BSX		54	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-E1-FR		55	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-E1-ATM		56	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-E3-FR		57	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-OC3-POS		58	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-OC12-POS		59	Redback
  	//VALUE	LAC-Real-Port-Type		NAS-PORT-TYPE-PPPOE		60	Redback
  	//VALUE	LE-IPSec-Deny-Action		Drop				1	Livingston
  	//VALUE	LE-IPSec-Deny-Action		ICMP-Reject			2	Livingston
  	//VALUE	LE-IPSec-Deny-Action		Pass-Through			3	Livingston
  	//VALUE	LE-IPSec-Log-Options		SA-Success-On			1	Livingston
  	//VALUE	LE-IPSec-Log-Options		SA-Failure-On			2	Livingston
  	//VALUE	LE-IPSec-Log-Options		Console-On			3	Livingston
  	//VALUE	LE-IPSec-Log-Options		Syslog-On			4	Livingston
  	//VALUE	LE-IPSec-Log-Options		SA-Success-Off			5	Livingston
  	//VALUE	LE-IPSec-Log-Options		SA-Failure-Off			6	Livingston
  	//VALUE	LE-IPSec-Log-Options		Console-Off			7	Livingston
  	//VALUE	LE-IPSec-Log-Options		Syslog-Off			8	Livingston
  	//VALUE	LE-Multicast-Client		On				1	Livingston
  	//VALUE	LE-NAT-Log-Options		Session-Success-On		1	Livingston
  	//VALUE	LE-NAT-Log-Options		Session-Failure-On		2	Livingston
  	//VALUE	LE-NAT-Log-Options		Console-On			3	Livingston
  	//VALUE	LE-NAT-Log-Options		Syslog-On			4	Livingston
  	//VALUE	LE-NAT-Log-Options		Success-Off			5	Livingston
  	//VALUE	LE-NAT-Log-Options		Failure-Off			6	Livingston
  	//VALUE	LE-NAT-Log-Options		Console-Off			7	Livingston
  	//VALUE	LE-NAT-Log-Options		Syslog-Off			8	Livingston
  	//VALUE	LE-NAT-Sess-Dir-Fail-Action	Drop				1	Livingston
  	//VALUE	LE-NAT-Sess-Dir-Fail-Action	ICMP-Reject			2	Livingston
  	//VALUE	LE-NAT-Sess-Dir-Fail-Action	Pass-Through			3	Livingston
  	//VALUE	Login-Service			Telnet				0	
  	//VALUE	Login-Service			Rlogin				1	
  	//VALUE	Login-Service			TCP-Clear			2	
  	//VALUE	Login-Service			PortMaster			3	
  	//VALUE	Login-Service			LAT				4	
  	//VALUE	Login-Service			X25-PAD				5	
  	//VALUE	Login-Service			X25-T3POS			6	
  	//VALUE	Login-Service			TCP-Clear-Quiet			7	
  	//VALUE	Mcast-Receive			NO-RECEIVE			1	Redback
  	//VALUE	Mcast-Receive			RECEIVE				2	Redback
  	//VALUE	Mcast-Send			NO-SEND				1	Redback
  	//VALUE	Mcast-Send			SEND				2	Redback
  	//VALUE	Mcast-Send			UNSOLICITED-SEND		3	Redback
  	//VALUE	MS-Acct-Auth-Type		PAP				1	Microsoft
  	//VALUE	MS-Acct-Auth-Type		CHAP				2	Microsoft
  	//VALUE	MS-Acct-Auth-Type		MS-CHAP-1			3	Microsoft
  	//VALUE	MS-Acct-Auth-Type		MS-CHAP-2			4	Microsoft
  	//VALUE	MS-Acct-Auth-Type		EAP				5	Microsoft
  	//VALUE	MS-Acct-EAP-Type		MD5				4	Microsoft
  	//VALUE	MS-Acct-EAP-Type		OTP				5	Microsoft
  	//VALUE	MS-Acct-EAP-Type		Generic-Token-Card		6	Microsoft
  	//VALUE	MS-Acct-EAP-Type		TLS				13	Microsoft
  	//VALUE	MS-ARAP-PW-Change-Reason	Just-Change-Password		1	Microsoft
  	//VALUE	MS-ARAP-PW-Change-Reason	Expired-Password		2	Microsoft
  	//VALUE	MS-ARAP-PW-Change-Reason	Admin-Requires-Password-Change	3	Microsoft
  	//VALUE	MS-ARAP-PW-Change-Reason	Password-Too-Short		4	Microsoft
  	//VALUE	MS-BAP-Usage			Not-Allowed			0	Microsoft
  	//VALUE	MS-BAP-Usage			Allowed				1	Microsoft
  	//VALUE	MS-BAP-Usage			Required			2	Microsoft
  	//VALUE	NAS-Port-Type			Async				0	
  	//VALUE	NAS-Port-Type			Sync				1	
  	//VALUE	NAS-Port-Type			ISDN				2	
  	//VALUE	NAS-Port-Type			ISDN-V120			3	
  	//VALUE	NAS-Port-Type			ISDN-V110			4	
  	//VALUE	NAS-Port-Type			Virtual				5	
  	//VALUE	NAS-Port-Type			PAIFS				6	
  	//VALUE	NAS-Port-Type			HDLC-Clear-Channel		7	
  	//VALUE	NAS-Port-Type			X25				8	
  	//VALUE	NAS-Port-Type			X75				9	
  	//VALUE	NAS-Port-Type			SDSL				11	
  	//VALUE	NAS-Port-Type			ADSL-CAP			12	
  	//VALUE	NAS-Port-Type			ADSL-DMT			13	
  	//VALUE	NAS-Port-Type			IDSL				14	
  	//VALUE	NAS-Port-Type			Ethernet			15	
  	//VALUE	NAS-Port-Type			xDSL				16	
  	//VALUE	NAS-Port-Type			Cable				17	
  	//VALUE	NAS-Port-Type			Wireless-Other			18	
  	//VALUE	NAS-Port-Type			Token-Ring			20	
  	//VALUE	NAS-Port-Type			FDDI				21	
  	//VALUE	NAS-Port-Type			Wireless-CDMA2000		22	
  	//VALUE	NAS-Port-Type			Wireless-UMTS			23	
  	//VALUE	NAS-Port-Type			Wireless-1X-EV			24	
  	//VALUE	NAS-Port-Type			IAPP				25	
  	//VALUE	NS-Admin-Privilege		Root-Admin			1	Netscreen
  	//VALUE	NS-Admin-Privilege		All-VSYS-Root-Admin		2	Netscreen
  	//VALUE	NS-Admin-Privilege		VSYS-Admin			3	Netscreen
  	//VALUE	NS-Admin-Privilege		Read-Only-Admin			4	Netscreen
  	//VALUE	NS-Admin-Privilege		Read-Only-VSYS-Admin		5	Netscreen
  	//VALUE	Prompt				No-Echo				1	
  	//VALUE	Prompt				Echo				2	
  	//VALUE	PVC-Circuit-Padding		AAA-CIRCUIT-PADDING		1	Redback
  	//VALUE	PVC-Circuit-Padding		AAA-CIRCUIT-NO-PADDING		2	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-RAW		1	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-ROUTE1483	2	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-AUTO1483		3	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-MULTI		4	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-BRIDGE1483	5	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPP		6	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPP-SERIAL	7	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPP-NLPID	8	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPP-AUTO		9	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPPOE		10	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-L2TP		11	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ATM-PPP-LLC		12	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-AUTO1490	13	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-MULTI		14	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-BRIDGE1490	15	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-PPP		16	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-PPP-AUTO	17	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-PPPOE		18	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-ROUTE1490	19	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-FRAME-L2TP		20	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-L2TP-VC-MUXED	21	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ETH			22	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ETH-PPPOE		23	Redback
  	//VALUE	PVC-Encapsulation-Type		AAA-ENCAPS-ETH-MULTI		24	Redback
  	//VALUE	Shasta-User-Privilege		User				1	Shasta
  	//VALUE	Shasta-User-Privilege		Super-User			2	Shasta
  	//VALUE	Shasta-User-Privilege		SSuper-User			3	Shasta
  	//VALUE	Shiva-Connect-Reason		Remote				1	Shiva
  	//VALUE	Shiva-Connect-Reason		Dialback			2	Shiva
  	//VALUE	Shiva-Connect-Reason		Virtual-Connection		3	Shiva
  	//VALUE	Shiva-Connect-Reason		Bandwidth-On-Demand		4	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Remote				1	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Error				2	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Idle-Timeout			3	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Session-Timeout			4	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Admin-Disconnect		5	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Dialback			6	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Virtual-Connection		7	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Bandwidth-On-Demand		8	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Failed-Authentication		9	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Preempted			10	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Blocked				11	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Tariff-Management		12	Shiva
  	//VALUE	Shiva-Disconnect-Reason		Backup				13	Shiva
  	//VALUE	Shiva-Function			Unknown				0	Shiva
  	//VALUE	Shiva-Function			Dialin				1	Shiva
  	//VALUE	Shiva-Function			Dialout				2	Shiva
  	//VALUE	Shiva-Function			Lan-To-Lan			3	Shiva
  	//VALUE	Shiva-Link-Protocol		HDLC				1	Shiva
  	//VALUE	Shiva-Link-Protocol		ARAV1				2	Shiva
  	//VALUE	Shiva-Link-Protocol		ARAV2				3	Shiva
  	//VALUE	Shiva-Link-Protocol		SHELL				4	Shiva
  	//VALUE	Shiva-Link-Protocol		AALAP				5	Shiva
  	//VALUE	Shiva-Link-Protocol		SLIP				6	Shiva
  	//VALUE	Shiva-Type-Of-Service		Analog				1	Shiva
  	//VALUE	Shiva-Type-Of-Service		Digitized-Analog		2	Shiva
  	//VALUE	Shiva-Type-Of-Service		Digital				3	Shiva
  	//VALUE	Shiva-Type-Of-Service		Digital-V110			4	Shiva
  	//VALUE	Shiva-Type-Of-Service		Digital-V120			5	Shiva
  	//VALUE	Shiva-Type-Of-Service		Digital-Leased-Line		6	Shiva
  	//VALUE	SS3-Firewall-User-Privilege	Remote-Access			1	3com
  	//VALUE	SS3-Firewall-User-Privilege	Bypass-Filters			2	3com
  	//VALUE	SS3-Firewall-User-Privilege	VPN-Client-Access		3	3com
  	//VALUE	SS3-Firewall-User-Privilege	Access-To-VPN			4	3com
  	//VALUE	SS3-Firewall-User-Privilege	Limited-Management		5	3com
  	//VALUE	SS3-Firewall-User-Privilege	L2TP-Client-Access		6	3com
  	//VALUE	Termination-Action		Default				0	
  	//VALUE	Termination-Action		RADIUS-Request			1	
  	//VALUE	Tunnel-DNIS			DNIS				1	Redback
  	//VALUE	Tunnel-DNIS			DNIS-Only			2	Redback
  	//VALUE	Tunnel-Function			LAC-Only			1	Redback
  	//VALUE	Tunnel-Function			LNS-Only			2	Redback
  	//VALUE	Tunnel-Function			LAC-LNS				3	Redback
  	//VALUE	Tunnel-Medium-Type		IP				1	
  	//VALUE	Tunnel-Medium-Type		IP6				2	
  	//VALUE	Tunnel-Medium-Type		NSAP				3	
  	//VALUE	Tunnel-Medium-Type		HDLC				4	
  	//VALUE	Tunnel-Medium-Type		BBN				5	
  	//VALUE	Tunnel-Medium-Type		IEEE-802			6	
  	//VALUE	Tunnel-Medium-Type		E-163				7	
  	//VALUE	Tunnel-Medium-Type		E-164				8	
  	//VALUE	Tunnel-Medium-Type		F-69				9	
  	//VALUE	Tunnel-Medium-Type		X-121				10	
  	//VALUE	Tunnel-Medium-Type		IPX				11	
  	//VALUE	Tunnel-Medium-Type		Appletalk			12	
  	//VALUE	Tunnel-Medium-Type		Decnet4				13	
  	//VALUE	Tunnel-Medium-Type		Vines				14	
  	//VALUE	Tunnel-Medium-Type		E-164-NSAP			15	
  	//VALUE	Tunnel-Type			PPTP				1	
  	//VALUE	Tunnel-Type			L2F				2	
  	//VALUE	Tunnel-Type			L2TP				3	
  	//VALUE	Tunnel-Type			ATMP				4	
  	//VALUE	Tunnel-Type			VTP				5	
  	//VALUE	Tunnel-Type			AH				6	
  	//VALUE	Tunnel-Type			IP-IP-Encap			7	
  	//VALUE	Tunnel-Type			MIN-IP-IP			8	
  	//VALUE	Tunnel-Type			ESP				9	
  	//VALUE	Tunnel-Type			PPTP				10	
  	//VALUE	Tunnel-Type			DVS				11	
  	//VALUE	Tunnel-Type			IP-IP				12	
  	//VALUE	Tunnel-Type			VLAN				13	
  	//VALUE	User-Service			Login-User			1	
  	//VALUE	User-Service			Framed-User			2	
  	//VALUE	User-Service			Callback-Login			3	
  	//VALUE	User-Service			Callback-Framed			4	
  	//VALUE	User-Service			Outbound			5	
  	//VALUE	User-Service			Administrative			6	
  	//VALUE	User-Service			NAS-Prompt			7	
  	//VALUE	User-Service			Authenicate-Only		8	
  	//VALUE	User-Service			Callback-NAS-Prompt		9	
  	//VALUE	User-Service			Call-Check			10	
  	//VALUE	User-Service			Callback-Administrative		11	
  	//VALUE	User-Service			Voice				12	
  	//VALUE	User-Service			Fax				13	
  	//VALUE	User-Service			Modem-Relay			14	
  	//VALUE	User-Service			IAPP-Register			15	
  	//VALUE	User-Service			IAPP-AP-Check			16	
  	//VALUE	User-Service			Call-Check-User			129	
  	//VALUE	Versanet-Termination-Cause	Normal-Hangup-No-Error-Occurred	0	Versanet
  	//VALUE	Versanet-Termination-Cause	Call-Waiting-Caused-Disconnect	3	Versanet
  	//VALUE	Versanet-Termination-Cause	Physical-Carrier-Loss		4	Versanet
  	//VALUE	Versanet-Termination-Cause	No-err-correction-at-other-end	5	Versanet
  	//VALUE	Versanet-Termination-Cause	No-resp-to-feature-negotiation	6	Versanet
  	//VALUE	Versanet-Termination-Cause	1st-modem-async-only-2nd-sync	7	Versanet
  	//VALUE	Versanet-Termination-Cause	No-framing-technique-in-common	8	Versanet
  	//VALUE	Versanet-Termination-Cause	No-protocol-in-common		9	Versanet
  	//VALUE	Versanet-Termination-Cause	Bad-resp-to-feature-negotiation	10	Versanet
  	//VALUE	Versanet-Termination-Cause	No-sync-info-from-remote-modem	11	Versanet
  	//VALUE	Versanet-Termination-Cause	Normal-Hangup-by-Remote-modem	12	Versanet
  	//VALUE	Versanet-Termination-Cause	Retransmission-limit-reached	13	Versanet
  	//VALUE	Versanet-Termination-Cause	Protocol-violation-occurred	14	Versanet
  	//VALUE	Versanet-Termination-Cause	Lost-DTR			15	Versanet
  	//VALUE	Versanet-Termination-Cause	Received-GSTN-cleardown		16	Versanet
  	//VALUE	Versanet-Termination-Cause	Inactivity-timeout		17	Versanet
  	//VALUE	Versanet-Termination-Cause	Speed-not-supported		18	Versanet
  	//VALUE	Versanet-Termination-Cause	Long-space-disconnect		19	Versanet
  	//VALUE	Versanet-Termination-Cause	Key-abort-disconnect		20	Versanet
  	//VALUE	Versanet-Termination-Cause	Clears-previous-disc-reason	21	Versanet
  	//VALUE	Versanet-Termination-Cause	No-connection-established	22	Versanet
  	//VALUE	Versanet-Termination-Cause	Disconnect-after-three-retrains	23	Versanet
  	//
#endif  
