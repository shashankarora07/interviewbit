#include<stdio.h>
#include<stdlib.h>

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
    int i = 0;

    for (i = start; i <= end - 1; i++) {
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

void printArray(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
}

void LongestConsecutiveSequence(int *A,int len)
{
    QuickSort(A,0,len-1);
    int count = 0, i = 0, max_count = 0;
    
    for (i = 0; i < len-1; i++) {
        
		if (A[i]+1 == A[i+1])
            count++;
		if (count > max_count)
            max_count = count;
            
        if (A[i]+1 != A[i+1] && (A[i] != A[i+1]))
            count = 0;
		if (A[i] == A[i+1]) {
			count++;
			++i;
		}
    }
    
    printf("max_count = %d\n",max_count+1);	
	
	printArray(A,len);
}

int main()
{
//	int arr[] = {97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81,\
// 				7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11,\
//				 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95,\
//				 94, 56, 28, 55, 66, 92, 79, 27, 42, 70};
	int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

	int size = sizeof(arr)/sizeof(arr[0]);
	LongestConsecutiveSequence(arr,size);

	return 0;
}
