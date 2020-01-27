#include<stdio.h>

typedef void (*callback)(void);
void callback_fun(callback ptr_to_callback_fun);

void fun()
{
	printf("Inside the function\n");
}

int main()
{

	callback ptr_to_func = fun;
	(*ptr_to_func)();
	printf("called my fun using function pointer\n");

	callback_fun(ptr_to_func);
	printf("back to main()\n");

	return 0;
}

void callback_fun(callback ptr_to_callback_fun)
{
	printf("Inside my callback function. Fun() is passed to other fun as a argument\n");
	(*ptr_to_callback_fun)();
}
