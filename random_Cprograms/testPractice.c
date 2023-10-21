#include<stdio.h>

extern int a;

int a = 10;

int main()
{

	int a = 20;
	{
		printf("aa = %d\n",a);
	}

	return 0;
}
