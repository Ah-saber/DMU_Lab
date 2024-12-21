%option yylineno
%{
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h> 
    #include <stdbool.h>
    #include "node.h" 
    #include "syntax.tab.h"
   
    int tmp = 0;
    int yycolumn = 1;
    #define YY_USER_ACTION \
        yylloc.first_line=yylloc.last_line=yylineno; \
        yylloc.first_column=yycolumn; \
        yylloc.last_column=yycolumn+yyleng-1; \
        yycolumn+=yyleng;
    
    extern bool lexError;

    int nums = 0;
    int ids = 0;
    int doublewords = 0;
    int singlewords = 0;
    int keys = 0;
    int wrongs = 0;
    int comments = 0;
    int buff = 100;
    char **wrong_info;
    
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
FLOAT [fF][lL][oO][aA][tT]
MAIN [mM][aA][iI][nN]
RETURN [rR][eE][tT][uU][rR][nN]
STRUCT [sS][tT][rR][uU][cC][tT]

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
INT 0|[1-9]{digit}*
NOTID {digit}*{ID}
IGNORE [ \t\r\n] 
TYPE [iI][nN][tT]
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


{RELOP} {yylval.node = createToken(yylineno, TOKEN_OTHER, "RELOP", yytext); return RELOP;}
{IF} { yylval.node = createToken(yylineno, TOKEN_OTHER, "IF", yytext); return IF; }
{ELSE} { yylval.node = createToken(yylineno, TOKEN_OTHER, "ELSE", yytext); return ELSE; }
{FOR} { yylval.node = createToken(yylineno, TOKEN_OTHER, "FOR", yytext); return FOR; }
{WHILE} { yylval.node = createToken(yylineno, TOKEN_OTHER, "WHILE", yytext); return WHILE; }
{WRITE} { yylval.node = createToken(yylineno, TOKEN_OTHER, "WRITE", yytext); return WRITE; }
{READ} { yylval.node = createToken(yylineno, TOKEN_OTHER, "READ", yytext); return READ; }
{MAIN} { yylval.node = createToken(yylineno, TOKEN_OTHER, "MAIN", yytext); return MAIN; }
{CALL} { yylval.node = createToken(yylineno, TOKEN_OTHER, "CALL", yytext); return CALL; }
{RETURN} { yylval.node = createToken(yylineno, TOKEN_OTHER, "RETURN", yytext); return RETURN; }
{STRUCT} { yylval.node = createToken(yylineno, TOKEN_OTHER, "STRUCT", yytext); return STRUCT; }
{TYPE} { yylval.node = createToken(yylineno, TOKEN_TYPE, "TYPE", yytext); return TYPE; }

{ID} { yylval.node = createToken(yylineno, TOKEN_ID, "ID", yytext); return ID; }
{INT} { yylval.node = createToken(yylineno, TOKEN_INT, "INT", yytext); return INT; }

{PLUS} { yylval.node = createToken(yylineno, TOKEN_CHAR, "PLUS", yytext); return PLUS; }
{MINUS} { yylval.node = createToken(yylineno, TOKEN_CHAR, "MINUS", yytext); return MINUS; }
{STAR} { yylval.node = createToken(yylineno, TOKEN_CHAR, "STAR", yytext); return STAR; }
{DIV} { yylval.node = createToken(yylineno, TOKEN_CHAR, "DIV", yytext); return DIV; }
{AND} { yylval.node = createToken(yylineno, TOKEN_CHAR, "AND", yytext); return AND; }
{OR} { yylval.node = createToken(yylineno, TOKEN_CHAR, "OR", yytext); return OR; }
{NOT} { yylval.node = createToken(yylineno, TOKEN_CHAR, "NOT", yytext); return NOT; }
{DOT} { yylval.node = createToken(yylineno, TOKEN_CHAR, "DOT", yytext); return DOT; }
{SEMI} { yylval.node = createToken(yylineno, TOKEN_CHAR, "SEMI", yytext); return SEMI; }
{COMMA} { yylval.node = createToken(yylineno, TOKEN_CHAR, "COMMA", yytext); return COMMA; }
{ASSIGNOP} { yylval.node = createToken(yylineno, TOKEN_CHAR, "ASSIGNOP", yytext); return ASSIGNOP; }

{LP} { yylval.node = createToken(yylineno, TOKEN_CHAR, "LP", yytext); return LP; }
{RP} { yylval.node = createToken(yylineno, TOKEN_CHAR, "RP", yytext); return RP; }
{LB} { yylval.node = createToken(yylineno, TOKEN_CHAR, "LB", yytext); return LB; }
{RB} { yylval.node = createToken(yylineno, TOKEN_CHAR, "RB", yytext); return RB; }
{LC} { yylval.node = createToken(yylineno, TOKEN_CHAR, "LC", yytext); return LC; }
{RC} { yylval.node = createToken(yylineno, TOKEN_CHAR, "RC", yytext); return RC; }


{IGNORE} { if(*yytext == '\n' || *yytext == '\r' ){ tmp ++; yycolumn = 1; /*列数复位*/ }}
{NOTID} {
    lexError = TRUE;
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
    lexError = TRUE;
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