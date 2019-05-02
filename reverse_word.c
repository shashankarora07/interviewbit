#include<stdio.h>
#include<string.h>

void reverseString(char *start, char *end)
{
	int i = 0;
	char temp;
	while (start < end) {
		temp = *start;
		*start++ = *end;
		*end-- = temp; 
	}
}

void reverseWord(char *s)
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
				++word_start;
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


int main()
{
	char str[] = "I am Shashank     Arora";
	//"I ma knahsahS arorA" first reverse word and then reverse whole string
	// OUTPUT: "Arora Shashank am I"
	char *temp = str;
	printf("actual string:%s\n",temp);
	int len = strlen(temp);
	printf("Actual len: %d\n",len);
	reverseWord(temp);
	
	
	return 0;
}
