#include<stdio.h>
#include<stdlib.h>


int mergeTwoSortedArray(int *A, int lenA, int *B, int lenB)
{
	int i = 0, j = 0, k = 0;
	int size = lenA + lenB;
	int *out = (int *)malloc(sizeof(int) * size);

	while(lenA && lenB)
	{
		if (A[i] < B[j]) {
			out[k++] = A[i++];
			lenA--;
		} else {
			out[k++] = B[j++];
			lenB--;
		}
	}

	if (lenA == 0) {
		while(lenB--) {
			out[k++] = B[j++];
		}
	}	
	
	if (lenB == 0) {
		while(lenA--) {
			out[k++] = A[i++];
		}
	}	

	PrintArray(out, size);
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
	
	int A[] = {1,5,8,10};
	int B[] = {3,6,7,9,12};

	//for (i = 0; i < size; i++)
	//	scanf("%d",&arr[size]);

	int sizeA = sizeof(A)/sizeof(A[0]);
	int sizeB = sizeof(B)/sizeof(B[0]);
	mergeTwoSortedArray(A,sizeA,B,sizeB);


	return 0;
}
