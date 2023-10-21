#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) (a)>(b)? (a):(b)

int rainWatertrap(int *a, int len)
{
	int start = 0;
	int end = 0;
	int count = 0, i = 0, var = 0;
	int temp = 0;
	int max = 0;
	int low = 0;
	int high = len-1;
	int leftmax = 0, rightmax = 0;
	

//	while (start < len) {
//		if (a[start] <=0) {
//			i++, start++;
//		}
//		if (a[start >= a[i]])
//			i++;
//			continue;
//		else
//			end = i;
//
//		var = start+1;
//		
//		while(var != end) {
//			count += a[start]-a[var];
//			var++;
//		}
//		start = end;
//		i++;
//	}

/*--------------------#################-----------------*/

//	end = start+1;
//	while (start < len) {
//		printf("start = %d and end = %d\n",start,end);
//		if (a[start] != 0) {
//		//	printf("?????????start = %d and end = %d\n",start,end);
//			if (a[start] > a[end]) {
//		//	printf("@@@@@@@@@@2start = %d and end = %d\n",start,end);
//				end++;
//				if (end < len-1)
//					max = MAX(a[end-1],a[end]);
//				continue;
//			}
//			//else
//			//	break;
//		printf("max = %d\n",max);
//		if (end >= len) {
//			end = start+1;
//			printf("aa geya es condition ch vi: end = %d\n",end);
//		}
//		if (end-start>1) {
//			temp = start+1;
//			printf("check value of end= %d and temp = %d\n",end,temp);
//			while (temp < end) {
//				count += a[start] - a[temp];
//		//		printf("start = %d &  temp = %d\n",start,temp);
//				temp++;
//			}
//			printf("count = %d\n",count);
//		}
//		start = end;		
//		//printf("IN LAST:::start = %d and end = %d\n",start,end);
//		if(a[start] < a[start+1] && a[start-1] > a[start] && start < len-1)
//		{
//			printf("If condition patch\n");
//			count += a[start+1] - a[start];
//			start++;
//		}
//		}
//		else {
//			start++;
//		}
//		end = start+1;		
//		printf("When it will exit. END= %d\n",end);
//	
//	}
	//printf("count = %d\n",count);

	while(low <= high) {
		printf("low = %d and high = %d\n",low,high);
		if (a[low] < a[high]) {
			if (a[low] > leftmax)
				leftmax = a[low];
			else
				
			low++;
		} 
		else {
			if (a[high] > rightmax)
				rightmax = a[high];
			else
				count += rightmax - a[high];
			high--;	
		}
	}		
	
	return count;
}

int main()
{
	//int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	//int arr[] = {3,0,0,2,0,4};
	int arr[] = {1,2,3,2,0,3,1,1,0,1,2,1,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	//size = 8;
	int unit = 0;
	
	unit = rainWatertrap(arr,size);
	printf("unit area = %d\n",unit);

	return 0;
}
