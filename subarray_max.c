#include <stdio.h>
#include <stdlib.h>

int * no_of_subarray(int *, int);
int * max_subarray(int *, int);
int main()
{
	int arr[] = {1,2,5,-7,2,3};

	int len = sizeof(arr)/sizeof(arr[0]);	
		
	//no_of_subarray(arr,len);
	max_subarray(arr,len);
	return 0;
}

int * max_subarray(int *a, int len)
{
	int i, j, k = 0, len1 = 0, index = 0;
	int *arr_out = (int *)malloc(sizeof(int)); 

	
	for (i = 0; i < len; i++) {
        k = i;
	//	printf("k = %d\n",k);
		for (j = i; j < len; j++) {
		//	printf("j = %d\n",j);
			if (*(a + j) < 0) {
				i = j;
				break;
			} else {
				len1 = 1, index = 0;
				while (k <= j) {
					arr_out = (int *)realloc(arr_out,len1 * sizeof(int));
					*(arr_out + index) = *(a + k);
				//	printf("%d ",*(a+k));
					printf("%d ",*(arr_out + index));
					
					k++, len1++, index++;
				}
				printf("\n");
			}
		   k = i;
		}
	}

}

int * no_of_subarray(int *a, int len)
{
	int i, j, k = 0;
	
	for (i = 0; i < len; i++) {
			k = i;
		for (j = i; j < len; j++) {
			while (k <= j) {
				printf("%d ",*(a+k));
				k++;
			}
			printf("\n");
			k = i;
		}
	}

}
