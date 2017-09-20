//=============================================================================
//Name			:rechteck.c
//Author			:MAK
//Version		:
//Description	:Zeichne_rechteck.c
//=============================================================================
#include <stdio.h>

void sterne(int anzahl);

void sterne(int anzahl)
{
	int lauf;
	for (lauf=0; lauf<anzahl; ++lauf)
	{
		printf("*");
	}
	printf("\n");
}

int main (void)
{
	int breite, hoehe;
	printf("Wie breit soll das Rechteck sein? ");
	scanf("%i", &breite);
	printf("Wie hoch soll das Rechteck sein? ");
	scanf("%i", &hoehe);
	
	while (hoehe > 0)
	{
		sterne(breite);
		--hoehe;
	}	
}
