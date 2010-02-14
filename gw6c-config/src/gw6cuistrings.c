/* *********************************************************************** */
/* $Id: gw6cuistrings.c,v 1.18 2008/02/04 16:48:09 cnepveu Exp $            */
/*                                                                         */
/* Copyright (c) 2007 Hexago Inc. All rights reserved.                     */
/*                                                                         */
/*   For license information refer to CLIENT-LICENSE.TXT                   */
/*                                                                         */
/* Description:                                                            */
/*   Offers default UI string for errors and other.                        */
/*                                                                         */
/* You may translate the strings herein as you wish.                       */
/*                                                                         */
/* Author: Charles Nepveu                                                  */
/*                                                                         */
/* Creation Date: November 2006                                            */
/* _______________________________________________________________________ */
/* *********************************************************************** */
#include <gw6cconfig/gw6cuistrings.h>


/* Struct containing string IDs with the related string.                   */
typedef struct { error_t _id; const char* _str; } tGw6cUIStrings;


static const tGw6cUIStrings Gw6cUIStrings[] = {

  /* And to start with... The NameValueParser strings */
  { GW6C_UIS__GROUP_NAMEVALUEPARSER,    // title
    "Name=Value Parser Error" },
  { GW6C_UIS__NMP_OPENFAIL,
    "Failed to open specified file." },
  { GW6C_UIS__NMP_BADCONFIGFILE,
    "Bad configuration file." },
  { GW6C_UIS__NMP_OPENFAILWRITE,
    "Failed to open file to write configuration data." },

  /* Next... Config strings */
  { GW6C_UIS__GROUP_GENERICCONFIG,    // title
    "Generic Configuration Error" },
  { GW6C_UIS__CFG_CANNOTLOADWHENCREATE,
    "Cannot load configuration when access mode is CREATE." },
  { GW6C_UIS__CFG_CANNOTAPPLYWHENREAD,
    "Cannot apply configuration data when access mode is READ." },
  { GW6C_UIS__CFG_CANNOTCANCELWHENREAD,
    "Cannot cancel configuration changes when access mode is READ."},
  { GW6C_UIS__CFG_CANNOTOVERRIDESAMECONTENTS,
    "Cannot override configuration data with same contents." },
  { GW6C_UIS__CFG_CANNOTOVERRIDEWHENREAD,
    "Cannot override configuration data when access mode is READ." },

  /* Then... GW6CConfig strings */
  { GW6C_UIS__GROUP_GW6CCONFIG,    // title
    "Gateway6 Client Configuration Error" },
  { GW6C_UIS__G6C_INVALIDCONF,
    "Invalid configuration." },
  { GW6C_UIS__G6C_FAILLOADDFLTCONF,
    "Failed to load default configuration: No default configuration file"\
    " was provided during initialization." },
   { GW6C_UIS__G6C_SUPPLYPASSWDWHENNOTANON,
   "Must supply password when authentication method is NOT anonymous." },
   { GW6C_UIS__G6C_PROXYCINVALIDMODE,
    "Proxy client cannot be enabled with tunnel mode v6udpv4." },
  { GW6C_UIS__G6C_KAINTERVALINVALID,
    "Keep-alive interval cannot be 0 when keep-alive is enabled." },
  { GW6C_UIS__G6C_IFTUNV6V4ANDV6UDPV4REQUIRED,
    "(if_tunnel_v6v4=,if_tunnel_v6udpv4=)You must provide both V6V4 and "\
    "V6UDPV4 interfaces when using V6ANYV4 tunnel mode." },
  { GW6C_UIS__G6C_IFTUNV6V4REQUIRED,
    "(if_tunnel_v6v4=)You must provide the V6V4 tunnel interface when using"\
    " V6V4 tunnel mode." },
  { GW6C_UIS__G6C_IFTUNV6UDPV4REQUIRED,
    "(if_tunnel_v6udpv4=)You must provide the V6UDPV4 tunnel interface when"\
    " using V6UDPV4 tunnel mode." },
  { GW6C_UIS__G6C_IFTUNV4V6REQUIRED,
    "(if_tunnel_v4v6=)You must provide the V4V6 tunnel interface when using"\
    " V4V6 tunnel mode." },

  /* The gw6c validation strings */
  { GW6C_UIS__GROUP_GW6CVALIDATION,    // title
    "Gateway6 Client Validation Error" },
  { GW6C_UIS__G6V_USERIDTOOLONG,
    "(userid=)User ID must not be longer than 253 characters." },
  { GW6C_UIS__G6V_USERIDINVALIDCHRS,
    "(userid=)Invalid characters found in user name." },
  { GW6C_UIS__G6V_PASSWDTOOLONG,
    "(passwd=)Password must not be longer than 128 characters." },
  { GW6C_UIS__G6V_PASSWDINVALIDCHRS,
    "(passwd=)Invalid characters found in password." },
  { GW6C_UIS__G6V_SERVERMUSTBESPEC,
    "(server=)A server MUST be specified." },
  { GW6C_UIS__G6V_SERVERTOOLONG,
    "(server=)Server must not be longer than 1025 characters." },
  { GW6C_UIS__G6V_SERVERINVALIDCHRS,
    "(server=)Invalid characters found in server string." },
  { GW6C_UIS__G6V_HOSTTYPEINVALIDVALUE,
    "(host_type=)Host type must be: <router|host>." },
  { GW6C_UIS__G6V_PREFIXLENINVALIDVALUE,
    "(prefixlen=)Prefix length must be between 0 and 128." },
  { GW6C_UIS__G6V_IFPREFIXINVALIDCHRS,
    "(if_prefix=)Invalid characters found in interface name." },
  { GW6C_UIS__G6V_IFPREFIXMUSTBESPEC,
    "(if_prefix=)Interface prefix must be supplied when host_type is 'router'." },
  { GW6C_UIS__G6V_DNSSERVERSTOOLONG,
    "(dns_server=)DNS servers string must not be longer than 1025 characters." },
  { GW6C_UIS__G6V_DNSSERVERSUNRESOLVABLE,
    "(dns_server=)Failed to resolve one or more DNS servers found in configuration." },
  { GW6C_UIS__G6V_GW6CDIRDOESNTEXIST,
    "(gw6_dir=)The directory does not exist." },
  { GW6C_UIS__G6V_AUTHMETHODINVALIDVALUE,
    "(auth_method=)Authorization method must be: <anonymous|"\
                 "any|digest-md5|plain|passdss-3des-1>." },
  { GW6C_UIS__G6V_AUTORETRYCONNECTINVALIDVALUE,
    "(retry_connect=)Retry connection must be:<yes|no>" },
  { GW6C_UIS__G6V_RETRYDELAYINVALIDVALUE,
    "(retry_delay=)Retry delay must be between 0 and 3600." },
  { GW6C_UIS__G6V_KEEPALIVEINVALIDVALUE,
    "(keepalive=)Keep-alive must be: <yes|no>" },
  { GW6C_UIS__G6V_KEEPALIVEINTERVINVALID,
    "(keepalive_interval=)Keep-alive interval must be positive." },
  { GW6C_UIS__G6V_TUNNELMODEINVALIDVALUE,
    "(tunnel_mode=)Tunnel mode must be: <v6anyv4|v6v4|v6udpv4|v4v6>" },
  { GW6C_UIS__G6V_IFTUNV6V4INVALIDCHRS,
    "(if_tunnel_v6v4=)Invalid characters found in interface name." },
  { GW6C_UIS__G6V_IFTUNV6UDPV4INVALIDCHRS,
    "(if_tunnel_v6udpv4=)Invalid characters found in interface name." },
  { GW6C_UIS__G6V_IFTUNV4V6INVALIDCHRS,
    "(if_tunnel_v4v6=)Invalid characters found in interface name." },
  { GW6C_UIS__G6V_CLIENTV4INVALIDVALUE,
    "(client_v4=)Invalid IPv4 address. Address must be: <auto|A.B.C.D>." },
  { GW6C_UIS__G6V_CLIENTV6INVALIDVALUE,
    "(client_v6=)IPv6 address must be: <auto|X:X::X:X>." },
  { GW6C_UIS__G6V_TEMPLATEINVALIDVALUE,
    "(template=)Template must be: <checktunnel|freebsd|netbsd|"\
                 "linux|windows|darwin|cisco|solaris|openbsd|openwrt|dongle6>" },
  { GW6C_UIS__G6V_PROXYCLIENTINVALIDVALUE,
    "(proxy_client=)Proxy client must be: <yes|no>" },
  { GW6C_UIS__G6V_BROKERLISTTOOLONG,
    "(broker_list=)Broker list filename cannot be greater than 256 characters." },
  { GW6C_UIS__G6V_BROKERLISTINVALIDCHRS,
    "(broker_list=)Invalid characters found in broker list file name." },
  { GW6C_UIS__G6V_LASTSERVTOOLONG,
    "(last_server=)Last server filename cannot be greater than 256 characters." },
  { GW6C_UIS__G6V_LASTSERVINVALIDCHRS,
    "(last_server=)Invalid characters found in last server file name." },
  { GW6C_UIS__G6V_ALWAYSUSERLASTSERVINVALIDVALUE,
    "(always_use_same_server=)Value must be: <yes|no>" },
  { GW6C_UIS__G6V_LOGLEVELINVALIDVALUE,
    "(log=)Log level must be between 0 and 3." },
  { GW6C_UIS__G6V_LOGDEVICEINVALIDVALUE,
    "(log=)Log device must be: <console|stderr|file|syslog>" },
  { GW6C_UIS__G6V_LOGFILENAMETOOLONG,
    "(log_filename=)Log filename cannot be greater than 256 characters." },
  { GW6C_UIS__G6V_LOGFILENAMEINVALIDCHRS,
    "(log_filename=)Invalid characters found in log file name." },
  { GW6C_UIS__G6V_LOGROTATIONINVALIDVALUE,
    "(log_rotation=)Log rotation must be: <yes|no>" },
  { GW6C_UIS__G6V_LOGROTSZINVALIDVALUE,
    "(log_rotation_size=)Log rotation size(in KB) must be: <16|32|128|1024>" },
  { GW6C_UIS__G6V_LOGROTDELINVALIDVALUE,
    "(log_rotation_delete=)Log rotation deletion must be: <yes|no>" },
  { GW6C_UIS__G6V_SYSLOGFACILITYINVALIDVALUE,
    "(syslog_facility=)Syslog facility must be: <USER|LOCAL0|"\
                 "LOCAL1|LOCAL2|LOCAL3|LOCAL4|LOCAL5|LOCAL6|LOCAL7>" },
  { GW6C_UIS__G6V_DNSSERVERSINVALIDCHRS,
    "(dns_server=)One or more DNS server specified contains invalid characters." },
  { GW6C_UIS__G6V_HAP6PROXYENABLEDINVALIDVALUE,
    "(hap6_proxy_enabled=)Home Access must be: <yes|no>" },
  { GW6C_UIS__G6V_HAP6WEBENABLEDINVALIDVALUE,
    "(hap6_web_enabled=)Home Web must be: <yes|no>" },
  { GW6C_UIS__G6V_HAP6DOCROOTDOESNTEXIST,
    "(hap6_document_root=)Home Web document root must exist." },
  { GW6C_UIS__G6V_HAP6DOCROOTNOTSPEC,
    "(hap6_document_root=)Must be specified when hap6_web_enabled=yes." },
  { GW6C_UIS__G6V_HAP6INCOMPV4V6,
    "(tunnel_mode=)Tunnel mode cannot be V4V6 with Home Access or Home Web." },
  { GW6C_UIS__G6C_PROXYANDKEEPALIVE,
    "(keepalive=)Keep-alives cannot be turned on when proxy mode is on." },
  { GW6C_UIS__G6V_RETRYDELAYMAXINVALIDVALUE,
    "(retry_delay_max=)Retry delay max must be between 0 and 3600." },
  { GW6C_UIS__G6V_RETRYDELAYGREATERRETRYDELAYMAX,
    "(retry_delay_max=)Retry delay max must be greater than retry delay." }
};


// --------------------------------------------------------------------------
// Function : get_ui_string
//
// Description:
//   Returns the user interface string specified by the id.
//
// Arguments:
//   id: int [IN], The string ID.
//
// Return values:
//   The UI string.
//
// Exceptions: (none)
//
// --------------------------------------------------------------------------
const char* get_ui_string( const error_t id )
{
  const unsigned int n = sizeof(Gw6cUIStrings) / sizeof(Gw6cUIStrings[0]);
  unsigned int i;

  for(i=0; i<n; i++)
    if(Gw6cUIStrings[i]._id == id)
      return Gw6cUIStrings[i]._str;

  return (const char*)0;    // NULL
}
