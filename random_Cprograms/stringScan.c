#include<stdio.h>
#include<stdlib.h>

void printArrayOfString()
{

}


int main(int argc, char* argv[])
{
	if (argc != 2) {
		perror("Usage: pass total no of string");
		exit(1);
	}

	int N = atoi(argv[1]);
	char buff[30];
	char** s = (char** )malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++) {
		scanf("%[^\n]%*c",buff);
		s[i] = buff;
		printf("%s\n", s[i]);
	}


	return 0;
}
