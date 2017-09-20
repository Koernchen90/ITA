//=============================================================================
//Name			:rechtwinkeldreieck.c
//Author			:MAK
//Version		:
//Description	:Rechtwinkliges Dreieck
//=============================================================================
#include <stdio.h>

int main(void)
{
	float a, b, c; 

   printf("Bitte drei Zahlen eingeben \na:");
   //scanf("%f, %f, %f", &a, &b, &c);
   scanf("%f", &a);
   printf("b:");
   scanf("%f", &b);
   printf("c:");
   scanf("%f", &c);
   
   if((c*c==a*a+b*b)||(b*b==a*a+c*c)||(a*a==b*b+c*c))
   {
		printf("Ja\n");
   }
   else 
   {
		printf("Nein\n");
   }

   return 0;
}

