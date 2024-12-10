#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

//进程不共享
int wait_mark;

void waiting()
{
    while(wait_mark != 0);
}

void stop()
{
    wait_mark = 0;
}

void main()
{
    int p1, p2;
    while((p1 = fork()) == -1);
    
    if(p1 > 0)
    {
        while((p2 = fork()) == -1);
        if(p2 > 0)
        {
            puts("parents");
            //sleep(1);
            wait_mark = 1;
            signal(SIGINT, stop);
            waiting();

            //其实是往进程发送信号
            kill(p1, 16);
            kill(p2, 17);

            wait(0);
            wait(0);

            printf("parent process is killed\n");
            exit(0);
        }
        else
        {
            puts("p2");
            wait_mark = 1;
            //如果信号到达，就运行stop函数
            signal(SIGINT, SIG_IGN);
            signal(17, stop);
            waiting();

            puts("child process 2 is killed by parent!");
            exit(0);
        }
    }
    else
    {
        puts("p1");
        wait_mark = 1;
        //绑定
        signal(SIGINT, SIG_IGN);
        signal(16, stop);
        waiting();

        puts("child process 1 is killed by parents");
        exit(0);
    }
}

//结果分析
//可能还没绑定就发送kill，父进程进了就等子进程，子进程会等到父进程发送kill再退出
//sleep信号的作用是1. 等子进程绑定;2.良好的交互
//可能第二个子进程先杀死，因为就算信号发来了，进程的调度信息也不一定