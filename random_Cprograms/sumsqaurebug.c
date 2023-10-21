#include<stdio.h>
#include<stdlib.h>

void print2D(int **a, int r, int c)
{
    int i,j;
    for (i = 0; i < r; i ++) {
        for (j = 0; j < c; j ++)
            printf("%d ",*(*(a + i) + j));
        printf("\n");
    }
}


int ** squareSum(int A, int *len1, int *len2) {
    *len2 = 2;
    *len1 = 0;
    int a, b;
    
    for (a = 0; a * a < A; a++) {
        for (b = 0; b * b < A; b++) {
            if (a * a + b * b == A) {
                *len1 = *len1 + 1;    
            }
        }
    }
    printf("a = %d and b = %d\n",a,b);
    int **ans = (int **)malloc(*len1 * sizeof(int *));
    int index = 0;
    
    for (a = 0; a * a < A; a++) {
        for (b = 0; b * b < A; b++) {
            if (a * a + b * b == A) {
                ans[index] = (int *)malloc(2 * sizeof(int));
                ans[index][0] = a;
                ans[index][1] = b;
                index++;
            }
        }
    }
//	print2D(ans,*len1,*len2);

    return ans;
}

int main()
{
	int **ret;
	ret = squareSum(5,0,2);
	
}
