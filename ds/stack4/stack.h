#ifndef STACK_H
#define STACK_H
//#define ARRAYSIZE 100

typedef struct {
//	int array[ARRAYSIZE];
	int *pArr;
	int size;
	int tos;
	
} Stack;

void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);
void push(Stack *ps, int data);
int pop(Stack *ps);


#endif
