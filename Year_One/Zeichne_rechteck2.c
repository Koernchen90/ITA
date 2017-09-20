//=============================================================================
//Name			:rechteck2.c
//Author			:MAK
//Version		:
//Description	:Zeichne_rechteck2.c
//=============================================================================
#include <stdio.h>

void sterne(int breite, int hoehe);

void sterne(int breite, int hoehe)
{
	int x;
	for (x=0; x<hoehe; ++x)
	{
		printf("*");
		
		int y;
		for (y=0; y<breite; ++y)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main (void)
{
	int breite, hoehe;
	printf("Wie breit soll das Rechteck sein? ");
	scanf("%i", &breite);
	printf("Wie hoch soll das Rechteck sein? ");
	scanf("%i", &hoehe);
	
	sterne(breite, hoehe);
	
}
