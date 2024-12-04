%option yylineno
%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h> 
    #include "syntax.tab.h"

    int nums = 0;
    int ids = 0;
    int doublewords = 0;
    int singlewords = 0;
    int keys = 0;
    int wrongs = 0;Complier/lex/lexical.l Complier/lex/makefile Complier/lex/syntax.y
    int comments = 0;
    int buff = 100;
    char **wrong_info;
    int tmp = 0;
%}

letter [a-zA-Z]
digit [0-9]

if [iI][fF]
else [eE][lL][sS][eE]
for [fF][oO][rR]
while [wW][hH][iI][lL][eE]
do [dD][oO]
int [iI][nN][tT]\b
write [wW][rR][iI][tT][eE]
read [rR][eE][aA][dD]

/*匹配/*，然后是任何非*，或者一个*后不是/多次，或者再匹配多个*最后跟一个/*/
COMMENT  "/*"([^*]|[*]+[^*/])*[*]+"/"
UNTERMINATED_COMMENT  "/*"([^*]|[*]+[^*/])* 

doubleword (>=|<=|!=|==)
singleword [+\-*/=(){}:,;<>!]
KEY ({if}|{else}|{for}|{while}|{do}|{int}|{write}|{read})
ID {letter}{digit}*{letter}*
NUM 0|[1-9]{digit}*
NOTID {digit}*{ID}
IGNORE [ \t\r\n] 
other .
%%

{COMMENT} {comments ++; printf("%-8s \t %s\n", "COMMENT", yytext); tmp = yylineno;}
{UNTERMINATED_COMMENT} {
    if(wrongs == 0) wrong_info = malloc(sizeof(char *)*100);
    if(wrongs >= buff)
    {
        buff += 100;
        wrong_info = realloc(wrong_info, buff * sizeof(char));
    }
    wrong_info[wrongs] = malloc(256 * sizeof(char));
    sprintf(wrong_info[wrongs], "line %d error: Unterminated comment starting with %s\n", tmp-1, yytext);
    wrongs ++; 
    tmp = yylineno;
}
{doubleword} {doublewords ++;  printf("%-8s \t %s\n", yytext, yytext); tmp = yylineno;}
{singleword} {singlewords ++;  printf("%-8s \t %s\n", yytext, yytext); tmp = yylineno;}
{KEY} {keys ++;  printf("%-8s \t %s\n", "KEY", yytext); tmp = yylineno;}
{ID} {ids ++;  printf("%-8s \t %s\n", "ID", yytext); tmp = yylineno;}
{NUM} {nums ++;  printf("%-8s \t %s\n", "NUM", yytext); tmp = yylineno;}
{IGNORE} { if(yytext = '\n') tmp ++;}
{NOTID} {
    if(wrongs == 0) wrong_info = (char**)malloc(sizeof(char *)*10);
    if(wrongs >= buff)
    {
        buff += 100;
        wrong_info = realloc(wrong_info, buff * sizeof(char));
    }Complier/lex/lexical.l Complier/lex/makefile Complier/lex/syntax.y
        wrong_info = realloc(wrong_info, buff * sizeof(char));
    }
    wrong_info[wrongs] = malloc(256 * sizeof(char));
    sprintf(wrong_info[wrongs], "line %d error: Unrecognized symbol %s\n", yylineno, yytext);
    wrongs ++;
    tmp = yylineno; 
} 

%%

int main(int argc, char **argv)
{
    FILE *out_file = fopen("result.txt", "w");
    int stdout_fd = dup(fileno(stdout)); 
    if(out_file == NULL)
    {
        perror("Unable to open result.txt");
        return 1;
    }
    if (stdout_fd == -1)
    {
        perror("Failed to save stdout");
        return 1;
    }

    if (freopen("result.txt", "w", stdout) == NULL)
    {
        perror("Failed to redirect stdout");
        return 1;
    }

    int i;
    printf("Number of lexically analyzed documents: %d\n", argc - 1);
    
    if(argc < 2)
    {
        yylex();
        printf("Done\n");
        return 0;
    }
    for(i = 1; i < argc; i ++)
    {
        FILE *f = fopen(argv[i], "r");
        if(!f)
        {
            perror(argv[i]);
            return 1;
        }
        yylineno = 1;
        printf("%-8s \t %s\n", "label", "value");
        yyrestart(f);
        yylex();
        fclose(f);
        fflush(stdout);             // 确保缓冲区数据写入文件
        dup2(stdout_fd, fileno(stdout)); // 恢复标准输出
        close(stdout_fd);           // 关闭保存的描述符

        printf("Total wrongs: %d\n", wrongs);
        int j;
        for(j = 0; j < wrongs; j ++)
        {
            printf("%s", wrong_info[j]);
        }
        printf("\nDone %d file\n", i);
    }
    if(argc > 1)
        puts("ALL FINISH");
    return 0;
}