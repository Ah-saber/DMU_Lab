#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

bool count_std(long long *lines, long long *words, long long *bytes)
{
    int c;
    int a_word = 0;

    *lines = *words = *bytes = 0ll;

    bool flag = 0;

    while ((c = fgetc(stdin)) != EOF)
    {
        (*bytes) ++;
        flag = 1;
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
    return flag;
}




int main(int argc, char *argv[])
{   
    long long lines, words, bytes;
    bool flag = count_std(&lines, &words, &bytes);
    if(argc <= 1 && !flag)
    {
        puts("No file path");
        return 1;
    }

    int i = 1; 
    if(flag) printf(" %lld %lld %lld\n", lines, words, bytes);

    while(argv[i] != NULL)
    {
        count_file(argv[i], &lines, &words, &bytes);
        printf(" %lld %lld %lld %s\n", lines, words, bytes, argv[i]);
        i ++;
    }

    return 1;
}