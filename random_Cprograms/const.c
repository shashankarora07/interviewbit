#include<stdio.h>


//const int b = 10;

void func()
{
	const int b = 20;
	int *p = &b;

	*p = 100;

	printf("func = %d\n",*p);

}

//const int b = 20;
int main()
{

	func();

//	int *p = &b;
//
//	*p = 100;
//
//	printf("func = %d\n",*p);
	return 0;
}


