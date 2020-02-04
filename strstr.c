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

int NoOfOccurrence(char *s, char *sfound)
{
	int ret = 0, count = 0;
	
	while(*s != '\0') {
		
		if (*s == *sfound) {
			ret = compare(s,sfound);
			if (ret)
				count += 1;
		}
		
		s++;
	}
	
	return count;
}

int main()
{
	char *s = "myname is shashankname arora namename";
	char *str = "name";
	char *ret = NULL;
	int no = 0;
	ret = myStrStr(s,str);
	printf("ret string = %s\n",ret);
	no = NoOfOccurrence(s,str);
	printf("no of occurence = %d\n",no);

	return 0;
}
