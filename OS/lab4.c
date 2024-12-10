#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

//p1不一定先于p2,调度是随机的
//流程是父进程创建子进程，无论是否wait，都等到子进程先写入文件buf，然后sleep，等待
//直到一个子进程exit退出，父进程才继续往下，此时保证了管道内有数据（除非出错），父进程
//读出数据，输出，wait等待，直到另一个子进程输出
//sleep是为了保证父进程有时间读数据，同时让显示更直观


void main()
{
	int i, r, p1, p2, fd[2];
	char buf[50], s[50];

	pipe(fd); //定义写端，其实管道的缓冲区是内核的缓冲区

	while((p1 = fork()) == -1);

	if(p1 == 0)
	{
		lockf(fd[1], 1, 0);
		sprintf(buf, "messegaes from child p1");
		printf("child process p1\n");

		sleep(5); //等父进程读，防止覆写

		write(fd[1], buf, 50);
		lockf(fd[1], 0, 0);
		exit(0);
	}
	else
	{
		while((p2 = fork()) == -1);
		if(p2 == 0)
		{
			lockf(fd[1], 1, 0);
			sprintf(buf, "messeages from child p2");
			printf("child process p2\n");
			sleep(5);
			write(fd[1], buf, 50);
			lockf(fd[1], 0, 0);
			exit(0);
		}
		wait(0);
		if((r = read(fd[0], s, 50)) == -1)
			puts("can't read pipe");
		else
		{
			if(strlen(s) == 0)
				puts("now zero");
			else puts(s);
		}

		wait(0);
		if((r = read(fd[0], s, 50)) == -1)
			puts("can't read pipe");
		else
		{
			if(strlen(s) == 0)
				puts("now zero");
			else puts(s);
		}

		exit(0);
	}
}
