/* Given a positive integer N, print all the integers from 1 to N. But for multiples of 3 print
“Fizz” instead of the number and for the multiples of 5 print “Buzz”. Also for number which are
multiple of 3 and 5, prints “FizzBuzz”. Example N = 5 Return: [1 2 Fizz 4 Buzz] Note: Instead of
printing the answer, you have to return it as list of strings. */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fizzBuzz(int a)
{
	char **A = (char **)malloc(sizeof(char*) * a);
	char buffer[20];
    

	for (int i = 1; i <= a; i++) {

		if (i % 3 == 0 && i % 5 == 0) {
			A[i-1] = (char *)malloc(sizeof(char) * 8);
			A[i-1] = "FizzBuzz";
		}
		else if (i % 3 == 0) {
			A[i-1] = (char *)malloc(sizeof(char) * 4);
			A[i-1] = "Fizz";
		}
		else if (i % 5 == 0) {
			A[i-1] = (char *)malloc(sizeof(char) * 4);
			A[i-1] = "Buzz";
		}
		else {
	
			sprintf(buffer, "%d", i);
			int len = strlen(buffer);
			A[i-1] = (char *)malloc(sizeof(char) * len);
			//printf("len = %d and buffer = %s and i-1 = %d\n",len,buffer,i-1);
			strcpy(A[i-1],buffer);
		}

	}

	for (int i = 0; i < a; i++) {
		printf("%s  ", A[i]);
	}
	printf("\n");


}


void PrintArray(int *a, int len)
{
	int i = 0;

	for (i = 0; i < len; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");

}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Usage: give random number");
		exit(1);
	}

	int size = atoi(argv[1]);
	//int *arr = (int*)malloc(size * sizeof(int));
	
	//for (int i = 0; i < size; i++)
	//	scanf("%d",&arr[i]);

	//PrintArray(arr,size);
	fizzBuzz(size);

	return 0;
}
