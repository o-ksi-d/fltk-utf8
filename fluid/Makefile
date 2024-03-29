#
# "$Id: Makefile,v 1.10.2.6.2.27 2004/10/18 20:22:22 easysw Exp $"
#
# FLUID makefile for the Fast Light Tool Kit (FLTK).
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
# Please report all bugs and problems to "fltk-uf8-bugs@fltk-uf8.org".
#

CPPFILES = \
	Fl_Function_Type.cxx \
	Fl_Menu_Type.cxx \
	Fl_Group_Type.cxx \
	Fl_Widget_Type.cxx \
	Fl_Type.cxx \
	Fl_Window_Type.cxx \
	Fluid_Image.cxx \
	code.cxx \
	factory.cxx \
	file.cxx \
	fluid.cxx \
	align_widget.cxx \
	about_panel.cxx \
	widget_panel.cxx \
	alignment_panel.cxx \
	function_panel.cxx

################################################################

OBJECTS = $(CPPFILES:.cxx=.o)

CLEAN	= core*

include ../makeinclude

all:	$(FLUID) fluid$(EXEEXT)

fluid$(EXEEXT):		$(OBJECTS) ../lib/$(LIBNAME) ../lib/$(FLLIBNAME) \
			../lib/$(IMGLIBNAME)
	echo Linking $@...
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LINKFLTKIMG) $(LDLIBS) $(LINKFLTKFORMS)
	$(POSTBUILD) $@ ../FL/mac.r

fluid-shared$(EXEEXT):	$(OBJECTS) ../src/$(DSONAME) ../src/$(FLDSONAME) \
			../src/$(IMGDSONAME)
	echo Linking $@...
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LINKSHARED) $(LDLIBS)
	$(POSTBUILD) $@ ../FL/mac.r

clean :
	-@ $(RM) *.o fluid$(EXEEXT) fluid-shared$(EXEEXT) $(CLEAN)

depend:	$(CPPFILES)
	makedepend -Y -I.. -f makedepend $(CPPFILES)

# Automatically generated dependencies...
include makedepend

install: all
	echo "Installing FLUID in $(DESTDIR)$(bindir)..."
	-$(MKDIR) $(DESTDIR)$(bindir)
	$(CP) $(FLUID) $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(STRIP) $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(DESTDIR)$(bindir)/fltk-utf8-config --post $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(CHMOD) 755 $(DESTDIR)$(bindir)/fluid$(EXEEXT)

uninstall:
	$(RM) $(DESTDIR)$(bindir)/fluid$(EXEEXT)

#
# Note: The rebuild target can only be used if you have the original .fl
#       files.  This is normally only used by the FLTK maintainers...
#

rebuild:
	./fluid -c about_panel.fl
	./fluid -c alignment_panel.fl
	./fluid -c function_panel.fl
	./fluid -c widget_panel.fl

#
# End of "$Id: Makefile,v 1.10.2.6.2.27 2004/10/18 20:22:22 easysw Exp $".
#
