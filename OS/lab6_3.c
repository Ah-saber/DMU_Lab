#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <string.h>


#define MSGKEY 75

struct msgform
{
    long mtype;
    char msgtext[1030];
}msg;

int msgqid, pid, pid1;
int wait_off;

void waitting()
{
    while(wait_off != 0);    
}

void stop()
{
    wait_off = 0;
}

//无法保证kill在waitting之后
//手动
void SERVER()
{
    signal(17, stop);
    do{
        //此处如果没有消息就阻塞
        wait_off = 1;
        waitting();

        msgrcv(msgqid, &msg, 1030, 0, 0); //收不到，阻塞
        printf("(server)received message %d\n", msg.mtype);
        printf("%s", msg.msgtext);
        printf("%d", pid);
        //sleep(1);
        //只负责开锁
        //kill(pid, 16);
    }while(msg.mtype != 1);

    msgctl(msgqid, IPC_RMID, 0);//删除消息队列
    exit(0);
}

void CLIENT()
{
    int i;
    char string_i[15];
    msgqid = msgget(MSGKEY, 0777);
    signal(16, stop);
    //sleep(2);
    for(i = 10; i >= 1; i --)
    {
        //服务端的阻塞会保证客户端先发
        wait_off = 1;
        waitting();
        msg.mtype = i;
        printf("(client)sent\n");
        sprintf(msg.msgtext, "the content of message is: ");
        sprintf(string_i, "message %d", i);
        strcat(msg.msgtext, string_i);
        strcat(msg.msgtext, "\n");
        msgsnd(msgqid, &msg, 1030, 0);
        //
        kill(pid, 17);
    }
    exit(0);
}

void main()
{
    msgqid = msgget(MSGKEY, 0777|IPC_CREAT);//创建队列

    while((pid = fork()) == -1);
    if(pid == 0)
        SERVER();
    else
    {
        //此时pid为CLIENT 的pid
        while((pid1 = fork()) == -1);
        if(pid1 == 0)
            CLIENT();
        else
        {
            int i = 10;
            while(i --)
            {
                char a = getchar();
                if(a == '\n')
                {
                    kill(pid1, 16);
                }
            }
        }
    }
    

    wait(0);
    wait(0);
}

