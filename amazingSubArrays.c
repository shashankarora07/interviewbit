/*
You are given a string S, and you have to find all the amazing substrings of S.
Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
Input
Only argument given is string S.
Output
Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints
1 <= length(S) <= 1e6
S can have special characters
Example
Input
    ABEC
Output
    6
Explanation
	Amazing substrings of given string are :
	1. A
	2. AB
	3. ABE
	4. ABEC
	5. E
	6. EC
	here number of substrings are 6 and 6 % 10003 = 6.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int IsVowel(char c)
{
	int value = 1;

	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
				value = 1;
				break;
		default: 
				value = 0;
				break;

	}

	return value;
}

int amazingSubArrayCount(char *s)
{
	int count = 0, i = 0;
	int len = strlen(s);

	for (i = 0; i < len; ++i)
	{
		if (IsVowel(s[i]))
			count += len - i;
	}


	return count;
}


int main()
{
	char *str = "abced";
	int ret = 0;

	ret = amazingSubArrayCount(str);
	printf("ret = %d\n",ret);

	return 0;
}
