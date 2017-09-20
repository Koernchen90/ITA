//=============================================================================
//Name			:fehlerquote.c
//Author			:MAK
//Version		:
//Description	:Fehlerquote.c
//=============================================================================
#include <stdio.h>

int main(void)
{
	float Fehler=30.0;
	double Jahr=0;
	
	while(Fehler>=1.0)
	{
		printf("Im Jahr %.0f liegt die Fehlerquote bei %.9f Prozent\n", Jahr, Fehler);
		++Jahr;
		Fehler=Fehler*0.9;
		
	} 

	return 0;
}
