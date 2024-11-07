#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include "cd.h"
#include "help.h"
#include "exit.h"
#include "echo.h"

//-----主进程函数----//
//这部分命令需要对主进程进行操作
char *main_function[] = {
    "cd",
    "help",
    "exit",
    "echo"
};

int (*main_func[])(char **) = {
    &as_cd,
    &as_help,
    &as_exit,
    &as_echo,
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

int call_mycommand(char **args, CommandMap command, char *line)
{
    pid_t pid1, pid2;
    int status;
    //管道实现
    int  pipefd[2];

    //重定向实现
    char *output_file = NULL;
    for(int i = 0; args[i] != NULL; i ++)
    {
        if(strcmp(args[i], ">") == 0)
        {
            output_file = args[i + 1];
            //puts(output_file);
            args[i] = NULL;
            break;
        }
    }

    //管道找命令
    bool is_pipe = 0;
    char **first_command = NULL, **second_command = NULL;
    for(int i = 0; args[i] != NULL; i ++)
    {
        if(!strcmp(args[i], "|"))
        {
            is_pipe = 1;
            first_command = malloc((i + 1) * sizeof(char*));
            if(first_command == NULL)
            {
                perror("allocate char");
                return 1;
            }

            memcpy(first_command, args, (i+1) * sizeof(char*));
            first_command[i] = NULL;

            int j = 1;
            while(args[j + i] != NULL)
                j ++;

            second_command = malloc((j + 1) * sizeof(char*));
            if(second_command == NULL)
            {
                perror("allocate char");
                return 1;
            }

            memcpy(second_command, args + i + 1, j*sizeof(char*));      
            break;  
        }
    }




    //如果需要创建子进程
    if(command.fork)
    {
        if(is_pipe)
        {
            CommandMap fir_command = get_command(first_command[0]);
            CommandMap sec_command = get_command(second_command[0]);
            if(fir_command.command == NULL || sec_command.command == NULL || fir_command.fork == 0 || sec_command.fork == 0)
            {
                puts("Don't support command");
                return 1;
            }
            
            if (pipe(pipefd) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }
            pid1 = fork();
            if(pid1 == 0)
            {
                //管道重定向，写端
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[0]);
                close(pipefd[1]);
                if(execvp(fir_command.path, first_command) == -1)
                {
                    perror("ashell exc");
                }
                exit(EXIT_FAILURE);
            }
            else
            {
                pid2 = fork();
                if(pid2 == 0)
                {
                    //管道重定向,读端
                    dup2(pipefd[0], STDIN_FILENO);
                    close(pipefd[1]);
                    close(pipefd[0]);
                    if(execvp(sec_command.path, second_command) == -1)
                    {
                        perror("ashell exc");
                    }
                    exit(EXIT_FAILURE);
                }
                //父进程关闭读写，防止除自己影响到管道
                close(pipefd[0]);
                close(pipefd[1]);

                //等子进程
                waitpid(pid1, NULL, 0);
                waitpid(pid2, NULL, 0);
            }
            free(first_command);
            free(second_command);
        }
        else
        {
            pid1 = fork();
            char *path = command.path;
            if(pid1 == 0)
            {
                if(output_file != NULL)
                {
                    int fd = open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
                    if(fd == -1)
                    {
                        perror("openfile");
                        return 1;
                    }
                    //重定向到文件
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                }
                //第0位是命令本身，args是为了传递参数
                if(execvp(path, args) == -1)
                {
                    perror("asshell exc"); //只是前缀，后面会有详细错误信息
                }
                exit(EXIT_FAILURE); //如果执行到这里说明程序调用不成功
            }
            else if(pid1 > 0)
            {
                //循环等待，实现不断等待子进程与保证子进程的回收
                do{
                    waitpid(pid1, &status, WUNTRACED);
                }while(!WIFEXITED(status) && !WIFSIGNALED(status));
            }
            else
            {
                perror("ashell exc");
                //创建失败
            }
            //1为main函数未结束
            return 1;
        }
    }
    else
    {
        //puts(command.command);
        for(int i = 0; i < num_of_mainfunc(); i ++)
        {
            if(strcmp(command.command, main_function[i]) == 0)
            {
                if(!strcmp(command.command, "echo"))
                    return (*main_func[i])(line);
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

    //puts(line);
    return line;
}

//设置分隔符
#ifndef TOKEN_SPLIT
#define TOKEN_SPLIT " \t\r\n\a"
#endif
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

int execute(char **args, char *line)
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
        return call_mycommand(args, command, line);
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

        printf("Ashell:~%s%% ", path);
        line = get_line();
        char *tmp_line = strdup(line);
        args = get_split_line(line);
        
        status = execute(args, tmp_line);

        free(line);
        free(args);
    }while(status);
}


int main()
{
    my_shell();

    return 0;
}




















