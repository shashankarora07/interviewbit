#include<stdio.h>
#include<string.h>
#include <stdlib.h>


int morseCode_StringValidate(char *s[], int len)
{
	int i = 0, j = 0, dash = 0, dot = 0, count = 0;

	for (i = 0; i < len; i++) {
		int size = strlen(s[i]);
		dash = 0, dot = 0, j = 0;
		printf("size = %d\n",size);
		while (j < size) {

			/* this while() code is required only in case when questioniare
			specify that no of dots '...' followed immediately with equal 
			no of dash '---' .*/
			/* if requirement matches with above case then commented if case
			would be better to use and break the loop. */
			/* while(s[i][j] == '.' && dot++ && ++j); */ /* this condition is wrong
			 due to post increment of dot variable */ 
			while(s[i][j] == '.' && ++dot && ++j);
			printf("dot = %d and j = %d\n",dot,j);

			//while(s[i][j] == '-' && dash++ && ++j);
			while(s[i][j] == '-' && ++dash && ++j);
			printf("dash = %d and j = %d\n",dash,j);
			
		/*	if (dot != dash) {
				printf("dot = %d and dash = %d\n",dot,dash);
				break;
			}
		*/
			/* if condition is sufficent in case when dots is followed by dash
			and string starts with . and ends with - */
		/*	if (s[i][j] == '.') {
				dot++, j++;
			}
			if (s[i][j] == '-') {
				dash++, j++;
			}
		*/
			//printf("dot = %d and dash = %d\n",dot,dash);

		}
		if ((dash == dot) && s[i][0] == '.' && s[i][size-1] == '-')
			count++;

	}

	return count;
}


int main(int argc, char *argv[])
{
	/*if (argc != 2) {
		perror("Usage: give string");
		exit(0);
	}	

	char *str = argv[1];
	*/

	//char *str[] = {"...--...----",".-.-.-.-"};
	char *str[] = {"...---...----",".-.-.-.-"};
	int len =2;
	
	int ret = -1;
	printf("len = %d\n", len);
	ret = morseCode_StringValidate(str,len);
	printf("total no of messages coded correctly = %d\n",ret);

	return 0;
}
