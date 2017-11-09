//=============================================================================
//Name			:rechteck_zeiger.c
//Author			:MAK
//Version		:
//Description	:Zeiger
//=============================================================================
#include <stdio.h>

void calc_rechteck_au(double s1, double s2, double* pa, double* pu)
{
	*pa=s1*s2;
	*pu=2*s1+2*s2;
}

int main(void)
{
	double h=30.0;
	double b=20.0;
	double a;
	double u;
	calc_rechteck_au(h, b, &a, &u);
	printf("%f %f\n", a,u);
}
