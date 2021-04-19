static int queue[10];
static int front;
static int rear;

void push(int data)
{
	queue[rear] = data;
	++rear;
}

int pop(void)
{
	int tmp = front;
	++front;
	return queue[tmp];
}
