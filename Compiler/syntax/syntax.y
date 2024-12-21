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
%type <node> ExtDecList
%type <node> Bool_Expr Add_Expr
%type <node> term factor
%type <node> MainDec FunDec FunBody
%type <node> StatList DecList DefList Dec Def VarList
%type <node> Statements Expr
%type <node> IfStat ElseStat WhileStat ForStat WriteStat ReadStat CompoundStat ExprStat VarDec CallStat 
%type <node> Specifier StructSpecifier Tag OptTag



// precedence and associativity

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS STAR DIV
%right NOT
%left LB RB LP RP 
%nonassoc ELSE

%%
// Dec
Program:                CodeDec                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Program", 1, $1); root = $$; }                                                                           
    ;
CodeDec:                Specifier MainDec                                       {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 2, $1, $2); }
    |                   Specifier FunDec CodeDec                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 3, $1, $2, $3); }
    |                   Specifier ExtDecList SEMI CodeDec                       {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 4, $1, $2, $3, $4); }
    |                   Specifier SEMI CodeDec                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 3, $1, $2, $3); }
    |                   error CodeDec                                           {synError = TRUE;  fprintf(stderr, "Functions need to declare types\n");}
    ;
MainDec:                MAIN LP VarList RP FunBody                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 5, $1, $2, $3, $4, $5); }
    |                   MAIN LP RP FunBody                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 4, $1, $2, $3, $4); } 
    ;   
FunDec:                 ID LP VarList RP FunBody                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 5, $1, $2, $3, $4, $5); }             
    |                   ID LP RP FunBody                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 4, $1, $2, $3, $4); }             
    ;
VarList:                Specifier VarDec                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 2, $1, $2); }             
    |                   Specifier VarDec COMMA VarList                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 4, $1, $2, $3, $4); }             
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
    |                   ID error                                                {synError = TRUE;}
    |                   VarDec LB error RB                                      {synError = TRUE;  fprintf(stderr, "Integer declarations are required in square brackets\n");}
    ;   


//stat
StatList:               Statements StatList                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "StatList", 2, $1, $2);   }  
    |                                                                           {$$ = NULL;}
    ;
Statements:             IfStat                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }      
    |                   WhileStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   ForStat                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   ReadStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   WriteStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   CompoundStat                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   ExprStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   CallStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
    |                   RETURN Expr SEMI/*RETUN*/                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 3, $1, $2, $3);}  
    ;       
IfStat:                 IF LP Expr RP Statements ElseStat                       {$$ = createNode(@$.first_line, NOT_A_TOKEN, "IfStat", 6, $1, $2, $3, $4, $5, $6);   }  
    |                   IF LP Expr RP Statements                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "IfStat", 5, $1, $2, $3, $4, $5);   }  
    ;       
ElseStat:               ELSE Statements                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ElseStat", 2, $1, $2);   }      
    ;
WhileStat:              WHILE LP Expr RP Statements                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "WhileStat", 5, $1, $2, $3, $4, $5);   }  
    ;
ForStat:                FOR LP Expr SEMI Expr SEMI Expr RP Statements           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ForStat", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);   }      
    ;
WriteStat:              WRITE Expr                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "WriteStat", 2, $1, $2);   }  
    ;
ReadStat:               READ ID                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ReadStat", 2, $1, $2);   }      
    ;
CompoundStat:           LC StatList RC                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CompoundStat", 3, $1, $2, $3);   }  
    |                   error RC                                                {synError = TRUE;}
    ;
ExprStat:               Expr SEMI                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExprStat", 2, $1, $2);   }  
    |                   SEMI                                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExprStat", 1, $1);   }  
    |                   error SEMI                                              {synError = TRUE;}
    |                   Expr error                                              {synError = TRUE; fprintf(stderr, "Statements need to end with a semicolon\n");}
    ;
CallStat:               CALL ID LP RP                                           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CallStat", 4, $1, $2, $3, $4);   }  
    |                   error RP                                                {synError = TRUE; }
    ;
//factor
Expr:                   ID ASSIGNOP Bool_Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }  
    |                   Bool_Expr                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 1, $1);   }   
    ;
Bool_Expr:              Add_Expr                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 1, $1);   }  
    |                   Add_Expr RELOP Add_Expr                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   } 
    |                   Add_Expr AND Add_Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }
    |                   Add_Expr OR Add_Expr                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }
    |                   NOT Add_Expr                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 2, $1, $2);   }
    ;
Add_Expr:               term                                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 1, $1);   }  
    |                   Add_Expr PLUS term                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 3, $1, $2, $3);   }  
    |                   Add_Expr MINUS term                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 3, $1, $2, $3);   }  
    ;
term:                   factor                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 1, $1);   }  
    |                   term STAR factor                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 3, $1, $2, $3);   }  
    |                   term DIV factor                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 3, $1, $2, $3);   }  
    ;
factor:                 LP Add_Expr RP                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 3, $1, $2, $3);   }  
    |                   ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 1, $1);   }  
    |                   INT                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 1, $1);   } 
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




