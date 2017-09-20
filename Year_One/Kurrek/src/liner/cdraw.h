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
#ifndef _CDRAW_H_
#define _CDRAW_H_

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

////////////////////////////////////////////////
class cdraw
{
private:
   Display *display;
   Window  *pwindow;
   Pixmap  *ppixmap;
   GC *pgcw; 
   GC *pgcp;
   Colormap colormap;
   
public:
   cdraw(Display *ndisplay, Window *npwindow, Pixmap *nppixmap, 
         GC *npgcw, GC *npgcp);
   void setcolor(const char *s);
   void clearwindow(void);
   void drawarc(unsigned int mx, unsigned int my, unsigned int r, 
                int phi1, int phi2, int fill);
   void drawline(int x1, int y1, int x2, int y2);
   void drawpoint(int x, int y);
   void drawpolyline(unsigned int n, int filled, 
                     unsigned int koords[]);
   void drawrectangle(unsigned int x1, unsigned int y1, unsigned int x2,
                      unsigned int y2, int filled);
   void drawtext(int x, int y, const char *s);
};
#endif
