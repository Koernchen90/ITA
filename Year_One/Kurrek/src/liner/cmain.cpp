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
#include <time.h> /* nur fuer nanosleep() */
#include <stdlib.h> /* nur fuer getenv() */
#include <string.h> /* nur fuer strcmp() */
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cdraw.h"
#include "cinput.h"
#include "coutput.h"
#include "cmain.h"

////////////////////////////////////////////////

cmain::cmain(
// fuer cdraw:
             Display *display, Window *window, Pixmap *pixmap, GC *gcw, GC *gcp,
// fuer cinput:
             channel_t channel=KEYBOARD, language_t language=NATIVE
// fuer coutput:
             ) : draw(display,window,pixmap,gcw,gcp), input(channel, language), output(&draw)
{
   if(getenv("LINER_LANGUAGE"))
   {
      if(!strcmp(getenv("LINER_LANGUAGE"),"FIG"))
         input.setlanguage(FIG);
      else if(!strcmp(getenv("LINER_LANGUAGE"),"HPGL")) 
         input.setlanguage(HPGL);
   }   
   if(getenv("LINER_LANGUAGE") && !strcmp(getenv("LINER_CHANNEL"),"NETWORK")) 
   {
      input.setchannel(NETWORK);
   }
}

/////////////////////////////////////////////////

void cmain::run(void)
{   
   if(!q.empty())   
   { 
      do
      {
         output.docommand(q);
      }
      while(output.geterror()!=OEMPTY);
   }
   if(input.geterror()!=IEOF)
   {
      input.getcommand(q);
   } 
   else
   {
      struct timespec tv={0L,2000000L};
      nanosleep(&tv, NULL);
   }
}

//////////////////////////////////////////////////
