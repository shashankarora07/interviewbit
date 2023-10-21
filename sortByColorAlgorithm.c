#include<stdio.h>
#include<stdlib.h>

/* Given an array with n objects colored red, white or blue, sort them in such a order red, white and blue.
	0, 1, and 2 to represent the color red, white, and blue respectively.

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2] */


void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int sortByColor(int *a, int len)
{

//	int i = 0;
//	int count0 = 0, count1 = 0, count2 = 0;
//
//	for (i = 0; i < len; i++) {
//		if (a[i] == 0)
//			count0++;
//		else if (a[i] == 1)
//			count1++;
//		else
//			count2++;
//	}
//
//	for (i = 0; i < len; i++) {
//		if (i < count0)
//			a[i] = 0;
//		else if (i < count0+count1)
//			a[i] = 1;
//		else
//			a[i] = 2;
//	}


/* ............  Dutch National Flag Algorithm ...........*/

	int low = 0;
	int mid = 0;
	int high = len-1;

	while(mid <= high) {
		switch(a[mid])
		{
			case 0: swap(&a[low],&a[mid]);
					low++, mid++;
					break;
			case 1: mid++;
					break;
			case 2: swap(&a[mid],&a[high]);
					high--;
					break;
		}
	}

}


int main(int argc, char *argv[])
{
	int size, no, i;
	
	if (argc != 2) {
		perror("Usage: give array size");
		exit(0);
	}	

	size = (int)atoi(argv[1]);
	int *arr = (int *)malloc(size * sizeof(int));

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	sortByColor(arr,size);		
	
	for(i = 0; i < size; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	return 0;
}
