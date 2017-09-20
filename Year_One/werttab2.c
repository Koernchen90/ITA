//=============================================================================
//Name			:werttab2.c
//Author			:MAK
//Version		:
//Description	:Kompilieren mit "gcc werttab2.c -lm"
//=============================================================================
#include <stdio.h>
#include <math.h>

int main (void)
{
	double wert=0; 
	double deg=0;
	double rad=0;
	int count=0;
	
	for(count=0;count<31;++count)
	{
		rad=deg*(M_PI/180);
		wert=cos(rad);
		printf("Der Cosinus von %.0lf° betraegt %lf\n", deg, wert);
		deg++;
	}

return 0;
}
