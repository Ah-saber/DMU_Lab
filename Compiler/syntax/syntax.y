%{
    #include "node.h"  
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    
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
%token <node> WRITE READ

// non terminals

%type <node> Program 
%type <node> Bool_Expr Add_Expr
%type <node> term factor

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
Program:                ID ASSIGNOP Bool_Expr                       {$$ = createNode(@$.first_line); printf("create Program\n");}
    |                   Bool_Expr                                   {$$ = createNode(@$.first_line); printf("create Program\n");}
    ;

Bool_Expr:              Add_Expr                                    {$$ = createNode(@$.first_line); printf("create Bool_Expr\n");}
    |                   Add_Expr RELOP Add_Expr                     {$$ = createNode(@$.first_line); printf("create Bool_Expr\n");}
    ;

Add_Expr:               term                                        {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    |                   Add_Expr PLUS term                          {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    |                   Add_Expr MINUS term                         {$$ = createNode(@$.first_line); printf("create Add_Expr\n");}
    ;

term:                   factor                                      {$$ = createNode(@$.first_line); printf("create term\n");}
    |                   term STAR factor                            {$$ = createNode(@$.first_line); printf("create term\n");}
    |                   term DIV factor                             {$$ = createNode(@$.first_line); printf("create term\n");}
    ;

factor:                 LP Add_Expr RP                              {$$ = createNode(@$.first_line); printf("create factor\n");}
    |                   ID                                          {$$ = createNode(@$.first_line); printf("create factor\n");}
    |                   NUM                                         {$$ = createNode(@$.first_line); printf("create factor\n");}
    ;
%%

int yyerror(char *msg){
    fprintf(stderr, "Error at line %d: %s", yylineno, msg);
}