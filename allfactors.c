#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int* allFactors(int A, int *len1) {
    int index = 0, i = 0, var = 1, j = 0;
    *len1 = var;
    int *out = (int *)malloc(*len1 * sizeof(int));
	float Sqrt_A = 0;
	Sqrt_A = sqrt(A);
    
	if (A == 1) {
        out[0] = A;
        return out;
      }
    var = 0;
    for (i = 1; i <= Sqrt_A; i++) {
        if (A % i == 0) {
            var += 1;
            *len1 = var;
            out = (int *)realloc(out,*len1 * sizeof(int));
            out[index++] = i;

            if (i != Sqrt_A) {
                var += 1;
                *len1 = var;
                out = (int *)realloc(out,*len1 * sizeof(int));
                out[index++] = A/i;

            }
        }
    }
	//printf("var = %d\n",var);
    int *a = (int *)malloc(sizeof(int) * var);
    index = 0;
    if (var % 2 == 0) {
        for (i = 0; i < var/2; i++) {
            a[i] = out[index];
            index += 2;
        }
        index = 0;
        for (j = i; j < var; j++) {
        //printf("j= %d\n",j);
            a[j] = out[var-index-1];
            index += 2;
        }
    } else {
        for (i = 0; i <= var/2; i++) {
            a[i] = out[index];
            index += 2;
        }
        index = 0;
        for (j = i; j < var; j++) {
            //printf("j= %d\n",j);
            a[j] = out[var-index-2];
            index += 2;
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
	printf("size = %d\n",size);

	b = allFactors(A,&len);
	//int sizeb = sizeof(b)/sizeof(b[0]);
	printf("expected output:\n");
    for (int i = 0; i < size; i++)
        printf("%d ",b[i]);
	printf("\n");

	return 0;
}
