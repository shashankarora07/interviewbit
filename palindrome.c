#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void checkPalindrome(char *s)
{
	int len = strlen(s);

	int left = 0;
	int right = len -1;

	while(right > left) {
		if (s[left++] != s[right--]) {
			printf("'%s' is not a palindrome\n",s);
			return;
		}
	}
	printf("'%s' is a palindrome\n",s);
}

int main()
{
	char *str = (char *)malloc(sizeof(char) * 50);
	printf("Enter string to check whether it is palindrome or not!\n");
	scanf("%s",str);
	
	checkPalindrome(str);
	
	
	return 0;
}
