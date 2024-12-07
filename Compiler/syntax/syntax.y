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
    int yyerror(char *msg){
        synError = TRUE;
        if(error_count == 0) errors = (char**)malloc(sizeof(char *)*100);
        if(error_count >= synbuff)
        {
            synbuff += 100;
            errors = realloc(errors, synbuff * sizeof(char));
        }
        errors[error_count] = malloc(256 * sizeof(char));
        snprintf(errors[error_count], 256, "Error at line %d: %s\n", yylineno, msg);
        error_count ++;
    }
    // int yyerror(char* msg){
    //     fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
    // }
    #define YYERROR_VERBOSE 1
    //#define YYDEBUG 1

%}

// declared types
%union {
    pNode node;
}


// tokens

%token <node> INT
%token <node> ID NUM
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
%type <node> Bool_Expr Add_Expr
%type <node> term factor
%type <node> MainDec FunDec FunBody
%type <node> StatList DecList 
%type <node> Statements Expr
%type <node> IfStat ElseStat WhileStat ForStat WriteStat ReadStat CompoundStat ExprStat VarDec CallStat



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
Program:                CodeDec                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Program", 1, $1); root = $$;}                                                                           
    ;
CodeDec:                MainDec                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 1, $1);}
    |                   FunDec CodeDec                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 2, $1, $2); }
    ;
MainDec:                MAIN LP RP FunBody                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 4, $1, $2, $3, $4); }
    ;   
FunDec:                 ID LP RP FunBody                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunDec", 4, $1, $2, $3, $4); }             
    //|                   error FunDec                                            {synError = TRUE;}  
    ;
VarDec:                 INT ID SEMI                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "VarDec", 3, $1, $2, $3);}
    |                   INT ID error
    ;   
FunBody:                LC DecList StatList RC                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunBody", 4, $1, $2, $3, $4); }
    |                   error RC                                                {synError = TRUE; }
    ;
 
 //list
DecList:                VarDec DecList                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "DecList", 2, $1, $2); }  
    |                                                                           {$$ = NULL; }
    ;
StatList:               Statements StatList                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "StatList", 2, $1, $2); }  
    |                                                                           {$$ = NULL;}
    ;
//stat
Statements:             IfStat                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }      
    |                   WhileStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   ForStat                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   ReadStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   WriteStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   CompoundStat                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   ExprStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    |                   CallStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1); }  
    ;               
IfStat:                 IF LP Expr RP Statements ElseStat                       {$$ = createNode(@$.first_line, NOT_A_TOKEN, "IfStat", 6, $1, $2, $3, $4, $5, $6); }  
    |                   IF LP Expr RP Statements                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "IfStat", 5, $1, $2, $3, $4, $5); }  
    ;       
ElseStat:               ELSE Statements                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ElseStat", 2, $1, $2); }      
    ;
WhileStat:              WHILE LP Expr RP Statements                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "WhileStat", 5, $1, $2, $3, $4, $5); }  
    ;
ForStat:                FOR LP Expr SEMI Expr SEMI Expr RP Statements           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ForStat", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9); }      
    ;
WriteStat:              WRITE Expr                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "WriteStat", 2, $1, $2); }  
    ;
ReadStat:               READ ID                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ReadStat", 2, $1, $2); }      
    ;
CompoundStat:           LC StatList RC                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CompoundStat", 3, $1, $2, $3); }  
    |                   error RC                                                {synError = TRUE;}
    ;
ExprStat:               Expr SEMI                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExprStat", 2, $1, $2); }  
    |                   SEMI                                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "ExprStat", 1, $1); }  
    |                   error SEMI                                              {synError = TRUE;}
    ;
CallStat:               CALL ID LP RP                                           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CallStat", 4, $1, $2, $3, $4); }  
    |                   error RP                                                {synError = TRUE;}
    ;
//factor
Expr:                   ID ASSIGNOP Bool_Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3); }  
    |                   Bool_Expr                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 1, $1); }   
    ;
Bool_Expr:              Add_Expr                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 1, $1); }  
    |                   Add_Expr RELOP Add_Expr                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3); }  
    ;
Add_Expr:               term                                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 1, $1); }  
    |                   Add_Expr PLUS term                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 3, $1, $2, $3); }  
    |                   Add_Expr MINUS term                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Add_Expr", 3, $1, $2, $3); }  
    ;
term:                   factor                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 1, $1); }  
    |                   term STAR factor                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 3, $1, $2, $3); }  
    |                   term DIV factor                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "term", 3, $1, $2, $3); }  
    ;
factor:                 LP Add_Expr RP                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 3, $1, $2, $3); }  
    |                   ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 1, $1); }  
    |                   NUM                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "factor", 1, $1); }  
    ;
%%
