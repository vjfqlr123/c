#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


void initQueue(Queue *ps, int size, int elesize)
{
	//ps->queue = malloc(sizeof(int) * size);
	ps->queue = malloc(elesize * size);
	assert(ps->queue != NULL);
	
	ps->elesize = elesize;
	ps->size = size;
	ps->front = 0;
	ps->rear = 0;
}

void freeQueue(Queue *ps)
{
	free(ps->queue);
}

void push(Queue *ps, const void *pdata)
{
	assert(ps->rear != ps->size);
	//ps->queue[ps->rear] = data;
	memcpy((unsigned char*)ps->queue + ps->elesize * ps->rear, pdata, ps->elesize);
	++ps->rear;
}

void pop(Queue *ps, void *pdata)
{
	assert(ps->front != ps->rear);
	//int tmp = ps->front;
	//++ps->front;
	
	memcpy(pdata, (unsigned char*)ps->queue + ps->elesize * ps->front, ps->elesize);
	++ps->front;
}
