/*
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
Example:
Input : [1, 0]
Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
* All elements in the array are in the range [0, N-1]
* N * N does not overflow for a signed integer
*/

#include<stdio.h>
#include<stdlib.h>

void PrintArray(int *a, int len)
{
	int i = 0;

	for (i = 0; i < len; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");

}

void RearrangeArray(int *A, int N)
{
	int i = 0;

	for (i = 0; i < N; i++) {
		A[i] = A[i] + (A[A[i]]%N)*N;
	}

	for (i = 0; i < N; i++) {
		A[i] = A[i]/N;
	}

	PrintArray(A,N);
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		perror("Usage: array size required");
		exit(0);
	}
	
	int size = atoi(argv[1]);
	int *arr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		scanf("%d",&arr[i]);

	RearrangeArray(arr,size);
	
	
	return 0;
}
