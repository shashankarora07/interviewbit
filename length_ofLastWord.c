#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int lengthOfWord(char *start, char *end)
{
	int count = 0;
	while (start <= end) {
		start++;
		count++;
	}
	printf("count = %d\n", count);
	return count;
}

int LengthOfLastWord(char *s, int len)
{
	char *word_start = NULL;
	char *word_end = s;
	int cnt = 0;

	while((*word_end == ' ') && (*(word_end+1) != '\0') && word_end++);

	printf("word_end :%s\n",word_end);
	while(*word_end != '\0') {
		if (word_start == NULL && (*word_end != ' ')) {
			word_start = word_end;
			printf("word_start :%s\n",word_start);
			//word_end++;
		}
		/*if (word_start && ((*(word_end+1) == ' ') || (*(word_end+1) == '\0'))) {
			//if (*(word_end+1) == '\0')
				cnt = lengthOfWord(word_start,word_end);
			word_start = NULL;
		}*/
		if (word_start == NULL && ((*(word_end+1) == ' ') || (*(word_end+1) == '\0'))) {
			word_end++;
			continue;
		}
		if (word_start) {
			if (*(word_end+1) == ' ') {
				cnt = lengthOfWord(word_start,word_end);
			word_start = NULL;
			}
			else if (*(word_end+1) == '\0')
				cnt = lengthOfWord(word_start,word_end);
		}

		word_end++;
	}

	return cnt;
}


int main(int argc, char *argv[])
{
	/*if (argc != 2) {
		perror("Usage: give string");
		exit(0);
	}	

	char *str = argv[1];
	*/
	//char *str = "myname is shashankname arora namename  ";
	//char *str = "   xDGBklKecz IAcOJYOH O  WY WPi     ";
	//char *str = "d";
	char *str = "";
	int len = strlen(str);
	
	int ret = -1;
	printf("len = %d\n", len);
	ret = LengthOfLastWord(str,len);
	printf("LengthOfLastWord = %d\n",ret);

	return 0;
}
