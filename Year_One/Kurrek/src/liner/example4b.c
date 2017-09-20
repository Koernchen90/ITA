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
#include <stdio.h>
#include "liner.h"

int main(void)
{
   int r,g,b,xoffset,yoffset;
   
   liner_init();
   for(r=0; r<64; ++r)
   {
      xoffset=(r%10)<<6;
      yoffset=(r/10)<<6;
      for(g=0; g<64; ++g)
      {
         for(b=0; b<64; ++b)
         { 
            color(r<<2,g<<2,b<<2);
            pixel(g+xoffset,b+yoffset);
         }
      }
   }
   color(0,0,0);
   text(150,150, "Viele");
   text(200,250, "Farben!");
   liner_exit();
   return 0;
}
