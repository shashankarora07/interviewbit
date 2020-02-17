#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void printSubString(char *s, int start, int end)
{
	printf("Max palindromic SubString\n");
	for (int i = start; i < end; i++) 
		printf("%c",*(s+i));
	printf("\n");
}

int longestPalindromeString(char *s, int len)
{
	int i = 0, j = 0, k = 0, start = 0;

	char table[len][len];
	memset(table,0,sizeof(table));

	int maxlength = 1;

	for (i = 0; i < len; i++)
		table[i][i] = 1;

	for (i = 0; i < len-1; i++) {
		if (s[i] == s[i+1]) {
			table[i][i+1] = 1;
			start = i;
			maxlength = 2;
		}
	}

	for (k = 3; k < len; k++) {
		for (i = 0; i < len - k + 1; i++) {
			j = i + k - 1;

			if (table[i+1][j-1] == 1 && s[i] == s[j]) {
				table[i][j] = 1;

				if (k > maxlength) {
					start = i;
					maxlength = k;
				}
			}
		}
	}

	printSubString(s,start,maxlength + start);

	return maxlength;
}

int main(int argc, char *argv[])
{

	if (argc != 2) {
		perror("Usage: give palindromic string");
		exit(0);
	}	

	char *str = argv[1];
	int len = strlen(str);
	
	int no = longestPalindromeString(str,len);
	printf("longestPalindromeString length = %d\n",no);

	return 0;
}
