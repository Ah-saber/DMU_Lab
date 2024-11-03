#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "cd.h"
#include "help.h"
#include "exit.h"

//-----主进程函数----//
//这部分命令需要对主进程进行操作
char *main_function[] = {
    "cd",
    "help",
    "exit",
};

int (*main_func[])(char **) = {
    &as_cd,
    &as_help,
    &as_exit,
};

//获取数量，后面遍历用
int num_of_mainfunc(){
    return sizeof(main_function) / sizeof(char *);
}



CommandMap get_command(const char *command)
{
    for(int i = 0; i < command_map_size(); i ++)
    {
        if(strcmp(command, command_map[i].command) == 0)
        {
            return command_map[i];
        }
    }
    CommandMap m = {NULL, NULL, 0};
    return m;
}

int call_mycommand(char **args, CommandMap command)
{
    pid_t pid;
    int status;

    //如果需要创建子进程
    if(command.fork)
    {
        pid = fork();
        char *path = command.path;
        if(pid == 0)
        {
            //第0位是命令本身，args是为了传递参数
            if(execvp(path, args) == -1)
            {
                perror("myshell exc error"); //只是前缀，后面会有详细错误信息
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
            perror("myshell exc error");
            //创建失败
        }
        //1为main函数未结束
        return 1;
    }
    else
    {
        for(int i = 0; i < num_of_mainfunc(); i ++)
        {
            if(strcmp(command.command, main_function[i]) == 0)
            {
                return (*main_func[i])(args);
            }
        }
    }
    return 1;
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

        if(pos >= buffsize)
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
        }
        token = strtok(NULL, TOKEN_SPLIT);
    }
    
    tokens[pos] = NULL;
    //printf("%s", tokens[1]);
    return tokens;
}

int execute(char **args)
{

    if(args[0] == NULL)
    {
        return 1;
    }

    CommandMap command = get_command(args[0]);
    if(command.command == NULL) 
        puts("Unkonw command");
    else
    {
        return call_mycommand(args, command);
    }
    return 1;
}


char *get_pwdforshell()
{
    char *pwd_path = getcwd(NULL, 0);
    int count_sp = 0;
    int idx;
    for(idx = 0; idx < sizeof(pwd_path); idx ++)
    {
        if(pwd_path[idx] == '/') ++ count_sp;
        if(count_sp >= 3) break;
    }

    pwd_path = pwd_path + idx;
    return pwd_path;
}

// Main loop
void my_shell()
{
    char *line;
    char **args;
    int status = 1;

    do{
        char *path = get_pwdforshell();

        printf("myshell:~%s%% ", path);
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




















