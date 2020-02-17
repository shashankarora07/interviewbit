#include<stdio.h>

int compare(char *x, char *y)
{
	//int index = 0;
	//int i = 0, saveindex = index;
	while(*y != '\0')
	{
		if (*x != *y) {
			return 0;
		}

		x++;
		y++;
	}

	return 1;
}

int myStrStr(char *s, char *sfound)
{
	int index = 0, ret = 0;
	
	while(*(s+index) != '\0') {
		
		if (*(s+index) == *sfound) {
			ret = compare(s+index,sfound);
			//printf(" ret = %d\n",ret );
			if (ret) {
				//printf(" index = %d\n",index);
				return index;
			}
		}
		
		//prevIndex=index;
		index++;
	}
	
	return -1;
}

/*int NoOfOccurrence(char *s, char *sfound)
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
}*/

int main()
{
	char *s = "myname is shashankname arora namename";
	char *str = "arora";
	//char *ret = NULL;
	int ret = -1;
	//int no = 0;
	ret = myStrStr(s,str);
	printf("ret string index= %d\n",ret);
	//no = NoOfOccurrence(s,str);
	//printf("no of occurence = %d\n",no);

	return 0;
}
