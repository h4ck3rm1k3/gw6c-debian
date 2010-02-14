// **************************************************************************
// $Id: pipeclient.h,v 1.4 2008/01/08 19:33:56 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a specialized IPC Client: The Named pipe client.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_pipeclient_h__
#define __gw6cmessaging_pipeclient_h__


#include <gw6cmessaging/ipcclient.h>
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
  class PipeClient : public IPCClient, public PipeIO
  {
  private:
    IPC_HANDLE      m_PipeHandle;
    string          m_PipeName;

  public:
    // Construction / destruction
                    PipeClient            ( const string& aPipeName );
    virtual         ~PipeClient           ( void );

    // IPC Client overrides.
    virtual error_t Connect               ( void );   // Blocking
    virtual error_t Disconnect            ( void );
  };

}
#if defined(WIN32) || defined(WINCE)
#pragma warning( default:4250 )
#endif

#endif
