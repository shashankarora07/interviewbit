#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int my_atoi(char *s)
{
	int len = strlen(s);
	int i = 0, j = 0, result = 0, sign = 1;
	while(*(s+j) == ' ' && ++j);
	for(i = j; i < len; i++) {
		if (s[i] == '-' || s[i] == '+')
			sign = (s[i]=='-'? -1:1);
		/*if (result>INT_MAX) {
			if (sign)
				return INT_MIN;
			return INT_MAX;
		}
		*/
		int temp = s[i]-'0';
		if (result > (INT_MAX/10)  || (result == INT_MAX/10 && temp > 7)) {
			if (sign==1)
				return INT_MAX;
			return INT_MIN;
		}
		if (isdigit(s[i])) {
			result = result * 10 + temp;
		}
		if (isalpha(s[i]) || s[i] == ' ') {
			printf("c =%c\n",s[i]);
			break;
		}
		//else if (s[])
	}
	

	return result*sign;
}

int main(int argc, char const *argv[])
{
	
	//char *str = "    2147483647 d 3 dsds";
	char *str = "   d31474836  ds 3 dsds";

	printf("ret atoi() =>%d\n",atoi(str));

	//printf("no =>%d\n",'9'-'0');

	int ret = 0;
	ret = my_atoi(str);
	printf("ret my_atoi() =>%d\n",ret);

	return 0;
}
