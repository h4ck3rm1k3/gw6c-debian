// **************************************************************************
// $Id: guimessengerimpl.h,v 1.5 2007/02/23 21:30:24 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   This is the Gateway6 Client GUI implementation of the messenger 
//   subsystem. The naming of the derived class as `client' indicate that 
//   the Gateway6 Client GUI is the client-side of the messaging subsystem.
//   (The GW6C service is the server-side of the messaging subsystem.)
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_guimessengerimpl_h__
#define __gw6cmessaging_guimessengerimpl_h__


#include <gw6cmessaging/clientmsgsender.h>
#include <gw6cmessaging/clientmsgtranslator.h>
#include <gw6cmessaging/communicationsmgr.h>
#undef PostMessage       // Because of stupid windows API PostMessage method

namespace gw6cmessaging
{

  // ------------------------------------------------------------------------
  class GUIMessengerImpl : public ClientMsgSender, public ClientMsgTranslator
  {
  public:
    typedef void    (*RecvStatusInfo)     ( const Gw6cStatusInfo* );
    typedef void    (*RecvTunnelInfo)     ( const Gw6cTunnelInfo* );
    typedef void    (*RecvBrokerList)     ( const Gw6cBrokerList* );
    typedef void    (*RecvHAP6StatusInfo) ( const HAP6StatusInfo* );

  public:
    // Handling functions.
    RecvStatusInfo  m_RecvStatusInfo;
    RecvTunnelInfo  m_RecvTunnelInfo;
    RecvBrokerList  m_RecvBrokerList;
    RecvHAP6StatusInfo m_RecvHAP6StatusInfo;
  private:
    CommunicationsManager m_CommManager;


  public:
                    GUIMessengerImpl      ( void );
    virtual         ~GUIMessengerImpl     ( void );


    // Message processing functions.
    void            EnableProcessing      ( void );
    void            DisableProcessing     ( void );


    // Overrides from the ClientMsgTranslator:
    error_t         Recv_StatusInfo       ( const Gw6cStatusInfo* aStatusInfo );
    error_t         Recv_TunnelInfo       ( const Gw6cTunnelInfo* aTunnelInfo );
    error_t         Recv_BrokerList       ( const Gw6cBrokerList* aBrokerList );
    error_t         Recv_HAP6StatusInfo   ( const HAP6StatusInfo* aHAP6StatusInfo );

    // Overrides from the ClientMsgSender:
    void            PostMessage           ( Message* pMsg );
  };

}

#endif
