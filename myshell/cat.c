#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void cat_file(const char *filename, bool is_n)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        perror("openfile");
        return;
    }

    int c;
    int i = 1;

    if(is_n) printf("    %d  ", i);

    i += 1;

    while((c = fgetc(file)) != EOF)
    {
        putchar(c);
        if(is_n && c == '\n')
        {
            printf("    %d  ", i);
            i ++;
        }
    }

    fclose(file);
}




int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        puts("No file path");
        return 1;
    }

    if(argc > 2)
    {
        if(!(strcmp(argv[1], "-n")))
            cat_file(argv[2], 1);
        else
        {
            puts("Unkown argument");
        }
    }
    else
    {
        cat_file(argv[1], 0);
    }
    
    return 1;
}

