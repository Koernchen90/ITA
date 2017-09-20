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
#include <iostream>
#include <algorithm> // wg. find()
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "coutput.h"

extern int done;
//----------------------------------------------
Coutput::Coutput(cdraw *npdraw): pdraw(npdraw)
{
   error=ONOERROR;
}
//----------------------------------------------
oerror_t Coutput::geterror(void) 
{
   return error;
}
//----------------------------------------------
void Coutput::docommand(deque<unsigned char> &q)
{
   string s;
   deque<unsigned char>::iterator qptr;
   
   qptr=find(q.begin(),q.end(),'\n'); 
   if(qptr == q.end())
   {
#if TEST
      fprintf(stderr, "%s:%d: empty queue!\n", __FILE__, __LINE__);
#endif
      error=OEMPTY;
      return;
   }
   error=ONOERROR;
   
   while(!q.empty())
   {
      char c;
      c = q.front();
#if TEST
      fprintf(stderr, "read char: >%c<\n",c);
#endif 
      q.pop_front();
      if(c=='\n') 
         break;
      s=s+c;
   }  
   docmdline(s);
}
//----------------------------------------------

void Coutput::docmdline(string s)
{
#  define DELIM " "
   string    cmd, args;
   string::size_type cmd_end;
   
   cmd_end=s.find_first_of(DELIM, 0);
   cmd = s.substr(0, cmd_end);
   args= s.substr(cmd_end+1, string::npos);
   if     (cmd=="L" || cmd=="LINE" ) do_line(args);
   else if(cmd=="A" || cmd=="ARG"  ) do_arc(args);
   else if(cmd=="C" || cmd=="CLEAR") do_clear();
   else if(cmd=="Q" || cmd=="QUIT" ) do_quit();
   else if(cmd=="O" || cmd=="COLOR") do_color(args);
   else if(cmd=="P" || cmd=="PIXEL") do_pixel(args);
   else if(cmd=="R" || cmd=="RECTANGLE") do_rectangle(args);
   else if(cmd=="T" || cmd=="TEXT" ) do_text(args);
   else if(cmd=="Y" || cmd=="POLYLINE") do_polyline(args);
#if TEST
   else
      fprintf(stderr, "Unknown CMD:>%s<!\n", s.c_str());
#endif
}

//------------------------------------------------

void Coutput::do_arc(string s)
{
   unsigned int mx, my, r;
   int phi1, phi2, filled;
   string::size_type start, stop;
   
   start=0;
   stop=s.find_first_of(DELIM,start);
   mx=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   my=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   r=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   phi1=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   phi2=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   filled=atoi((s.substr(start, stop)).c_str());
   
#if TEST
   fprintf(stderr, "ARC:>%u,%u,%u,%i,%i,%i<\n", mx, my, r, phi1, phi2, filled);
#endif
   pdraw->drawarc(mx,my,r,phi1,phi2,filled);
}

//----------------------------------------------L

void Coutput::do_line(string s)
{
   int x1, y1, x2, y2;
   string::size_type start, stop;
   
   start=0;
   stop=s.find_first_of(DELIM,start);
   x1=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   y1=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   x2=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   y2=atoi((s.substr(start, stop)).c_str());
   
#if TEST
   fprintf(stderr, "LINE:>%i,%i,%i,%i<\n", x1,y1,x2,y2);
#endif
   pdraw->drawline(x1,y1,x2,y2);
}

//----------------------------------------------L

void Coutput::do_rectangle(string s)
{
   unsigned int x1, y1, x2, y2;
   int filled;
   string::size_type start, stop;
   
   start=0;
   stop=s.find_first_of(DELIM,start);
   x1=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   y1=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   x2=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   y2=atoi((s.substr(start, stop)).c_str());

   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   filled=atoi((s.substr(start, stop)).c_str());
   
#if TEST
   fprintf(stderr, "RECTANGLE:>%u,%u,%u,%u,%i<\n", x1,y1,x2,y2,filled);
#endif
   pdraw->drawrectangle(x1,y1,x2,y2,filled);
}

//----------------------------------------------O
void Coutput::do_clear(void)
{
   pdraw->clearwindow();
}

//----------------------------------------------O
void Coutput::do_color(string s)
{
   const char *t;
   t=s.c_str();
   pdraw->setcolor(t);
}
//----------------------------------------------P
void Coutput::do_pixel(string s)
{
   int x, y;
   string::size_type stop;
   
   stop=s.find_first_of(DELIM,0);
   x=atoi((s.substr(0, stop)).c_str());
   ++stop;
   y=atoi((s.substr(stop, string::npos)).c_str());
   pdraw->drawpoint(x,y);
}

//----------------------------------------------T

void Coutput::do_text(string s)
{
   int x, y;
   const char *t;
   string::size_type start, stop;
   
   start=0;
   stop=s.find_first_of(DELIM,start);
   x=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   y=atoi((s.substr(start, stop)).c_str());
   
   start=stop+1;
   t=s.substr(start, string::npos).c_str();
   pdraw->drawtext(x,y,t);
}
//----------------------------------------------

void Coutput::do_quit(void)
{
   kill(getpid(), SIGINT);
}

//----------------------------------------------L

void Coutput::do_polyline(string s)
{
   int filled;
   unsigned int *koords=NULL;
   unsigned int i, n;
   string::size_type start, stop;
   
   start=0;
   stop=s.find_first_of(DELIM,start);
   n=(unsigned int)atoi((s.substr(start, stop)).c_str());
   
   koords=(unsigned int *)malloc(2*n*sizeof(unsigned int));
   if(!koords)
   {
      fprintf(stderr, "%s %l: malloc(2*%u*size): problem!\n", 
             __FILE__, __LINE__, n);
      return;
   }
   start=stop+1;
   stop=s.find_first_of(DELIM,start);
   filled=atoi((s.substr(start, stop)).c_str());   

   for(i=0; i<n; ++i)
   {
      start=stop+1;
      stop=s.find_first_of(DELIM,start);
      koords[i+i]=atoi((s.substr(start, stop)).c_str());
   
      start=stop+1;
      stop=s.find_first_of(DELIM,start);
      koords[i+i+1]=atoi((s.substr(start, stop)).c_str());
   }
#if TEST
   fprintf(stderr, "POLYLINE:>%u, %i, DATA<\n", n, filled);
#endif
   pdraw->drawpolyline(n, filled, koords);
   free(koords);
}
