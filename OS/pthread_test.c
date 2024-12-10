#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* A_print()
{
	sleep(1);
	int i;
	for(i = 0; i < 3; i ++)
	{
		puts("aa");
	}
	return NULL;
}

//注意是void×
void* B_print()
{
	int i;
	for(i = 0; i < 6; i ++)
	{
		puts("bb");
	}
	return NULL;
}

int main()
{
	pthread_t tid1, tid2;

	// 线程号，线程属性，void函数（线程工作函数），函数参数
	if(pthread_create(&tid1, NULL, A_print, NULL) == -1)
	{
		perror("prthread1");
		return 1;
	}

	
	if(pthread_create(&tid2, NULL, B_print, NULL) == -1)
	{
		perror("prthread2");
		return 1;
	}
	//第二个参数是函数返回值，
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}


