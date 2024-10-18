#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//Function declaration



//int my_cd(char **args);
//int my_ls(char **args);
//int my_help(char **args);
//int my_exit(char **args);
//int my_echo(char **args);
//int my_rm(char **args);
//int my_mkdir(char **args);
//int my_pwd(char **args);
//int my_wc(char **args);
//int my_cat(char **args);



char *get_line()
{
    char *line = NULL;
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




















