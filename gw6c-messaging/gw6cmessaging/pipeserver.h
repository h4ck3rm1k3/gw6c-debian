// **************************************************************************
// $Id: pipeserver.h,v 1.5 2008/01/08 19:33:57 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a specialized IPC Server: The Named pipe server.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_pipeserver_h__
#define __gw6cmessaging_pipeserver_h__


#include <gw6cmessaging/ipcserver.h>
#include <gw6cmessaging/pipeio.h>
#include <gw6cmessaging/gw6cuistrings.h>
#include <string>
using namespace std;


#if defined(WIN32) || defined(WINCE)
#pragma warning( disable:4250 )
#endif
namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class PipeServer : public IPCServer, public PipeIO
  {
  private:
    string          m_PipeName;
    bool            m_bClientConnected;

  public:
    // Construction / destruction
                    PipeServer            ( const string& aPipeName );
    virtual         ~PipeServer           ( void );

    // IPC Server overrides.
    virtual error_t CreateConnectionPoint ( void );   // Non-Blocking
    virtual error_t AcceptConnection      ( void );   // Blocking
    virtual error_t CloseConnection       ( void );   // Non-Blocking
  };

}
#if defined(WIN32) || defined(WINCE)
#pragma warning( default:4250 )
#endif

#endif
