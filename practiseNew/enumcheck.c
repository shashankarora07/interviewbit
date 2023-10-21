#include<stdio.h>

typedef enum transaction_type {
    UNKNOWN = 0,
    BATTERY_SWAP = 1,
    BATTERY_ISSUE = 2,
    BATTERY_RETURN = 3,
    EXECUTIVE = 4,
	EKDKS = 5,
	QWIWIE = 6
} transaction_type_t;

int main()
{

	printf("sizeof enum transaction_type_t = %ld\n",sizeof(transaction_type_t));

	return 0;
}
