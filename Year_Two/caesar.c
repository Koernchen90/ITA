//=============================================================================
//Name			:caesar.c
//Author			:MAK
//Version		:
//Description	:Caesar-Verchluesselung
//=============================================================================
#include <stdio.h>
int main(void)
{
	int x;
	x = getchar();
	while(x != EOF)
	{
		if(x >= 'A' && x <= 'Y' || x >= 'a' && x <= 'y')
		{
			putchar(x-1);
		}
		else
		{
			if(x == 'Z' || x == 'z')
			{
				putchar ('A');
			}
			else
			{
				putchar(x);
			}
		}
		x = getchar();
	}

	return 0;
}
