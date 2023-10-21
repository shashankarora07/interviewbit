#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *nstr;

void stringReplace(char *s)
{
	char *p;
	int i = 0, cn = 0;
	int repeat = 0;
	nstr = (char*)malloc(1);
	
	while(s[i] != '\0') {
		
		if (strstr(&s[i],"Hello") == &s[i]) {
			//repeat++;
			nstr = realloc(nstr,2);
			strcpy(&nstr[cn],"Hi");
			printf("...IF......s[%d] = %c and nstr[%d] = %c\n", i, s[i],cn, nstr[cn]);
			i = i+5;
			cn = cn+2;
			printf("...IF.....i = %d and cn = %d\n",i,cn);
		}
		else {
			nstr = realloc(nstr,1);
			nstr[cn] = *(s+i);
			printf("elseIF...s[%d] = %c and nstr[%d] = %c\n", i, s[i],cn, nstr[cn]);
			cn++;
			i++;
			printf("elseIF...i = %d and cn = %d\n",i,cn);
		}
//		if(p) {
//			strcpy(p,"Hi");
//			printf("p = %s\n",p);
//			printf("s = %s\n",s);
//		}
//		else {
//			printf("string not found\n");
//		}
//		*s++;
		
	}
	//nstr = realloc(nstr,1);
	nstr[cn] = '\0';
	//p = strstr(s,"Hello");

	//printf("%s\n",p);
	//printf("repeat = %d\n",repeat);
	printf("%s\n",s);
	printf("%s\n",nstr);
}

int main()
{
//	char str[] = "Hello there, I am here. Hi Hello, ";
	char str[] = "Hello I am here. Hi Hello, you are ";

	stringReplace(str);



	return 0;
}
