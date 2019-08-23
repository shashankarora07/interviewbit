#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) a >= b ? b : a

int maxArea(int *a, int len)
{
	int maxarea = 0, area = 0;
	int i = 0;
	
	for (i = 0; i < len; i++)
	{
		
		
	}	


	return maxarea;
}


int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Usage: size of array is not given");
		exit(1);
	}

	int size = atoi(argv[1]);
	int i = 0, area = 0;
	int arr[size];
	
	for (i = 0; i < size; i++)
		scanf("%d",&arr[size]);

	area = maxArea(arr,size);
	printf("max area = %d\n",area);


	return 0;
}
