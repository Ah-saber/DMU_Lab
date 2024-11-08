#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#ifndef TOKEN_SPLIT
#define TOKEN_SPLIT " \t\n\r\a"
#endif

int as_echo(const char *line)
{
    char *split = strpbrk(line, TOKEN_SPLIT);
    char *real_output = malloc(strlen(line) + 1);
    if(real_output == NULL)
    {
        perror("malloc");
        return 1;
    }
    //找到分隔符
    if(split != NULL)
    {
        size_t first = split - line;
        strcpy(real_output, line + first + 1);
    }
    else
    {
        strcpy(real_output, line);
    }

    puts(real_output);

    free(real_output);
    return 1;
}

int main(int argc, char **argv)
{
    char *line;
    if(argc > 1)
    {
        line = argv[1];
        as_echo(line);
        return 1;
    }
    else return 1;
}