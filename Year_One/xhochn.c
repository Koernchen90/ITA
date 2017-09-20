//=============================================================================
//Name			:xhochn.c
//Author			:MAK
//Version		:
//Description	:
//=============================================================================
#include <stdio.h>
#include <math.h>

int main(void)
{
	int x,n,fx;
	
	printf("x=");
	scanf("%i", &x);
	printf("n=");
	scanf("%i", &n);
	//fx=x;
	
	if (x==0 && n==0)
	{
		printf("0⁰ ist nicht definiert!\n");
	}//if
	else
	{
		fx=pow(x, n);
		/*for(count=1;count<n;++count)
		{
			fx=fx*x;
		}//for*/
		printf("%i^%i=%i\n", x,n,fx);
	}//else
	return 0;
}
