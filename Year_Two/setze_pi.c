//=============================================================================
//Name			:setze_pi.c
//Author			:MAK
//Version		:
//Description	:setze_auf_pi
//=============================================================================
#include <stdio.h>

void setze_auf_pi(double* px)
{
	*px=3.1415;
}
int main (void)
{
	double x;
	double* px;
	px=&x;
	setze_auf_pi(px);
	printf("%f\n", x);
	return 0;
}
