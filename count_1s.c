#include<stdio.h>

int main()
{
	int no = 2147483647, count = 0;

	while(no!=0) {
		if(no & 1)
			count++;
		no = no >> 1;
	}
	printf("count = %d\n",count);


	return 0;
}

