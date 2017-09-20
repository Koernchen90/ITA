# liner - graphical output from textmode applications
# Copyright (C) 2006, 2007 Joerg Kurrek
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51
# Franklin St, Fifth Floor, Boston, MA 02110, USA 
#
PROG="\"liner\""
VERSION="\"1.09\""
YEAR="\"2013\""
first: default

coutput.o: coutput.cpp coutput.h
	g++ ${FGLOPTS} ${CCOPTS} -c coutput.cpp

cinput.o: cinput.cpp cinput.h
	g++ ${FGLOPTS} ${CCOPTS} -c cinput.cpp

cmain.o: cmain.cpp cmain.h
	g++ ${FGLOPTS} ${CCOPTS} -c cmain.cpp
  
cdraw.o: cdraw.cpp cdraw.h
	g++ ${FGLOPTS} ${CCOPTS} -c cdraw.cpp
	
liner: liner.cpp cinput.o coutput.o cmain.o cdraw.o
	g++ -DPROG=${PROG} -DVERSION=${VERSION} -DYEAR=${YEAR} \
	-L/usr/X11R6/lib -lX11 -o liner \
	liner.cpp \
	cinput.o \
	coutput.o \
	cmain.o \
	cdraw.o

example5: example5.c
	cc -lm -o example5 example5.c

default: liner example1 example2 example3 example4 example5

run:
	./example4|./liner

clean:
	rm *~ *.bak *.o 2>/dev/null | true

install:
	cp liner example1 example2 example3 example4 example5 /usr/local/bin;\
	chmod 755 /usr/local/bin/liner /usr/local/bin/example1    \
	          /usr/local/bin/example2 /usr/local/bin/example3 \
	          /usr/local/bin/example4 /usr/local/bin/example5;\
	cp liner.h /usr/local/include;\
	chmod 644 /usr/local/include/liner.h
	