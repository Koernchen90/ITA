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
#ifndef _COUTPUT_
#define _COUTPUT_
#include <deque>
#include <string>
#include "cdraw.h"

using namespace std;

enum oerror_t {ONOERROR,OEMPTY};

class Coutput
{
private: 
   cdraw *pdraw;
   oerror_t error;
public:
   Coutput(cdraw *npdraw);
   oerror_t geterror(void);
   void docommand(deque<unsigned char> &q);
   void docmdline(string s); 
   void do_arc(string s);    // A
   void do_line(string s);   // L
   void do_clear(void);      // C
   void do_color(string s);  // O
   void do_pixel(string s);  // P
   void do_quit(void);       // Q
   void do_rectangle(string s);// R
   void do_text(string s);     // T
   void do_polyline(string s); // Y
};
#endif
