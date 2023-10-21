#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *a, int len, int x)
{
	int start = 0;
	int end = len - 1;	
	int mid = 0;

	while(start <= end) {
		mid = (start + end)/ 2;
		if (a[mid] == x) {
			return a[mid];
		}
		else if (a[mid] < x) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		
	}

	return -1;
}

int binarySearchRecursion(int *a, int start, int end, int x)
{
	int mid = 0;
	while(start<=end) {
		int mid = (start+end)/2;	
		if (a[mid] == x) {
			return a[mid];
		}
		else if (a[mid] < x) {
			return binarySearchRecursion(a,mid+1,end,x);
		}
		else {
			return binarySearchRecursion(a,start,mid-1,x);
		}
	}
	return -1;
}

int main()
{
	int arr[] = {2,5,7,9,10,13,15,16,19,20};
	int len = sizeof(arr)/sizeof(arr[0]);
	int no = 0;
	int ret = 0;
	printf("Enter no to check it is present in array or not\n");
	scanf("%d",&no);
	//ret = binarySearch(arr,len,no);
	ret = binarySearchRecursion(arr,0,len-1,no);
	printf("ret = %d\n",ret);
	no = (no == ret) ? printf("given no %d is present in array\n",ret) : printf("given no %d is not present\n",no);
	
	
	return 0;
}
