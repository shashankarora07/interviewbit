#include<stdio.h>
#include<stdlib.h>

/* Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays. */

int intersectionTwoSortedArray(int *A, int lenA, int *B, int lenB)
{
	int i = 0, j = 0, k = 0;
	int size = lenA + lenB;
	int *out = (int *)malloc(sizeof(int) * size);

	while(i < lenA && j < lenB)
	{
		printf("LenA = %d lenB = %d, i = %d, j = %d\n",lenA,lenB,i,j);
		if (A[i] == B[j]) {
			out[k++] = A[i++];
			j++;
		}
		else if (A[i] < B[j]) {
			i++;
		}
		else {
			j++;
		}

	}

	PrintArray(out, k);
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
		perror("Usage: size of array is not given");
		exit(1);
	}

	int size = atoi(argv[1]);
	//int arr[size];
	
	int A[] = {1,2,3,3,4,5,6};
	int B[] = {3,3,5};

	//for (i = 0; i < size; i++)
	//	scanf("%d",&arr[size]);

	int sizeA = sizeof(A)/sizeof(A[0]);
	int sizeB = sizeof(B)/sizeof(B[0]);
	intersectionTwoSortedArray(A,sizeA,B,sizeB);


	return 0;
}
