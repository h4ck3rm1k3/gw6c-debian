# ###########################################################################
#
# $Id: Makefile,v 1.3 2008/03/26 16:35:00 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# Description: Makefile for module library gw6c-pal 
#              (Gateway6 Client Platform Abstraction Layer)
#
# Author: Charles Nepveu
#
# Date: August 2007
#
# ###########################################################################
#


#
# Target directory definition.
#
linux_CDIR=common unix-common
freebsd_CDIR=common unix-common
openbsd_CDIR=common unix-common
netbsd_CDIR=common unix-common netbsd
darwin_CDIR=common unix-common
sunos_CDIR=common unix-common
dongle6_CDIR=common unix-common


#
# ###########################################################################
#
.PHONY: env-check platform-obj platform-inc


# This makefile target will check the execution context and environment.
#
env-check:
	@[ -n "${PLATFORM}" ]     || { echo "Error: Invalid environment." ; exit 1 ; }
	@[ -n "${PLATFORM_DIR}" ] || { echo "Error: Invalid environment." ; exit 1 ; }
	@[ -n "${OBJS_DIR}" ]     || { echo "Error: Invalid environment." ; exit 1 ; }
	@[ -n "${DEFS_DIR}" ]     || { echo "Error: Invalid environment." ; exit 1 ; }
	@[ -n "${OUT_INC_DIR}" ]  || { echo "Error: Invalid environment." ; exit 1 ; }


# This makefile target will compile the platform PAL objects.
#
platform-obj: env-check
	@for dir in $(${PLATFORM}_CDIR) ; do \
		$(MAKE) -C $$dir platform-obj ; \
	done


# This makefile target will copy the platform includes to out_inc.
#
platform-inc: env-check
	@for dir in $(${PLATFORM}_CDIR) ; do \
		$(MAKE) -C $$dir platform-inc ; \
	done


#
# ###########################################################################
