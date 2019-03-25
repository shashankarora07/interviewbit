#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

int* repeated_missing_element(int *a, int len)
{
	int index = 0;
	int out[2];
	for (int i = 0; i < len; i++) {
		if (a[i] != index + 1) 
			swap(a,&a[i],&a[a[i]-1]);
	
		index++;	
	}
	
	for (int i = 0; i < len; i++)
		printf("%d\t",a[i]);

	for (int i = 0; i < len; i++) {
		if (a[i] == a[i+1])
			printf("repeated element  = %d and missing element = %d\n",a[i], a[i] + 1);
			out[0] = a[i];
			out[1] = a[i] + 1;
			return out;
	}	
	
	//return a;
}


int main()
{
	int arr[] = {3,1,2,5,3};
	int len1 = sizeof(arr)/sizeof(arr[0]);
//	printf("len = %d\n",len1);
	int a[len1];
	a = repeated_missing_element(arr,len1);


	return 0;
}
