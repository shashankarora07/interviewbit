#include<stdio.h>
#include<string.h>

char* reverseString(char *a)
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
	
	return a;
}

void reverseWord(char *s)
{
	
	
	char *start = s;
	char *temp = s;
	printf("%s\n",end);

	



}


int main()
{
	char str[] = "I am Shashank Arora";
	//"I ma knahsahS arorA" first reverse word and then reverse whole string
	// OUTPUT: "Arora Shashank am I"
	char *temp = str;

	reverseWord(temp);
	
	
	return 0;
}
