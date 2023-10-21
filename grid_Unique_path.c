/*
A robot is located at the top-left corner of an A x B grid.
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
How many possible unique paths are there?
Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.
Example :
Input : A = 2, B = 2
Output : 2
2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
https://www.interviewbit.com/problems/grid-unique-paths/
*/

/*int fact(int x)
{
    return x<2 ? x : x*fact(x-1);
}*/
#include<stdio.h>
#include <stdlib.h>

int GridUniquePaths(int A, int B)
{
	// Grid
	int T[A][B];
	int i = 0, j = 0; // row, column

	for (i = 0; i < A; ++i) {
		for (j = 0; j < B; ++j) {
			
			if (0 == i && 0 == j)
				T[i][j] = 1;
			else if (0 == i)
				T[i][j] = T[i][j-1];
			else if (0 == j)
				T[i][j] = T[i-1][j];
			else
				T[i][j] = T[i-1][j] + T[i][j-1];
		}
	}

	return T[A-1][B-1];
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		perror("Usage: pass row and column for grid");
		exit(1);
	}

	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	int totalways = GridUniquePaths(row,col);
	printf("no of unique ways to reach bottom-right = %d\n",totalways);

	return 0;
}
