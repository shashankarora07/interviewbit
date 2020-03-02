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

		if (isdigit(s[i])) {
			if (result > (INT_MAX/10)  || (result == INT_MAX/10 && temp > 7)) {
				if (sign==1)
					return INT_MAX;
			return INT_MIN;
		}
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
	//char *str = "     -2147483648 d  51";
	char *str ="     512147826 d 2 8070067M75 X199R 547 8C0A11 93I630\
	 4P4071 029W433619 M3 5 14703818 776366059B9O43393";

	printf("ret atoi() =>%d\n",atoi(str));

	//printf("no =>%d\n",'9'-'0');

	int ret = 0;
	ret = my_atoi(str);
	printf("ret my_atoi() =>%d\n",ret);

	return 0;
}
