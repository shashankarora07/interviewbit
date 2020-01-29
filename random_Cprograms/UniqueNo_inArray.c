#include<stdio.h>
#include<stdlib.h>

/* remove the duplicates in place such that each element appear atmost twice or not more than twice
 and return the new length. */

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for (int i = start; i <= end - 1; i++) {
        if (arr[i] <= pivot){
            swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex],&arr[end]);

    return pIndex;
}

int QuickSort(int *arr, int start, int end)
{
    int pIndex;
    if (start < end) {
        pIndex = partition(arr,start,end);
        QuickSort(arr,start,pIndex-1);
        QuickSort(arr,pIndex+1,end);
    }

}

int UniqueElementsInArray(int *a, int len)
{
	printf("Unique no in array\n");
	int i = 0, count = 0;

	for (i = 0; i < len; i++) {
		
		if ((i < len -2) && (a[i] == a[i+1] || a[i] == a[i+2]) || (i >= 1 && a[i] == a[i-1])) {
			continue;
		}
		else {
			printf("%d\t",a[i]);
		}
	}
	printf("\n");

	return 0;
}

int main(int argc, char *argv[])
{
	int size, no, i, start, end;
	
	if (argc != 2) {
		perror("Usage: give array size");
		exit(0);
	}	

	size = atoi(argv[1]);
	int *arr = (int*)malloc(size * sizeof(int));

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);

    start = 0;
    end = size - 1;
    QuickSort(arr,start,end);

    printf("*** Sorted array ***\n");
    for(int i = 0; i < size; i++)
        printf("%d\n",arr[i]);

	
	UniqueElementsInArray(arr,size);		
	
//	for(i = 0; i < size; i++)
//		printf("%d  ",arr[i]);
//	printf("\n");

	return 0;
}
