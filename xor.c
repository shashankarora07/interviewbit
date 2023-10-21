#include<stdio.h>


unsigned int swap_bit(unsigned int no)
{
	unsigned int x,y,num;
	x = (~(~0 << 1) << 0);
	printf("x = %d\n",x);
	y = (~(~0 << 1) << 2);
	printf("y = %d\n",y);
	num = no ^ (x | y);
	printf("num = %d\n",num);


}

int main()
{
	unsigned int no = 6;
	swap_bit(no);


	return 0;
}
