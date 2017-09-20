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
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "cdraw.h"
#include "cmain.h"

#ifndef STD_X
#   define STD_X 80
#endif
#ifndef STD_Y
#   define STD_Y 60
#endif
#ifndef STD_W
#   define STD_W 640
#endif
#ifndef STD_H
#   define STD_H 480
#endif

#define TEST 0
#if TEST
extern Colormap cl_colormap;
#endif

static int done=0;
void sigintfunc(int signr);
void getmyenv(int *x, int *y, int *w, int *h);
void getmyopts(int argc, char *argv[], int *x, int *y, int *w, int *h);
char *version = PROG " V." VERSION;
char *prog    = PROG;

int main(int argc, char **argv)
{
   Display *cl_display; /* Verbindung zum XServer */
   int cl_screen;       /* Bildschirm-Nr. */
   Window  cl_window;   /* Fenster */
   Pixmap  cl_pixmap;   /* Schatten-Ausgabe */
   GC cl_gc;            /* Graphik-Kontext */
   GC cl_gcp;           /* Graphik-Kontext fuer Pixmaps */
   XEvent cl_event;     /* Ereignis-Struktur */
   KeySym cl_key;       /* Taste */
   XSizeHints cl_hint;  /* Nachricht an Andere ueber Fenstereigensch. */
   unsigned long cl_foreground; /* Vordergrund-Farbe */
   unsigned long cl_background; /* Hintergrund-Farbe */
   
   if(signal(SIGINT, sigintfunc)==SIG_ERR)
   {
      fprintf(stderr, "%s %lf: signal() error!\n", __FILE__, __LINE__);
      return 2;
   }
   /*********************************************************************/

   cl_hint.x      = STD_X; cl_hint.y      = STD_Y; 
   cl_hint.width  = STD_W; cl_hint.height = STD_H;
   getmyenv(&cl_hint.x, &cl_hint.y, &cl_hint.width, &cl_hint.height);
   getmyopts(argc, argv, &cl_hint.x, &cl_hint.y, &cl_hint.width, &cl_hint.height);

   /*********************************************************************/
   
   cl_display = XOpenDisplay("");  /* open $DISPLAY */
   if(!cl_display)
   {
      fprintf(stderr, "%s, %l:XOpenDisplay failed!\n", __FILE__, __LINE__);
      return 1;
   }
                                   /* create window */
   
   cl_screen = DefaultScreen(cl_display);
   cl_background = WhitePixel(cl_display, cl_screen);
   cl_foreground = BlackPixel(cl_display, cl_screen);   
   cl_hint.flags = PPosition | PSize; 
   cl_window = XCreateSimpleWindow(cl_display, 
                                   DefaultRootWindow(cl_display),
                                   cl_hint.x,
                                   cl_hint.y,
                                   cl_hint.width,
                                   cl_hint.height,
                                   5, /* Randbreite */
                                   cl_foreground,
                                   cl_background);                                 
                                   
   XSetStandardProperties(cl_display, cl_window, 
                          version, /* window title */
                          prog,    /* icon title */
                          None,    /* filename of icon bitmap */
                          argv, argc, &cl_hint);
                          
   cl_gc = XCreateGC(cl_display, cl_window, 0, 0);               
   XSetBackground(cl_display, cl_gc, cl_background);
   XSetForeground(cl_display, cl_gc, cl_foreground);

   XSelectInput(cl_display, cl_window, ButtonPressMask|KeyPressMask|ExposureMask);
   XMapRaised(cl_display, cl_window);
   
                                   /* create and clear pixmap */
   XWindowAttributes cl_att;
   XGetWindowAttributes(cl_display, cl_window, &cl_att);
   cl_pixmap = XCreatePixmap(cl_display, DefaultRootWindow(cl_display),
                             cl_att.width, cl_att.height,
                             cl_att.depth); /* bit per pixel */
   cl_gcp= XCreateGC(cl_display, cl_pixmap, 0, 0);
   
   XSetBackground(cl_display, cl_gcp, BlackPixel(cl_display, cl_screen));
   XSetForeground(cl_display, cl_gcp, WhitePixel(cl_display, cl_screen));
   XFillRectangle(cl_display, cl_pixmap, cl_gcp, 0, 0, cl_att.width, cl_att.height);
   XSetBackground(cl_display, cl_gcp, WhitePixel(cl_display, cl_screen));
   XSetForeground(cl_display, cl_gcp, BlackPixel(cl_display, cl_screen));
   
                                   /* create other objects */
#if TEST
   cl_colormap=XDefaultColormap(cl_display, cl_screen);
#endif
                                   
   cmain cl_main(cl_display, &cl_window, &cl_pixmap, &cl_gc, &cl_gcp, KEYBOARD, NATIVE);
   
   done=0;
   while(!done)
   {
      if(!XEventsQueued(cl_display, QueuedAfterReading))
      {
         XFlush(cl_display);
         cl_main.run();
      }
      else
      {
         XNextEvent(cl_display, &cl_event);
         switch(cl_event.type)
         {
         case Expose:
            if(cl_event.xexpose.count==0)
            {
               XCopyArea(cl_display, cl_pixmap, cl_window, cl_gc, 0, 0, 
               cl_att.width,cl_att.height,0,0);
#if debug
               XDrawString(cl_event.xexpose.display, cl_event.xexpose.window, cl_gc, 
                           50, 50, version, strlen(version));
#endif               
            }
            break;
         
         case MappingNotify:
            XRefreshKeyboardMapping((XMappingEvent *) &cl_event);
            break;
         
         case ButtonPress:  
            break;
         
         case KeyPress:
            {
               int i;
               char text[10];
               i=XLookupString((XKeyEvent *) &cl_event, text, 10, &cl_key, 0);
               if(i==1 && text[0]=='q') 
                  done=1;
            }      
            break;   
         }/* switch cl_event.type */
#if debug
         system("echo -n -e '\7'");  /* Event-Melder */
#endif
      }/* if XEventsQueued() */

   }/* while !done */
   
   XFreeGC(cl_display, cl_gc);   
   XDestroyWindow(cl_display, cl_window);
   XFreePixmap(cl_display, cl_pixmap);
   XCloseDisplay(cl_display);

   return 0;
   
}/* main */

