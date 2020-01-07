#include<stdio.h>
#include<stdlib.h>

int rainWatertrap(int *a, int len)
{
	int start = 0;
	int end = 0;
	int count = 0, i = 0, var = 0;
	int temp = 0;
	

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

	end = start+1;
	while (start < len) {
		//printf("start = %d and end = %d\n",start,end);
		if (a[start] != 0) {
		//	printf("?????????start = %d and end = %d\n",start,end);
			if (a[start] > a[end]) {
		//	printf("@@@@@@@@@@2start = %d and end = %d\n",start,end);
				end++;
				continue;
			}
			//else
			//	break;
		if (end >= len)
			end = start+1;
		if (end < len) {
			temp = start+1;
			while (temp < end) {
				count += a[start] - a[temp];
		//		printf("start = %d &  temp = %d\n",start,temp);
				temp++;
			}
		//	printf("count = %d\n",count);
		}
		start = end;		
		//printf("IN LAST:::start = %d and end = %d\n",start,end);
		}
		else {
			start++;
		}
		end = start+1;		
	
	}
	//printf("count = %d\n",count);
	
	return count;
}

int main()
{
	//int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int arr[] = {3,0,0,2,0,4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int unit = 0;

	unit = rainWatertrap(arr,size);
	printf("unit area = %d\n",unit);

	return 0;
}
