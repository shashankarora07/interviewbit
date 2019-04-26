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
	binaryPrint(reverse_num);
}

void binaryPrint(int no)
{
	int i;
	for (i = 0; i < 32; i++) {
		if((no & (1 << (31 - i))))
			printf("1");
		else
			printf("0");
	}
	printf("\n");


}

int main()
{

	unsigned int A = 3;
	binaryPrint(A);
	reverse(A);


	return 0;
}
