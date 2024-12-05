%{
    #include "node.h"  
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"

    int yyerror(char *msg){
        fprintf(stderr, "Error at line %d: %s", yylineno, msg);
    }
    
    #define YYERROR_VERBOSE 1
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

%type <node> Program 
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
Program:                MainDec                                                 {$$ = createNode(@$.first_line); printf("create Program\n");}
    |                   FunDec Program                                          {$$ = createNode(@$.first_line); printf("create EProgramxpr\n");}
    ;
MainDec:                MAIN LP RP FunBody                                      {$$ = createNode(@$.first_line); printf("create MainDec\n");}
    ;   
FunDec:                 ID LP RP FunBody                                        {$$ = createNode(@$.first_line); printf("create FunDec\n");}             
    ;
VarDec:                 INT ID SEMI                                                 {$$ = createNode(@$.first_line); printf("create VarDec\n");}
    ;   
FunBody:                LC DecList StatList RC                                  {$$ = createNode(@$.first_line); printf("create FunBody\n");}
    ;
 
 //list
DecList:                VarDec DecList                                          {$$ = createNode(@$.first_line); printf("create DecList\n");}
    |                                                                           {$$ = createNode(@$.first_line); printf("create DecList\n");}
    ;
StatList:               StatList Statements                                     {$$ = createNode(@$.first_line); printf("create StatList\n");}
    |                                                                           {$$ = createNode(@$.first_line); printf("create StatList\n");}
    ;
//stat
Statements:             IfStat                                                  {$$ = createNode(@$.first_line); printf("create Statements\n");}    
    |                   WhileStat                                               {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   ForStat                                                 {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   ReadStat                                                {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   WriteStat                                               {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   CompoundStat                                            {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   ExprStat                                                {$$ = createNode(@$.first_line); printf("create Statements\n");}
    |                   CallStat                                                {$$ = createNode(@$.first_line); printf("create Statements\n");}
    ;               
IfStat:                 IF LP Expr RP Statements ElseStat                       {$$ = createNode(@$.first_line); printf("create IfStat\n");}
    |                   IF LP Expr RP Statements                                {$$ = createNode(@$.first_line); printf("create IfStat\n");}
    ;       
ElseStat:               ELSE Statements                                         {$$ = createNode(@$.first_line); printf("create ElseStat\n");}    
    ;
WhileStat:              WHILE LP Expr RP Statements                             {$$ = createNode(@$.first_line); printf("create WhileStat\n");}
    ;
ForStat:                FOR LP Expr SEMI Expr SEMI Expr RP Statements           {$$ = createNode(@$.first_line); printf("create ForStat\n");}    
    ;
WriteStat:              WRITE Expr                                              {$$ = createNode(@$.first_line); printf("create WriteStat\n");}
    ;
ReadStat:               READ ID                                                 {$$ = createNode(@$.first_line); printf("create ReadStat\n");}    
    ;
CompoundStat:           LC Statements RC                                        {$$ = createNode(@$.first_line); printf("create CompoundStat\n");}
    ;
ExprStat:               Expr SEMI                                               {$$ = createNode(@$.first_line); printf("create ExprStat\n");}
    |                   SEMI                                                    {$$ = createNode(@$.first_line); printf("create ExprStat\n");}
    ;
CallStat:               CALL ID LP RP                                           {$$ = createNode(@$.first_line); printf("create CallStat\n");}
    ;

Expr:                   ID ASSIGNOP Bool_Expr                                   {$$ = createNode(@$.first_line); printf("create Expr\n");}
    |                   Bool_Expr                                               {$$ = createNode(@$.first_line); printf("create Expr\n");}
    ;

Bool_Expr:              Add_Expr                                                {$$ = createNode(@$.first_line); printf("create Bool_Expr\n");}
    |                   Add_Expr RELOP Add_Expr                                 {$$ = createNode(@$.first_line); printf("create Bool_Expr\n");}
    ;

Add_Expr:               term                                                    {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    |                   Add_Expr PLUS term                                      {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    |                   Add_Expr MINUS term                                     {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    ;

term:                   factor                                                  {$$ = createNode(@$.first_line); printf("create term\n");}
    |                   term STAR factor                                        {$$ = createNode(@$.first_line); printf("create term\n");}
    |                   term DIV factor                                         {$$ = createNode(@$.first_line); printf("create term\n");}
    ;

factor:                 LP Add_Expr RP                                          {$$ = createNode(@$.first_line); printf("create factor\n");}
    |                   ID                                                      {$$ = createNode(@$.first_line); printf("create factor\n");}
    |                   NUM                                                     {$$ = createNode(@$.first_line); printf("create factor\n");}
    ;
%%
