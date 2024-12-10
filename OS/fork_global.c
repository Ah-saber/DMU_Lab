#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int globa = 4;

void main()
{
	pid_t pid;
	int vari = 5;
	printf("before fork.\n");

	if((pid = fork()) < 0)
		exit(0);
	else if(pid == 0)
	{
		globa ++;
		vari --;
		printf("child %d changed\n", getpid());
	}
	else
		printf("Parent %d not change\n", getpid());
k1: printf("globa = %d, var = %d\n, pid = %d", globa, vari, getpid());
k2: exit(0);
}
