#include<stdio.h>
#include<stdlib.h>

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


int main()
{
	int no = 6;
	char *ret;

	ret = digitsInBinary(no);
	printf("addr ret = 0x%x\n",ret);
	printf("binary representation:\n");
	printf("%s\n",ret);
	
	return 0;
}

