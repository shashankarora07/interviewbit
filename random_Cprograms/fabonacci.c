#include<stdio.h>

void fabonacci(int a, int b, int count)
{	
	int c = 0;
	if (count-1 < 0)
		return;

	count--;
	c = a+b;
	a = b;
	printf("%d \n",c);
	fabonacci(a,c,count);
}	

int main()
{

	int a = 0, b = 1, no = 10;
	printf("%d \n%d\n",a,b);

	fabonacci(a,b,no-2);


	return 0;
}
