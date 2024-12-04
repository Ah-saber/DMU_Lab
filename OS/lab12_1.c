#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024 //buffsize

int main(int argc, char **argv)
{
    int fd;
    char buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        perror("outfilename");
        return 1;
    }

    //open files
    //only write  not exist then create / exist then clear ; only owner can write and read
    if((fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    {
        fprintf(ner can write and stderr, "open %s Error: %s\n\a", argv[1], strerror(errno));
        return 1;
    }


    puts("Now, please input string");
    puts("(To quit use CTRL+D)");

    while(1)
    {
        fgets(buffer, BUFFER_SIZE, stdin);
        if(feof(stdin)) break;

        write(fd, buffer, strlen(buffer));
    }

    close(fd);
    return 0;
}