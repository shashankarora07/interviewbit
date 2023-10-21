/*
Reverse digits of an integer.
Example1:
x = 123,
return 321
Example2:
x = -123,
return -321
Return 0 if the result overflows and does not fit in a 32 bit signed integer
*/

//INTMAX - 2147483647
#include<stdio.h>
#include<limits.h>

// Use input -> -1146467285, -1234567891, 
//   
void DigitReverse(int A)
{
	int sign = 1;
	int res = 0, rem = 0;
	if (A < 0) {
		A *= -1;
		sign = -1;
	}
	while (A > 0) {
		rem = A % 10;
		printf("rem = %d   ",rem);

		if (res > INT_MAX/10 || res == INT_MAX/10 && rem > INT_MAX%10) {
			printf("res = %d\n",0);
			return;
		}
		res = res*10 + rem;
		A /= 10;
		printf("res = %d   and   A = %d\n",res, A);
	}

	res *= sign;

	printf("result = %d\n",res);
}

int main()
{
	int no = 0;
	printf("Value of INT_MAX = %d and INT_MIN = %d\n",INT_MAX,INT_MIN);
	printf("Enter number:\n");
	scanf("%d",&no);
	DigitReverse(no);

	return 0;
}
