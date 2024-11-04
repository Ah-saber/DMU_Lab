#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count_file(const char *filename, long long *lines, long long *words, long long *bytes)
{
    FILE *file = fopen(filename, "r");
    if(!file)
    {
        perror("file open");
        return;
    }

    int c;
    int a_word = 0;

    *lines = *words = *bytes = 0ll;

    while((c = fgetc(file)) != EOF)
    {
        (*bytes) ++;

        //printf("%d\n", c);
        if(c == '\n')
        {
            (*lines) ++;
        }

        //空白
        if(isspace(c) || c == '\n')
        {
            a_word = 0;
        }
        else
        {
            //第一个词直接加1，之后是单遇到空格之后的词就加1
            if(!a_word){
                a_word = 1;
                (*words) ++;
            }
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

    int i = 1;
    while(argv[i] != NULL)
    {
        long long lines, words, bytes;
        count_file(argv[i], &lines, &words, &bytes);
        printf(" %lld %lld %lld %s\n", lines, words, bytes, argv[i]);
        i ++;
    }

    return 1;
}