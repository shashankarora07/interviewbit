#include<stdio.h>
#define type(x) (char*)(&x+1) - (char*)(&x)

int main()
{
	int c = 10;
	int arr[] = {1,2,3,4,5};
	//int *p = &arr;
	//printf("%x\n",p);
//	int size = (char*)(&arr+1) - (char*)(arr);
	int size = (int*)(&arr+1) - (int*)(arr);
//	int size = (&c+1);
	printf("c = %d\n",type(c));
	printf("size = %d\n",size);
//	printf("%d\n",arr[size-1]);
	
		
	printf("%x\n",arr[0]);
	printf("%x\n",&arr[0]);
	printf("%x\n",arr[1]);
	printf("%x\n",&arr[1]);

	return 0;
}
