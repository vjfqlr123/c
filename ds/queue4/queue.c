#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


void initQueue(Queue *ps, int size)
{
	ps->queue = malloc(sizeof(int) * size);
	assert(ps->queue != NULL);
	
	ps->size = size;
	ps->front = 0;
	ps->rear = 0;
}

void freeQueue(Queue *ps)
{
	free(ps->queue);
}

void push(Queue *ps, int data)
{
	assert(ps->rear != ps->size);
	ps->queue[ps->rear] = data;
	++ps->rear;
}

int pop(Queue *ps)
{
	assert(ps->front != ps->rear);
	int tmp = ps->front;
	++ps->front;
	return ps->queue[tmp];
}
