#
# "$Id: Makefile,v 1.12.2.6.2.19 2004/10/18 20:22:21 easysw Exp $"
#
# Top-level makefile for the Fast Light Tool Kit (FLTK).
#
# Copyright 1998-2004 by Bill Spitzak and others.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
#
# Please report all bugs and problems to "fltk-utf8-bugs@fltk-utf8.org".
#

include makeinclude

DIRS	=	xutf8 $(IMAGEDIRS) src fluid test documentation

all: makeinclude
	for dir in $(DIRS); do\
		echo "=== making $$dir ===";\
		(cd $$dir; $(MAKE) $(MFLAGS)) || break;\
	done

install: makeinclude
	-mkdir -p $(DESTDIR)$(bindir)
	$(RM) $(DESTDIR)$(bindir)/fltk-utf8-config
	-cp fltk-utf8-config $(DESTDIR)$(bindir)
	-chmod 755 $(DESTDIR)$(bindir)/fltk-utf8-config
	for dir in FL $(DIRS); do\
		echo "=== installing $$dir ===";\
		(cd $$dir; $(MAKE) $(MFLAGS) install) || break;\
	done

uninstall: makeinclude
	$(RM) $(DESTDIR)$(bindir)/fltk-utf8-config
	for dir in FL $(DIRS); do\
		echo "=== uninstalling $$dir ===";\
		(cd $$dir; $(MAKE) $(MFLAGS) uninstall) || break;\
	done

depend: makeinclude
	for dir in $(DIRS); do\
		echo "=== making dependencies in $$dir ===";\
		(cd $$dir; $(MAKE) $(MFLAGS) depend) || break;\
	done

clean:
	-$(RM) core *.o
	for dir in $(DIRS); do\
		echo "=== cleaning $$dir ===";\
		(cd $$dir; $(MAKE) $(MFLAGS) clean) || break;\
	done

distclean: clean
	$(RM) config.*
	$(RM) fltk-utf8-config fltk-utf8.list makeinclude
	$(RM) FL/Makefile
	$(RM) documentation/*.$(CAT1EXT)
	$(RM) documentation/*.$(CAT3EXT)
	$(RM) documentation/fltk-utf8.pdf
	$(RM) documentation/fltk-utf8.ps
	$(RM) -r documentation/fltk-utf8.d
	for file in test/*.fl; do\
		$(RM) test/`basename $file .fl`.cxx; \
		$(RM) test/`basename $file .fl`.h; \
	done

makeinclude: configure configh.in makeinclude.in
	if test -f config.status; then \
		./config.status --recheck; \
		./config.status; \
	else \
		./configure; \
	fi
	touch config.h

configure: configure.in
	autoconf

portable-dist:
	epm -v -s fltk-utf8.xpm fltk-utf8

native-dist:
	epm -v -f native fltk-utf8


#
# End of "$Id: Makefile,v 1.12.2.6.2.19 2004/10/18 20:22:21 easysw Exp $".
#
