//=============================================================================
//Name			:menuestart.c
//Author			:MAK
//Version		:
//Description	:Arbeitsblatt C18A - Fußgesteuerte Schleife mit do-while
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	int i;
	
	do
	{
		//system("clear");
		printf("\n\nIhre Moeglichkeiten:\n");
		printf("0: Ende\n");
		printf("1: Taschenrechner starten\n");
		printf("2: Editor starten\n");
		printf("3: Spiel starten\n");
		printf("Auswahl:");
		scanf("%i", &i);
		
		if (i==0)
		{
			printf("...wird beendet\n");
		}
		else
		{
			if (i==1)
			{
				printf("Taschenrechner wird gestartet...\n");
				system("xcalc&");
			}
			else
			{
				if (i==2)
				{
					printf("Editor wird gestartet...\n");
					system("gedit&");
				}
				else
				{
					if (i==3)
					{
						printf("Viel Spaß beim zocken!\n");
						system("gnome-mahjongg&");
					}
					else
					{
						if (i>=4)
						{
							printf("Eingabe ungueltig!\n");
						}
					}
				}
			}
		}
	}
	while(i != 0);

	return 0;
}
