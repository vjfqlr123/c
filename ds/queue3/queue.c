#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#define ARRYSIZE 10

void initQueue(Queue *ps)
{
	ps->front = 0;
	ps->rear = 0;
}

void push(Queue *ps, int data)
{
	if(ps->rear == ARRYSIZE){
		fprintf(stderr, "queue is full\n");
		exit(1);
	}
	
	ps->queue[ps->rear] = data;
	++ps->rear;
}

int pop(Queue *ps)
{
	if(ps->front == ps->rear){
		fprintf(stderr, "queue is empty\n");
		exit(2);
	}
	
	int tmp = ps->front;
	++ps->front;
	return ps->queue[tmp];
}
