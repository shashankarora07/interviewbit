#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a > b) ? a:b)

void print2D(int **a, int r, int c)
{
	int i,j;
	for (i = 0; i < r; i ++) {	
		for (j = 0; j < c; j ++)
			printf("%d ",*(*(a + i) + j));
		printf("\n");
	}

}

int** prettyPrint(int A)
{	
	int r = A * 2 - 1;
	int c = A * 2 - 1;
	int **out = (int **)malloc(sizeof(int*) * r);
	int i, j;
	i = j = 0;
	int count = 0;
	
	for (i = 0; i < r; i++) {
		*(out + i) = (int *)malloc(sizeof(int) * c);	
		for (j = 0; j < c; j ++) {
			
			*(*(out + i) + j) = MAX(abs(i-(A-1)),abs(j-(A-1))) + 1;
			
		}
	}

	print2D(out,r,c);

	return out;
}


int main()
{
	int no = 3;
	prettyPrint(no);

	return 0;
}
