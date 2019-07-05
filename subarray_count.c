#include<stdio.h>
#include<stdlib.h>

int subarrayr2ount_numRange(int *a, int size, int r1, int r2)
{
	int count = 0;
    int sum = 0, i, j, k = 0;
    for (i = 0; i < size; i++) {
			k = i;
        for (j = i; j < size; j++) {
			while(k <= j) {
				printf("%d ",a[k]);
            	sum += a[k];
				k++;
				}
				printf("..sum = %d ..",sum);
            	if (sum >= r1 && sum <= r2) {
                	count++;
					sum = 0;
					printf("count = %d\n",count);
            	}
            	if (sum < r1 || sum > r2) {
                	sum = 0;
					printf("sum becomes %d\n",sum);
            	}
			
			k = i;
			printf("\n");
        }
    }
    return count;

}

int main(int argc, int *argv[])
{
	//int arr[] = {10,5,1,0,2};
	int arr[] = {80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90};
	int len = sizeof(arr)/sizeof(arr[0]);

	if (argc != 3) {
		perror("Usage: two args are required\n");
		exit(1);
	}
	
	int r1 = atoi(argv[1]);
	int r2 = atoi(argv[2]);
	int c = 0;
	
	c = subarrayr2ount_numRange(arr,len,r1,r2);
	printf("count = %d\n",c);

	return 0;
}
