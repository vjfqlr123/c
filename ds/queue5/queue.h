#ifndef QUEUE_H
#define QUEUE_H


typedef struct{
	//int *queue;
	void *queue;
	int elesize;
	int size;
	int front;
	int rear;
	
} Queue;

void initQueue(Queue *ps, int size, int elesize);
void freeQueue(Queue *ps);
void push(Queue *ps, const void *pdata);
void pop(Queue *ps, void *pdata);

#endif 
