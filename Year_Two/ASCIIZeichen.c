//=============================================================================
//Name			:ASCIIZeichen.c
//Author			:MAK
//Version		:
//Description	:Ausgabe aller ASCII-Zeichen von 32 bis 127
//=============================================================================
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	signed char x;	
	
	for (x=32; x<127; ++x)
	{
		printf("%c",x);
		fflush(stdout);	//Ausgabepuffer wird geleert - Geht auch bei '\n' oder wenn er voll ist (EOF)
		//sleep(1);			//Zum Testen wie 'Sleep' funktioniert
		usleep(100000);	//'microsleep' durch <stdlib.h> in ms
	}
	
return 0;
}
