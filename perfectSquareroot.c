#include<stdio.h>

int perfectSqaureRoot(int no)
{
	


}

int main(int argc, int *argv[])
{
	
	if (argc != 2) {
		perror("Usage: give integer number");
		exit(0);
	}

	int num = atoi(argv[1]);	
	perfectSqaureRoot(num);



	return 0;
}
