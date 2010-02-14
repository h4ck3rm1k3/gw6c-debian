# ###########################################################################
#
# $Id: Makefile,v 1.5 2008/02/29 17:23:00 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# Description: Makefile for common platforms
#
# Author: Charles Nepveu
#
# Date: August 2007
#
# ###########################################################################
#

INC_DIR:=inc
SRC_DIR:=src

ifdef DEBUG
CFLAGS+=-c -g -I${DEFS_DIR} -I${INC_DIR} -DPLATFORM=\"${PLATFORM}\" -D_REENTRANT -DDEBUG ${EXTRA_CFLAGS}
else
CFLAGS+=-c -O2 -I${DEFS_DIR} -I${INC_DIR} -DPLATFORM=\"${PLATFORM}\" -D_REENTRANT ${EXTRA_CFLAGS}
endif

OBJS:=$(patsubst ${SRC_DIR}/%.c,${OBJS_DIR}/%.o,$(wildcard ${SRC_DIR}/*.c))


.PHONY: platform-obj platform-inc


#
# ###########################################################################
#

platform-obj: ${OBJS}


${OBJS_DIR}/pal_version.o: ${SRC_DIR}/pal_version.c ${INC_DIR}/pal_version.h
	$(CC) ${CFLAGS} -o $@ ${SRC_DIR}/pal_version.c


#
# ###########################################################################
#

platform-inc:
	@cp -f $(wildcard ${INC_DIR}/*.*) $(OUT_INC_DIR)


#
# ###########################################################################
