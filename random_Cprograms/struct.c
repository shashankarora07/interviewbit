#include<stdio.h>


typedef struct nested_t {
	int b;
	char c;
}nested_t; 

typedef struct elements_t {
	int a;
	nested_t nes;
}elements_t; 

typedef struct elements_t elements_t;

//struct elements_t
//{
//	int a;
//	struct nested_t {
//		int b;
//		char c;
//	}y; 
//
//}x; 

struct fix 
{
	int a;
	int t;
	int q;
	union u {
		int b;
		int p;
		int m;
		int o;
		double c;
	}d;
}s;


union dar
{
	char q;
	//char x;
	struct abc {
		char st;
		//int a;	
	}d;
}qq;

int main()
{
	elements_t x;
	printf("sizeof(x) = %d\n",sizeof(x));
	
	printf("sizeof(s) = %d\n",sizeof(s));
	
	printf("sizeof(qq) = %d\n",sizeof(qq));


	return 0;
}
