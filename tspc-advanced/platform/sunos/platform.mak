# ###########################################################################
#
# $Id: platform.mak,v 1.2 2008/01/09 15:09:19 cnepveu Exp $
#
# Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
#  This file contains platform-specific makefile rules and symbols.
#
# ###########################################################################
#

# Additional platform CFLAGS.
#
PLATFORM_CFLAGS=-I/usr/sfw/include

# Platform default interface names for each tunnel mode.
#
PLATFORM_V6V4=ip.tun0
PLATFORM_V6UDPV4=
PLATFORM_V4V6=
