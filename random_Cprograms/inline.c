#include<stdio.h>

static inline int square(int x) { \
					return x*x;   \
				}

int main()
{

	int ret = 36/square(6);
	printf("%d\n",ret);

	return 0;
}
