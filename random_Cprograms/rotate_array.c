#include<stdio.h>

void print(int *a, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d  ",a[i]);
	}
	printf("\n");
}

int rotate_left(int *arr, int size, int lno)
{
	int i = 0;
	int temp = 0;
	for (i = 0; i < lno; i++) {
		rotateLeftbyone(arr,size);
	}
	
	print(arr,size);
}

int rotateLeftbyone(int *a, int len)
{
	int temp = a[0], i = 0;
	for (i = 0; i < len - 1; i++)
		a[i] = a[i+1];
	a[i] = temp;	

}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	rotate_left(arr,len,2);	


	return 0;
}
