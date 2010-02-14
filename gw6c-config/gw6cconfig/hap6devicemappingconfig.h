// **************************************************************************
// $Id: hap6devicemappingconfig.h,v 1.3 2007/11/12 20:50:22 krause Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Wraps the NAME=VALUE configuration object to offer HAP6 Device Mapping
//   generic accessors.
//
// Author: Charles Nepveu
//
// Creation Date: February 2007
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cconfig_hap6devicemappingconfig_h__
#define __gw6cconfig_hap6devicemappingconfig_h__


#include <gw6cconfig/namevalueconfig.h>
#include <gw6cconfig/gw6cuistrings.h>
#include <vector>
#include <map>
using namespace std;


namespace gw6cconfig
{
  // Type definition.
  typedef vector<string>            t_stringarray;
  typedef map<string, string> t_stringmap;


  // ------------------------------------------------------------------------
  class HAP6DeviceMappingConfig
  {
  private:
    NameValueConfig*  m_pConfig;            // The configuration accessor object.

  public:
    // Construction / destruction.
                      HAP6DeviceMappingConfig( void );
    virtual           ~HAP6DeviceMappingConfig( void );  

    // Initialization.
    void              Initialize          ( const string& aConfigFile,
                                            const t_accessMode aEAccessMode );

    // Load / Cancel / Save.
    bool              Load                ( void );
    bool              Save                ( void );
    bool              CancelChanges       ( void );

    // Validation routine.
    bool              ValidateConfig      ( void );

    // HAP6 Device Mapping Configuration accessors.
    bool              AddDeviceMapping    ( const string& aName, const string& aAddress );
    bool              DelDeviceMapping    ( const string& aName );

    bool              GetDeviceAddress    ( const string& aName, string& aAddress ) const;
    bool              SetDeviceAddress    ( const string& aName, const string& aAddress );

    bool              GetDeviceNameList   ( t_stringarray& aNameList ) const;
    bool              GetDeviceList       ( t_stringmap& aDeviceMap ) const;

  private:
    bool              ValidateDeviceName  ( const string& aDeviceName );
    bool              ValidateIPAddress   ( const string& aIPAddress );
  };

}

#endif
