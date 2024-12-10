#include <stdio.h>
#include <unistd.h>

void main()
{
	int pid, pid1;
	while((pid = fork()) == -1);
	if(pid != 0)
	{
		//father
		while((pid1 = fork()) == -1);
		if(pid1 != 0) //father
		{
			printf("c\n");
			printf("%d\n", getpid());
		}
		else //son2
		{
			printf("b\n");
			printf("%d\n", getppid());
		}
	}
	else //son1
	{
		printf("a\n");
		printf("%d\n", getpid());
	}

}
