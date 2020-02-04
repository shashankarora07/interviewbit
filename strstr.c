#include<stdio.h>

int compare(char *x, char *y)
{
	while(*y != '\0')
	{
		if (*x != *y)
			return 0;
		x++;
		y++;
	}

	return 1;
}

char *myStrStr(char *s, char *sfound)
{
	int ret = 0;
	
	while(*s != '\0') {
		
		if (*s == *sfound) {
			ret = compare(s,sfound);
			if (ret)
				return s;
		}
		
		s++;
	}
	
	return NULL;
}

int main()
{
	char *s = "Aro";
	char *str = "Arora";
	char *ret = NULL;
	ret = myStrStr(s,str);
	printf("ret string = %s\n",ret);

	return 0;
}
