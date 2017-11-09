//=============================================================================
//Name			:verdoppel_x.c
//Author			:MAK
//Version		:
//Description	:verdoppel_x
//=============================================================================
#include <stdio.h>

void verdoppel_x(double x, double* px)
{
	*px=x*2;
}
int main (void)
{
	double x;
	double* px;
	px=&x;
	scanf("%lf", &x);
	verdoppel_x(x, px);
	printf("%f\n", x);
	return 0;
}
