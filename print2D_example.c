#include<stdio.h>
#include<stdlib.h>


int **allocate2D(int A)
{	
	int r = A * 2 - 1;
	int c = A * 2 - 1;
	int **out = (int **)malloc(sizeof(int*) * r);
	int i, j;
	i = j = 0;
	int count = 0;
	
	for (i = 0; i < r; i ++) {
		*(out + i) = (int *)malloc(sizeof(int) * c);	
		for (j = 0; j < c; j ++) {
			*(*(out + i) + j) = ++count;	
		}
	}
	print2D(out,r,c);
	
	return out[0][0];

}

void print2D(int **a, int r, int c)
{
	int i,j;
	for (i = 0; i < r; i ++) {	
		for (j = 0; j < c; j ++)
			printf("%d ",*(*(a + i) + j));
		printf("\n");
	}
}

int main()
{
	int no = 3;
	int **a;
	a = allocate2D(no);
	//print2D(a);
	
	printf("#############################\n");
	printf("#############################\n");
	printf("2D array by passing as argument and return address to main\n");
	int **arr;

	return 0;
}
