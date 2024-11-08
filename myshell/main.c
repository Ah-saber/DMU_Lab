#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <termios.h>
#include <dirent.h>
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
    int i;
    for(i = 0; i < command_map_size(); i ++)
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
    int i;
    for(i = 0; args[i] != NULL; i ++)
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
    int i;
    for(i = 0; args[i] != NULL; i ++)
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
                if(!strcmp(fir_command.command, "echo"))
                    first_command[1] = line;
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
                    if(!strcmp(sec_command.command, "echo"))
                        second_command[1] = line;
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
                if(!strcmp(command.command, "echo"))
                        args[1] = line;
                if(execvp(path, args) == -1)
                {
                    perror("ashell exc"); //只是前缀，后面会有详细错误信息
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
        int i;
        for(i = 0; i < num_of_mainfunc(); i ++)
        {
            if(strcmp(command.command, main_function[i]) == 0)
            {
                return (*main_func[i])(args);
            }
        }
    }
    return 1;
}

//---------读入与补全实现----------

void enable_raw_mode() {
    //设置原始模式，原本为规则模式，即缓冲行等自动执行，维护一些输入输出程序
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);  // 仅关闭行缓冲和回显
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disable_raw_mode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;  //还原
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// 更新 complete_file 函数，实现文件补全
// 文件补全函数：找到最后一个空格后面的部分进行补全
int complete_name(char *input) {
    DIR *dir;
    struct dirent *entry;
    
    int bk = strlen(input);
    // 查找最后一个空格的位置
    char *last_space = strrchr(input, ' ');
    const char *prefix = (last_space == NULL) ? input : last_space + 1; // 如果没有空格，则从头开始匹配
    size_t prefix_len = strlen(prefix);

    //puts(input);
    
    // 打开当前目录
    if ((dir = opendir(".")) == NULL) {
        perror("opendir() error");
    } else {
        while ((entry = readdir(dir)) != NULL) {
            // 匹配文件名的前缀
            if (strncmp(entry->d_name, prefix, prefix_len) == 0) {
                // 构建补全后的字符串
                if (last_space != NULL) {
                    size_t base_len = last_space - input + 1; // 包含空格的位置
                    snprintf(input + base_len, 256, "%s", entry->d_name);
                } else {
                    snprintf(input, 256, "%s", entry->d_name);  // 没有空格时直接替换整个 input
                }
                break;
            }
        }
        closedir(dir);
    }

    return bk;
}


#define BUFF_SIZE 64

char *get_line()
{
    int i = 0;
    int buff = BUFF_SIZE;
    char *input = malloc(buff * sizeof(char));
    
    char *backup;

    if(!input)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    input[0] = '\0';

    enable_raw_mode();


    //printf("Enter command: ");
    while (1)
    {
        char c = getchar();
        
        if(i > buff)
        {
            buff += BUFF_SIZE;
            backup = input;
            input = realloc(input, buff * sizeof(char));
        }

        // 检查是否按下 Backspace 键（通常为 127 或 8）
        if ((int)c == 127 || (int)c == 8) {
            if (strlen(input) > 0) {
                input[strlen(input) - 1] = '\0';  // 删除最后一个字符
                printf("\b \b");  // 在终端上退格、清除字符、再退格
                fflush(stdout); //刷新输出
            }
        } 
        else if (c == '\t') {
            int bk = complete_name(input); // 文件补全，将匹配结果填入 input
            int j;
            for (j = 0; j < bk; j ++) {
                printf("\b");
            }
            printf("%s", input); // 使用 \r 回到行首更新显示
            fflush(stdout);
        } 
        else if (c == '\n') {
            printf("\n");
            break;
        } 
        else {
            strncat(input, &c, 1);
            i ++; // 记录是否超空间
            putchar(c);  // 手动回显字符
        }
    }
    //fflush(stdout);
    printf("\r");
    disable_raw_mode();
    
    if(i > 0) return input;
    else return NULL;
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

    if(line == NULL) return NULL;

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
    if(args == NULL || line == NULL) return 1;
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
        char *tmp_line = NULL;
        if(line != NULL)
            tmp_line = strdup(line);
        
        args = get_split_line(line);
        //puts("nihao");
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




















