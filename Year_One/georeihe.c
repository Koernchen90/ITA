//=============================================================================
//Name			:georeihe.c
//Author			:MAK
//Version		:
//Description	:georeihe.c
//=============================================================================
#include <stdio.h>

int main(void)
{
	double i=0;
	double sum=1;
	
	while(1)
	{
		if(i==i+sum) break;	
		i=i+sum;
		sum=sum/2.0;
		printf("i=%.52f\n", i);
	}	
	return 0;
}
