#include<stdio.h>
#include<stdlib.h>
/* Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j */


int isDiffkPossible(int *a, int len, int k)
{
	int i = 0, j = 1;
	
	while (j<len) {
		if (i==j)
			j++;
		if (i != j && (abs(a[j]-a[i])==k)) {
			printf("diffk exist\n");
			return 1;
		}
		if (abs(a[j]-a[i]) < k)
			j++;
		else
			i++;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int size, no, i;
	
	if (argc != 3) {
		perror("Usage: give array size and diffk element");
		exit(0);
	}	

	size = atoi(argv[1]);
	int k = atoi(argv[2]);
	int *arr = (int*)malloc(size * sizeof(int));

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);
	
	int ret = isDiffkPossible(arr,size,k);		
	printf("ret = %d\n",ret);
	
	
	return 0;
}
