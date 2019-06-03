#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void reverseString(char *start, char *end)
{
	int i = 0;
	char temp;
	printf("start = %c and end = %c\n",*start,*end);
	while (start < end) {
		temp = *start;
		*start++ = *end;
		*end-- = temp; 
	}
}

/*void reverseWord(char *s)
{
		
	char *word_start = s;
	char *temp = s;
	while(*temp) {
		temp++;
		//printf("temp = %c and word_start = %c\n",*temp,*word_start);
		if (*temp == '\0') {
			reverseString(word_start, temp - 1);
		}
		else if (*temp == ' ') {
			printf("temp = %c and word_start = %c\n",*temp,*word_start);
			if (*word_start == *temp) {
				//word_start = temp + 1;
				printf("if same then temp = %c and word_start = %c\n",*temp,*word_start);
			}
			else {
			printf("INSIDE Else :: temp = %c and word_start = %c\n",*temp,*word_start);
			reverseString(word_start, temp - 1);
			word_start = temp+1;
			}
		}
	}
	
	printf("%s\n",s);
	int len = strlen(s);
	printf("len after reverse: %d\n",len);

	reverseString(s, temp - 1);
	printf("%s\n",s);

}
*/

void removeExtraSpaces(char *s)
{
	int len = strlen(s);
	int i = 0, j = -1;
	bool extraSpace = false;

	while(++j < len && s[j] == ' ');

	while(j < len) {
		if (s[j] != ' ' ) {
			s[i++] = s[j++];
			extraSpace = false;
		}
		else if (s[j++] == ' ' ) {
			if (!extraSpace) {
				s[i++] = ' ';
				//s[i++] = ' ';
				extraSpace = true;
			}
		}
	}
	printf("i = %d\n",i);
	if (s[i-1] == ' ') {
		printf("In if part\n");
		s[i-1] = '\0';
	}
	else {
		s[i] = '\0';
		printf("In else part\n");
	}
		
}

void reverseWord(char *s)
{
		
	char *word_start = NULL;
	char *temp = s;
	char *cpy_str = s;
	int len = 0;
	while(*cpy_str) {
		len++;
		cpy_str++;
	}
	printf("len = %d\n",len);
	//int len = strlen(s);
	int j = 0,i;

	while(*temp) {
		if (word_start == NULL && (*temp != ' ')) {
			word_start = temp;
			printf("###%s\n",word_start);
		}
		if (word_start && ((*(temp + 1) == ' ') || *(temp+1) == '\0')) {
			printf("temp =%s\n",temp);
			printf("word_start =%s\n",word_start);
			reverseString(word_start, temp);
			word_start = NULL;
		}
		temp++;
		}
	
	printf("string After reverse:%s\n",s);
	len = strlen(s);
	printf("len after reverse: %d\n",len);

	reverseString(s,temp-1);
	removeExtraSpaces(s);
	printf("After remove extra space:%s\n",temp);
	len = strlen(s);
	printf("len after removing spaces: %d\n",len);
	printf("%s\n",s);

}


int main()
{
	char str[] = "   I am Shashank     Arora   ";
	//"I ma knahsahS arorA" first reverse word and then reverse whole string
	// OUTPUT: "Arora Shashank am I"
	char *temp = str;
	printf("actual string:%s\n",temp);
	int len = strlen(temp);
	printf("Actual len: %d\n",len);
//	removeExtraSpaces(temp);
//	printf("After remove extra space:%s\n",temp);
//	len = strlen(temp);
//	printf("len after removing spaces: %d\n",len);
	reverseWord(temp);
	
	
	return 0;
}
