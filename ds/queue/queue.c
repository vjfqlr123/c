#include <stdio.h>
int queue[10];
int front;
int rear;

void push(int data)
{
	queue[rear] = data;
	++rear;
}

int pop(void)
{
	int tmp = front;
	++front;
	return queue[tmp];
}

int main(void)
{
	push(100);
	push(200);
	printf("1 pop() : %d\n", pop());
	
	push(300);
	printf("2 pop() : %d\n", pop());
	printf("3 pop() : %d\n", pop());
	
	return 0;
}


