#include <stdio.h>
#include <stdlib.h>

int * no_of_subarray(int *, int);
int max_sum_contiguous_subarray(int *, int );

int main()
{
	int arr[] = {1,2,-7,4,2,3};

	int len = sizeof(arr)/sizeof(arr[0]);	
		
	no_of_subarray(arr,len);
	return 0;
}

int * no_of_subarray(int *a, int len)
{
	int i, j, k = 0, sum = 0;
	int *max_arr = (int *)malloc(sizeof(int)*(len*(len+1)));
	static int count = 0;
	
	for (i = 0; i < len; i++) {
			k = i;
		for (j = i; j < len; j++) {
			while (k <= j) {
				printf("%d ",*(a+k));
				sum += *(a+k);
				k++;
			}
			max_arr[count] = sum;
			count++;
			printf("\n");
			k = i;
			sum = 0;
		}
	}
//	for (i = 0; i < count; i++)
//		printf("%d\n",*(max_arr + i));
	printf("count = %d\n",count);
	max_sum_contiguous_subarray(max_arr, count);
}

int max_sum_contiguous_subarray(int *a, int len)
{
	int max_sum = *(a+0);

	for (int i = 0; i < len; i++) {
		if (*(a+i)>max_sum) {
			max_sum = *(a+i);
		}
	}
	
	printf("max_sum in contiguous subarray = %d\n",max_sum);
	return max_sum;
}
