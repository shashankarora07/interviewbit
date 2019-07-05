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

void checkPalindrome(char *A)
{

    int len = 0;
    char *cpy_str = A;
    while(*cpy_str) {
        len++;
        cpy_str++;
    }
    int left = 0;
    int right = len -1;
    short comeOut1 = 1;
    short comeOut2 = 1;

    while(right >= left) {
        while(comeOut1) {
            if (isAlphaNumeric(A[left])) {
                comeOut1 = 0;
            }
            else {
                left++;
            }
        }
        while(comeOut2) {
            if (isAlphaNumeric(A[right])) {
                comeOut2 = 0;
            }
            else {
                right--;
            }
        }
        if ((A[left] == abs(32-A[right]))) {
            //left++;
            //right--;
        }
        if (abs(32 - A[left]) == A[right]) {
          // left++;
           // right--;
        }
        if (A[left] != A[right]) {
			printf("not equal\n");
            return 0;
        } else {
            left++;
            right--;
        }
        comeOut1 = 1;
        comeOut2 = 1;
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
	
	char *str = "A man, a plan, a canal: Panama\"";
	//char *str = "1a2";
	//char *str = "\"";
	checkPalindrome(str);
	
	
	return 0;
}
