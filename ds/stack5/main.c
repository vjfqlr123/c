#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1, s2;
	initStack(&s1, 10, sizeof(int));
	initStack(&s2, 100, sizeof(double));
	
	int i;
	
	i = 100; push(&s1, &i);
	i = 200; push(&s1, &i);
	i = 300; push(&s1, &i);
	
	double d;
	
	d = 1.1; push(&s2, &d);
	d = 2.2; push(&s2, &d);
	d = 3.3; push(&s2, &d);
	
	int j;
	
	pop(&s1, &j);		printf("s1 1 pop() : %d\n", j);
	pop(&s1, &j);		printf("s1 2 pop() : %d\n", j);
	pop(&s1, &j);		printf("s1 3 pop() : %d\n", j);
	
	double f;
	
	pop(&s2, &f);		printf("s1 1 pop() : %f\n", f);
	pop(&s2, &f);		printf("s1 2 pop() : %f\n", f);
	pop(&s2, &f);		printf("s1 3 pop() : %f\n", f);
	
	cleanupStack(&s1);
	cleanupStack(&s2);
	return 0;
}
