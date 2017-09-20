//=============================================================================
//Name			:zeiger.c
//Author			:MAK
//Version		:
//Description	:Arbeitsblatt: Zeiger
//=============================================================================
#include <stdio.h>

int main (void)
{
	int x = 1;
	int* px = NULL;
	
	px = &x; //Adresse von a
	*px = -3;
	
	printf("  x=%i\n", x);
	printf(" &x=%p\n", &x);		//Adress-Operator
	printf(" px=%p\n", px);		//%p - Ausgabe in HEX
	printf("&px=%p\n", &px);
	printf("*px=%i\n", *px);	//'Inhalts-Operator' - Die Var., deren Adresse in px steht
		
	return 0;
}

