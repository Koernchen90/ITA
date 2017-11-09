//=============================================================================
//Name			:klassenspiegel1.c
//Author			:MAK
//Version		:
//Description	:C43A - Aufgabe 2a
//=============================================================================
#include <stdio.h>

int main (void)
{
	double AMW;
	int i;
	double noten[6];	//|0|1|2|3|4|5|
	double anz = 0.0;
	double summe = 0.0;

	for(i=1; i<=6; ++i)
	{
		printf("Wie oft kam Note %i vor: ", i);
		scanf("%lf", &noten[i]);
		anz = anz + noten[i];
		summe = summe + i * noten[i];
	}
	AMW = summe / anz;
	
	printf("Klassenspiegel:\n");
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("| 1 | 2 | 3 | 4 | 5 | 6 |AMW|ANZ|\n");
	printf("+---+---+---+---+---+---+---+---+\n");
	printf("| %.0f | %.0f | %.0f | %.0f | %.0f | %.0f |%.1lf| %.0lf|\n", noten[1], noten[2], noten[3], noten[4], noten[5], noten[6], AMW, anz);
	printf("+---+---+---+---+---+---+---+---+\n");

	return 0;
}
