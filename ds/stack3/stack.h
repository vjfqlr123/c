#ifndef STACK_H
#define STACK_H
#define ARRAYSIZE 100

typedef struct {
	int array[ARRAYSIZE];
	int tos;
	
} Stack;

void push(Stack *ps, int data);
int pop(Stack *ps);
void initStack(Stack *ps);

#endif
