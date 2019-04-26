#include<stdio.h>





void binaryPrint(int no)
{
	int i;

	for(i = 0; i < 32; i++) {
		if (i%8 == 0)
			printf(" ");
		if (no & (1 << (31 - i)))
			printf("1");
		else
			printf("0");
	}
	printf("\n");

}

int main()
{
	//int num = 2147483647;
	int num = 5;
	int n = 3, mask = 0, mask1;
	binaryPrint(num);
	
	mask1 = (1 << n);
	binaryPrint(mask1);
	mask = (num - (1 << n));
	binaryPrint(mask);
	//num &= (num + (1 << 4));
	num = num & mask;
	binaryPrint(num);



}