/**********************************************************/

void getmyopts(int argc, char *argv[], int *x, int *y, 
               int *w, int *h)
{
   char *usage=PROG " -w <width> -h <height> "
               "-x <xoffset> -y <yoffset> | -? | -v\n";
   char *copy="Version " VERSION ", Copyright (C) " YEAR " Joerg Kurrek\n"
              "liner comes with ABSOLUTELY NO WARRANTY.\n"
              "This is free software, and you are welcome to redistribute\n"
              "it under certain conditions, see GPL for details.\n";
   int rc;
   const char myopts[]="h:vw:x:y:?";
   
   while((rc=getopt(argc, argv, myopts))!=EOF)
   {
      switch(rc)
      {
      case '?':
         printf("%s%s", usage, copy);
         exit(0);
      break; 
      case 'v':
         printf("%s\n", version);
         exit(0);
      break;
      case 'h': 
         if(optarg) *h=(int)atoi(optarg);
      break;
      case 'w': 
         if(optarg) *w=(int)atoi(optarg);
      break;
      case 'x': 
         if(optarg) *x=atoi(optarg);
      break;
      case 'y': 
         if(optarg) *y=atoi(optarg);
      break;      
      default:
         fprintf(stderr, "%s\n",usage);
      break;
       }/* switch */	    
   }/* for options */
}/* getmyopts() */

/**********************************************************/

void getmyenv(int *x, int *y, int *w, int *h)
{
   if(getenv("LINER_X")) *x=atol(getenv("LINER_X"));
   if(getenv("LINER_Y")) *y=atol(getenv("LINER_Y"));
   if(getenv("LINER_W")) *w=atol(getenv("LINER_W"));
   if(getenv("LINER_H")) *h=atol(getenv("LINER_H"));
   
}/* getmyenv() */

/*********************************************************/

void sigintfunc(int signr)
{ 
   signal(signr, SIG_IGN); 
   done = 1;

}/* sigintfunc() */
