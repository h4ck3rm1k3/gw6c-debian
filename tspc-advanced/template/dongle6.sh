#!/bin/sh
#
# $Id: dongle6.sh,v 1.2 2008/02/22 23:59:22 krause Exp $
#
# This source code copyright (c) Hexago Inc. 2002-2007.
#
# For license information refer to CLIENT-LICENSE.TXT
#
# Note: IPV6 support and tun Support must be enabled before calling this script.
# 


LANGUAGE=C

if [ -z $TSP_VERBOSE ]; then
   TSP_VERBOSE=0
fi

KillProcess()
{
   if [ ! -z $TSP_VERBOSE ]; then
      if [ $TSP_VERBOSE -ge 2 ]; then
         echo killing $*
      fi
   fi
   PID=`ps axww | grep $1 | grep -v grep | awk '{ print $1;}'`
   echo $PID
   if [ ! -z $PID ]; then
      kill $PID
   fi
}

Display()
{
   if [ -z $TSP_VERBOSE ]; then
      return;
   fi
   if [ $TSP_VERBOSE -lt $1 ]; then
      return;
   fi
   shift
   echo "$*"
}

Exec()
{
   if [ ! -z $TSP_VERBOSE ]; then
      if [ $TSP_VERBOSE -ge 2 ]; then
         echo $*
      fi
   fi
   $* # Execute command
   if [ $? -ne 0 ]; then
      echo "Error while executing $1"
      echo "   Command: $*"
      exit 1
   fi
}

ExecNoCheck()
{
   if [ ! -z $TSP_VERBOSE ]; then
      if [ $TSP_VERBOSE -ge 2 ]; then
         echo $*
      fi
   fi
   $* # Execute command
}

# Program localization 

Display 1 "--- Start of configuration script. ---"
Display 1 "Script: " `basename $0`

ifconfig=/sbin/ifconfig
route=/sbin/route
ipconfig=/usr/sbin/ip
radvd_script=/etc/init.d/radvd
radvd_conf=/var/etc/radvd.conf

if [ -z $TSP_HOME_DIR ]; then
   echo "TSP_HOME_DIR variable not specified!;"
   exit 1
fi

if [ ! -d $TSP_HOME_DIR ]; then
   echo "Error : directory $TSP_HOME_DIR does not exist"
   exit 1
fi
#

if [ -z $TSP_HOST_TYPE ]; then
   echo Error: TSP_HOST_TYPE not defined.
   exit 1
fi


#################################
# Run tunnel destruction script.
#################################
if [ X"${TSP_OPERATION}" = X"TSP_TUNNEL_TEARDOWN" ]; then

  Display 1 Tunnel tear down starting...


  # Remove tunnel
  if [ X"${TSP_TUNNEL_MODE}" = X"v6v4" ]; then
    ExecNoCheck $ipconfig tunnel del $TSP_TUNNEL_INTERFACE
  fi

  # Remove addresses
  PREF=`echo $TSP_CLIENT_ADDRESS_IPV6 | sed "s/:0*/:/g" |cut -d : -f1-2`
  OLDADDR=`$ifconfig $TSP_TUNNEL_INTERFACE | grep "inet6.* $PREF" | sed -e "s/^.*inet6 addr: //" -e "s/ Scope.*\$//"`
  if [ ! -z $OLDADDR ]; then
    Display 1 "Removing old IPv6 address $OLDADDR"
    Exec $ifconfig $TSP_TUNNEL_INTERFACE del $OLDADDR
  fi

  # Bring interface down.
  ExecNoCheck $ifconfig $TSP_TUNNEL_INTERFACE down

  # Delete any IPv6 route
  ExecNoCheck $route -A inet6 del ::/0 2>/dev/null # delete old default route
  ExecNoCheck $route -A inet6 del 2000::/3 2>/dev/null  # delete old gw route


  # Router deconfiguration.
  if [ X"${TSP_HOST_TYPE}" = X"router" ]; then
    # Remove prefix routing on TSP_HOME_INTERFACE
    ExecNoCheck $route -A inet6 del $TSP_PREFIX::/$TSP_PREFIXLEN

    # Remove address from TSP HOME INTERFACE
    OLDADDR=`$ifconfig $TSP_HOME_INTERFACE | grep "inet6.* $PREF" | sed -e "s/^.*inet6 addr: //" -e "s/ Scope.*\$//"`
    if [ ! -z $OLDADDR ]; then
      Display 1 "Removing old IPv6 address $OLDADDR"
      Exec $ifconfig $TSP_HOME_INTERFACE del $OLDADDR
    fi

    # Kill router advertisement daemon
    $radvd_script stop > /dev/null 2>&1
  fi


  Display 1 Tunnel tear down completed.

  exit 0
