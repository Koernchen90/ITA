//=============================================================================
//Name			:bmi.c
//Author			:MAK
//Version		:
//Description	:Berechnung des body-mass-index
//=============================================================================
#include <stdio.h>

int main(void)
{
	float BMI, m, l;

	//Eingabe der Werte zur Berechnung des BMI
   printf("Bitte folgende Werte eingeben um Ihren BMI zu ermitteln \n");
   printf("Körpergröße in cm: ");
   scanf("%f", &l);
   printf("Körpergewicht in kg: ");
   scanf("%f", &m);  

   //Berechnung des BMI
   BMI=m/((l*l/10000));
   
   //Einschaetzung ermitteln und ausgeben
   if(BMI<=16.0)
   {
		printf("Starkes Untergewicht, Ihr BMI betraegt %f\n", BMI);
   }
   else 
   {
		if(BMI<=17.0)
		{
		printf("Maessiges Untergewicht, Ihr BMI betraegt %f\n", BMI);
		}
		else
		{
			if(BMI<=18.5)
			{
				printf("Leichtes Untergewicht, Ihr BMI betraegt %f\n", BMI);
			}
			else
			{
				if(BMI<=25.0)
				{
					printf("Normalgewicht, Ihr BMI betraegt %f\n", BMI);
				}
				else
				{
					if(BMI<=30.0)	
					{
						printf("Praeadipositas, Ihr BMI betraegt %f\n", BMI);
					}
					else
					{
						if(BMI<=35.0)
						{
							printf("Adipositas leicht, Ihr BMI betraegt %f\n", BMI);
						}
						else
						{
							if(BMI<=40.0)
							{
								printf("Adipositas maessig, Ihr BMI betraegt %f\n", BMI);
							}
							else
							{
								if(BMI>40.0)
								{
									printf("Adipositas stark, Ihr BMI betraegt %f\n", BMI);
								}
							}
						}
					}
				}
			}
		}
   }

   return 0;
}

