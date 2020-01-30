#include<stdio.h>

#define square(x)  x*x

int main()
{

	int ret = 36/square(6);
	printf("%d\n",ret);

	return 0;
}
