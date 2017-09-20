//=============================================================================
//Name			:schaltjahr.c
//Author			:MAK
//Version		:
//Description	:Schaltjahr - ja oder nein?
//=============================================================================
#include <stdio.h>
int main(void)
{
	int jahr=0;
	
	printf("Jahreszahl = Schaltjahr?\n\n");
	printf("Bitte Jahreszahl angeben:");
	scanf("%d", &jahr);

	if (jahr % 4 ==0)
	{
		if (jahr % 100==0)
		{
			if (jahr %400 ==0)
			{
				printf("%d ist ein Schaltjahr.\n", jahr);
			}
			else
			{
				printf("%d ist kein Schaltjahr.\n", jahr);
			}

		}
		else
		{
			printf("%d ist ein Schaltjahr.\n", jahr);
		}
	}
	else
	{
   	printf("%d ist kein Schaltjahr.\n",  jahr);
   }   
	return 0;
}
