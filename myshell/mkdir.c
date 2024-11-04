#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mode_t string_to_mode(const char *str)
{
    return (mode_t)strtol(str, NULL, 8);
}

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("No dir path\n");
        return 1;
    }

    if(!(strcmp(argv[1], "-m")))
    {
        if(argv[2] == NULL)
        {
            puts("No mode argument");
            return 1;
        }

        if(mkdir(argv[3], string_to_mode(argv[2])) != 0)
        {  
            perror("mkdir");
        }
    }
    else
    {
        if(mkdir(argv[1], 0777) != 0)
        {
            perror("mkdir");
        }
    }

    return 1;
}