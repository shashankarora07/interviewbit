#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("Usage: give integer no");
		exit(0);
	}

	int no = atoi(argv[1]);
	if (no == 0)
		return 0;

	if ((no & 3) == 0) {
		printf("%d is mutiple of 4\n",no);
	}
	else
		printf("%d is not mutiple of 4\n",no);

	int cpyno = no;
	while(no != 1) {
		if (no % 4 != 0) {
			printf("%d is not power of 4\n",cpyno);
			return 0;
		}
		no /= 4; 
	}
	if (no == 1)
		printf("%d is power of 4\n",cpyno);

}