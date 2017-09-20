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
#ifndef _CINPUT_H_
#define _CINPUT_H_
#include <deque>
using namespace std;

enum language_t {NATIVE,FIG,HPGL};
enum channel_t {KEYBOARD,NETWORK};
enum ierror_t {OK,NOTIMPLEMENTED,INPERR,NOINPUT,IEOF};

class cinput
{
private:
   channel_t channel;
   language_t language;
   ierror_t error;
public:
   cinput(channel_t, language_t);
   void getcommand(deque<unsigned char> &q);
   void getcommandkb(deque<unsigned char> &q);
   ierror_t geterror(void);
   void setchannel(channel_t);
   void setlanguage(language_t);
};
#endif
