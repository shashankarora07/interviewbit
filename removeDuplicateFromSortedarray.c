#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int *a, int len)
{
	int i = 0, j = 0;

	for (i = 1; i < len; i++) {
		
		if (a[j] != a[i]) {
			a[j+1] = a[i];
			j++;
		}
	}	
	len = j+1;

	return len;
}

int main(int argc, char *argv[])
{
	int size, no, i;
	
	if (argc != 2) {
		perror("Usage: give array size");
		exit(0);
	}	

	size = atoi(argv[1]);
	int arr[size];

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	size = removeDuplicates(arr,size);		
	
	for(i = 0; i < size; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	return 0;
}
