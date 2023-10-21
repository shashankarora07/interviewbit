#include<stdio.h>
#include<stdlib.h>


int removeGivenElements(int *a, int len, int b)
{
	int i = 0, j = 0;

	for (i = 0; i < len; i++) {
		
		if (b != a[i]) {
			a[j++] = a[i];
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
	int *arr = (int*)malloc(size * sizeof(int));

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	size = removeGivenElements(arr,size,3);		
	
	for(i = 0; i < size; i++)
		printf("%d  ",arr[i]);
	printf("\n");

	return 0;
}
