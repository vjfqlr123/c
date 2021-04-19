#ifndef QUEUE_H
#define QUEUE_H

#define ARRYSIZE 10

typedef struct{
	int queue[ARRYSIZE];
	int front;
	int rear;
	
} Queue;

void initQueue(Queue *ps);
void push(Queue *ps, int data);
int pop(Queue *ps);

#endif 
