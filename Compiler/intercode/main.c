#include "node.h"
#include "inter.h"
#include "syntax.tab.h"
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
    FILE* fs = fopen(argv[1], "r");
    if(!fs)
    {
        perror(argv[1]);
        return 1;
    }

    FILE* fm = fopen(argv[2], "wt+");
    if(!fm)
    {
        perror(argv[2]);
        return 1;
    }

    //yydebug = 1;
    yyrestart(fs);
    yyparse();

    if(!lexError && !synError)
    {
        table = initTable();
        printTreeInfo(root, 0); //递归打印节点      
        traverseTree(root);

        interCodeList = newInterCodeList();
        
        if(!semErrors)
        {
            printTable(table);
            genInterCodes(root);
            if(!interError) printInterCode(fm, interCodeList);
        }

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