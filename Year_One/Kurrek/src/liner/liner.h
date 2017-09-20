/*
liner - graphical output from textmode applications
Copyright (C) 2006, 2007, 2013 Joerg Kurrek

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
#ifndef _LINER_H_
#define _LINER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KGL 0
#define PS  1
#define OUTDISPLAY 0
#define OUTFILE    1
#define OUTPIPE    2
#define DEFAULT_W 640 
#define DEFAULT_H 480
#define OUTPT_REDIR ">/dev/null"
#define ERROR_REDIR "2>/dev/null"
#define KGL_OUTFILE "out.liner"
#define GS_OUTFILE "out.gs"
#define GS_RESFILENAME ".gsXresources"
#define GS_PREAMBLE "%!PS-Adobe-2.0"
#define GS_STDFONT "Helvetica"
#define GS_STDFONTSIZE 20.0

static FILE* display=NULL;
static int language=KGL;
static int action=OUTDISPLAY;
static int set_init(int initlang);
static int liner_init_xywh(int initlang, int initaction, 
                           unsigned int x, unsigned int y,unsigned int w, unsigned int h);
static int liner_init(void);
static void liner_exit(void);
static void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
static void pixel(unsigned int x, unsigned int y);
static void rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, int fill);
static void polyline(unsigned int n, int filled, unsigned int *koords);                      
static void arc(unsigned int mx, unsigned int my, unsigned int r,int phi1, int phi2, int fill);
static void text(unsigned int x, unsigned int y, const char *t);
static void setfont(const char *newfnt, double newfntsz);                
static void color(unsigned int r, unsigned int g, unsigned int b);
static void ncolor(const char *t);
static void clear(void);
/*************************************************************************
 Initialisierung
*************************************************************************/
static int liner_init_xywh(int initlang, int initaction, 
                           unsigned int x, unsigned int y,unsigned int w, unsigned int h)
{
   char cmd[1024]="", file[1024]="";
   if(display)
   {
      fprintf(stderr, "%s %d: display already open!\n", __FILE__, __LINE__);
      return 1;
   }
   language=initlang;
   action=initaction;
   switch(language)
   {
   case KGL: 
      snprintf(cmd, sizeof(cmd)-1, 
      "liner -x %u -y %u -w %u -h %u " OUTPT_REDIR " " ERROR_REDIR, x, y, w, h);
      strncat(file, KGL_OUTFILE, sizeof(file)-1);
      break;
   case PS:  
      {
         FILE *resfile;
         resfile=fopen(GS_RESFILENAME, "w");
         if(!resfile)
         {
            fprintf(stderr, "%s %d: could not open resource file!\n", 
                    __FILE__, __LINE__);
            return 4;
         }
         /* x- und y-Koordinate lassen sich bei gs nur per     */
         /* Resource-File einstellen, Breite und Hoehe nur per */
         /* Kdo-Zeilen-Parameter. Und die Aufloesung muss 72   */
         /* sein (DPI? Prozent?)  :-/                          */
         fprintf(resfile,"Ghostscript*geometry: +%u+%u\n"
                         "Ghostscript*xResolution: 72\n"
                         "Ghostscript*yResolution: 72\n",x,y);
         fclose(resfile);
         system ("xrdb " GS_RESFILENAME);
         snprintf(cmd, sizeof(cmd)-1, 
         "gs -g%ux%u " OUTPT_REDIR " " ERROR_REDIR, w, h);
         strncat(file, GS_OUTFILE, sizeof(file)-1);
      }
      break;
   default:
      fprintf(stderr, "%s %d: unknown language\n", __FILE__, __LINE__);
      return 2;
   }
   switch(action)
   {
   case OUTDISPLAY: display=popen(cmd,"w");  break;
   case OUTFILE:    display=fopen(file,"w"); break;
   case OUTPIPE:    display=stderr;          break;
   }        
   if(!display)
   {
      fprintf(stderr, "%s %d: could not start command/open file!\n", 
              __FILE__, __LINE__);
      return 3;
   }
   
   switch(language)
   {
   case PS:
      fprintf(display, "%s\n", GS_PREAMBLE);
      fflush(display);
      break;
   }
   setfont(GS_STDFONT, GS_STDFONTSIZE);
   return 0;
}
/************************************************************************/
static int liner_init(void)
{
   return liner_init_xywh(KGL, OUTDISPLAY, 0, 0, DEFAULT_W, DEFAULT_H);
}  
/************************************************************************/
static void liner_exit(void)
{
   if(!display)
   {
      fprintf(stderr,"%s %d: display already closed\n", __FILE__, __LINE__);
      return;
   }
   switch(language)
   {
   case KGL: fprintf(display, "Q\n");    break;
   case PS:  fprintf(display, "quit\n"); break;
   }
   fflush(display);
   switch(action)
   {
   case OUTDISPLAY: pclose(display); break;
   case OUTFILE:    fclose(display); break;
   }
   display=NULL;
}
/*****************************************************************
                      Graphik-Ausgabe
/*******************************************************************/
static void line(unsigned int x1, unsigned int y1, 
                 unsigned int x2, unsigned int y2)
{
   switch(language)
   {
   case KGL: 
      fprintf(display, 
              "L %u %u %u %u\n", x1,y1,x2,y2);
      break;
   case PS:
      fprintf(display, 
              "%u %u moveto %u %u lineto\nstroke\n",
               x1, y1,      x2, y2);
      break;
   }
   fflush(display);
}
/*******************************************************************/
static void pixel(unsigned int x, unsigned int y)
{
   switch(language)
   {
   case KGL: fprintf(display, "P %i %i\n", x, y); break;
   case PS:  line(x,y,x+1,y+1); return;
   }
   fflush(display);
}
/*******************************************************************/
static void rectangle(unsigned int x1, unsigned int y1, 
                      unsigned int x2, unsigned int y2, int fill)
{
   switch(language)
   {
   case KGL: 
      fprintf(display, 
      "R %u %u %u %u %i\n", x1, y1, x2, y2, fill); 
      break;
   case PS:  
      fprintf(display, 
      "%u %u moveto %u %u lineto %u %u lineto %u %u lineto %u %u lineto %s\n", 
       x1, y1,      x2, y1,      x2, y2,      x1, y2,      x1, y1,
       fill?"fill":"stroke"); 
       break;
   }
   fflush(display);
}
/******************************************************************/
static void polyline(unsigned int n, int filled, unsigned int *koords)
{
   unsigned int i;
   switch(language)
   {
   case KGL:
      fprintf(display, "Y %u %i", n, filled);
      for(i=0; i<n; ++i)
      {
         fprintf(display, " %u %u", 
                 koords[i+i], koords[i+i+1]);
      }
      fprintf(display, "\n");
      break;
   case PS:
      fprintf(display, "%u %i moveto\n",
              koords[0], koords[1], filled);
      for(i=1; i<n; ++i)
      {
         fprintf(display, "%u %u lineto\n", 
                 koords[i+i], koords[i+i+1]);
      }
      fprintf(display, "%s\n", filled?"fill":"stroke");
      break;
   }
   fflush(display);
}
/*******************************************************************/
static void arc(unsigned int mx, unsigned int my, unsigned int r,
                int phi1, int phi2, int fill)
{
   switch(language)
   {
   case KGL: 
      fprintf(display, "A %u %u %u %i %i %i\n", 
              mx, my, r, phi1, phi2, fill); 
      break;
   case PS:
      fprintf(display, 
      "%u %u %u %i %i arc %s\n", 
      mx, my, r, phi1, phi2, fill?"fill":"stroke");
      break;
   }
   fflush(display);
}
/*******************************************************************/
static void text(unsigned int x, unsigned int y, const char *t)
{
   switch(language)
   {
   case KGL: 
      fprintf(display, "T %i %i %s\n", x, y, t); 
      break;
   case PS:   
      fprintf(display, 
              "%u %u moveto\n(%s) show\n", x, y, t);
      break;
   }
   fflush(display);
}
/********************************************************************/
static void setfont(const char *newfnt, double newfntsz)
{
   switch(language)
   {
   case PS:
      fprintf(display, "/%s findfont "  
      "dup length dict begin {def} forall "
      "/Encoding ISOLatin1Encoding def "
      "currentdict end /%s-ISOLatin1 exch definefont "
      "%f scalefont setfont\n", 
      newfnt, newfnt, newfntsz);
      break;
   }
   fflush(display); 
}
/*******************************************************************/
static void color(unsigned int r, unsigned int g, unsigned int b)
{
   switch(language)
   {
   case KGL: fprintf(display, "O rgb:%02X/%02X/%02X\n", r,g,b); break;
   case PS:  
      fprintf(display, "%f %f %f setrgbcolor\n", 
                        r/256.0,g/256.0,b/256.0); 
      break;
   }
}
/*******************************************************************/
static void ncolor(const char *t)
{
   switch(language)
   {
   case KGL: fprintf(display, "O %s\n", t); break;
   }
}
/*******************************************************************/
static void clear(void)
{
   switch(language)
   {
   case KGL: fprintf(display, "C\n");        break;
   case PS:  fprintf(display, "showpage\n"); break;
   }
   fflush(display);
}
#endif /* _LINER_H_ */
