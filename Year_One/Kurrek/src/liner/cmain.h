/*
liner - graphical output from textmode applications
Copyright (C) 2006 Joerg Kurrek

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 51
Franklin St, Fifth Floor, Boston, MA 02110, USA 
*/
#ifndef _CMAIN_H_
#define _CMAIN_H_

#include <time.h> /* nur fuer nanosleep() */
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cdraw.h"
#include "cinput.h"
#include "coutput.h"

class cmain
{
private:
   cdraw draw;
   cinput input;
   Coutput output;
   deque<unsigned char> q;
   
public:
   cmain(Display *display, Window *window, Pixmap *pixmap, GC *gcw, GC *gcp,
         channel_t channel, language_t language);
   void run(void);
};
#endif
