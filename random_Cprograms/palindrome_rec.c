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


void checkPalindrome_rec(char *A, int left, int right)
{

 //   int len = 0;
 //   char *cpy_str = A;
 //   while(*cpy_str) {
 //       len++;
 //       cpy_str++;
 //   }
 //   int left = 0;
 //   int right = len -1;


    if (right >= left) {
       if (!isAlphaNumeric(A[left])) {
            left++;
			return checkPalindrome_rec(A,left,right);
        }
       if (!isAlphaNumeric(A[right])) {
            right--;
			return checkPalindrome_rec(A,left,right);
        }
        if ((A[left] != A[right]) && (abs(A[left] - A[right]) != 32)) {
			printf("not equal\n");
            return 0;
        }
		left++;
        right--;

		return checkPalindrome_rec(A,left,right);
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
	
	char *str = "A man, a plan, a canal: Panama";
	//char *str = "1a2";
	//char *str = "\"";
	int len = strlen(str);
	checkPalindrome_rec(str,0,len-1);
	
	
	return 0;
}
