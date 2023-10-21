#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a):(b))


/* remove the duplicates in place such that each element appear atmost twice or not more than twice
 and return the new length. */

int reachEndofArray(int *A, int len)
{
	int jump = 1, i = 0, range = 0;
	int maxrange = A[0];
	int maxJump = A[0];

	for (i = 1; i < len; i++) {
		
		if (i == len - 1 || maxrange > len -1)
			return jump;
	
		range = i + A[i];
		maxrange = max(range,maxrange);
		
		if (range > maxrange) {
			maxrange = range;
		}
		maxJump--;
		printf("maxrange = %d & maxJump = %d\n",maxrange,maxJump);
		if (maxJump <= 0 || maxrange > len-1) {
			jump++;
			maxJump = maxrange;
			printf("maxJump = %d\n",maxJump);			
		}
	
	}
	
//	return jump;
}

int main(int argc, char *argv[])
{
	int size, no, i, jump = 0;
	
	if (argc != 2) {
		perror("Usage: give array size");
		exit(0);
	}	

	size = atoi(argv[1]);
	int *arr = (int*)malloc(size * sizeof(int));

	printf("Enter array \n");
	for(i = 0; i < size; i++)
		scanf("%d",&arr[i]);

    //printf("*** Sorted array ***\n");
    //for(int i = 0; i < size; i++)
    //    printf("%d\n",arr[i]);

	jump = reachEndofArray(arr,size);
	printf("minimum Jump = %d\n",jump);
	
//	for(i = 0; i < size; i++)
//		printf("%d  ",arr[i]);
//	printf("\n");

	return 0;
}
