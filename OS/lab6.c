#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int msgid; 
    int status;
    char str1[] = {"test message:hello!"};
    char str2[] = {"test message:goodbye!"};
    char str3[] = {"The third message!"};

    struct msgbuf{
        long msgtype;
        char msgtext[1024];
    }sndmsg, rcvmsg;

    //0666表示八进制，意思是消息队列文件的权限
    //创建并获取msgid
    if((msgid = msgget(IPC_PRIVATE, 0666)) == -1)
    {
        puts("msgget error!");
        exit(254);
    }

    sndmsg.msgtype = 111;
    sprintf(sndmsg.msgtext, str1);

    //加一是因为最后存储要加一个\0
    if(msgsnd(msgid, &sndmsg, sizeof(str1)+1, 0) == -1)
    {
        puts("msgsnd error");
        exit(254);
    }

    sndmsg.msgtype = 222;
    sprintf(sndmsg.msgtext, str2);

    if(msgsnd(msgid, &sndmsg, sizeof(str2)+1, 0) == -1)
    {
        puts("msgsnd error");
        exit(254);
    }

    sndmsg.msgtype = 333;
    sprintf(sndmsg.msgtext, str3);

    if(msgsnd(msgid, &sndmsg, sizeof(str3)+1, 0) == -1)
    {
        puts("msgsnd error");
        exit(254);
    }

    //不等消息接受到就返回，实际就是收不到消息不阻塞
    if(status = msgrcv(msgid, &rcvmsg, 80, 0, IPC_NOWAIT) == -1)
    {
        puts("msgsnd error");
        exit(254);
    }

    printf("The received message:%s the type is %ld.\n", rcvmsg.msgtext, rcvmsg.msgtype);
    msgctl(msgid, IPC_RMID, 0);
    exit(0);
}