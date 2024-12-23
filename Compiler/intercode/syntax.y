%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "lex.yy.c"
    #include "node.h"
    extern bool synError;
    extern char **errors;

    int error_count = 0;
    int synbuff = 100;
    char **errors;
    pNode root = NULL;
    char *errors_msg = NULL;
    #define YYERROR_VERBOSE 1
    
    int yyerror(const char* msg){
        synError = TRUE;
        if(errors_msg != NULL)
        {
            fprintf(stderr, "Error type B at line %d: %s", yylineno, errors_msg);
            errors_msg = NULL;
        }
        else fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
    }
    
    //#define YYDEBUG 1

%}
%define parse.error detailed

// declared types
%union {
    pNode node;
}


// tokens

%token <node> INT 
%token <node> ID TYPE
%token <node> COMMA
%token <node> DOT
%token <node> SEMI
%token <node> RELOP
%token <node> ASSIGNOP
%token <node> PLUS MINUS STAR DIV
%token <node> AND OR NOT 
%token <node> LP RP LB RB LC RC
%token <node> IF
%token <node> ELSE
%token <node> WHILE
%token <node> FOR
%token <node> STRUCT
%token <node> RETURN
%token <node> WRITE READ CALL
%token <node> MAIN 


// non terminals

%type <node> Program CodeDec 
%type <node> ExtDecList ExtDefList ParamDec
%type <node> Args
%type <node> MainDec FunDec FunBody
%type <node> StatList DecList DefList Dec Def VarList 
%type <node> Statements Expr
%type <node> VarDec
%type <node> Specifier StructSpecifier Tag OptTag



// precedence and associativity

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left DOT
%left LB RB
%left LP RP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%
// Dec
Program:                ExtDefList                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Program", 1, $1); root = $$; }                                                                           
    ;
ExtDefList:             CodeDec ExtDefList                                      { $$ = createNode(@$.first_line, NOT_A_TOKEN, "ExtDefList", 2, $1, $2);}
    |                   MainDec                                                 { $$ = createNode(@$.first_line, NOT_A_TOKEN, "ExtDefList", 1, $1);}
    //|                   error                                                   {synError = TRUE;  fprintf(stderr, "Need main function\n");}
    ;
CodeDec:                Specifier FunDec FunBody                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 3, $1, $2, $3); }
    |                   Specifier ExtDecList SEMI                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 3, $1, $2, $3); }
    |                   Specifier SEMI                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 2, $1, $2); }
    |                   error SEMI                                              { synError = TRUE; }
    ;                                                     
MainDec:                Specifier MAIN LP VarList RP FunBody                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 6, $1, $2, $3, $4, $5, $6); }
    |                   Specifier MAIN LP RP FunBody                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 5, $1, $2, $3, $4, $5); } 
    ;   
FunDec:                 ID LP VarList RP                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 4, $1, $2, $3, $4); }             
    |                   ID LP RP                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 3, $1, $2, $3); }             
    |                   error RP                                                {synError = TRUE; }
    ;
VarList:                ParamDec                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "VarList", 1, $1); }             
    |                   ParamDec COMMA VarList                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "VarList", 3, $1, $2, $3); }             
    ;
ParamDec:               Specifier VarDec                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ParamDec", 2, $1, $2); }             
    ;
ExtDecList:             VarDec                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExtDecList", 1, $1); }
    |                   VarDec COMMA ExtDecList                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExtDecList", 3, $1, $2, $3); }
    ;
FunBody:                LC DefList StatList RC                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunBody", 4, $1, $2, $3, $4);  }
    |                   error RC                                                {synError = TRUE;  }
    ;
//Specifier
Specifier:              TYPE                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Specifier", 1, $1);  }
    |                   StructSpecifier                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Specifier", 1, $1);  }
    ;   
StructSpecifier:        STRUCT OptTag LC DefList RC                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "StructSpecifier", 5, $1, $2, $3, $4, $5);  }
    |                   STRUCT Tag                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "StructSpecifier", 2, $1, $2);  }
    ;
OptTag:                 ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "OptTag", 1, $1);  }
    |                                                                           {$$ = NULL ;}
    ;   
