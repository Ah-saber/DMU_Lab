#ifndef HELP
#define HELP

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char *command;
    char *path;
    bool fork;
    char *help;
}CommandMap;

CommandMap command_map[] = {
    {"cd", "", 0, "--change the dir"},
    {"help", "./bin/help.o", 0, "--for help"},
    {"exit", "", 0, "--exit"},
    {"ls", "./bin/ls.o", 1, "--list the files  --Optional parameters -l"},
    {"rm", "./bin/rm.o", 1, "--remove something  --Optional parameters -d(actually -rf)"},
    {"mkdir", "./bin/mkdir.o", 1, "--make new dir  --Optional parameters -m"},
    {"pwd", "./bin/pwd.o", 1, "--print work dir"},
    {"wc", "./bin/wc.o", 1, "--print lines, word, and byte for file"},
    {"cat", "./bin/cat.o", 1, "--print the content of file --Optional parameters -n"},
    {"echo", "./bin/echo.o", 1, "--print something"},
};

//Function declaration
int command_map_size()
{
    return sizeof(command_map) / sizeof(CommandMap);
}


int as_help(char **args)
{
    puts("\n\t   Welcome to A_Shell");
    puts("\tThe following commands mey be helpful");
    
    int i;
    for(i = 0; i < command_map_size(); i ++)
    {
        printf("\t%s  ", command_map[i].command);
        printf("\t%s\n", command_map[i].help);
    }
 
    puts("");
    puts("\tby the way, Ashell supports pipe and redirect (just some command)");
    puts("\tA little sketchy, but have fun");
    puts("\tTip: maybe try tab completion(just filename)\n");

    return 1;
}

#endif
