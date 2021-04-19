#include <stdio.h>
#include <pthread.h>

void* thread_main(void *arg);

int sum=0;

int main(int argc, char *argv[])
{
	pthread_t id1, id2;
	int rang1[] = {1, 5};
	int rang2[] = {6, 10};	
	
	pthread_create(&id1, NULL, thread_main, (void*)rang1);
	pthread_create(&id2, NULL, thread_main, (void*)rang2);
	
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	
	printf("result : %d\n", sum);
	
	return 0;
}

void* thread_main(void *arg)
{
	int start = ((int*)arg))[0];
	int end = ((int*)arg))[1];
	
	while(start <= end){
		sum += start;
		++start;
	}
	return NULL;
}
