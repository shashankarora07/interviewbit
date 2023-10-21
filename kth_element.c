#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *a, int start, int end)
{
	int pivot = a[end];
	int pIndex = start;
	int i = 0;
	for (i = start; i <= end-1; i++) {
		if (a[i] <= pivot) {
			swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[pIndex],&a[end]);
	
	return pIndex;
}

int QuickSort(int *a, int start, int end)
{
	int pIndex;
	if (start < end) {
		pIndex = partition(a,start,end);
		QuickSort(a,start,pIndex - 1);
		QuickSort(a,pIndex + 1,end);
	}
}

int kthsmallest(int *A, int len, int B)
{
	QuickSort(A,0,len-1);
	
	for(int i = 0; i < len; i++) {
		printf("%d   ",A[i]);
	}
	printf("\n");
	
	return A[B-1];
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Usage: array size required");
		exit(0);
	}
	
	int size = atoi(argv[1]);
	int arr[size];
	//int arr[] = {2,1,8,5,12,9,15,1,5};
	printf("Enter %d array element:\n",size);
	for (int i = 0; i < size; i++)
		scanf("%d",arr+i);
	
	int len = sizeof(arr)/sizeof(arr[0]);
	int kno = 0;		

	printf("Enter kth index:\n");
	scanf("%d",&kno);
	kno = kthsmallest(arr,len,kno);
	printf("Kth smallest element = %d\n",kno);
	
}
