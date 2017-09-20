//=============================================================================
//Name			:rechner.c
//Author			:MAK
//Version		:
//Description	:Arbeitsblatt C19A - Mehrfachauswahl mit switch
//=============================================================================
#include <stdio.h>
int main (void)
{
	int c;
	double a=0;
	double b=0;
	float x=0;
	
	do
	{
		printf("\nBitte erste Zahl eingeben: ");
		scanf("%lf", &a);
		printf("Bitte zweite Zahl eingeben: ");
		scanf("%lf", &b);
		
		printf("\nWas soll mit den Zahlen gemacht werden?\n");
		printf("0: Ende\n");
		printf("1: addieren\n");
		printf("2: subtrahieren\n");
		printf("3: multiplizieren\n");
		printf("4: dividieren\n");
		printf("Eingabe:");
		scanf("%i", &c);

		switch(c)
		{
			case 0:
				break;
			case 1:
				printf("Addieren: %f+%f=%f\n", a, b, x=a+b);
				break;
			case 2:
				printf("Subtrahieren: %f-%f=%f\n", a, b, x=a-b);
				break;
			case 3:
				printf("Multiplizieren: %f*%f=%f\n", a, b, x=a*b);
				break;
			case 4:
				printf("Dividieren: %f/%f=%f\n", a, b, x=a/b);
				break;
			default:
				printf("Fehler\n");
		}
	}
	while(c != 0);	
		
	return 0;
}
