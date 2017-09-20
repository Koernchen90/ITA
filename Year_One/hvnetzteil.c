//=============================================================================
//Name			:hvnetzteil.c
//Author			:MAK
//Version		:
//Description	:Aufgabe 4 - Hochspannungsnetzteil
//=============================================================================
#include <stdio.h>

int main(void)
{
	float U, t;
	//U=m*t+b
	
	//Eingabe der Werte 
	printf("Geben Sie die Zeit in Sekunden an um die Spannung zu ermitteln \nt:");
	scanf("%f", &t);
	
	if(t<=5.0)
	{
		U=(1.0/5.0)*t;
		printf("Die Spannung bei %.3f Sekunden betraegt %.3f Kilovolt\n", t, U);
	}
	else
	{
		if(t<=7.0)
		{
			U=(1.0/2.0)*t-1.5;
			printf("Die Spannung bei %.3f Sekunden betraegt %.3f Kilovolt\n", t, U);
		}
		else
		{
			if(t<12.0)
			{
				U=(1.0/5.0)*t+0.6;
				printf("Die Spannung bei %.3f Sekunden betraegt %.3f Kilovolt\n", t, U);
			}
			else
			{
				if(t>=12.0)
				printf("Die Anlaufzeit von 12 Sekunden ist abgeschlossen\n");
				printf("Die Spannung hat ihren Maximalwert von 3 Kilovolt erreicht\n");
			}
		}
	}
	
	return 0;
}
