#include<stdio.h>
#include<stdlib.h>
#include<stack.h>

int rainWatertrap(int *a, int len)
{
	Stack *S = NULL;

	

}

int main()
{
	//int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int arr[] = {3,0,0,2,0,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int unit = 0;

	unit = rainWatertrap(arr,size);
	printf("unit area = %d\n",unit);

	return 0;
}
