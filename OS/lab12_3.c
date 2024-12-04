#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int args, char **argv)
{
    struct stat statbuf;
    time_t t;

    if(args < 2)
    {
        puts("input a file");
        exit(1);
    }


    if(stat(argv[1], &statbuf) == 0)
    {
        t = statbuf.st_atime;
        printf("%s\n", ctime(&t));
    }
    else
    {
        perror(argv[1]);
        exit(1);
    }

    return 0;
}