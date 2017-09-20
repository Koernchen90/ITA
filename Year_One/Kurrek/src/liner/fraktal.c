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
#include "liner.h"
void fraktal(int x1, int y1, int x2, int y2, int ebene)
{
   line(x1, y1, x2, y2);
   if(ebene>0)
   {
      int xm, ym, dx, dy, xk, yk;
      sleep(0);
      xm=(x1+x2)/2;
      ym=(y1+y2)/2;
      dx=(xm-x2);
      dy=(ym-y2);
      xk=xm-dy;
      yk=ym+dx;
      
      fraktal(x1, y1, xk, yk, ebene-1);
      fraktal(xk, yk, x2, y2, ebene-1);
   }
}

int main(void)
{
   int i;
   liner_init();
   for(i=0; i<20; ++i)
   {
      fraktal(220,200,400,300,i);
      sleep(2);
   }
   liner_exit();
   return 0;
}
