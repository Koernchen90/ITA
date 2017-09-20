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
#include <math.h>
#include "liner.h"

#define PI 3.141
int main(void)
{
   int t;
   int u, u0=72, f=50;
   liner_init();
   for (t=0; t<640; ++t)
   {
      u=u0*sin(2*PI*f*t);
      pixel(t,240+u);
   }
   getchar();   
   liner_exit();
   return 0;
}
