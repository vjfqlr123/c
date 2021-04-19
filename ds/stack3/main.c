#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1, s2;
	//Stack stacks[10];
	//s1.tos = 0;
	//s2.tos = 0;
	initStack(&s1);
	initStack(&s2);
	
	push(&s1, 100);
	push(&s1, 200);
	push(&s1, 300);
	
	push(&s2, 900);
	push(&s2, 800);
	push(&s2, 700);
	
	printf("s1 1 pop() : %d\n", pop(&s1));
	printf("s1 2 pop() : %d\n", pop(&s1));
	printf("s1 3 pop() : %d\n", pop(&s1));
	
	printf("s2 1 pop() : %d\n", pop(&s2));
	printf("s2 2 pop() : %d\n", pop(&s2));				
	printf("s2 3 pop() : %d\n", pop(&s2));	
	
	pop(&s1);
	
	
	return 0;
}