Tag:                    ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Tag", 1, $1);  }
    ;
 
 //list
DefList:                Def DefList                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "DefList", 2, $1, $2);}  
    |                                                                           {$$ = NULL; }
    ;
Def:                    Specifier DecList SEMI                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Def", 3, $1, $2, $3);  }
    ;   
DecList:                Dec                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "DecList", 1, $1);  }
    |                   Dec COMMA DecList                                       {$$ = createNode(@$.first_line, NOT_A_TOKEN, "DecList", 3, $1, $2, $3);  }
    ;
Dec:                    VarDec                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Dec", 1, $1);  }
    |                   VarDec ASSIGNOP Expr/*定义赋值*/                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Dec", 3, $1, $2, $3);  }
    ;
VarDec:                 ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "VarDec", 1, $1); }
    |                   VarDec LB INT RB/*数组*/                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "VarDec", 4, $1, $2, $3, $4);  }
    |                   error RB                                      {synError = TRUE;  fprintf(stderr, "Integer declarations are required in square brackets\n");}
    ;   


//stat
StatList:               Statements StatList                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "StatList", 2, $1, $2);   }  
    |                                                                           {$$ = NULL;}
    ;
Statements:             IF LP Expr RP Statements  %prec LOWER_THAN_ELSE         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 5, $1, $2, $3, $4, $5);   }  
    |                   IF LP Expr RP Statements ELSE Statements                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 7, $1, $2, $3, $4, $5, $6, $7);   }        
    |                   WHILE LP Expr RP Statements                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 5, $1, $2, $3, $4, $5);   }  
    |                   FOR LP Expr SEMI Expr SEMI Expr RP Statements           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);   }      
    |                   READ ID SEMI                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 2, $1, $2, $3);   } 
    |                   WRITE Expr SEMI                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 3, $1, $2, $3);   }  
    |                   FunBody                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   Expr SEMI                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   RETURN Expr SEMI/*RETUN*/                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 3, $1, $2, $3);}  
    |                   error SEMI                                               {synError = TRUE;}
    ;       
Expr:                   Expr ASSIGNOP Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   ID LP Args RP                                           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 4, $1, $2, $3, $4);   }   
    |                   ID LP RP                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }   
    |                   Expr DOT ID                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }   
    |                   Expr LB Expr RB                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 4, $1, $2, $3, $4);   }   
    |                   NOT Expr                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 2, $1, $2);   }
    |                   MINUS Expr                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 2, $1, $2);   }
    |                   LP Expr RP                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }   
    |                   Expr RELOP Expr                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   } 
    |                   Expr AND Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }
    |                   Expr OR Expr                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }
    |                   Expr PLUS Expr                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   Expr MINUS Expr                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   Expr STAR Expr                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   Expr DIV Expr                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 1, $1);   }  
    |                   INT                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 1, $1);   } 
    ;
Args :                  Expr COMMA Args                                         { $$ = createNode(@$.first_line, NOT_A_TOKEN, "Args", 3, $1, $2, $3); }
    |                   Expr                                                    { $$ = createNode(@$.first_line, NOT_A_TOKEN, "Args", 1, $1); }
    ; 
%%


// void yyreport_syntax_errors(void) {
//         if (yychar == YYEMPTY) {
//             // 如果没有 token 被输入，输出错误信息
//             fprintf(stderr, "Syntax error: unexpected end of input.\n");
//         } else {
//             // 打印当前 token 的错误信息
//             printf("%d\n", yychar);
//             fprintf(stderr, "Syntax error: unexpected token '%s'.\n", yytname[yychar - 255]); //255是FIRST_TOKEN, yychar是lookahead token

//             // 输出期望的符号
//             if (YYNTOKENS > 0) {
//                 fprintf(stderr, "Expecting: ");
//                 for (int i = 0; i < YYNTOKENS; i++) {
//                     if (yycheck[i + yystate] == yystate) {
//                         fprintf(stderr, "%s ", yytname[i]);
//                     }
//                 }
//                 fprintf(stderr, "\n");
//             }
//         }
// }




