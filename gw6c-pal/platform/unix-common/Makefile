# ###########################################################################
#
# $Id: Makefile,v 1.6 2008/02/29 17:23:01 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# Description: Makefile for unix common platforms
#
# Author: Charles Nepveu
#
# Date: August 2007
#
# ###########################################################################
#

INC_DIR:=inc
SRC_DIR:=src
COMMON_INC=../common/inc

ifdef DEBUG
CFLAGS:=-c -g -I${DEFS_DIR} -I${INC_DIR} -I${COMMON_INC} -DPLATFORM=\"${PLATFORM}\" -D_REENTRANT -DDEBUG ${EXTRA_CFLAGS}
else
CFLAGS:=-c -O2 -I${DEFS_DIR} -I${INC_DIR} -I${COMMON_INC} -DPLATFORM=\"${PLATFORM}\" -D_REENTRANT ${EXTRA_CFLAGS}
endif

OBJS:=$(patsubst ${SRC_DIR}/%.c,${OBJS_DIR}/%.o,$(wildcard ${SRC_DIR}/*.c))


.PHONY: platform-obj platform-inc


#
# ###########################################################################
#

platform-obj: ${OBJS}


#
# ###########################################################################
#

platform-inc:
	@cp -f $(wildcard ${INC_DIR}/*.*) $(OUT_INC_DIR)


#
# ###########################################################################
