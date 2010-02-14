# ###########################################################################
#
# $Id: Makefile,v 1.33 2008/01/09 15:08:41 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# Description: GNU Makefile for Gateway6 Client application.
#              This application requires the following modules:
#              - gw6c-pal      : Platform Abstraction Layer
#              - gw6c-config   : Configuration Subsystem
#              - gw6c-messaging: Messaging Subsystem
#
# Usage:
#       make [platform=<your platform>] [DEBUG=1] all
#       make [platform=<your platform>] <installdir=/path/to/install> install
#       This makefile will attempt to detect your platform if not supplied.
#
# Author: Charles Nepveu
#
# Date: October 2007
#
# ###########################################################################
#

# NOTE: This makefile MUST be interpreted by GNU make.

PWD           :=$(shell pwd)
PLATFORM_DIR  :=$(PWD)/platform
OBJS_DIR      :=$(PWD)/objs
BIN_DIR       :=$(PWD)/bin
TARGET        :=$(BIN_DIR)/gw6c
GW6CPAL_DIR   :=$(PWD)/../gw6c-pal
GW6CPAL_INCDIR:=$(GW6CPAL_DIR)/out_inc
GW6CPAL_DEFDIR:=$(GW6CPAL_DIR)/defs
GW6CPAL_LIBDIR:=$(GW6CPAL_DIR)/out_lib
GW6CCFG_DIR   :=$(PWD)/../gw6c-config
GW6CCFG_INCDIR:=$(GW6CCFG_DIR)
GW6CCFG_LIBDIR:=$(GW6CCFG_DIR)/lib
GW6CMSG_DIR   :=$(PWD)/../gw6c-messaging
GW6CMSG_INCDIR:=$(GW6CMSG_DIR)
GW6CMSG_LIBDIR:=$(GW6CMSG_DIR)/lib

PLATFORM      :=$(shell [ -z "$(platform)" ] && uname | tr "[A-Z]" "[a-z]" || echo "$(platform)" )
SUPPORTED_PLATFORMS=linux netbsd freebsd openbsd darwin sunos dongle6

INSTALL_DIR   :=$(DESTDIR)
INSTALL_BIN   :=$(INSTALL_DIR)/bin
INSTALL_MAN   :=$(INSTALL_DIR)/man
INSTALL_TEMPL :=$(INSTALL_DIR)/template


SUBDIRS=$(PWD)/src/lib \
	$(PWD)/src/net \
	$(PWD)/src/tsp \
	$(PWD)/src/xml \
	$(PLATFORM_DIR)/unix-common \
	$(PLATFORM_DIR)/$(PLATFORM) \
	$(PWD)/template \
	$(PWD)/conf \
	$(PWD)/man

CC_INC_PATHS=-I$(PLATFORM_DIR)/$(PLATFORM) -I$(PWD)/include -I$(GW6CPAL_INCDIR) -I$(GW6CPAL_DEFDIR) -I$(GW6CCFG_INCDIR) -I$(GW6CMSG_INCDIR)
LD_LIB_PATHS=-L$(GW6CPAL_LIBDIR) -L$(GW6CCFG_LIBDIR) -L$(GW6CMSG_LIBDIR)
LD_LIBRARIES=-lgw6cpal -lgw6cconfig -lgw6cmessaging

# Export these variables to sub-makes.
export PLATFORM_DIR PLATFORM BIN_DIR OBJS_DIR TARGET DEBUG CC_INC_PATHS LD_LIB_PATHS LD_LIBRARIES INSTALL_DIR INSTALL_BIN INSTALL_MAN INSTALL_TEMPL


#
# ###########################################################################
#
.PHONY: all platform-check check-gw6c-pal check-gw6c-config check-gw6c-messaging build-gw6c check-gw6c-install install clean cleanall

all: platform-check check-gw6c-pal check-gw6c-config check-gw6c-messaging build-gw6c


