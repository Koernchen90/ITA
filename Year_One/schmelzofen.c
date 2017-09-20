//=============================================================================
//Name			:schmelzofen.c
//Author			:MAK
//Version		:
//Description	:schmelzofen.c
//=============================================================================
#include <stdio.h>

int main(void)
{
	double Energie=100.0;
	double offen=0;
	
	while(Energie>=30.0)
	{
		printf("Ofen %.0f mal geoeffnet, %.2f Prozent Leistung\n", offen, Energie);
		offen++;
		Energie=Energie*0.95;
	}
	if(Energie<=30.0)
	{
		printf("Der Ofen wurde zu oft geoeffnet und hat mehr als 70\45 Prozent seiner Leistung verloren\n");
	}
	
	return 0;
	
}
