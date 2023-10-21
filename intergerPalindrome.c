#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int IsintergerPalindrome(int no)
{
	int cdigit = 0;
	int cpy = no, tmp = no;
	while(cpy != 0) {
		cpy /= 10;
		cdigit++;
	}
	//digit update
	cdigit = cdigit - 1;
	//printf("cdigit = %d\n",no/(int)pow(10,cdigit));
	//printf("rem = %d\n",no%10);
	int halfint = cdigit/2;
	int leftd = 0, rightd = 0;
	while(halfint != cdigit)
	{
		rightd = no % 10;
		leftd = (tmp / (int)pow(10,cdigit)) % 10;
		printf("rightd = %d\n",rightd);
		printf("leftd = %d\n",leftd);
		if (leftd != rightd) {
			printf("%d is not a integer palindrome\n",tmp);
			return 0;
		}
		cdigit--;
		no /= 10;
	}
	printf("%d is interger palindrome\n",tmp);

}

int main(int argc, char *argv[])
{
	
	if (argc != 2) {
		perror("Usage: give integer input");
		exit(1);
	}

	int no = atoi(argv[1]);

	IsintergerPalindrome(no);


	return 0;
}
