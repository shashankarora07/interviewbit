#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool isAlphaNumeric(char c) {
	if ((c >= '0' && c <= '9') || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return true;
	}
	return false;
}

int checkPalindrome(char *A)
{

    int len = 0;
    char *cpy_str = A;
    while(*cpy_str) {
        len++;
        cpy_str++;
    }
    int left = 0;
    int right = len -1;

    while(right >= left) {
       if (!isAlphaNumeric(A[left])) {
            left++;
			continue;
        }
       if (!isAlphaNumeric(A[right])) {
            right--;
			continue;
        }
        if ((A[left] != A[right]) && (abs(A[left] - A[right]) != 32)) {
			printf("not equal\n");
            return 0;
        }
		left++;
        right--;
        }
    

	printf("'%s' is a palindrome\n",A);
}

int main()
{
	/*
	char *str = (char *)malloc(sizeof(char) * 50);
	printf("Enter string to check whether it is palindrome or not!\n");
	scanf("%s",str);
	*/
	
	char *str = "  A man,   a plan, a canal: Panam a  \"";
	//char *str = "1a2";
	//char *str = "\"";
	checkPalindrome(str);
	
	
	return 0;
}
