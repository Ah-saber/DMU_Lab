#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *path = getcwd(NULL, 0); //动态分配内存
    if(path != NULL)
    {
        printf("%s\n", path);
        free(path);
    }
    else
    {
        perror("myshell pwd:");
    }

    return 0;
}