# This makefile target will check the platform.
#
platform-check:
	@for plat in ${SUPPORTED_PLATFORMS} ; do \
		[ "${PLATFORM}" = "$$plat" ] && platform_ok=xxx || platform_ok=$$platform_ok ; \
	done && ([ -z "$$platform_ok" ] && { \
	    echo ; \
	    echo "Error: Target platform <${PLATFORM}> is invalid!"; \
	    echo "Syntax: make platform=<target platform> all"; \
	    echo ; \
	    echo "    where <target platform> is one of the following:"; \
	    echo "        linux        for Linux."          ; \
	    echo "        freebsd      for FreeBSD."        ; \
	    echo "        openbsd      for OpenBSD."        ; \
	    echo "        netbsd       for NetBSD."         ; \
	    echo "        darwin       for Mac OS X darwin."; \
	    echo "        openwrt      for OpenWRT."        ; \
	    echo "        sunos        for Sun/Solaris."    ; \
	    echo ; \
	    exit 1;\
	} || echo "Building Gateway6 Client for platform ${PLATFORM} ..." ; )


# This makefile target will check and build the Gateway6 Client Platform 
# Abstraction Layer if it is not built.
#
check-gw6c-pal:
	@[ -d ${GW6CPAL_DIR} ] || { \
	    echo "Gateway6 Client Platform Abstraction Layer module is not found. (${GW6CPAL_DIR})"; \
	    exit 1 ; \
	}
	@[ -f ${GW6CPAL_LIBDIR}/libgw6cpal.a ] || { \
	    echo "Building gw6c-pal module ..." ; \
	    $(MAKE) -C ${GW6CPAL_DIR} ; \
	}


# This makefile target will check and build the Gateway6 Client Configuration
# Subsystem if it is not built.
#
check-gw6c-config:
	@[ -d ${GW6CCFG_DIR} ] || { \
	    echo "Gateway6 Client Configuration Subsystem module is not found. (${GW6CCFG_DIR})"; \
	    exit 1 ; \
	}
	@[ -f ${GW6CCFG_LIBDIR}/libgw6cconfig.a ] || { \
	    echo "Building gw6c-config module ..." ; \
	    $(MAKE) -C ${GW6CCFG_DIR} ; \
	}


# This makefile target will check and build the Gateway6 Client Messaging
# Subsystem if it is not built.
#
check-gw6c-messaging:
	@[ -d ${GW6CMSG_DIR} ] || { \
	    echo "Gateway6 Client Messaging Subsystem module is not found. (${GW6CMSG_DIR})"; \
	    exit 1 ; \
	}
	@[ -f ${GW6CMSG_LIBDIR}/libgw6cmessaging.a ] || { \
	    echo "Building gw6c-messaging module ..." ; \
	    $(MAKE) -C ${GW6CMSG_DIR} ; \
	}


# This makefile target will build the Gateway6 Client.
#
build-gw6c:
	mkdir -p $(OBJS_DIR)
	mkdir -p $(BIN_DIR)
	@for dir in ${SUBDIRS}; do \
	    $(MAKE) -C $$dir all || exit 1; \
	done


# This makefile target will install the Gateway6 Client.
#
check-gw6c-install:
	@[ -n "$(INSTALL_DIR)" ] || { \
	    echo ; \
	    echo "Error: You must specify the install directory"; \
	    echo "Syntax: make [platform=<os-type>] installdir=</path/to/install> install"; \
	    echo ; \
	    exit 1;\
	}

install: check-gw6c-install all
	@mkdir -p $(INSTALL_DIR)
	@mkdir -p $(INSTALL_BIN)
	@mkdir -p $(INSTALL_MAN)
	@mkdir -p $(INSTALL_TEMPL)

	@for dir in ${SUBDIRS}; do \
	    $(MAKE) -C $$dir install || exit 1; \
	done

	@cp $(TARGET) $(INSTALL_BIN)
	@cp $(BIN_DIR)/gw6c.conf.sample $(INSTALL_BIN)
	@[ -f $(INSTALL_BIN)/gw6c.conf ] || { \
	    cp $(INSTALL_BIN)/gw6c.conf.sample $(INSTALL_BIN)/gw6c.conf; \
	}


# This makefile target will clean the build tree of the Gateway6 Client.
#
clean:
	@for dir in ${SUBDIRS}; do \
	    $(MAKE) -C $$dir clean || exit 1; \
	done
	rm -rf $(TARGET) $(BIN_DIR)/gw6c.conf.sample $(OBJS_DIR)


# This makefile target will clean the build tree of the Gateway6 Client,
# and the submodules.
#
cleanall: clean
	$(MAKE) -C ${GW6CMSG_DIR} clean
	$(MAKE) -C ${GW6CCFG_DIR} clean
	$(MAKE) -C ${GW6CPAL_DIR} clean
