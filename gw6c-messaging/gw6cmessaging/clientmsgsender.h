// **************************************************************************
// $Id: clientmsgsender.h,v 1.5 2007/04/02 20:12:02 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines the different messages the Gateway6 Client GUI can send.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_clientmsgsender_h__
#define __gw6cmessaging_clientmsgsender_h__


#include <gw6cmessaging/messagesender.h>
#include <gw6cmessaging/hap6msgdata.h>
#include <gw6cmessaging/gw6cuistrings.h>
#undef PostMessage


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class ClientMsgSender
  {
  protected:
    // Construction / destruction.
                    ClientMsgSender       ( void );
  public:
    virtual         ~ClientMsgSender      ( void );

  public:
    void            Send_StatusInfoRequest( void );
    void            Send_TunnelInfoRequest( void );
    void            Send_BrokerListRequest( void );
    void            Send_HAP6ConfigInfo   ( const HAP6ConfigInfo* aHAP6CfgInfo );
    void            Send_HAP6StatusInfoRequest( void );

  protected:
    virtual void    PostMessage           ( Message* pMsg )=0;
  };

}

#endif
