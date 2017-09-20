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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xatom.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include "cdraw.h"

#define TEST 0
#if TEST
Colormap cl_colormap;
#endif

cdraw::cdraw(Display *ndisplay, Window *npwindow, Pixmap *nppixmap, 
             GC *npgcw, GC *npgcp) 
            : display(ndisplay),pwindow(npwindow),ppixmap(nppixmap),pgcw(npgcw),
            pgcp(npgcp)
{
   colormap = XDefaultColormap(display, DefaultScreen(display));
}

/////////////////////////////////////////////////

void cdraw::setcolor(const char *s)
{
   static XColor xcolor;
   Status rc;
   rc=XParseColor(display, 
#if TEST
   cl_colormap,
#else
   colormap,
#endif
   s, &xcolor);
   if(rc==0)  
   {
      fprintf(stderr,"XParseColor(): Error!\n");
      return; 
   }
   rc=XAllocColor(display, 
#if TEST
   cl_colormap,
#else
   colormap,
#endif         
   &xcolor);
   if(rc==0) 
   {
      fprintf(stderr,"XAllocColor(): Error!\n");
      return;
   }
   XSetForeground(display, *pgcw, xcolor.pixel);
   XSetForeground(display, *pgcp, xcolor.pixel);
}   

void cdraw::drawarc(unsigned int mx, unsigned int my, 
                    unsigned int r,
                    int phi1, int phi2, int filled)
{
   if(!filled)
   {
      XDrawArc(display, *pwindow, *pgcw, 
               mx-r, my-r, 2*r, 2*r, 64*phi1, 64*phi2);
      XDrawArc(display, *ppixmap, *pgcp, 
               mx-r, my-r, 2*r, 2*r, 64*phi1, 64*phi2);
   }
   else
   {
      XFillArc(display, *pwindow, *pgcw, 
               mx-r, my-r, 2*r, 2*r, 64*phi1, 64*phi2);
      XFillArc(display, *ppixmap, *pgcp, 
               mx-r, my-r, 2*r, 2*r, 64*phi1, 64*phi2);
   }
}

void cdraw::drawrectangle(unsigned int x1, unsigned int y1, 
            unsigned int x2, unsigned int y2, int filled)
{
   unsigned int h, w;
   int x, y;

   if(x1==x2||y1==y2) return;
   if(x1<x2) {x=x1; w=x2-x1;}
   else      {x=x2; w=x1-x2;}
   if(y1<y2) {y=y1; h=y2-y1;}
   else      {y=y2; h=y1-y2;}

   if(!filled)
   {
      XDrawRectangle(display, *ppixmap, *pgcp, x, y, w, h);
      XDrawRectangle(display, *pwindow, *pgcw, x, y, w, h);
   }
   else
   {
      XFillRectangle(display, *ppixmap, *pgcp, x, y, w, h);
      XFillRectangle(display, *pwindow, *pgcw, x, y, w, h);
   }
}

void cdraw::drawline(int x1, int y1, int x2, int y2)
{
   XDrawLine(display, *ppixmap, *pgcp, x1,y1,x2,y2);
   XDrawLine(display, *pwindow, *pgcw, x1,y1,x2,y2);
}

void cdraw::drawpoint(int x, int y)
{
   XDrawPoint(display, *ppixmap, *pgcp, x,y);
   XDrawPoint(display, *pwindow, *pgcw, x,y);
}

void cdraw::drawtext(int x, int y, const char *s)
{
   if(!s) return;
   size_t len;
   len=strlen(s);
   XDrawImageString(display, *ppixmap, *pgcp, x, y, s, len);
   XDrawImageString(display, *pwindow, *pgcw, x, y, s, len);
}

void cdraw::clearwindow(void)
{ 
   XWindowAttributes att;
   XGetWindowAttributes(display, *pwindow, &att);
   int screen;
   screen=DefaultScreen(display);

   XSetBackground(display, *pgcp, BlackPixel(display, screen));
   XSetForeground(display, *pgcp, WhitePixel(display, screen));
   XFillRectangle(display, *ppixmap, *pgcp, 0, 0, att.width, att.height);
   XSetBackground(display, *pgcp, WhitePixel(display, screen));
   XSetForeground(display, *pgcp, BlackPixel(display, screen));
   XCopyArea(display, *ppixmap, *pwindow, *pgcp, 0, 0, 
             att.width, att.height, 0, 0);
}

void cdraw::drawpolyline(unsigned int n, int filled, 
                         unsigned int *koords)
{
   unsigned int i;
   XPoint *points=NULL;
   if(!koords) return;
#if 1
   fprintf(stderr,"Polygon:n=%u,filled=%i\n", n, filled);
#endif
   
   points=(XPoint *)malloc(n*sizeof(XPoint));
   if(!points)
   {
      fprintf(stderr,"%s %l: malloc(%u xpoints): problem!\n",
              __FILE__, __LINE__, n);
      return;
   }
   for(i=0; i<n; ++i)
   {
       points[i].x=koords[i+i];
       points[i].y=koords[i+i+1];
#if 1
       fprintf(stderr,"Polygon:x=%i,y=%i\n", koords[i+i], koords[i+i+1]);
#endif
   }
   if(!filled)
   {
      XDrawLines(display, *pwindow, *pgcw, points, n, 
                 CoordModeOrigin);
      XDrawLines(display, *ppixmap, *pgcp, points, n, 
                 CoordModeOrigin); 
   }
   else
   {
      XFillPolygon(display, *pwindow, *pgcw, points, n, Complex,
                   CoordModeOrigin);
      XFillPolygon(display, *ppixmap, *pgcp, points, n, Complex,
                   CoordModeOrigin);
   }
   free(points);
}
