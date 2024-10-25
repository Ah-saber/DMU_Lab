#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Function declaration

typedef struct{
    char *command;
    char *path;
}CommandMap;


CommandMap command_map[] = {
    {"cd", "~/myshell/bin/cd"},
    {"help", "~/myshell/bin/help"},
    {"exit", "~/myshell/bin/exit"},
    {"ls", "~/myshell/bin/ls"},
    {"rm", "~/myshell/bin/rm"},
    {"mkdir", "~/myshell/bin/mkdir"},
    {"pwd", "~/myshell/bin/pwd"},
    {"wc", "~/myshell/bin/wc"},
};

int command_map_size()
{
    return sizeof(command_map) / sizeof(CommandMap);
}

char *get_command_path(const char *command)
{
    for(int i = 0; i < command_map_size(); i ++)
    {
        if(strcmp(command, command_map[i].command) == 0)
        {
            return command_map[i].path;
        }
    }
    return NULL;
}

int call_mycommand(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0)
    {
        if(execvp(args[0], args) == -1)
        {
            perror("myshell error"); //只是前缀，后面会有详细错误信息
        }
        exit(EXIT_FAILURE); //如果执行到这里说明程序调用不成功
    }
    else if(pid > 0)
    {
        //循环等待，实现不断等待子进程与保证子进程的回收
        do{
            waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
    {
        perror("myshell error");
        //创建失败
    }
}

char *get_line()
{
    char *line = NULL;
    ssize_t buff = 0;//有符号整数，错误时返回-1
    
    //好处是不用手动开空间
    if(getline(&line, &buff, stdin) == -1)
    {
        if(feof(stdin)){
            exit(0);
        }
        else
        {
            perror("myshell error");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}

//设置分隔符
#define TOKEN_SPLIT " \t\r\n\a"
#define TOKEN_BUFF 64

char **get_split_line(char *line)
{
    int buffsize = TOKEN_BUFF, pos = 0;
    char **tokens = malloc(buffsize * sizeof(char*));
    char *token, **tokens_backup;

    if(!tokens)
    {
        fprintf(stderr, "myshell: split_line_tokens allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_SPLIT);
    while(token != NULL)
    {
        tokens[pos ++] = token;

        if(pos > buffsize)
        {
            buffsize += TOKEN_BUFF;
            tokens_backup = tokens; //重申内存之前先保存备份，防止申请失败后无法释放这部分内存
            tokens = realloc(tokens, buffsize * sizeof(char*));

            if(!tokens)
            {
                free(tokens_backup);
                fprintf(stderr, "myshell: split_line_tokens allocation error");
                exit(EXIT_FAILURE);
            }

            token = strtok(NULL, TOKEN_SPLIT);
        }
    }
    
    tokens[pos] = NULL;

    return tokens;
}

int execute(char **args)
{
    int status = 1;

    if(args[0] == NULL)
    {
        return 1;
    }

    char *path = get_command_path(args[0]);
    if(path == NULL) 
        puts("Unkonw command");
    else
    {
        return call_mycommand(args);
    }
}


// Main loop
void my_shell()
{
    char *line;
    char **args;
    int status = 1;

    do{
       printf("%%");
       line = get_line();
       args = get_split_line(line);
       status = execute(args);

       free(line);
       free(args);
    }while(status);
}


int main()
{
    my_shell();

    return 0;
}




















