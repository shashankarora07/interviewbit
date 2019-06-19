#include<stdio.h>

int duplicateArray(int *A, int n)
{
	int slow = A[0];
	int fast = A[A[0]];

	while (slow != fast) {
		slow = A[slow];
		fast = A[A[fast]];
		printf("slow = %d and fast = %d\n",slow,fast);
	}

	fast = 0;
	while(slow != fast) {
		slow = A[slow];
		fast = A[fast];
	}

	if (slow == 0)
		return -1;

	return slow;
}


int main()
{
	
	int arr[] = {1,6,2,7,3,4,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	int repeatnum = 0;
	
	//printf("arr[2] = %d\n",arr[2]++);
	//printf("arr[3] = %d\n",arr[2]);
	repeatnum = duplicateArray(arr,len);
	printf("repeatnum = %d\n",repeatnum);


	return 0;
}
