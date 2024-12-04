#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>


typedef struct node{
    int lineNo;
}Node;

typedef Node* pNode;

static inline pNode createNode(int lineNo){
    pNode curNode = NULL;
    curNode = (pNode)malloc(sizeof(Node));

    curNode->lineNo = lineNo;

    return curNode;
}



#endif
