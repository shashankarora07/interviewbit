#include<stdio.h>

void stringread()
{
	int no = 0, i = 0;
	char c;

	printf("total people entered in room:\n");
	scanf("%d",&no);
	char *arr[no];
	
	while(c != '\n') {
		
	}
}

void func()
{
	char *arr[] = {"Hi","Hello","OHH","HeLLOO","Kya","Baat", "Kar","rahee", "Hoo"};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < len; i++) {
		printf("%s\n",arr[i]);
	}
}

int main()
{
	int no = 0, i = 0, l = 0;
	//func();
	//stringread();
	printf("total people entered in room:\n");
	scanf("%d",&no);
	
	char *a = "";
	char **arr = (char **)malloc(sizeof(char*)*no);
	
	printf("Name them all\n");

	for (i = 0; i < no; i++) {
		scanf("%ms",&a);
		printf("a = %s\n",a);
		l = strlen(a);
		arr[i] = (char*)malloc(sizeof(char)*l);
		strcpy(arr[i],a);
	}

	
	for (i = 0; i < no; i++) {
		printf("%s\n",*(arr+i));
	}

}
