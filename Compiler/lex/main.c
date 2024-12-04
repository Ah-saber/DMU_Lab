#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i;
    if(argc < 2)
    {
        yylex();
        printf("Done lex\n");
        return 0;
    }
    for(i = 0; i < argc; i ++)
    {
        FILE *f = fopen(argv[i], "r");
        if(!f)
        {
            perror(argv[i]);
            return 1;
        }
        yyrestart(f);
        yylex();
        fclose(f);
        printf("Done %d\n", i);
    }
    if(argc > 1)
        puts("ALL FINISH");
    return 0;
}