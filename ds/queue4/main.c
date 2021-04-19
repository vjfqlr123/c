#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue s1, s2;

	initQueue(&s1, 10);
	initQueue(&s2, 100);
	
	push(&s1, 100);
	push(&s1, 200);
	push(&s1, 300);
	
	printf("s1 1 pop() : %d\n", pop(&s1));
	printf("s1 2 pop() : %d\n", pop(&s1));
	printf("s1 3 pop() : %d\n", pop(&s1));
	
	push(&s2, 900);
	push(&s2, 800);
	push(&s2, 700);
	
	printf("s2 1 pop() : %d\n", pop(&s2));
	printf("s2 2 pop() : %d\n", pop(&s2));
	printf("s2 3 pop() : %d\n", pop(&s2));
	
	freeQueue(&s1);
	freeQueue(&s2);
	return 0;
}
