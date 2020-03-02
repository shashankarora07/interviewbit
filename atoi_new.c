#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int my_atoi(char *A)
{
    int len = strlen(A);
    int i = 0, j = 0, result = 0, sign = 1;
    while(*(A+j) == ' ' && ++j);
    for(i = j; i < len; i++) {
        if (A[i] == '-' || A[i] == '+') {
            sign = (A[i]=='-'? -1:1);
            continue;
        }
        /*if (result>INT_MAX) {
            if (sign)
                return INT_MIN;
            return INT_MAX;
        }
        */
        int temp = A[i]-'0';
        //if (result > (INT_MAX/10)  || (result == INT_MAX/10 && temp > 7)) {
        
        /*if ((((result >= (INT_MAX/10)) && temp > 7)) || (((result*sign <= (INT_MIN/10)) && temp > 8))) {
        	printf("return INT_MAX or INT_MIN\n");
        	//printf("printing result = %d \n",result);
            if (sign==1) {
                return INT_MAX;
            }
            return INT_MIN;
        }*/

        if (A[i] >= '0' && A[i] <= '9') {
        	printf("result before compare = %d \n",result);
        	if (result > (INT_MAX/10)  || (result == (INT_MAX/10) && temp > 7)) {
        	   	printf("return INT_MAX or INT_MIN\n");
        	//printf("printing result = %d \n",result);
            if (sign == 1) {
                return INT_MAX;
            } else {
            	printf("printing INI_MIN\n");
            	return INT_MIN;
            }
            }
            result = result * 10 + temp;
            printf("result = %d \n",result);
        }
        
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || A[i] == ' ') {
            //printf("c =%c\n",s[i]);
            break;
        }
        //else if (s[])
    }
    printf("result * sign = %d\n", result*sign);

	return result*sign;
}

int main(int argc, char const *argv[])
{
	
	//char *str = "    2147483647 d 3 dsds";
	//char *str = "   d31474836  ds 3 dsds";
	char *str = "   -2147483648 d  5121478262 8070067M75 X199R 547 8C0A11 93I630\
	 4P4071 029W433619 M3 5 14703818 776366059B9O43393";

	printf("ret atoi() =>%d\n",atoi(str));

	//printf("no =>%d\n",'9'-'0');

	int ret = 0;
	ret = my_atoi(str);
//	printf("int value = %d\n",5121478262);
	printf("ret my_atoi() =>%d\n",ret);

	return 0;
}
