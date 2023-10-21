#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
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

void QuickSort(int *a, int start, int end)
{
	int pIndex = 0;

	if (start < end) {
		pIndex = partition(a,start,end);
		QuickSort(a,start,pIndex-1);
		QuickSort(a,pIndex+1,end);
	}
}


int main(int argc, char *argv[])
{
	int size, i = 0;
	
	if (argc != 2) {
		perror("Usage: give array size ");
		exit(0);
	}	

	size = atoi(argv[1]);
	int *arr = (int*)malloc(size * sizeof(int));
    
	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	int start = 0;
	int end = size - 1;
	QuickSort(arr,start,end);		
	
	printf("||||| Sorted array |||||||\n");
	for(i = 0; i < size; i++)
		printf("%d\n",arr[i]);

	int maxa = arr[size-1];
	int maxb = arr[size-2];
	int mina = arr[1];
	int minb = arr[0];
	
	if (mina*minb > maxa*maxb)
		printf("product max = %d\n",mina*minb);
	else
		printf("product max = %d\n",maxa*maxb);
		
	
	return 0;
}
