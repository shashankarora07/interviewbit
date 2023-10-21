#include <stdio.h>

void binaryFormofInteger(int no)
{
	for (int i = 0; i < 32; i++) {
		if (i % 8 == 0 && i != 0)
			printf(" ");
		if (no & (0x1 << (31 - i)))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int bitsChangeToMakeNewNum2(int no1, int no2)
{
	int count = 0;
	for(int i = 0; i < 32; i++) {
		
		if ((no1 & (0x1 << i)) ^ (no2 & (0x1 << i)))
			count++;
	}

	return count;
}

int main()
{
	int num1 = 5;
	int num2 = 10;

	binaryFormofInteger(5);
	binaryFormofInteger(10);
	int count = bitsChangeToMakeNewNum2(num1, num2);
	printf("%d bits need to change in number %d integer to make num2 integer i.e %d\n",count, num1, num2);

	return 0;
}
