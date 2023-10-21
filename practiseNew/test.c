#include <stdio.h> 
#include <stdlib.h> 

struct node {
	int i;
	struct node *next;
};

int main(void) 
{ 
//	int i; 
//	int *ptr = (int *) malloc(5 * sizeof(int)); 
//
//	for (i=0; i<5; i++) 
//		*(ptr + i) = i; 
//
//	printf("%d \n", *ptr++); 
//	printf("%d \n", (*ptr)++); 
//	printf("%d \n", *ptr); 
//	printf("%d \n", *++ptr); 
//	printf("%d \n", ++*ptr); 

	int arr[] = {1,2,3};
	int *ptr = &arr[2];
	//printf("%d\n",arr[0]);
	//printf("%d\n",arr[1]);
	//printf("%d\n",arr[2]);
	printf("%d\n",ptr[-1]);
	printf("%d\n",ptr[-2]);
	printf("%d\n",ptr[-3]);

	printf("%d\n",sizeof(struct node));
} 

