//=============================================================================
//Name			:printbin_u8.c
//Author			:MAK
//Version		:
//Description	:Aufgabe: C25A 1
	/*	Leider bietet printf() auch im aktuellen Standard C11 keine Möglichkeit, 
	Zahlen in der Darstellung im Dualsystem auszugeben - und das, obwohl nahezu 
	jeder Rechner intern so arbeitet, die Umwandlung also besonders einfach wäre.
	Daher muss man als Programmierer selbst eine solche Funktion schreiben. 
	Eine sehr einfache Lösung, die allerdings nur für Zahlen im Datentyp unsigned
	char geeignet ist, zeigt das folgende
	Programm:
	______________________________________________________________________
	#include <stdio.h>
	int main (void)
	{
		int i ;
		unsigned char x=135; //Nur als Beispiel 
		for (i=0; i<8; ++i)
		{
			if (x>127) printf("1"); else printf("0");
			x=x*2;
		}
		printf("\n");
		return 0;
	}
	_____________________________________________________________________
	a) Das Programmstück soll zu einer Funktion printbin_u8(x) zusammengefasst werden.
		Die Funktion nimmt eine Zahl x und gibt sie wie oben aus. Wie lautet der Prototyp?
	b) Erstellen Sie bitte die Funktionsdefinition (schreiben Sie also die Funktion)!
	c) Testen Sie die Funktion mit einem kleinen Programm printbin_u8.c!

a) void printbin_u8 (unsigned char zahl)
*/
//=============================================================================
#include <stdio.h>
//Prototyps
void printbin_u8 (unsigned char x);


int main (void)
{
    printbin_u8 (255);	//Welche Zahl Dual angezeigt werden? 
}

// b)
void printbin_u8 (unsigned char x)
{
	int i ;
	for (i=0; i<8; ++i)
	{
		if (x>127) 
			printf("1"); 
		else
			printf("0");
		x=x*2;
	}
	printf("\n");
	return;
}
