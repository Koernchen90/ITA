/* Version 0.02, 20.03.2013 */
/*
psliner - graphical output from textmode applications
Copyright (C) 2006, 2007, 2012, 2013 Joerg Kurrek

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
#ifndef _PSLINER_H_
#define _PSLINER_H_

#include <stdio.h>
#include <stdlib.h>
FILE* display=NULL;
/***********************
 Initialisierung
************************/
#define DEFAULT_W 640 
#define DEFAULT_H 480
#define GS_OUTPT_REDIR ">/dev/null"
#define GS_ERROR_REDIR "2>/dev/null"
#define PREAMBLE "%!PS-Adobe-2.0"
#define STDFONT "Helvetica"
#define STDFONTSIZE 20.0
/*******************************************************************/
static void liner_init_xywh(unsigned int x, unsigned int y, unsigned w, unsigned h)
{
   char cmd[1024];
   snprintf(cmd, sizeof(cmd)-1, "gs -g%ux%u " 
            GS_OUTPT_REDIR " " GS_ERROR_REDIR, w, h);
   display=popen(cmd,"w");
   if(!display)
   {
      printf("%s %d: could not start command!\n", __FILE__, __LINE__);
      exit(120);
   }                     
   fprintf(display?display:stderr, "%s\n", PREAMBLE);
   fflush(display?display:stderr);
}
/*******************************************************************/
static void liner_init(void)
{
   liner_init_xy(DEFAULT_W, DEFAULT_H);
}
/*******************************************************************/
static void liner_exit(void)
{
   if(display)
   {
      pclose(display);
      display=NULL;
   }
}
/********************************************************************/
/*                   Graphik-Ausgabe                                */
/********************************************************************/
static void polyline(unsigned int n, int filled, unsigned int *koords)
{
   unsigned int i;
   fprintf(display?display:stderr, "%u %i moveto\n",
           koords[0], koords[1], filled);
   for(i=1; i<n; ++i)
   {
      fprintf(display?display:stderr, "%u %u lineto\n", 
              koords[i+i], koords[i+i+1]);
   }
   fprintf(display?display:stderr, "%s\n", filled?"fill":"stroke");
   fflush(display?display:stderr);
}
/*******************************************************************/
static void arc(unsigned int mx, unsigned int my, unsigned int r,
                int phi1, int phi2, int filled)
{
   fprintf(display?display:stderr, "%u %u %u %i %i arc %s\n", 
           mx, my, r, phi1, phi2, filled?"fill":"stroke");
   fflush(display?display:stderr);
}
/*******************************************************************/
static void rectangle(unsigned int x1, unsigned int y1, 
                      unsigned int x2, unsigned int y2, int fill)
{
   fprintf(display?display:stderr, "%u %u moveto %u %u lineto %u %u lineto "
                                   "%u %u lineto %u %u lineto %s\n",
                                   x1, y1,       x2, y1,      x2, y2,      
                                   x1, y2,       x1, y1,      fill?"fill":"stroke");
   fflush(display?display:stderr);
}
/*******************************************************************/
static void clear(void)
{
   fprintf(display?display:stderr, "showpage\n");
   fflush(display?display:stderr);
}
/*******************************************************************/
static void color(unsigned int r, unsigned int g, unsigned int b)
{
   fprintf(display?display:stderr, "%u %u %u setrgbcolor\n", r,g,b);
   fflush(display?display:stderr);
}
/*******************************************************************/
static void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
   fprintf(display?display:stderr, "%u %u moveto %u %u lineto\nstroke\n", 
           x1, y1, x2, y2);
   fflush(display?display:stderr);
}
/*******************************************************************/
/*
static void ncolor(const char *t)
{
   fprintf(display?display:stderr, "O %s\n", t);
}
/*******************************************************************/
static void pixel(unsigned int x, unsigned int y)
{
   line(x,y,x+1,y+1);
}
/*******************************************************************/
static void setfont(const char *newfnt, double newfntsz)
{
   fprintf(display?display:stderr,
   "/%s findfont "  
   "dup length dict begin "
   "{def} forall "
   "/Encoding ISOLatin1Encoding def "
   "currentdict "
   "end "
   "/%s-ISOLatin1 exch definefont "
   "%f scalefont setfont\n", newfnt, newfnt, newfntsz);
   fflush(display?display:stderr); 
}
/*******************************************************************/
static void text(unsigned int x, unsigned int y, const char *t)
{
   static int firsttime=1;
   if(firsttime)
   {
      setfont(STDFONT, STDFONTSIZE);
      firsttime=0;
   }
   fprintf(display?display:stderr, "%u %u moveto\n", x, y);
   fprintf(display?display:stderr, "(%s) show\n", t);
   fflush(display?display:stderr);
}
/*******************************************************************/
static void quit(void)
{
   fprintf(display?display:stderr, "quit\n");
   fflush(display?display:stderr);
}
#endif /* _PSLINER_H_ */
