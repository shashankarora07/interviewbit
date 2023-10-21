#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool isAlphaNumeric(char c){
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
     return true;
    return false;
}

void checkPalindrome(char *A)
{
    int i=0,len=0;
    while(A[len]!='\0'){
     len++;
    }
    int j=len-1;
    while(i<=j){
       // cout<<A[i]<<" "<<A[j]<<endl;
        if(!isAlphaNumeric(A[i])){
         i++;
         continue;
        }
        if(!isAlphaNumeric(A[j])){
         j--;
         continue;
        }
        if(A[i]!=A[j]&&abs(A[i]-A[j])!=32)
         return 0;
        
        i++;j--;
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
	checkPalindrome(str);
	
	
	return 0;
}
