//=============================================================================
//Name			:muenzrueckgabe.c
//Author			:MAK
//Version		:
//Description	:Muenzrueckgabeautomat
//=============================================================================
#include <stdio.h>

int main(void)
{
	int Betrag=0;
	int anz_50c=0;
	int anz_20c=0;
	int anz_10c=0;
	int anz_5c=0;
	int anz_2c=0;
	int anz_1c=0;		//Bereiche nullen, da sonst scheiße ausgegeben wird
	
	//Eingabe der Werte 
	printf("Bitte Betrag zwischen 1 und 99 Cent eingeben: \nBetrag:");
	scanf("%d", &Betrag);
	
	if(Betrag>99||Betrag<=0)
	{
		printf("Betrag falsch, bitte an die Vorgabe halten!\n");
	}
	else
	{
		while(Betrag>=50)//mehr als 50 cent 
		{ 
			Betrag-=50; //'x-=y' -> x=x-y
			anz_50c++; 
		}
		while(Betrag>=20)//mehr als 20 cent 
		{ 
			Betrag-=20; 
			anz_20c++; 
		}
		while(Betrag>=10)//mehr als 10 cent 
		{ 
			Betrag-=10; 
			anz_10c++; 
		}
		while(Betrag>=5)//mehr als 5 cent 
		{ 
			Betrag-=5; 
			anz_5c++; 
		}
		while(Betrag>=2)//mehr als 2 cent 
		{ 
			Betrag-=2; 
			anz_2c++; 
		}
		while(Betrag>=1)//mehr als 1 cent 
		{ 
			Betrag-=1; 
			anz_1c++; 
		}
	
		//Ausgabe der Werte
		printf("Folgende Muenzanzahl wird ausgegeben:\n");
		printf("%dx 50 Cent-Muenze\n", anz_50c);
		printf("%dx 20 Cent-Muenze(n)\n", anz_20c);
		printf("%dx 10 Cent-Muenze(n)\n", anz_10c);
		printf("%dx  5 Cent-Muenze(n)\n", anz_5c);
		printf("%dx  2 Cent-Muenze(n)\n", anz_2c);
		printf("%dx  1 Cent-Muenze(n)\n", anz_1c);
	}	
	
	return 0;
}
