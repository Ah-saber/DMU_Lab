#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

#include "type.h"


#define TRUE 1
#define FALSE 0

typedef struct node{
    int lineNo;  //输出行
    NodeType type; //node type 
    char* name;
    char* val;

    struct node* child;
    struct node* brother;

}Node;

typedef Node* pNode;

//deep copy , keep origin string
static inline char* newString(char* origin){
    if(origin == NULL ) return NULL;
    int length = strlen(origin) + 1;

    char* p = (char*)malloc(sizeof(char) * length);
    assert(p != NULL);
    strncpy(p, origin, length);
    return p;
}

static inline pNode createNode(int lineNo, NodeType type, 
                char* name, int argc, ...){
    pNode curNode = NULL;
    curNode = (pNode)malloc(sizeof(Node));

    assert(curNode != NULL);

    curNode->lineNo = lineNo;
    curNode->type = type;
    curNode->name = newString(name);

    va_list valist;
    va_start(valist, argc); //point the first val

    pNode tempNode = va_arg(valist, pNode); //get a arg

    curNode->child = tempNode;
    //if(tempNode == NULL) return curNode;
    int i;

    for(i = 1; i < argc; i ++)
    {
        tempNode->brother = va_arg(valist, pNode);
        if(tempNode->brother != NULL)
        {
            tempNode = tempNode->brother;
        }
    }

    va_end(valist);
    return curNode;
}

//leaves
static inline pNode createToken(int lineNo, NodeType type, char* name, char* value)
{
    pNode tokenNode = (pNode)malloc(sizeof(Node));

    assert(tokenNode != NULL);

    tokenNode->lineNo = lineNo;
    tokenNode->type = type;

    tokenNode->name = newString(name);
    tokenNode->val = newString(value);

    tokenNode->child = NULL;
    tokenNode->brother = NULL;

    return tokenNode;
}

static inline void delNode(pNode* node){
    if (node == NULL) return ;
    pNode p = *node;
    while(p->child != NULL)
    {
        pNode tmp = p->child;
        p->child = p->child->brother;
        delNode(&tmp);
    }
    //release
    free(p->name);
    free(p->val);
    free(p);

    p = NULL;
}

static inline void printTreeInfo(pNode curNode, int height)
{
    if(curNode == NULL){
        return;
    }

    int i;
    for(i = 0; i < height; i ++)
    {
        printf("  ");
    }

    printf("%s", curNode->name);
    if(curNode->type == NOT_A_TOKEN)
    {
        printf("  (%d)", curNode->lineNo);
    }
    else if(curNode->type == TOKEN_INT || curNode->type == TOKEN_ID || curNode->type == TOKEN_CHAR)
    {
        printf(":  %s", curNode->val);
    }
    
    puts("");
    printTreeInfo(curNode->child, height + 1);
    printTreeInfo(curNode->brother, height);
}

#endif
