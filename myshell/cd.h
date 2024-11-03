#ifndef CD
#define CD

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int cd(char *argv[])
{
    char *default_path = getenv("HOME");

    if(argv[1] == NULL)
    {
        if(chdir(default_path) != 0)
        {
            perror("myshell cd:");
        }
    }
    else
    {
        puts("now change dir");
        if(chdir(argv[1]) != 0)
        {
            perror("myshell cd:");
        } 
    }

    return 1;      
}

#endif