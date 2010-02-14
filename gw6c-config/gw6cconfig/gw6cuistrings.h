/* *********************************************************************** */
/* $Id: gw6cuistrings.h,v 1.18 2008/02/04 16:48:07 cnepveu Exp $            */
/*                                                                         */
/* Copyright (c) 2007 Hexago Inc. All rights reserved.                     */
/*                                                                         */
/*   For license information refer to CLIENT-LICENSE.TXT                   */
/*                                                                         */
/* Description:                                                            */
/*   Contains the user interface(UI) strings of the Gateway6 Configuration */
/*   subsystem.                                                            */
/*                                                                         */
/* Author: Charles Nepveu                                                  */
/*                                                                         */
/* Creation Date: November 2006                                            */
/* _______________________________________________________________________ */
/* *********************************************************************** */
#ifndef __gw6cconfig_gw6cuistrings_h__
#define __gw6cconfig_gw6cuistrings_h__


#ifndef ERRORT_DEFINED
#define ERRORT_DEFINED
typedef signed int error_t;
#endif


/* ----------------------------------------------------------------------- */
/* Gateway6 Client User Interface string ID definitions.                   */
/* ----------------------------------------------------------------------- */
#define GW6C_UIS__NOERROR                              (error_t)0x00000000
#define GW6C_UIS__GROUP_NAMEVALUEPARSER                (error_t)0x00010000
#define GW6C_UIS__NMP_OPENFAIL                         (error_t)0x00010001
#define GW6C_UIS__NMP_BADCONFIGFILE                    (error_t)0x00010002
#define GW6C_UIS__NMP_OPENFAILWRITE                    (error_t)0x00010003
#define GW6C_UIS__GROUP_GENERICCONFIG                  (error_t)0x00020000
#define GW6C_UIS__CFG_CANNOTLOADWHENCREATE             (error_t)0x00020001
#define GW6C_UIS__CFG_CANNOTAPPLYWHENREAD              (error_t)0x00020002
#define GW6C_UIS__CFG_CANNOTCANCELWHENREAD             (error_t)0x00020003
#define GW6C_UIS__CFG_CANNOTOVERRIDESAMECONTENTS       (error_t)0x00020004
#define GW6C_UIS__CFG_CANNOTOVERRIDEWHENREAD           (error_t)0x00020005
#define GW6C_UIS__GROUP_GW6CCONFIG                     (error_t)0x00030000
#define GW6C_UIS__G6C_INVALIDCONF                      (error_t)0x00030001
#define GW6C_UIS__G6C_FAILLOADDFLTCONF                 (error_t)0x00030002
#define GW6C_UIS__G6C_SUPPLYPASSWDWHENNOTANON          (error_t)0x00030003
#define GW6C_UIS__G6C_PROXYCINVALIDMODE                (error_t)0x00030004
#define GW6C_UIS__G6C_KAINTERVALINVALID                (error_t)0x00030005
#define GW6C_UIS__G6C_IFTUNV6V4ANDV6UDPV4REQUIRED      (error_t)0x00030006
#define GW6C_UIS__G6C_IFTUNV6V4REQUIRED                (error_t)0x00030007
#define GW6C_UIS__G6C_IFTUNV6UDPV4REQUIRED             (error_t)0x00030008
#define GW6C_UIS__G6C_IFTUNV4V6REQUIRED                (error_t)0x00030009
#define GW6C_UIS__GROUP_GW6CVALIDATION                 (error_t)0x00040000
#define GW6C_UIS__G6V_USERIDTOOLONG                    (error_t)0x00040001
#define GW6C_UIS__G6V_USERIDINVALIDCHRS                (error_t)0x00040002
#define GW6C_UIS__G6V_PASSWDTOOLONG                    (error_t)0x00040003
#define GW6C_UIS__G6V_SERVERMUSTBESPEC                 (error_t)0x00040004
#define GW6C_UIS__G6V_SERVERTOOLONG                    (error_t)0x00040005
#define GW6C_UIS__G6V_SERVERINVALIDCHRS                (error_t)0x00040006
#define GW6C_UIS__G6V_HOSTTYPEINVALIDVALUE             (error_t)0x00040007
#define GW6C_UIS__G6V_PREFIXLENINVALIDVALUE            (error_t)0x00040008
#define GW6C_UIS__G6V_IFPREFIXINVALIDCHRS              (error_t)0x00040009
#define GW6C_UIS__G6V_DNSSERVERSTOOLONG                (error_t)0x0004000A
#define GW6C_UIS__G6V_DNSSERVERSUNRESOLVABLE           (error_t)0x0004000B
#define GW6C_UIS__G6V_GW6CDIRDOESNTEXIST               (error_t)0x0004000C
#define GW6C_UIS__G6V_AUTHMETHODINVALIDVALUE           (error_t)0x0004000D
#define GW6C_UIS__G6V_AUTORETRYCONNECTINVALIDVALUE     (error_t)0x0004000E
#define GW6C_UIS__G6V_RETRYDELAYINVALIDVALUE           (error_t)0x0004000F
#define GW6C_UIS__G6V_KEEPALIVEINVALIDVALUE            (error_t)0x00040010
#define GW6C_UIS__G6V_KEEPALIVEINTERVINVALID           (error_t)0x00040011
#define GW6C_UIS__G6V_TUNNELMODEINVALIDVALUE           (error_t)0x00040012
#define GW6C_UIS__G6V_IFTUNV6V4INVALIDCHRS             (error_t)0x00040013
#define GW6C_UIS__G6V_IFTUNV6UDPV4INVALIDCHRS          (error_t)0x00040014
#define GW6C_UIS__G6V_IFTUNV4V6INVALIDCHRS             (error_t)0x00040015
#define GW6C_UIS__G6V_CLIENTV4INVALIDVALUE             (error_t)0x00040016
#define GW6C_UIS__G6V_CLIENTV6INVALIDVALUE             (error_t)0x00040017
#define GW6C_UIS__G6V_TEMPLATEINVALIDVALUE             (error_t)0x00040018
#define GW6C_UIS__G6V_PROXYCLIENTINVALIDVALUE          (error_t)0x00040019
#define GW6C_UIS__G6V_BROKERLISTTOOLONG                (error_t)0x0004001A
#define GW6C_UIS__G6V_BROKERLISTINVALIDCHRS            (error_t)0x0004001B
#define GW6C_UIS__G6V_LASTSERVTOOLONG                  (error_t)0x0004001C
#define GW6C_UIS__G6V_LASTSERVINVALIDCHRS              (error_t)0x0004001D
#define GW6C_UIS__G6V_ALWAYSUSERLASTSERVINVALIDVALUE   (error_t)0x0004001E
#define GW6C_UIS__G6V_LOGLEVELINVALIDVALUE             (error_t)0x0004001F
#define GW6C_UIS__G6V_LOGDEVICEINVALIDVALUE            (error_t)0x00040020
#define GW6C_UIS__G6V_LOGFILENAMETOOLONG               (error_t)0x00040021
#define GW6C_UIS__G6V_LOGFILENAMEINVALIDCHRS           (error_t)0x00040022
#define GW6C_UIS__G6V_LOGROTATIONINVALIDVALUE          (error_t)0x00040023
#define GW6C_UIS__G6V_LOGROTSZINVALIDVALUE             (error_t)0x00040024
#define GW6C_UIS__G6V_SYSLOGFACILITYINVALIDVALUE       (error_t)0x00040025
#define GW6C_UIS__G6V_DNSSERVERSINVALIDCHRS            (error_t)0x00040026
#define GW6C_UIS__G6V_HAP6PROXYENABLEDINVALIDVALUE     (error_t)0x00040027
#define GW6C_UIS__G6V_HAP6WEBENABLEDINVALIDVALUE       (error_t)0x00040028
#define GW6C_UIS__G6V_HAP6DOCROOTDOESNTEXIST           (error_t)0x00040029
#define GW6C_UIS__G6V_HAP6DOCROOTNOTSPEC               (error_t)0x0004002A
#define GW6C_UIS__G6V_HAP6INCOMPV4V6                   (error_t)0x0004002B
#define GW6C_UIS__G6V_PASSWDINVALIDCHRS                (error_t)0x0004002C
#define GW6C_UIS__G6V_IFPREFIXMUSTBESPEC               (error_t)0x0004002D
#define GW6C_UIS__G6V_LOGROTDELINVALIDVALUE            (error_t)0x0004002F
#define GW6C_UIS__G6C_PROXYANDKEEPALIVE                (error_t)0x00040030
#define GW6C_UIS__G6V_RETRYDELAYMAXINVALIDVALUE        (error_t)0x00040031
#define GW6C_UIS__G6V_RETRYDELAYGREATERRETRYDELAYMAX   (error_t)0x00040032

/* ----------------------------------------------------------------------- */
/* Get string function.                                                    */
/* ----------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" const char* get_ui_string( const error_t id );
#else
const char* get_ui_string( const error_t id );
#endif

#endif
