%{
    #include "lex.yy.c"
%}


%token INT
%token if
%token while


%%

/*rule*/
EXPR: 
    | INT {printf("find expr");}
    ;
KEY:
    | while {printf("find key");}
    ;

%%
/*main*/
