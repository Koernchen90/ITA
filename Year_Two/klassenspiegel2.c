//=============================================================================
//Name			:klassenspiegel2.c
//Author			:MAK
//Version		:
//Description	:C43A - Aufgabe 2b
//=============================================================================
#include <stdio.h>

int main (void)
{
	double AMW;
	int i;
	double noten[6]={0,0,0,0,0,0};
	double anz = 0.0;
	double summe = 0.0;
	int eingabe;
	
	
	do
	{
		printf("Bitte die Note des naechsten Schuelers eingeben (Ende mit o): ");
		scanf("%i", &eingabe);
		noten[eingabe] = noten[eingabe] + 1;
		if(eingabe != 0 && eingabe<=6)
			{
			anz = anz + 1; 
			}
		summe = summe + eingabe;
		
		/*printf("Merker 1: %f\n", noten[1]);
		printf("Merker 2: %f\n", noten[2]);
		printf("Merker 3: %f\n", noten[3]);
		printf("Merker 4: %f\n", noten[4]);
		printf("Merker 5: %f\n", noten[5]);
		printf("Merker 6: %f\n", noten[6]);
		printf("Merker Z: %f\n", anz);*/
	}
	while(eingabe != 0);
	
	AMW = summe / anz;
	
	printf("Klassenspiegel:\n");
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("| 1 | 2 | 3 | 4 | 5 | 6 |AMW|ANZ|\n");
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("| %.0f | %.0f | %.0f | %.0f | %.0f | %.0f |%.1lf| %.0lf|\n", noten[1], noten[2], noten[3], noten[4], noten[5], noten[6], AMW, anz);
	printf("+---+---+---+---+---+---+---+---+\n");

	return 0;
}
