#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
}Stack;

Stack *StackNode(int);
void Push(Stack **, int);
void DisplayStack(Stack *);
int Pop(Stack **);
int IsStackEmpty(Stack *);
int Top(Stack *);
#endif
