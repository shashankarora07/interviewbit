#include <stdio.h>
#include <stdlib.h>

int * no_of_subarray(int *, int);
int main()
{
	int arr[] = {1,2,-7,4,2,3};

	int len = sizeof(arr)/sizeof(arr[0]);	
		
	no_of_subarray(arr,len);
	return 0;
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
