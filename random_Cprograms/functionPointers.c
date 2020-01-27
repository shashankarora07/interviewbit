#include<stdio.h>

//void (*funptr_arr[])(int,int);

struct abc {
	int a;
};

void add(int a,int b)
{
	printf("addition of %d and %d is %d\n",a,b,a+b);
}

void subtract(int a,int b)
{
	printf("Subtraction of %d and %d is %d\n",a,b,a-b);
}

void multiply(int a,int b)
{
	printf("Multiplication of %d and %d is %d\n",a,b,a*b);
}

int main()
{
	char *array[] = {"add","subtract","multiply"};
	int no, a = 10, b = 20;
	
	printf("%s\n",array[0]);
	
//	void (*funptr_arr)(int,int) = &subtract;
//		(*funptr_arr)(a,b);	
	void (*funptr_arr[])(int,int) = {add,subtract,multiply};
	do { printf("Enter choice\n");
		scanf("%d",&no);
		if (no > 2)
			break;	
	
		(*funptr_arr[no])(a,b);	
		
		}while(no <= 2);


	return 0;
}
