#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifdef DEBUG
#define DEBUG
#endif

//#define DEBUG

int countallfactors(int A)
{
	int count = 0, i = 0;

    for (i = 1; i <= sqrt(A); i++) {
        if (A % i == 0) {
				count++;
            if (i != sqrt(A)) {
				count++;
            }
        }
    }


	return count;
}

int* allFactors_Optimised_V1(int A, int *len1) {
    int index = 0, i = 0, count = 0, j = 0, k = 0;
	float Sqrt_A = 0;
	Sqrt_A = sqrt(A);
	int *a = NULL;
    
	if (A == 1) {
		*len1 = 1;
		a = (int *)malloc(*len1 * sizeof(int));
        a[0] = A;
        return a;
      }

    for (i = 1; i <= Sqrt_A; i++) {
        if (A % i == 0) {
            if (A/i == i)
				count++;
			else
				count += 2;
        }
    }

	#ifdef DEBUG
	printf("count = %d\n",count);
	#endif

	*len1 = count;
	k = count - 1;
	
    a = (int *)malloc(*len1 * sizeof(int));

	for (i = 1; i <= Sqrt_A; i++) {
		if (A % i == 0) {
			if (A/i == i) {
				a[j++] = i;
			} else {
				a[j++] = i;
				a[k--] = A/i;
			}
		}
	}

    return a;

}


int main()
{
	int a[] = {1,2,3,4,6,8,9,12,16,18,24,27,32,36,48,54,64,72,81,96,108,128,144,162,192,216,256,288,324,384,432,512,576,648,768,864,1024,1152,1296,1536,1728,2304,2592,3072,3456,4608,5184,6912,9216,10368,13824,20736,27648,41472,82944};
	int A = 38808;
	//int A = 36;
	int len = 1;
	int *b;
	int size = countallfactors(A);
	#ifdef DEBUG
	printf("size = %d\n",size);
	#endif

	b = allFactors_Optimised_V1(A,&len);
	printf("expected output:\n");
    for (int i = 0; i < size; i++)
        printf("%d ",b[i]);
	printf("\n");

	return 0;
}
