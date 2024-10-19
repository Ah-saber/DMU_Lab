#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//Function declaration

char *get_line()
{
    char *line = NULL;
    ssize_t buff = 0;//有符号整数，错误时返回-1
    
    if(getline(&line, buff, stdin) == -1)
    {
        if(feof(stdin)){
            exit(0);
        }
        else
        {
            perror("readline wrong");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}

char **get_split_line(char *line)
{
    char **split_res = NULL;

    return split_res;
}

int execute(char **args)
{
    int status = 1;
    return status;
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




















