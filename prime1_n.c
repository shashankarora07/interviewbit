#include<stdio.h>
#include<stdlib.h>


int checkprime(int no)
{
    int j = 0;
    
    for (j = 2; j< no; j++) {
        if (no % j == 0) {
            return 1;
        }
    }
    return 0;
}
 
int* sieve(int A, int *len1) {
    int i = 0, index = 0;
    *len1 = 1;
	//printf("len1 = %d\n",*len1);
    int *out = (int *)malloc(*len1 * sizeof(int));
	int *out1;
	int var = 0;
   // out[0] = 1;
//	printf("out[0] = %d\n",out[0]);
	
    if (A == 1) {
        return out;
    }
    for (i = 2; i <= A; i++) {
        // check for prime
        
        if (!checkprime(i)) {
            //printf("*len1 = %d\n",*len1);
			var++;
            *len1 = var;
            out = (int *)realloc(out,*len1 * sizeof(int));
            *(out+index) = i;
            index++;
        }    
    }

    //printf("*len1 = %d\n",*len1);
	for (i = 0; i < *len1; i++)
		printf("%d   ",out[i]);
	printf("\n");

	printf("--------------------\n");
	printf("Ans = %d\n",6%2);
    
    return out;
}



int main()
{
	int var = 1;
	sieve(100,&var);

	return 0;
}
