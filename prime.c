#include<stdio.h>

int isPrime(int A) 
{
	int i = 0, flag = 1, rem = 0;

	for (i = 2; i <= A / 2; i++) {
		if ((rem = A % i) == 0) {
			printf("Inside rem = %d\n",rem);	
			printf("%d is not prime number.\n",A);
			flag = 0;
			break;
		}
		printf("rem = %d\n",rem);	
	}
	if (flag) {
		printf("%d is prime number.\n",A);
	}     

}

int main()
{
	
	int no = 0;
	
	printf("Enter no:\n");
	scanf("%d",&no);
	isPrime(no);

	return 0;
}
