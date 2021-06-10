#include<stdio.h>


int Add(int a, int b)
{
	return a + b;
}

void printFunc(char *str)
{
	printf("Hello %s\n",str);
}

void passFunc(void (*funp)(char *))
{
	funp("man!");
	//printf("add = %d\n",c);
}

int (*fun_ptr)(int, int);
void passFunc(void (*funp)(char *));
int passFuncInt(int (*funptr)(int , int));
void (*fptr)(char *);

int main()
{
	int result;
	
	fun_ptr = &Add;
	result = (*fun_ptr)(2,3);
	printf("result = %d\n",result);
	
	fptr = &printFunc;
	(*fptr)("man!");

	//passFunc((*fun_ptr)(2,4));
	passFunc(fptr);
	passFuncInt((*fun_ptr)(2,4));

}
