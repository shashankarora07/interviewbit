#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

typedef struct points {
	int x;
	int y;
}Points;


int coverPoints(Points *a, int len) 
{
	int count = 0, i = 0;

	for (i = 0; i < len-1; i++) {
		count += MAX(abs(a[i].x - a[i+1].x),abs(a[i].y - a[i+1].y));
	}

	return count;
}

int main(int argc, char const *argv[])
{
	Points arr[] = {{4,6},{1,2}, {4,5}, {10,12}};
	int len = sizeof(arr)/sizeof(arr[0]);

	int Stepcounts = coverPoints(arr,len);
	printf("Stepcounts = %d\n",Stepcounts);

	return 0;
}