#include<stdio.h>
#include<string.h>

void reverseString(char *s)
{
	int i = 0;
	int len = strlen(s);
	printf("len = %d\n",len);
	char c;

	printf("%c\n",*(s+len));
	for (i = 0; i < len/2; i++) {
		c = *(s + len - i - 1);
		*(s + len - i - 1) = *(s + i);
		*(s + i) = c;
	}
	for (i = 0; i < len; i++)
		printf("%c",*(s+i));
	printf("\n");
}


int main()
{
	char *str = "HelloWorld";
/*
	*(str+3) = 'd';
	char arr[] = "ShashankArora";
	arr[4] = 's';
	printf("str = %s\n",str);
	printf("arr = %s\n",arr);
*/
	
/*	char *s = "see";
	str = &s;
	printf("str = %s\n",str);
	char arr[] = "ShashankArora";
	char a[] = "see";
	arr = &a;
	printf("arr = %s\n",arr);
*/
	reverseString(str);
			
	
	return 0;
}
