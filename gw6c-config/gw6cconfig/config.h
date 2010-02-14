// **************************************************************************
// $Id: config.h,v 1.3 2007/01/30 18:53:06 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Provides a simple configuration accessor. This class contains means of
//   applying and cancelling configuration changes.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cconfig_config_h__
#define __gw6cconfig_config_h__


#include <gw6cconfig/parser.h>


namespace gw6cconfig
{
  // Type definitions.
  typedef enum { AM_READ, AM_CREATE, AM_RW } t_accessMode;


  // ------------------------------------------------------------------------
  class Config
  {
  protected:
    Parser*         m_pParser;            // Generic parser object.
    t_accessMode    m_eAccessMode;        // Access mode to configuration.
    string          m_sConfigFile;        // Configuration file name.

  protected:
    // Construction / destruction
                    Config                ( const string& aConfigFile,
                                            const t_accessMode aEAccessMode );
  public:
    virtual         ~Config               ( void );

    virtual bool    LoadConfiguration     ( void ); // Load config data
    virtual bool    ApplyConfiguration    ( void ); // Save changes
    virtual bool    CancelConfiguration   ( void ); // Revert changes

    virtual bool    OverrideConfiguration ( const string& aFileName );
  };

}

#endif
