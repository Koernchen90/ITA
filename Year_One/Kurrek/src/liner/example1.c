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
#include <stdlib.h>
#ifdef PS
#  include "psliner.h"
#else
#  include "liner.h"
#endif

int main(void)
{
   int i;
   printf("%d\n",liner_init_xywh(0,0,80,80,640,480));
   for (i=0; i<480; i+=5)
   {
      rectangle(1,1,640,480,0);
      line(0,i,639,479-i);
      usleep(50000);
   }
   setfont("Palatino", 96);
   text(20,20,"H\xc4LLO");
   sleep(5);
   liner_exit();
   return 0;
}
