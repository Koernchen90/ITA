//=============================================================================
//Name			:banner.c
//Author			:MAK
//Version		:
//Description	:Arbeitsblatt C23A - Hello, World als Banner
//=============================================================================
#include <stdio.h>
void h(void);
void a(void);
void l(void);
void a(void);
void banner(void);

int main (void)
{
	do
	{
		banner();
		sleep(1);
	}
	while (1);	
}

void h(void)
{
	printf("**********\n"
			 "    **    \n"
			 "    **    \n"
			 "**********\n");
	return;
}

void a(void)
{
	printf("**********\n"
			 "     *   *\n"
			 "     *   *\n"
			 "**********\n");
	return;
}

void l(void)
{
	printf("**********\n"
			 "*         \n"
			 "*         \n"
			 "*         \n");
	return;
}

void o(void)
{
	printf(" ******** \n"
			 "*        *\n"
			 "*        *\n"
			 " ******** \n");
	return;
}

void banner(void)
{
	h();
	a();
	l();
	l();
	o();
}


