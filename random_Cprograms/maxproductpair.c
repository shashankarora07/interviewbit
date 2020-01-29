#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxProductPair(int *a, int len)
{
	int i = 0;
	
	int maxa = INT_MIN;
	int maxb = INT_MIN;
	int mina = INT_MIN;
	int minb = INT_MIN;

	for (i = 0; i < len; i++) {
		
		if (a[i] > maxa) {
			maxb = maxa;
			maxa = a[i];
		}
		else if(a[i] > maxb) {
			maxb = a[i];
		}

		if (a[i] < 0 && abs(a[i]) > abs(mina))	{
			minb = mina;
			mina = a[i];	
		}
		else if (a[i] < 0 && abs(a[i]) > abs(minb)) {
			minb = a[i];
		}

	}
	
	if (mina*minb > maxa*maxb) {
		return mina*minb;
	} else {
		return maxa*maxb;
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
	
	int ret = maxProductPair(arr,size);		
	printf("ret = %d\n",ret);
	
	
	return 0;
}
