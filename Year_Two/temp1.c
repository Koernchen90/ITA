//=============================================================================
//Name			:temp1.c
//Author			:MAK
//Version		:
//Description	:C43A - Aufgabe 1a
//=============================================================================
#include <stdio.h>
#define TAGSTUNDEN 24

int main(void)
{
	int messwert[TAGSTUNDEN];
	int lauf, lauf1;
	
	for(lauf=0; lauf<TAGSTUNDEN; lauf++)
	{
		printf("Bitte die Temperatur um %i:00 eingeben:", lauf);
		scanf("%i", &messwert[lauf]);
	}
	
	for(lauf=0; lauf<TAGSTUNDEN; lauf++)
	{
		printf("%i:00", lauf);
		for(lauf1=0; lauf1<=messwert[lauf]; lauf1++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