fi


if [ X"${TSP_HOST_TYPE}" = X"host" ] || [ X"${TSP_HOST_TYPE}" = X"router" ]; then
   #
   # Configured tunnel config (IPv6) 
   Display 1 "$TSP_TUNNEL_INTERFACE setup"
   if [ X"${TSP_TUNNEL_MODE}" = X"v6v4" ]; then
      Display 1 "Setting up link to $TSP_SERVER_ADDRESS_IPV4"
	ExecNoCheck $ipconfig tunnel del $TSP_TUNNEL_INTERFACE
	ExecNoCheck sleep 1
        Exec $ipconfig tunnel add $TSP_TUNNEL_INTERFACE mode sit ttl 64 remote $TSP_SERVER_ADDRESS_IPV4
   fi

   Exec $ifconfig $TSP_TUNNEL_INTERFACE up

   PREF=`echo $TSP_CLIENT_ADDRESS_IPV6 | sed "s/:0*/:/g" |cut -d : -f1-2`
   OLDADDR=`$ifconfig $TSP_TUNNEL_INTERFACE | grep "inet6.* $PREF" | sed -e "s/^.*inet6 addr: //" -e "s/ Scope.*\$//"`
   if [ ! -z $OLDADDR ]; then
      Display 1 "Removing old IPv6 address $OLDADDR"
      Exec $ifconfig $TSP_TUNNEL_INTERFACE del $OLDADDR
   fi
   Display 1 "This host is: $TSP_CLIENT_ADDRESS_IPV6/$TSP_TUNNEL_PREFIXLEN"
   Exec $ifconfig $TSP_TUNNEL_INTERFACE add $TSP_CLIENT_ADDRESS_IPV6/$TSP_TUNNEL_PREFIXLEN
   Exec $ifconfig $TSP_TUNNEL_INTERFACE mtu 1280
   # 
   # Default route  
   Display 1 "Adding default route"
   ExecNoCheck $route -A inet6 del ::/0 2>/dev/null # delete old default route
   ExecNoCheck $route -A inet6 del 2000::/3 2>/dev/null  # delete old gw route
   Exec $route -A inet6 add ::/0 dev $TSP_TUNNEL_INTERFACE
   Exec $route -A inet6 add 2000::/3 dev $TSP_TUNNEL_INTERFACE
fi

# Router configuration if required
if [ X"${TSP_HOST_TYPE}" = X"router" ]; then
   Display 1 "Router configuration"
   Display 1 "Kernel setup"
   if [ X"${TSP_PREFIXLEN}" != X"64" ]; then
      #Better way on linux to avoid loop with the remaining /48?
      $route -A inet6 add $TSP_PREFIX::/$TSP_PREFIXLEN dev $TSP_HOME_INTERFACE 2>/dev/null
   fi
   Display 1 "Adding prefix to $TSP_HOME_INTERFACE"
   OLDADDR=`$ifconfig $TSP_HOME_INTERFACE | grep "inet6.* $PREF" | sed -e "s/^.*inet6 addr: //" -e "s/ Scope.*\$//"`
   if [ ! -z $OLDADDR ]; then
      Display 1 "Removing old IPv6 address $OLDADDR"
      Exec $ifconfig $TSP_HOME_INTERFACE del $OLDADDR
   fi
   Exec $ifconfig $TSP_HOME_INTERFACE add $TSP_PREFIX::1/64
   # Router advertisement configuration 
   Display 1 "Create new $radvd_conf"
   echo "##### Automatically generated by the Gateway6 Client ####" > "$radvd_conf"
   echo "interface $TSP_HOME_INTERFACE" >> "$radvd_conf"
   echo "{" >> "$radvd_conf"
   echo " AdvSendAdvert on;" >> "$radvd_conf"
   echo " prefix $TSP_PREFIX::/64" >> "$radvd_conf"
   echo " {" >> "$radvd_conf"
   echo " AdvOnLink on;" >> "$radvd_conf"
   echo " AdvAutonomous on;" >> "$radvd_conf"
   echo " };" >> "$radvd_conf"
   echo "};" >> "$radvd_conf"
   echo "" >> "$radvd_conf"

   $radvd_script stop > /dev/null 2>&1

   if [ -f $radvd_conf ]; then
      $radvd_script start > /dev/null 2>&1
   else
      echo "Error : file $radvd_conf not found"
      exit 1
   fi
fi

Display 1 "--- End of configuration script. ---"

exit 0

#---------------------------------------------------------------------
