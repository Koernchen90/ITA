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
#include <queue>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>

using namespace std;
#include "cinput.h"

//==============================================
cinput::cinput(channel_t c, language_t l): channel(c), language(l)
{
   error    = NOINPUT;
}
//----------------------------------------------
void cinput::getcommand(deque<unsigned char> &q)
{
   error=OK;
                  // Daten einsammeln (non-blocking!)
   switch(channel)
   {
      case KEYBOARD: getcommandkb(q); break;
      default: error=NOTIMPLEMENTED;  break;
   }
                 // Daten uebersetzen
   if(error==OK)
   {
      switch(language)
      {
         case NATIVE: break; 
         default: error=NOTIMPLEMENTED; break;
      }
   }
}
//----------------------------------------------
void cinput::getcommandkb(deque<unsigned char>& q)
{
#define INBUFSIZE 10240

   char    ca[INBUFSIZE];
   fd_set  readset;
   ssize_t result;
   int     s_result;
   struct  timeval tv={0L,100L};    
   
   if(error==INPERR) { return; }
   
   FD_ZERO(&readset);
   FD_SET(fileno(stdin), &readset);
   s_result = select(1, &readset, NULL, NULL, &tv);
   if(s_result==-1) // echter Fehler!
   {
#if TEST
      fprintf(stderr,"%s:%d:select():%s!\n",__FILE__,__LINE__,
              strerror(errno));
#endif
      /* error=INPERR; */
      return;
   }
   else if(s_result==0) // nix erhalten...
   {
      error=NOINPUT;
      return;
   }

   result=read(fileno(stdin),ca,INBUFSIZE); 
   if(result==-1)  // echter Fehler!
   {
#if TEST
      fprintf(stderr,"%s:%d:read():%s!\n",__FILE__,__LINE__,
              strerror(errno));
#endif
      error=INPERR;
      return;
   }
   else if(result==0)   // Dateiende
   {
#if TEST
      fprintf(stderr,"%s:%d:Dateiende erreicht!\n",
              __FILE__,__LINE__);
#endif
      error=IEOF;
      return;
   }
   
   for(ssize_t i=0; i<result; ++i)
   {
      q.push_back(ca[i]);
#if TEST
      printf("Schreibe Zeichen: >%c<\n", ca[i]);
#endif
   }
   error=NOINPUT;
   return;
}
//----------------------------------------------
void cinput::setchannel(channel_t c) {channel=c;}
void cinput::setlanguage(language_t l) {language=l;}
ierror_t cinput::geterror(void) {return error;}
//==============================================
