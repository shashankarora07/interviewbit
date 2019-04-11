#include<stdio.h>

unsigned int reverse(unsigned int a)
{
	int i;
	unsigned int reverse_num = 0;
	for (i = 0; i < 32; i++) {
		if (a & 1 << i)
			reverse_num |= ~(~0 <<1) << (31 - i);
	}

	printf("reverse_num = %d\n",reverse_num);
	for (i = 0; i < 32; i++) {
		if((reverse_num >> i) & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}


int main()
{

	unsigned int A = 3;
	for (int i = 0; i < 32; i++) {
		if((A >> i) & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	reverse(A);


	return 0;
}
