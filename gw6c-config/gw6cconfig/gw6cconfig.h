// **************************************************************************
// $Id: gw6cconfig.h,v 1.13 2008/02/04 16:48:07 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Wraps the NAME=VALUE configuration object to offer
//   Gateway6-Client-oriented configuration data accessors(get/set), along
//   with validation routines and error handling.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cconfig_gw6cconfig_h__
#define __gw6cconfig_gw6cconfig_h__


#include <gw6cconfig/namevalueconfig.h>
#include <gw6cconfig/gw6cuistrings.h>
#include <vector>
using namespace std;


namespace gw6cconfig
{
  // Type definitions.
  typedef vector<error_t> t_errorarray;


  // ------------------------------------------------------------------------
  class GW6CConfig
  {
  private:
    NameValueConfig*  m_pConfig;            // The configuration accessor object.
    string            m_sDfltCfgFile;       // The default config file name (for LoadDefault()).
    t_errorarray      m_lsValidationErrors; // The list of validation errors(for ValidateConfigData()).
    bool              m_bValid;             // A boolean indicating if data can successfully be retrieved or set.

  public:
    // Construction / destruction.
                      GW6CConfig          ( void );
    virtual           ~GW6CConfig         ( void );

    // Initialization.
    void              Initialize          ( const string& aConfigFile,
                                            const t_accessMode aEAccessMode,
                                            const string& aDfltCfgFile = "" );

    // Load / Cancel / Save / Load defaults.
    bool              Load                ( void );
    bool              Save                ( void );
    bool              CancelChanges       ( void );
    bool              LoadDefaults        ( void );

  protected:
    // Validation and error retrieval routines
    bool              ValidateConfigData  ( void ); // Used by ::Load()
  public:
    bool              IsConfigurationValid( void ) { return m_bValid; }
    const t_errorarray& GetValidationErrors ( void ) { return m_lsValidationErrors; }

  public:
    // Gateway6 Client Configuration Data accessors.
    void              Get_UserID          ( string& sUserID ) const;
    void              Set_UserID          ( const string& sUserID );

    void              Get_Passwd          ( string& sPasswd ) const;
    void              Set_Passwd          ( const string& sPasswd );

    void              Get_Server          ( string& sServer ) const;
    void              Set_Server          ( const string& sServer );

    void              Get_HostType        ( string& sHostType ) const;
    void              Set_HostType        ( const string& sHostType );

    void              Get_PrefixLen       ( string& sPrefixLen ) const;
    void              Set_PrefixLen       ( const string& sPrefixLen );

    void              Get_IfPrefix        ( string& sIfPrefix ) const;
    void              Set_IfPrefix        ( const string& sIfPrefix );

    void              Get_DnsServer       ( string& sDnsServer ) const;
    void              Set_DnsServer       ( const string& sDnsServer );

    void              Get_Gw6cDir         ( string& sGw6cDir ) const;
    void              Set_Gw6cDir         ( const string& sGw6cDir );

    void              Get_AuthMethod      ( string& sAuthMethod ) const;
    void              Set_AuthMethod      ( const string& sAuthMethod );

    void              Get_AutoRetryConnect( string& sAutoRetryConnect ) const;
    void              Set_AutoRetryConnect( const string& sAutoRetryConnect );

    void              Get_RetryDelay      ( string& sRetryDelay ) const;
    void              Set_RetryDelay      ( const string& sRetryDelay );

    void              Get_RetryDelayMax   ( string& sRetryDelayMax ) const;
    void              Set_RetryDelayMax   ( const string& sRetryDelayMax );

    void              Get_KeepAlive       ( string& sKeepAlive ) const;
    void              Set_KeepAlive       ( const string& sKeepAlive );

    void              Get_KeepAliveInterval( string& sKeepAliveInterval ) const;
    void              Set_KeepAliveInterval( const string& sKeepAliveInterval );

    void              Get_TunnelMode      ( string& sTunnelMode ) const;
    void              Set_TunnelMode      ( const string& sTunnelMode );

    void              Get_IfTunV6V4       ( string& sIfTunV6V4 ) const;
    void              Set_IfTunV6V4       ( const string& sIfTunV6V4 );

    void              Get_IfTunV6UDPV4    ( string& sIfTunV6UDPV4 ) const;
    void              Set_IfTunV6UDPV4    ( const string& sIfTunV6UDPV4 );

    void              Get_IfTunV4V6       ( string& sIfTunV4V6 ) const;
    void              Set_IfTunV4V6       ( const string& sIfTunV4V6 );

    void              Get_ClientV4        ( string& sClientV4 ) const;
    void              Set_ClientV4        ( const string& sClientV4 );

    void              Get_ClientV6        ( string& sClientV6 ) const;
    void              Set_ClientV6        ( const string& sClientV6 );

    void              Get_Template        ( string& sTemplate ) const;
    void              Set_Template        ( const string& sTemplate );

    void              Get_ProxyClient     ( string& sProxyClient ) const;
    void              Set_ProxyClient     ( const string& sProxyClient );

    void              Get_BrokerLstFile   ( string& sBrokerLstFile ) const;
    void              Set_BrokerLstFile   ( const string& sBrokerLstFile );

    void              Get_LastServFile    ( string& sLastServFile ) const;
    void              Set_LastServFile    ( const string& sLastServFile );

    void              Get_AlwaysUseLastSrv( string& sAlwaysUseLastSrv ) const;
    void              Set_AlwaysUseLastSrv( const string& sAlwaysUseLastSrv );

    void              Set_Log             ( const string& sLogDevice, const string& sLogLevel );
    void              Get_Log             ( const string& sLogDevice, string& sLogLevel ) const;

    void              Get_LogFileName     ( string& sLogFileName ) const;
    void              Set_LogFileName     ( const string& sLogFileName );

    void              Get_LogRotation     ( string& sLogRotation ) const;
    void              Set_LogRotation     ( const string& sLogRotation );

    void              Get_LogRotationSz   ( string& sLogRotationSz ) const;
    void              Set_LogRotationSz   ( const string& sLogRotationSz );

    void              Get_LogRotationDel  ( string& sLogRotationDel ) const;
    void              Set_LogRotationDel  ( const string& sLogRotationDel );

    void              Get_SysLogFacility  ( string& sSysLogFacility ) const;
    void              Set_SysLogFacility  ( const string& sSysLogFacility );

    void              Get_Hap6ProxyEnabled( string& sHap6ProxyEnabled ) const;
    void              Set_Hap6ProxyEnabled( const string& sHap6ProxyEnabled );

    void              Get_Hap6WebEnabled  ( string& sHap6WebEnabled ) const;
    void              Set_Hap6WebEnabled  ( const string& sHap6WebEnabled );

    void              Get_Hap6DocumentRoot( string& sHap6DocumentRoot ) const;
    void              Set_Hap6DocumentRoot( const string& sHap6DocumentRoot );
  };

}

#endif
