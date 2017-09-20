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

int main(void)
{
   int i,j;
   liner_init();   
   for (j=0; j<500; j+=10)
   {
      for (i=0; i<750; i+=10)
      {
         line(i+1,j+1,i-1,j-1);
         line(i-1,j+1,i+1,j-1);
      }
   }
   sleep(5);
   liner_exit();
   return 0;
}
