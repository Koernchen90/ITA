//=============================================================================
//Name			:emitterschaltung.c
//Author			:MAK
//Version		:
//Description	:Berechnung einer Emmitterschaltung
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define pi 3.14159265

int main (void)
{
	float U, fu, Ptot, Bmin;
	double Uce, Ur4, Ur3, Ic, R3, R4, Ur2, Ur1, Ibmax, Iq, R1, R2, C1, C2, C3, Pr1, Pr2, Pr3, Pr4;

	//Manuelle Eingabe
	printf("======================================================\n");
	printf("E M M I T T E R S C H A L T U N G\n");
	printf("Bitte folgende Werte eingeben:\n");
	printf("Betriebsspannung U0=");
	scanf("%f", &U);				//Eingabe Betriebsspannung U0
	printf("Untere Grenzfrequenz fu=");
	scanf("%f", &fu);				//Eingabe untere Grenzfrequenz
	printf("Maximale Transistor-Verlustleistung Ptot=");
	scanf("%f", &Ptot);			//Maximale Transistor-Verlustleistung Ptot
	printf("Minimale Transistor-Gleichstromverstärkung Bmin=");
	scanf("%f", &Bmin);			//Minimale Transistor-Gleichstromverstärkung Bmin
	
	//Verarbeitung
	Uce=U/2;
	Ur4=U/10;
	Ur3=U-Uce-Ur4;
	Ic=Ptot/Uce;
	R3=Ur3/Ic;
	R4=Ur4/Ic;
	Ur2=Ur4+0.7;
	Ur1=U-Ur2;
	Ibmax=Ic/Bmin;
	Iq=10.0*Ibmax;
	R1=Ur1/Iq;
	R2=Ur2/Iq;
	C1=1/(2*M_PI*fu*(1/R1+1/R2));
	C2=C1;
	C3=1/(2*M_PI*fu*R4);
	Pr1=Ur1*Iq;
	Pr2=Ur2*Iq;
	Pr3=Ur3*Iq;
	Pr4=Ur4*Iq;


	//Ausgabe
	printf("\n\nAUSGABE\n");
	printf("Uce=%.3fV\n", Uce);
	printf("Ur4=%.3fV\n", Ur4);
	printf("Ur3=%.3fV\n", Ur3);
	printf("Ic=%.3fA\n", Ic);
	printf("R3=%.3f\316\251\n", R3);
	printf("R4=%.3f\316\251\n", R4);
	printf("Ur2=%.3fV\n", Ur2);
	printf("Ur1=%.3fV\n", Ur1);
	printf("Ibmax=%.3fA\n", Ibmax);
	printf("Iq=%.3fA\n", Iq);
	printf("R1=%.3f\316\251\n", R1);
	printf("R2=%.3f\316\251\n", R2);
	printf("C1=%.3fF\n", C1);
	printf("C2=%.3fF\n", C2);
	printf("C3=%.3fF\n", C3);
	printf("Pr1=%.3fW\n", Pr1);
	printf("Pr2=%.3fW\n", Pr2);
	printf("Pr3=%.3fW\n", Pr3);
	printf("======================================================\n");
	
	
return 0;
}
