#include<stdio.h>

int main(int argc, char const *argv[])
{
	unsigned char arr[2] = {0x01, 0x00};
	unsigned short int x = *(unsigned short int *)arr;

	printf("%d\n", x);

	return 0;
}
