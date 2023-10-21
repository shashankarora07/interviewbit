#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addOneToNumber(int *A, int len)
{
	int end = len-1;
	int carry = 0, i = 0, flag = 0, j = 0;
	printf("len = %d\n",len);

	while (j < len && A[j] == 0)
		j++;

	if (j == len) {
	    A[j-1] = 1;
	    printf("start and j = %d and A[%d] = %d\n",j-1,j-1,A[j-1]);
	    return;
	}

	//if (A[j] == 9 && j == end) {
	//	int *out_new = (int *)malloc(sizeof(int)*2);
	//	out_new[1] = 0;
	//	out_new[0] = 1;
	//	printf("%d and %d\n",out_new[0],out_new[1] );
	//	return;
	//}

	//int *out = (int *)malloc(sizeof(int)*(len-j));
	int *out_new = (int *)malloc(sizeof(int)*(len-j));

	for (i = end; i >= j; i--) {

/*		if (A[i] < 9 && !carry && i == end) {
			out[i-j] = A[i] + 1;
			flag  = 1;
			printf("coming and i = %d and out[%d] = %d\n",i,i-j,out[i-j]);
		}
		else if (A[i] == 9 && !flag && (carry || i-j != 0) && ) {
			out[i-j] = 0;
			carry = 1;
			printf("carry : %d and i = %d and out[%d] = %d\n",carry,i,i-j,out[i-j]);
		}
		else if (A[i] < 9 && carry) {
			out[i-j] = A[i] + carry;
			carry = 0;
			printf("carry : %d and i = %d and out[%d] = %d\n",carry,i,i-j,out[i-j]);
		}
		else {
			out[i-j] = A[i];
			printf("flag : %d and i = %d and out[%d] = %d\n",flag,i,i-j,out[i-j]);
		}
*/
		if (A[i] < 9 && i == end) {
			out_new[i-j] = A[i] + 1;
			printf("i = %d and out_new[%d] = %d\n",i,i-j,out_new[i-j]);
			break;
		}

		if (A[i] == 9) {
			carry = 1;
			out_new[i-j] = 0;
			printf("carry : %d and i = %d and out_new[%d] = %d\n",carry,i,i-j,out_new[i-j]);
		}
		else {
			out_new[i-j] = A[i] + carry;
			carry = 0;
			printf("carry : %d and i = %d and out_new[%d] = %d\n",carry,i,i-j,out_new[i-j]);
			break;
		}
	}

	/*if (carry) {
		int *out_new = (int *)malloc(sizeof(int)*(len-j+1));
		//out = realloc(out,len-j+1);
		out_new[0] = carry;
		for (i = 0; i < len-j; i++)
			out_new[i+1] = out[i];
		printf("carry : %d and realloc i = %d and out = %d\n",carry,0,out_new[0]);
		for (i = 0; i < len-j+1; i++)
			printf("%d ",out_new[i]);
		free(out);
	}*/
	if (!carry) {
		for (int k = i-1; k >=j; k--) {
			out_new[k-j] = A[k];
			printf("carry : %d and k = %d and out_new[%d] = %d\n",carry,k,k-j,out_new[k-j]);
		}
	}
	if (carry) {
		int *out = (int *)malloc(sizeof(int)*(len-j+1));
		out[0] = carry;
		for (int k = 0; k < len-j; k++) {
			out[k+1] = out_new[k];
			printf("carry : %d and k = %d and out[%d] = %d\n",carry,k+1,k-j+1,out_new[k]);
		}
		for (i = 0; i < len-j+1; i++)
			printf("%d ",out[i]);
		
		printf("\n");
		free(out_new);
	}


/*	if (!carry) {
		for (i = 0; i < len-j; i++)
			printf("%d ",out_new[i]);	
	}
*/
	

}

int main()
{
	//int arr[] = {0,0,0,9,9,9,1};
	//int arr[] = {0,0,0,9,8,8};
	//int arr[] = {9};
	int arr[] = {9,9,9,9,9};
	//int arr[] = {9, 8, 6, 0, 3, 3, 7, 4, 3, 7, 9};
	//int arr[] = {9,0,9};
	//int arr[] = {8, 9, 6, 6, 2, 4, 6, 7, 8, 1, 2, 9};
	int size = sizeof(arr)/sizeof(arr[0]);

	addOneToNumber(arr,size);


	return 0;
}