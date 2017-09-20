/*
liner - graphical output from textmode applications
Copyright (C) 2006, 2013 Joerg Kurrek

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
#include "liner.h"

int main(void)
{
   int r,g,b,xoffset,yoffset;
   liner_init_xywh(1,0,100,100,640,480);
   for(b=0; b<64; b+=1)
   {
      xoffset=(b%10)<<6;
      yoffset=(b/10)<<6;
      for(r=0; r<64; r+=2)
      {
         for(g=0; g<64; g+=2)
         { 
            color(r*4,g*4,b*4);
            pixel(r+xoffset,g+yoffset);
         }
      }
   }
   color(0,0,0);
   text(150,150, "Viele");
   text(200,250, "Farben!");
   getchar();
   liner_exit();
   return 0;
}
