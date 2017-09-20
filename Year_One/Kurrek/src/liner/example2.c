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
#include <stdlib.h>
#include "liner.h"

int main(void)
{
   long x1, y1, x2, y2;
   liner_init();
   while(1)
   {
      fprintf(stderr,"Linien zeichnen, Ende mit x1-Wert<0:\n");
      fprintf(stderr,"Bitte x1 eingeben:");
      scanf("%ld", &x1);
      if(x1<0) 
         break;
      fprintf(stderr,"Bitte y1 eingeben:");
      scanf("%ld", &y1);
      fprintf(stderr,"Bitte x2 eingeben:");
      scanf("%ld", &x2);
      fprintf(stderr,"Bitte y2 eingeben:");
      scanf("%ld", &y2);
      
      line(x1,y1,x2,y2);
   }
   printf("Ende in 10 Sekunden...\n");
   sleep(10);
   liner_exit();
   return 0;
}
