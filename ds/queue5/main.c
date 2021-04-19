#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue s1, s2;

	initQueue(&s1, 10, sizeof(int));
	initQueue(&s2, 100, sizeof(double));
	
	int i;
	
	i = 100; push(&s1, &i);
	i = 200; push(&s1, &i);
	i = 300; push(&s1, &i);
	
	int j;
	
	pop(&s1, &j); printf("s1 1 pop() : %d\n", j);
	pop(&s1, &j); printf("s1 2 pop() : %d\n", j);
	pop(&s1, &j); printf("s1 3 pop() : %d\n", j);
	
	double d;
	
	d = 1.1; push(&s2, &d);
	d = 2.2; push(&s2, &d);
	d = 3.3; push(&s2, &d);
	
	double f;
	
	pop(&s2, &f); printf("s2 1 pop() : %f\n", f);
	pop(&s2, &f); printf("s2 2 pop() : %f\n", f);
	pop(&s2, &f); printf("s2 3 pop() : %f\n", f);
	
	freeQueue(&s1);
	freeQueue(&s2);
	return 0;
}
