// **************************************************************************
// $Id: namevalueconfig.h,v 1.4 2007/01/30 18:53:08 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   This class provides access to the NAME=VALUE configuration data.
//   Consultation and modification of configuration data is allowed.
//   This class extends the Config class.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cconfig_namevalueconfig_h__
#define __gw6cconfig_namevalueconfig_h__


#include <gw6cconfig/config.h>
#include <list>
using namespace std;


namespace gw6cconfig
{
  // Type definitions.
  typedef list<string> stringlist;


  // ------------------------------------------------------------------------
  class NameValueConfig : public Config
  {
  public:
    // Construction / destruction
                    NameValueConfig       ( const string& aFileName, const t_accessMode aEAccessMode );
    virtual         ~NameValueConfig      ( void );

    // NameValueConfig operations
    void            GetVariableValue      ( const string& aName, string& aValue ) const;
    void            SetVariableValue      ( const string& aName, const string& aValue );
    void            RemoveVariable        ( const string& aName );
    void            GetVariableNameList   ( stringlist& aList ) const;
  };

}

#endif
