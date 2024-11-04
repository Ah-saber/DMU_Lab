#ifndef ECHO
#define ECHO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOKEN_SPLIT " \t\n\r\a"

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

    return 1;
}

#endif