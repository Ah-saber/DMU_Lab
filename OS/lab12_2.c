#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NEWFILE (O_WRONLY | O_CREAT | O_TRUNC)


int main()
{
    char buf1[] = {"woshidabian\n\n\n\n"};
    char buf2[] = {"goushishiwo"};

    int fd;
    int length;
    if((fd = open("test", NEWFILE, 0600)) == -1)
    {
        perror("Open file error");
        exit(255);
    }

    length = strlen(buf1);
    if(write(fd, buf1, length) != length)
    {
        //strerror返回错误码对应字符串
        printf("ERROR, writr file failed:%s\n", strerror(errno)); //最后一次的错误类型码
        exit(255); //仅表示错误，无固定含义
    }

    //偏移到距离文件头80的位置，八进制是120
    if(lseek(fd, 80, SEEK_SET) == -1)
    {
        printf("ERROR, lseek failed:%s\n", strerror(errno));
        exit(255);
    }

    length = strlen(buf2);
    if(write(fd, buf2, length) != length)
    {
        printf("ERROR, write file failed:%s\n", strerror(errno));
        exit(255);
    }

    close(fd);
    return 0;
}