#include<stdio.h>


typedef struct nested_t {
	int b:1;
	char c:1;
	int a:1;
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

typedef int (*initcall_t)(void);
typedef initcall_t initcall_entry_t;


//static initcall_entry_t *initcall_levels[] __initdata = {
//    __initcall0_start,
//    __initcall1_start,
//    __initcall2_start,
//    __initcall3_start,
//    __initcall4_start,
//    __initcall5_start,
//    __initcall6_start,
//    __initcall7_start,
//    __initcall_end,
//};
//
///* Keep these in sync with initcalls in include/linux/init.h */
//static char *initcall_level_names[] __initdata = {
//    "pure",
//    "core",
//    "postcore",
//    "arch",
//    "subsys",
//    "fs",
//    "device",
//    "late",
//};
//
//static void __init do_initcalls(void)
//{
//    int level;
//
//    for (level = 0; level < ARRAY_SIZE(initcall_levels) - 1; level++)
//        do_initcall_level(level);
//}

/**
 * ARRAY_SIZE - get the number of elements in array @arr
 * @arr: array to be sized
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
//define in linux/kernel.h
int main()
{
	elements_t x;
	printf("sizeof(x) = %d\n",sizeof(x));
	
	printf("sizeof(s) = %d\n",sizeof(s));
	
	printf("sizeof(qq) = %d\n",sizeof(qq));

	nested_t nes;

	printf("sizeof(nes) = %d\n",sizeof(nes));


	return 0;
}
