%option yylineno
%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h> 
    #include "node.h" 
    #include "syntax.tab.h"
   
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line=yylloc.last_line=yylineno; \
        yylloc.first_column=yycolumn; \
        yylloc.last_column=yycolumn+yyleng-1; \
        yycolumn+=yyleng;
    

    int nums = 0;
    int ids = 0;
    int doublewords = 0;
    int singlewords = 0;
    int keys = 0;
    int wrongs = 0;
    int comments = 0;
    int buff = 100;
    char **wrong_info;
    int tmp = 0;
%}

letter [a-zA-Z]
digit [0-9]

/*匹配/*，然后是任何非*，或者一个*后不是/多次，或者再匹配多个*最后跟一个/*/

COMMENT  "/*"([^*]|[*]+[^*/])*[*]+"/"
UNTERMINATED_COMMENT  "/*"([^*]|[*]+[^*/])* 

doubleword (>=|<=|!=|==)
singleword (>|<)

IF [iI][fF]
ELSE [eE][lL][sS][eE]
FOR [fF][oO][rR]
WHILE [wW][hH][iI][lL][eE]
INT [iI][nN][tT]
MAIN [mM][aA][iI][nN]

WRITE [wW][rR][iI][tT][eE]
READ [rR][eE][aA][dD]
CALL [cC][aA][lL][lL]

PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
NOT "!"
DOT "."
SEMI ";"
COMMA ","
ASSIGNOP "="
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
RELOP ({doubleword}|{singleword})
ID {letter}{digit}*{letter}*
NUM 0|[1-9]{digit}*
NOTID {digit}*{ID}
IGNORE [ \t\r\n] 
other .
%%

{COMMENT} {
    comments ++; printf("%-8s \t %s\n", "COMMENT", yytext); tmp = yylineno;
}
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


{RELOP} {
    printf("%-8s \t %s\n", yytext, yytext); 
    tmp = yylineno;
    return RELOP;
}

{IF} {printf("%-8s \t %s\n", "IF", yytext); tmp = yylineno; return IF;}
{ELSE} {printf("%-8s \t %s\n", "ELSE", yytext); tmp = yylineno; return ELSE;}
{FOR} {printf("%-8s \t %s\n", "FOR", yytext); tmp = yylineno; return FOR;}
{WHILE} {printf("%-8s \t %s\n", "WHILE", yytext); tmp = yylineno; return WHILE;}
{WRITE} {printf("%-8s \t %s\n", "WRITE", yytext); tmp = yylineno; return WRITE;}
{INT} {printf("%-8s \t %s\n", "INT", yytext); tmp = yylineno; return INT;}
{READ} {printf("%-8s \t %s\n", "READ", yytext); tmp = yylineno; return READ;}
{MAIN} {printf("%-8s \t %s\n", "MAIN", yytext); tmp = yylineno; return MAIN;}
{CALL} {printf("%-8s \t %s\n", "CALL", yytext); tmp = yylineno; return CALL;}

{ID} {ids ++;  printf("%-8s \t %s\n", "ID", yytext); tmp = yylineno; return ID;}
{NUM} {nums ++;  printf("%-8s \t %s\n", "NUM", yytext); tmp = yylineno; return NUM;}

{PLUS} {printf("%-8s \t %s\n", "PLUS", yytext); tmp = yylineno; return PLUS;}
{MINUS} {printf("%-8s \t %s\n", "MINUS", yytext); tmp = yylineno; return MINUS;}
{STAR} {printf("%-8s \t %s\n", "STAR", yytext); tmp = yylineno; return STAR;}
{DIV} {printf("%-8s \t %s\n", "DIV", yytext); tmp = yylineno; return DIV;}
{AND} {printf("%-8s \t %s\n", "AND", yytext); tmp = yylineno; return AND;}
{OR} {printf("%-8s \t %s\n", "OR", yytext); tmp = yylineno; return OR;}
{NOT} {printf("%-8s \t %s\n", "NOT", yytext); tmp = yylineno; return NOT;}
{DOT} {printf("%-8s \t %s\n", "DOT", yytext); tmp = yylineno; return DOT;}
{SEMI} {printf("%-8s \t %s\n", "SEMI", yytext); tmp = yylineno; return SEMI;}
{COMMA} {printf("%-8s \t %s\n", "COMMA", yytext); tmp = yylineno; return COMMA;}
{ASSIGNOP} {printf("%-8s \t %s\n", "ASSIGNOP", yytext); tmp = yylineno; return ASSIGNOP;}

