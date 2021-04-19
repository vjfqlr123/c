#include <stdio.h>
#include "stack.h"

int main(void)
{
	push(100);
	push(200);
	push(300);
	
	printf("1 pop() : %d\n", pop());
	printf("2 pop() : %d\n", pop());
	printf("3 pop() : %d\n", pop());
	
		
	return 0;
}
