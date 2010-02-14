#
# Global Gateway6 Client Makefile.
#
installdir=$DESTDIR
all:
	cd tspc-advanced && $(MAKE) all

install:
	cd tspc-advanced && $(MAKE) install

clean:
	cd tspc-advanced && $(MAKE) cleanall

