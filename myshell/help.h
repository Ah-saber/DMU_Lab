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
    {"help", "/home/ahsaber/DMU_Lab/myshell/bin/help.o", 0, "--for help"},
    {"exit", "", 0, "--exit"},
    {"ls", "/home/ahsaber/DMU_Lab/myshell/bin/ls.o", 1, "--list the files"},
    {"rm", "/home/ahsaber/DMU_Lab/myshell/bin/rm.o", 1, "--remove something"},
    {"mkdir", "/home/ahsaber/DMU_Lab/myshell/bin/mkdir.o", 1, "--make new dir"},
    {"pwd", "/home/ahsaber/DMU_Lab/myshell/bin/pwd.o", 1, "--print work dir"},
    {"wc", "/home/ahsaber/DMU_Lab/myshell/bin/wc.o", 1, "--print some file informantions"},
};

//Function declaration
int command_map_size()
{
    return sizeof(command_map) / sizeof(CommandMap);
}


int as_help(char **args)
{
    puts("Welcome to AS_shell");
    puts("The following commands mey be helpful");
    
    for(int i = 0; i < command_map_size(); i ++)
    {
        printf("    %s  ", command_map[i].command);
        printf("    %s\n", command_map[i].help);
    }

    puts("A little sketchy, but have fun");
    return 1;
}

#endif