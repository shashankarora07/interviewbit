#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void nextGreaterElement(int *a,int len)
{
	int i = 0, j = 0, nextgrt = 0;

	for (i = 0; i < len; i++) {
			nextgrt = -1;
		for (j = i+1; j < len; j++) {
			if (a[i] < a[j]) {
				nextgrt = a[j];
				break;
			}
		}
		printf("%d -> %d\n",a[i],nextgrt);
	}

}

int main(int argc, char *argv[])
{
	int size, no, i;
	
	if (argc != 2) {
		perror("Usage: give array size ");
		exit(0);
	}	
	
	size = atoi(argv[1]);
	int *arr = (int*)malloc(size * sizeof(int));
    
	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	nextGreaterElement(arr,size);		
	
	
	return 0;
}
