#include<stdio.h>

void binaryPrint(int no)
{
	int i;
	for (i = 0; i < 32; i++) {
		if (i%8 == 0)
			printf(" ");
		if((no & (1 << (31 - i))))
			printf("1");
		else
			printf("0");
	}
	printf("\n");


}

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

unsigned int reverse_byte(unsigned int a)
{
	int i;
	unsigned int rev_byte = 0;
	int SIZE = sizeof(int) * 8;
	int mask = 0xFF;
	int no = 0;
	printf("no = %d and its binaryPrint\n", a);
	binaryPrint(a);
	for (i = 0; i < SIZE; i++) {
		if (i % 8 == 0) {
			no = a & mask;
			rev_byte |= (no << SIZE-i-8);
			//binaryPrint(rev_byte);
			a = a >> 8;
		}

	}

	printf("rev byte = %d\n",rev_byte);
	binaryPrint(rev_byte);
}


unsigned int reverse_byteII(unsigned int a)
{
	int i;
	unsigned int rev_byte = 0;
	int SIZE = sizeof(int) * 8;
	int mask = 0xFF;
	int no = 0;
	printf("no = %d and its binaryPrint\n", a);
	binaryPrint(a);
	for (i = 0; i < SIZE; i+=8) {
			no = a & mask;
			rev_byte |= (no << SIZE-i-8);
			//binaryPrint(rev_byte);
			a = a >> 8;
		}

	printf("rev byte = %d\n",rev_byte);
	binaryPrint(rev_byte);
}


unsigned int reverse_byteIII(unsigned int a)
{
	int i;
	unsigned int rev_byte = 0;
	int SIZE = sizeof(a);
	//int mask = 0xFF;
	int no = a;
	char temp = NULL;
	
	char *p = (char *)&no;

	printf("no = %d and its binaryPrint\n", a);
	binaryPrint(a);
	for (i = 0; i < SIZE/2; i++) {
			temp = *(p+i);
			*(p+i) = *(p+SIZE-i-1);
			*(p+SIZE-i-1) = temp;
		}

	printf("rev byte = %d\n",no);
	binaryPrint(no);
}

int main()
{

	unsigned int A = 3;
	binaryPrint(A);
	reverse(A);
	A = 0x00005826;
	//reverse_byte(A);
	//reverse_byteII(A);
	reverse_byteIII(A);


	return 0;
}
