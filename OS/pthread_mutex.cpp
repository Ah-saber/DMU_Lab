#include <iostream>
#include <pthread.h>

int global = 0;

pthread_mutex_t mutex;

void *A(void* arg) 
{
	for(int i = 0; i < 10; i ++)
	{
		pthread_mutex_lock(&mutex);

		++ global;
		
		pthread_mutex_unlock(&mutex);
	}
	return nullptr;
}

void *B(void *arg)
{
	for(int i = 0; i < 10; i ++)
	{
		pthread_mutex_lock(&mutex);

		-- global;

		pthread_mutex_unlock(&mutex);
	}
	return nullptr;
}


int main()
{
	pthread_t tid1, tid2;

	if((pthread_create(&tid1, NULL, A, NULL)) == -1)
	{
		perror("A");
		return 1;
	}

	if((pthread_create(&tid2, NULL, B, NULL)) == -1)
	{
		perror("B");
		return 1;
	}

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}





