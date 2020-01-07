#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

void String_reverseUsingStack(char *s)
{
	//int len = strlen(s);
	Stack *S = NULL;

	while(*s != '\0') {
		Push(&S,*s);
		*s++;
	}
	while(!IsStackEmpty(S))
		printf("%c",Pop(&S));
	printf("\n");
}


int main()
{
	char s[] = "Shashank Arora";

	String_reverseUsingStack(s);

	return 0;
}
