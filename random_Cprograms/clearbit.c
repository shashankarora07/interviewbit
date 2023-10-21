#include<stdio.h>
#include<stdlib.h>

#define mask(n,p) ~(~0<<n)<<p

char* digitsInBinary(int A)
{   
    int k = 31; 
    char* res = (char*)malloc(sizeof(char)* 33);
   
    res[32] = '\0';
   
    if (!A)
        return "0";
   
    while(A){ 
        if (A % 2 == 1)
            res[k--] = '1';
        else
            res[k--] = '0';
   
        A /= 2;
    }
   
    return &res[k+1];
}

void binaryPrint(int no, int tbits)
{
    int i;

    for(i = 0; i < tbits; i++) {
        if (i%8 == 0 && i != 0)
            printf(" ");
        if (no & (1 << ((tbits-1) - i)))
            printf("1");
        else
            printf("0");
    }
    printf("\n");

}


int swapBitsInPair(int A, int p1, int p2, int n)
{
	int p1bits = 0,p2bits = 0;
	
	p1bits = A & mask(n,p1);
	p2bits = A & mask(n,p2);
	//printf("p1bits %s\n",digitsInBinary(p2bits));
	//binaryPrint(p1bits,8);
	//binaryPrint(p2bits,8);

	int res = (p1bits >> p1) ^ (p2bits >> p2);
	//binaryPrint(res,8);
	
	res = (res << p2) | (res << p1);	
	A = A ^ res;	

	binaryPrint(A,8);
}

void Clearbit()
{
	int x1 = 0,x2 = 0;
	int *p = (int*)0x10000000;
	printf("enter p1 and p2 position to clear the bits\n");
	scanf("%d %d",&x1,&x2);
	printf("enter num\n");
	scanf("%d",p);
	printf("no = %d\n",*p);
	int num = *p;
	binaryPrint(num,8);
	int n = abs(x1-x2)+1;
	
	int mask = ~(~0<<n)<<abs(x2-x1-1);

	num &= ~mask;

	binaryPrint(num,8);
	
	
}

int main()
{
	int no = 47;
//	printf("%s\n",digitsInBinary(no));
	
	//swapBitsInPair(no,1,5,3);
	Clearbit(no);
	
	return 0;
}
