#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void checkPalindrome(char *s)
{
	int len = strlen(s);

	int left = 0;
	int right = len -1;

	while(right > left) {
		if ((s[left] >= 65 && s[left] <= 90) || (s[left] >= 97 && s[left] <= 122)) {	
		}
		else {
			left++;
		}
		if ((s[right] >= 65 && s[right] <= 90) || (s[right] >= 97 && s[right] <= 122)) {	
		}
		else {
			right++;
		}
		if (s[left] != s[right]) {
			printf("'%s' is not a palindrome\n",s);
			return;
		}
		left++;
		right++;
	}
	printf("'%s' is a palindrome\n",s);
}

int main()
{
	/*
	char *str = (char *)malloc(sizeof(char) * 50);
	printf("Enter string to check whether it is palindrome or not!\n");
	scanf("%s",str);
	*/
	
	char *str = "A man, a plan, a canal: Panama";
	checkPalindrome(str);
	
	
	return 0;
}
