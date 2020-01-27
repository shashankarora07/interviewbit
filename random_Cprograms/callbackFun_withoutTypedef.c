#include<stdio.h>

//typedef void (*callback)(void);
void callback_fun(void (*callback)(void));

void fun()
{
	printf("Inside the function\n");
}

int main()
{

	void (*ptr_to_func)(void)  = fun;
	(*ptr_to_func)();
	printf("called my fun using function pointer\n");

	callback_fun(ptr_to_func);
	printf("back to main()\n");

	return 0;
}

void callback_fun(void (*ptr_to_callback_fun)(void))
{
	printf("Inside my callback function. Fun() is passed to other fun as a argument\n");
	(*ptr_to_callback_fun)();
}
