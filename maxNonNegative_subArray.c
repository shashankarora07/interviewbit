#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* MaxNonNegative_subArray(int *a, int len)
{
	int max_sum, curr_sum, j, i, sIndex, eIndex, start, end, lensubArr;
	max_sum = curr_sum = i = j = sIndex	= eIndex = start = end = 0;
	lensubArr = 0;
	int *max_range;

	for (i = 0; i < len; i++) {
			if (a[i] >= 0) {
				start = i;
				curr_sum = 0;
				while(a[i] >= 0 && i < len) {
					curr_sum += a[i];
					i++;
				}
			//	curr_range = (int *)realloc(curr_range,sizeof(int) * (j+1));
			//	curr_range[j] = a[i];
			//	j++;
				end = i;
				printf("end = %d and start = %d\n",end,start);
				if ((max_sum < curr_sum) || (max_sum == curr_sum && end - start > lensubArr)) {
					sIndex = start;
					eIndex = end;
					lensubArr = end - start;
					max_sum = curr_sum;
					//max_range = curr_range;
				}
			}
	}
	len = eIndex - sIndex;
	printf("len = %d\n",len);
	max_range = (int *)malloc(sizeof(int) * len);
	for (i = sIndex; i < eIndex; i++) {
		max_range[j] = a[i];
		j++;
	}
	
/*
	for(int i = 0; i < 4; i++)
		printf("%d ",max_range[i]);
	printf("\n");
*/
	return max_range;
	
}

int main()
{
	//int arr[] = {1,2,5,-7,2,5};
	int arr[] = {0,0,-1,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	int *out;

	out = MaxNonNegative_subArray(arr,len);
	int lout = sizeof(out);
	printf("lout = %d\n",lout);
	for(int i = 0; i < 4; i++)
		printf("%d ",out[i]);
	printf("\n");

	return 0;
}
