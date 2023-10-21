#include<stdio.h>
#include<string.h>

void reverseString(char *a)
{
	int i = 0;
	int len = strlen(a);
	printf("len = %d\n",len);
	char c;

	for (i = 0; i < len/2; i++) {
		c = *(a + len - i - 1);
		*(a + len - i - 1) = *(a + i);
		*(a + i) = c;
	}
	printf("%s\n",a);

}


int main()
{
	char str[] = "Sh  ";
	char *temp = str;

	reverseString(temp);
	
	
	return 0;
}
