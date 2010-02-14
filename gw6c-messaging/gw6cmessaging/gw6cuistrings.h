/* *********************************************************************** */
/* $Id: gw6cuistrings.h,v 1.19 2008/03/20 16:55:31 cnepveu Exp $           */
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
#ifndef __gw6cmessaging_gw6cuistrings_h__
#define __gw6cmessaging_gw6cuistrings_h__


#ifndef ERRORT_DEFINED
#define ERRORT_DEFINED
typedef signed int error_t;
#endif


/* ----------------------------------------------------------------------- */
/* Gateway6 Client User Interface string ID definitions.                   */
/* ----------------------------------------------------------------------- */
#define GW6CM_UIS__NOERROR                          (error_t)0x00000000

#define GW6CM_UIS_WRITEPIPEFAILED                   (error_t)0x00000001
#define GW6CM_UIS_PEEKPIPEFAILED                    (error_t)0x00000002
#define GW6CM_UIS_READPIPEFAILED                    (error_t)0x00000003
#define GW6CM_UIS_PIPESERVERALRDUP                  (error_t)0x00000004
#define GW6CM_UIS_FAILCREATESERVERPIPE              (error_t)0x00000005
#define GW6CM_UIS_CLIENTALRDYCONN                   (error_t)0x00000006
#define GW6CM_UIS_CLIENTCONNFAILED                  (error_t)0x00000007
#define GW6CM_UIS_PIPESVRDISCFAIL                   (error_t)0x00000008
#define GW6CM_UIS_FAILCREATECLIENTPIPE              (error_t)0x00000009
#define GW6CM_UIS_PIPECLIDISCFAIL                   (error_t)0x0000000A

#define GW6CM_UIS_BADPACKET                         (error_t)0x0000000B
#define GW6CM_UIS_IPCDESYNCHRONIZED                 (error_t)0x0000000C
#define GW6CM_UIS_PACKETSNOTORDERED                 (error_t)0x0000000D
#define GW6CM_UIS_READBUFFERTOOSMALL                (error_t)0x0000000E
#define GW6CM_UIS_SENDBUFFERTOOBIG                  (error_t)0x0000000F
#define GW6CM_UIS_IOWAITTIMEOUT                     (error_t)0x00000010
#define GW6CM_UIS_MSGPROCDISABLED                   (error_t)0x00000011
#define GW6CM_UIS_MESSAGENOTIMPL                    (error_t)0x00000012
#define GW6CM_UIS_CWRAPALRDYINIT                    (error_t)0x00000013
#define GW6CM_UIS_CWRAPNOTINIT                      (error_t)0x00000014

// Gateway6 Client errors
#define GW6CM_UIS_ERRUNKNOWN                        (error_t)0x00000015
#define GW6CM_UIS_FAILEDBROKERLISTEXTRACTION        (error_t)0x00000016
#define GW6CM_UIS_ERRCFGDATA                        (error_t)0x00000017
#define GW6CM_UIS_ERRMEMORYSTARVATION               (error_t)0x00000018
#define GW6CM_UIS_ERRSOCKETIO                       (error_t)0x00000019
#define GW6CM_UIS_ERRFAILSOCKETCONNECT              (error_t)0x0000001A
#define GW6CM_UIS_EVNTBROKERREDIRECTION             (error_t)0x0000001B
#define GW6CM_UIS_ERRBROKERREDIRECTION              (error_t)0x0000001C
#define GW6CM_UIS_ERRTSPVERSIONERROR                (error_t)0x0000001D
#define GW6CM_UIS_ERRTSPGENERICERROR                (error_t)0x0000001E
#define GW6CM_UIS_ERRTUNMODENOTAVAILABLE            (error_t)0x0000001F
#define GW6CM_UIS_ERRNOCOMMONAUTHENTICATION         (error_t)0x00000020
#define GW6CM_UIS_ERRAUTHENTICATIONFAILURE          (error_t)0x00000021
#define GW6CM_UIS_ERRBADTUNNELPARAM                 (error_t)0x00000022
#define GW6CM_UIS_ERRINTERFACESETUPFAILED           (error_t)0x00000023
#define GW6CM_UIS_ERRKEEPALIVETIMEOUT               (error_t)0x00000024
#define GW6CM_UIS_ERRKEEPALIVEERROR                 (error_t)0x00000025
#define GW6CM_UIS_ERRTUNNELIO                       (error_t)0x00000026
#define GW6CM_UIS_ERRTUNLEASEEXPIRED                (error_t)0x00000027
#define GW6CM_UIS_ERRHAP6SETUP                      (error_t)0x00000028
#define GW6CM_UIS_ERRHAP6EXPOSEDEVICES              (error_t)0x00000029
#define GW6CM_UIS_ERRTSPSERVERTOOBUSY               (error_t)0x0000002A
#define GW6CM_UIS_ERRINVALGW6ADDR                   (error_t)0x0000002B


/* ----------------------------------------------------------------------- */
/* Get string function.                                                    */
/* ----------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" const char* get_mui_string( const error_t id );
#else
const char* get_mui_string( const error_t id );
#endif

#endif
