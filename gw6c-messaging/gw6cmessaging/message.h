// **************************************************************************
// $Id: message.h,v 1.8 2008/01/08 19:33:56 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a Gateway6 Client message for IPC communication.
//
//  Important notice:
//   ALWAYS USE `CreateMessage' AND `FreeMessage' FUNCTIONS FOR
//   CONSTRUCTION AND DESTRUCTION.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_message_h__
#define __gw6cmessaging_message_h__


#include <pal.h>


// Undefine Windows Win32 API PostMessage
#undef PostMessage


// Useful macros
#define MSG_HEADER_LEN                    offsetof(gw6cmessaging::Message::__MSG_CONTENTS, _data)
#define MSG_MAX_USERDATA                  (64260 - (MSG_HEADER_LEN))

// Message IDs definition.
// Sent from Gateway6 Client GUI - received by Gateway6 Client
#define MESSAGEID_REQUEST_STATUSINFO      0x0001  // Request for status info
#define MESSAGEID_REQUEST_TUNNELINFO      0x0002  // Request for tunnel info
#define MESSAGEID_REQUEST_BROKERLIST      0x0003  // Request for broker list
#define MESSAGEID_HAP6CONFIGINFO          0x0004  // Send HAP6 config info
#define MESSAGEID_REQUEST_HAP6STATUSINFO  0x0005  // Request for HAP6 status info

// Sent from Gateway6 Client - received by Gateway6 Client GUI
#define MESSAGEID_STATUSINFO              0x0101  // Status info message
#define MESSAGEID_TUNNELINFO              0x0102  // Tunnel info message
#define MESSAGEID_BROKERLIST              0x0103  // Broker list message
#define MESSAGEID_HAP6STATUSINFO          0x0104  // Send HAP6 status info


#if defined(WIN32) || defined(WINCE)
#pragma warning( disable: 4200 )
#endif
namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  union Message
  {
  public:
    uint8_t      rawdata[0];
    struct __MSG_CONTENTS
    {
      struct __MSG_HEADER
      {
        uint16_t _msgid;
        uint16_t _datalen;
      }          header;
      uint8_t    _data[0];
    }            msg;

    // Gets the size of the data in this class.
    uint32_t        GetRawSize            ( void ) const;

    // Static creator and destructor.
    static Message* CreateMessage         ( const uint16_t aMsgId, const uint32_t aDataLen, const uint8_t* aData );
    static void     FreeMessage           ( Message* pMsg );
    static void     AssertMessage         ( const Message* pMsg );
  };

}
#if defined(WIN32) || defined(WINCE)
#pragma warning( default: 4200 )
#endif

#endif
