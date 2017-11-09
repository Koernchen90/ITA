#include <stdio.h>

int main (void)
{
	double arithmittel;
	int lauf;
	double messwert[10];
	double summe;
	messwert[0]=47.21;
	messwert[1]=46.97;
	messwert[2]=47.80;
	messwert[3]=48.12;
	messwert[4]=47.15;
	messwert[5]=48.19;
	messwert[6]=45.02;
	messwert[7]=44.72;
	messwert[8]=49.35;
	messwert[9]=45.28;

	summe=0.0;
	for(lauf=0; lauf<10; ++lauf)
	{
		summe=summe+messwert[lauf];
	}

	arithmittel=summe/10;

	printf("Summe der Messwerte......: %lf\n", summe);
	printf("Arithmetischer Mittelwert: %lf\n", arithmittel);

	return 0 ;
}

