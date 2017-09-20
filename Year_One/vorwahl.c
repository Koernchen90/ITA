//=============================================================================
//Name			:vorwahl.c
//Author			:MAK
//Version		:
//Description	:Arbeitsblatt C19A - Mehrfachauswahl mit switch
//=============================================================================
#include <stdio.h>
int main (void)
{
	int vorwahl;
	
	do
	{
		printf("Vorwahlnr. eingeben (Ende mit 0): ");
		scanf("%i", &vorwahl);
		switch(vorwahl)
		{
			case 0:
				break;
			case 5221:
				printf("Herford\n");
				break;
			case 571:
				printf("Minden\n");
				break;
			case 521:
				printf("Bielefeld\n");
				break;
			default:
				printf("Fehler\n");
		}
	}
	while(vorwahl != 0);	
		
	return 0;
}
