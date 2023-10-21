#include<stdio.h>
#include<stdlib.h>

void func(int **p)
{
	int count = *p;
	count++;
	printf("*p = %d\n",*p);
	(*p)++;
	printf("count = %d\n",count);
	printf("*p = %d\n",*p);

}

int main()
{
	int a = 10;
	func(&a);
	int b = 20;
	func(&b);
	printf("%d and %d\n",a,b);
	
//	int a = 100;
//	int *p;
//	*p  = a;
//
//	printf("%d and %d and %d\n",*p,a);

	return 0;
}
