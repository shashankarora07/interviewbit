#include<stdio.h>
#include<stdlib.h>

int *fun()
{
	//int arr[] = {1,2,3,4,5};
	int *arr = (int *)malloc(5 * sizeof(int));
	
	for(int i = 0; i < 5; i++)
		arr[i] = i;
	
	return &arr[2];
}

int main()
{
	int *ret;
	ret = fun();
	printf("ret addr = %x\n",ret);

	for (int i = 0; i < 5; i++)
		printf("%d\t",ret[i]);
	printf("\n");

	int arr[] = {1,2};
	
	printf("addr of arr = 0x%x\n",arr);
	printf("addr of &arr = 0x%x\n",&arr);
	printf("addr of arr[0] = 0x%x\n",arr[0]);
	printf("addr of &arr[0] = 0x%x\n",&arr[0]);
	printf("addr of arr[1] = 0x%x\n",arr[1]);
	printf("addr of &arr[1] = 0x%x\n",&arr[1]);

	printf("-----------------------------------\n");
	printf("Below is Array with dynamic allocation:\n\n");

	int *a = (int *)malloc(sizeof(int)*2);
	*(a+0) = 1;
	*(a+1) = 2;	
			   	 								
	printf("addr of a = 0x%x\n",a);
	printf("addr of &a = 0x%x\n",&a);
	printf("addr of *(a+0) = 0x%x\n",*(a+0));
	printf("addr of (a+0) = 0x%x\n",(a+0));
	printf("addr of *(a+1) = 0x%x\n",*(a+1));
	printf("addr of (a+1) = 0x%x\n",(a+1));

	//declaring
	printf("#################################\n\n");
	printf("Now things will go to the new level\n\n");
	
	int array[] = {1,2,3,4,5,6};
	int *ptr = array;

	printf("Declared array and pointer ptr which is pointing to the array\n");
	printf("addr of array = 0x%x\n",array);
	printf("addr of &array = 0x%x\n",&array);
	printf("value stored at addr '0x%x' of &array[0]= 0x%x\n",&array[0],array[0]);
	printf("addr of array stored in pointer ptr = 0x%x\n",ptr);
	printf("addr of pointer ptr= 0x%x\n",&ptr);
	printf("addr of &array+1 = 0x%x\n",&array+1);
	printf("addr of (&array)+1 = 0x%x\n",(&array)+1);
	printf("addr of &array+2 = 0x%x\n",&array+2);
	printf("addr of &array+3 = 0x%x\n",&array+3);
	printf("addr of pointer (ptr+1) = 0x%x\n",(ptr+1));
	printf("addr of pointer (ptr+2) = 0x%x\n",(ptr+2));
	printf("addr of pointer &ptr+1 = 0x%x\n",&ptr+1);
	printf("addr of pointer &ptr+2 = 0x%x\n",&ptr+2);
	printf("addr of pointer &ptr+3 = 0x%x\n",&ptr+3);
	printf("addr of pointer *(&ptr+3) = 0x%x\n",*(&ptr+3));



											
			   	 																	
			   	 																	
			   	 																
																				
								
	return 0;
}
