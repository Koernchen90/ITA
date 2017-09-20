//=============================================================================
//Name			:c_entladen.c
//Author			:MAK
//Version		:
//Description	:c_entladen.c
//=============================================================================
#include <stdio.h>
#include <math.h>

int main(void)
{
	double C, R, U, tau, t, Uc;
	
	//Werte ermitteln
	C=100.0*pow(10.0, (-6.0));//*10.0*e-9);
	R=100.0*pow(10.0, (3.0));//*10.0*e-3);
	U=350.0;
	tau=R*C;
	t=0.0;
	Uc=0.0;
	
	while(Uc>=24.0 || Uc==0.0)
	{
		t++;
		Uc=U*exp((-t)/tau);
		printf("Uc(%.0fs) = %.3f V\n", t, Uc);	
	}
	if(Uc<=24.0)
	{
		printf("Kondesatorspannung ist ungefaehrlich: Uc(%.0fs)=%.3f Volt\n", t, Uc);
	}
	
	return 0;
}
