#include "node.h"
#include "syntax.tab.h"
#include "semantic.h"
#include <stdbool.h>

extern pNode root;
extern int yylineno;
extern int yydebug;
extern int yyparse();
extern void yyrestart(FILE*);


unsigned lexError = FALSE;
unsigned synError = FALSE;


//errors
extern char** wrong_info;
extern int wrongs;
extern char** errors;
extern int yynerrs;



int main(int argc, char** argv)
{
    if(argc <= 1)
    {   
        yyparse();
        return 1;
    }
    FILE* f = fopen(argv[1], "r");

    if(!f)
    {
        perror(argv[1]);
        return 1;
    }

    //yydebug = 1;
    yyrestart(f);
    yyparse();

    if(!lexError && !synError)
    {
        table = initTable();
        printTreeInfo(root, 0); //递归打印节点      
        traverseTree(root);

        if(!semErrors) printTable(table);
        deleteTable(table);
        if(root != NULL) delNode(&root);
    }

    if(lexError)
    {
        printf("Total lex wrongs: %d\n", wrongs);
        int j;
        for(j = 0; j < wrongs; j ++)
        {
            printf("%s", wrong_info[j]);
        }
    }

    
    return 0;
}