{LP} {printf("%-8s \t %s\n", "LP", yytext); tmp = yylineno; return LP;}
{RP} {printf("%-8s \t %s\n", "RP", yytext); tmp = yylineno; return RP;}
{LB} {printf("%-8s \t %s\n", "LB", yytext); tmp = yylineno; return LB;}
{RB} {printf("%-8s \t %s\n", "RB", yytext); tmp = yylineno; return RB;}
{LC} {printf("%-8s \t %s\n", "LC", yytext); tmp = yylineno; return LC;}
{RC} {printf("%-8s \t %s\n", "RC", yytext); tmp = yylineno; return RC;}


{IGNORE} { if(*yytext = '\n'){ tmp ++; yycolumn = 1; /*列数复位*/ }}
{NOTID} {
    if(wrongs == 0) wrong_info = (char**)malloc(sizeof(char *)*10);
    if(wrongs >= buff)
    {
        buff += 100;
        wrong_info = realloc(wrong_info, buff * sizeof(char));
    }
    wrong_info[wrongs] = malloc(256 * sizeof(char));
    sprintf(wrong_info[wrongs], "line %d error: Unrecognized symbol %s\n", yylineno, yytext);
    wrongs ++; 
    tmp = yylineno;
}
{other} {
    if(wrongs == 0) wrong_info = (char**)malloc(sizeof(char *)*10);
    if(wrongs >= buff)
    {
        buff += 100;
        wrong_info = realloc(wrong_info, buff * sizeof(char));
    }
    wrong_info[wrongs] = malloc(256 * sizeof(char));
    sprintf(wrong_info[wrongs], "line %d error: Unrecognized symbol %s\n", yylineno, yytext);
    wrongs ++;
    tmp = yylineno; 
} 

%%

// int main(int argc, char **argv)
// {
//     FILE *out_file = fopen("result.txt", "w");
//     int stdout_fd = dup(fileno(stdout)); 
//     if(out_file == NULL)
//     {
//         perror("Unable to open result.txt");
//         return 1;
//     }
//     if (stdout_fd == -1)
//     {
//         perror("Failed to save stdout");
//         return 1;
//     }

//     if (freopen("result.txt", "w", stdout) == NULL)
//     {
//         perror("Failed to redirect stdout");
//         return 1;
//     }

//     int i;
//     printf("Number of lexically analyzed documents: %d\n", argc - 1);
    
//     if(argc < 2)
//     {
//         //yylex();
//         printf("Done\n");
//         return 0;
//     }
//     for(i = 1; i < argc; i ++)
//     {
//         FILE *f = fopen(argv[i], "r");
//         if(!f)
//         {
//             perror(argv[i]);
//             return 1;
//         }
//         yylineno = 1;
//         printf("%-8s \t %s\n", "label", "value");
//         yyrestart(f);
//         yyparse();
//         //yylex();
//         fclose(f);
//         fflush(stdout);             // 确保缓冲区数据写入文件
//         dup2(stdout_fd, fileno(stdout)); // 恢复标准输出
//         close(stdout_fd);           // 关闭保存的描述符

//         printf("Total wrongs: %d\n", wrongs);
//         int j;
//         for(j = 0; j < wrongs; j ++)
//         {
//             printf("%s", wrong_info[j]);
//         }
//         printf("\nDone %d file\n", i);
//     }
//     if(argc > 1)
//         puts("ALL FINISH");
//     return 0;
// }