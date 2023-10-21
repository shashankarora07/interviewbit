#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *nstr;

void stringReplace(char *s)
{
	char a[] = "";
	int i = 0, cn = 0;
	int repeat = 0, count = 0;
	nstr = (char*)malloc(1);
	
	while(s[i] != '\0') {
		
		while(*(s+i) != ' ') {
				*(a + count) = *(s + i);
				count++;
				i++;
			}
			//repeat++;
		if (strcmp(a, "Hello")) {
			nstr = realloc(nstr,2);
			strcpy(&nstr[cn],"Hi");
			printf("...IF......s[%d] = %c and nstr[%d] = %c\n", i, s[i],cn, nstr[cn]);
			cn = cn+2;
			printf("...IF.....i = %d and cn = %d\n",i,cn);
		}
		if (*(s+i) == ' ') {
			nstr = realloc(nstr,1);
			strcpy(&nstr[cn], ' ');
			printf("elseIF...s[%d] = %c and nstr[%d] = %c\n", i, s[i],cn, nstr[cn]);
			cn++;
			printf("elseIF...i = %d and cn = %d\n",i,cn);
		}
		if (!strcmp(a, "Hello")) {
			nstr = realloc(nstr,count);
			strcpy(&nstr[cn],a);
			printf("notcmp.....s[%d] = %c and nstr[%d] = %c\n", i, s[i],cn, nstr[cn]);
			cn = cn+count+1;
			printf("notcmp....i = %d and cn = %d\n",i,cn);
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
		count = 0;	
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
