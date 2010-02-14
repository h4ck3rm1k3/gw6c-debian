/* *********************************************************************** */
/* $Id: gw6cuistrings.c,v 1.11 2008/03/20 16:55:33 cnepveu Exp $            */
/*                                                                         */
/* Copyright (c) 2007 Hexago Inc. All rights reserved.                     */
/*                                                                         */
/*   LICENSE NOTICE: You may use and modify this source code only if you   */
/*   have executed a valid license agreement with Hexago Inc. granting     */
/*   you the right to do so, the said license agreement governing such     */
/*   use and modifications.   Copyright or other intellectual property     */
/*   notices are not to be removed from the source code.                   */
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
#include <gw6cmessaging/gw6cuistrings.h>


/* Struct containing string IDs with the related string.                   */
typedef struct { error_t _id; const char* _str; } tGw6cUIStrings;


static const tGw6cUIStrings Gw6cUIStrings[] = {

  { GW6CM_UIS__NOERROR, "SUCCESS" },    // Should never log this, but...

  /* PIPE ERRORS */
  { GW6CM_UIS_WRITEPIPEFAILED,
    "Failed writing on the named pipe." },
  { GW6CM_UIS_PEEKPIPEFAILED,
    "Failed \"peeking\" IO status on named pipe." },
  { GW6CM_UIS_READPIPEFAILED,
    "Failed reading on the named pipe." },
  { GW6CM_UIS_PIPESERVERALRDUP,
    "Pipe server is already up." },
  { GW6CM_UIS_FAILCREATESERVERPIPE,
    "Failed creation of pipe server." },
  { GW6CM_UIS_CLIENTALRDYCONN,
    "Pipe client is already connected." },
  { GW6CM_UIS_CLIENTCONNFAILED,
    "Pipe client connection failed." },
  { GW6CM_UIS_PIPESVRDISCFAIL,
    "Pipe server disconnection failed." },
  { GW6CM_UIS_FAILCREATECLIENTPIPE,
    "Failed creation of client pipe." },
  { GW6CM_UIS_PIPECLIDISCFAIL,
    "Pipe client disconnection failed." },

  /* IPC LAYER ERRORS */
  { GW6CM_UIS_BADPACKET,
    "Invalid/erroneous IPC data packet received." },
  { GW6CM_UIS_IPCDESYNCHRONIZED,
    "IPC communication desynchronized. Need re-initialization." },
  { GW6CM_UIS_PACKETSNOTORDERED,
    "ERROR, IPC sequential packet number is not ordered." },
  { GW6CM_UIS_READBUFFERTOOSMALL,
    "IPC layer internal buffer size too small to read data packet." },
  { GW6CM_UIS_SENDBUFFERTOOBIG,
    "User message data is too big to be sent through the IPC." },
  { GW6CM_UIS_IOWAITTIMEOUT,
    "Failed acquiring IO mutex to perform requested IPC operation." },

  /* MESSAGING LAYER ERRORS */
  { GW6CM_UIS_MSGPROCDISABLED,
    "Message processing is disabled. Reception of messages is unavailable." },
  { GW6CM_UIS_MESSAGENOTIMPL,
    "Unknown message received. Processing for that message is not implemented." },
  { GW6CM_UIS_CWRAPALRDYINIT,
    "C language wrapper for messaging layer is already initialized." },
  { GW6CM_UIS_CWRAPNOTINIT,
    "C language wrapper for messaging layer is not implemented call initialize_messaging()." },

  /* GATEWAY6 CLIENT ERRORS */
  { GW6CM_UIS_ERRUNKNOWN,                 
    "Unknown error." },
  { GW6CM_UIS_FAILEDBROKERLISTEXTRACTION, 
    "Failed redirection broker list extraction." },
  { GW6CM_UIS_ERRCFGDATA, 
    "Configuration data is invalid." },
  { GW6CM_UIS_ERRMEMORYSTARVATION, 
    "Memory allocation error." },
  { GW6CM_UIS_ERRSOCKETIO, 
    "Socket I/O error." },
  { GW6CM_UIS_ERRFAILSOCKETCONNECT, 
    "Socket error, cannot connect." },
  { GW6CM_UIS_EVNTBROKERREDIRECTION, 
    "A redirection has been received from the Gateway6." },
  { GW6CM_UIS_ERRBROKERREDIRECTION, 
    "Redirection error." },
  { GW6CM_UIS_ERRTSPVERSIONERROR, 
    "The Gateway6 is not supporting this TSP protocol version." },
  { GW6CM_UIS_ERRTSPGENERICERROR, 
    "Generic TSP protocol error." },
  { GW6CM_UIS_ERRTUNMODENOTAVAILABLE, 
    "The requested tunnel mode is not available on the Gateway6." },
  { GW6CM_UIS_ERRNOCOMMONAUTHENTICATION, 
    "Authentication method is not supported by the Gateway6." },
  { GW6CM_UIS_ERRAUTHENTICATIONFAILURE, 
    "Authentication failure." },
  { GW6CM_UIS_ERRBADTUNNELPARAM, 
    "Bad tunnel parameters received from the Gateway6." },
  { GW6CM_UIS_ERRINTERFACESETUPFAILED, 
    "Failed to execute tunnel configuration script." },
  { GW6CM_UIS_ERRKEEPALIVETIMEOUT, 
    "A keepalive timeout occurred." },
  { GW6CM_UIS_ERRKEEPALIVEERROR, 
    "A keepalive network error occurred." },
  { GW6CM_UIS_ERRTUNNELIO, 
    "Internal tunnel I/O error." },
  { GW6CM_UIS_ERRTUNLEASEEXPIRED, 
    "The tunnel lease has expired." },
  { GW6CM_UIS_ERRHAP6SETUP, 
    "The HAP6 setup script did not complete successfully." },
  { GW6CM_UIS_ERRHAP6EXPOSEDEVICES, 
    "The HAP6 subsystem could not apply the HomeAccess configuration successfully." },
  { GW6CM_UIS_ERRTSPSERVERTOOBUSY,
    "The Gateway6 is too busy to handle your TSP session. Please retry later." },
  { GW6CM_UIS_ERRINVALGW6ADDR,
    "The Gateway6 address is invalid." }
};


// --------------------------------------------------------------------------
// Function : get_mui_string
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
const char* get_mui_string( const error_t id )
{
  const unsigned int n = sizeof(Gw6cUIStrings) / sizeof(Gw6cUIStrings[0]);
  unsigned int i;

  for(i=0; i<n; i++)
    if(Gw6cUIStrings[i]._id == id)
      return Gw6cUIStrings[i]._str;

  return (const char*)0;    // NULL
}
