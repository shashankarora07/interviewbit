#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


void checkPalindrome(char *s)
{
	int len = strlen(s);

	int left = 0;
	int right = len -1;
	bool comeOut1 = true;
	bool comeOut2 = true;

	while(right > left) {
		while(comeOut1) {
			if ((s[left] >= 65 && s[left] <= 90) || (s[left] >= 97 && s[left] <= 122)) {	
				comeOut1 = false;
			}
			else {
				left++;
			}
		}
		while(comeOut2) {
			if ((s[right] >= 65 && s[right] <= 90) || (s[right] >= 97 && s[right] <= 122)) {	
				comeOut2 = false;
			}
			else {
				right--;
			}
		}
		if ((s[left] == abs(32-s[right]))) {
			left++;
			right--;
		}
		else if (abs(32 - s[left]) == s[right]) {
			left++;
			right--;
		}
		else if (s[left] != s[right]) {
			printf("'%s' is not a palindrome\n",s);
			return;
		} else {
			left++;
			right--;
		}
		comeOut1 = true;
		comeOut2 = true;
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
