/*
Given two binary strings, return their sum (also a binary string).
Example:
a = "100"
b = "11"
Return a + b = “111”.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *s, int start, int end)
{
	char temp;
	while (start < end) {
		temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

void addBinaryString(char *s1, char *s2)
{
	int count = 0, i = 0, carry = 0, no = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char c[2];

	int len = (len1 > len2) ? len1 : len2;
	char *result = (char *)malloc(sizeof(char) * (len + 2));

	reverse(s1,0,len1-1);
	//printf("revese s1 = %s\n",s1);
	reverse(s2,0,len2-1);
	//printf("revese s2 = %s\n",s2);

	for (i = 0; i < len; i++)
	{
		int a = (i < len1) ? s1[i]-'0':0;
		int b = (i < len2) ? s2[i]-'0':0;
		count++;
		int temp = a + b + carry;
		carry = temp / 2;
		no = temp % 2;
		//itoa(temp%2,c,10);
		//printf("no %d\n",no );
		snprintf(c,sizeof(c),"%d",no);
		//printf("c = %s\n",c);
		strcat(result,c);
		//printf("result = %s\n",result);
	}

	if (carry == 1) {
		//itoa(carry,c,10);
		//printf("carry c = %d\n",carry);
		snprintf(c,sizeof(c),"%d",carry);
		strcat(result,c);
	}

	len = strlen(result);
	reverse(result,0,len-1);
	printf("result = %s\n",result);
}


int main()
{
	char str1[] = "10100";
	char str2[] = "110";
	//char *str1 = "10100";
	//char *str2 = "110";

	addBinaryString(str1,str2);

	return 0;
}
