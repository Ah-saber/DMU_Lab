#ifndef SEMANTIC_H
#define SEMENTIC_H

#define HASH_TABLE_SIZE 0x3fff
#define STACK_DEEP

#include "node.h"

typedef struct type* pType;
typedef struct fieldList* pFieldList;
typedef struct tableItem* pItem;
typedef struct hashTable* pHash;
typedef struct stack* pStack;
typedef struct table* pTable;

typedef struct type {
    Kind kind; //记录什么类型
    union {
        // 基本类型
        BasicType basic;
        // 数组类型信息包括元素类型与数组大小构成
        struct {
            pType elem;
            int size;
        } array;
        // 结构体类型信息是一个链表
        struct {
            char* structName;
            pFieldList field;
        } structure;

        struct {
            int argc;          // argument counter
            pFieldList argv;   // argument vector
            pType returnType;  // returnTyper
        } function;
    } u;
} Type;

typedef struct fieldList {
    char* name;       // 域名(即Expr名)
    pType type;       // 类型
    bool isArg;       // 地址(传址)
    pFieldList tail;  // 下一个域
} FieldList;

typedef struct tableItem {
    int symbolDepth;
    pFieldList field;
    pItem nextSymbol;  // same depth next symbol, linked from stack
    pItem nextHash;    // same hash code next symbol, linked from hash table
} TableItem;

typedef struct hashTable {
    pItem* hashArray;
} HashTable;

typedef struct stack {
    pItem* stackArray;
    int curStackDepth;
} Stack;

typedef struct table {
    pHash hash;
    pStack stack;
    int unNamedStructNum;
    // int enterStructLayer;
} Table;

extern pTable table;

// Type functions
pType newType(Kind kind, ...);
pType copyType(pType src);
void deleteType(pType type);
bool checkType(pType type1, pType type2);
void printType(pType type);

// FieldList functions

// inline pFieldList newFieldList() {
//     pFieldList p = (pFieldList)malloc(sizeof(FieldList));
//     p->name = NULL;
//     p->type = NULL;
//     p->tail = NULL;
//     return p;
// }

pFieldList newFieldList(char* newName, pType newType);
pFieldList copyFieldList(pFieldList src);
void deleteFieldList(pFieldList fieldList);
void setFieldListName(pFieldList p, char* newName);
void printFieldList(pFieldList fieldList);

// tableItem functions

// inline pItem () {
//     pItem p = (pItem)malloc(sizeof(TableItem));
//     p->symbolDepth = 0;
//     p->field = NULL;
//     p->nextHash = NULL;
//     p->nextSymbol = NULL;
//     return p;
// }

pItem newItem(int symbolDepth, pFieldList pfield);
void deleteItem(pItem item);
bool isStructDef(pItem src);

// Hash functions
pHash newHash();
void deleteHash(pHash hash);
pItem getHashHead(pHash hash, int index);
void setHashHead(pHash hash, int index, pItem newVal);

// Stack functions
pStack newStack();
void deleteStack(pStack stack);
void addStackDepth(pStack stack);
void minusStackDepth(pStack stack);
pItem getCurDepthStackHead(pStack stack);
void setCurDepthStackHead(pStack stack, pItem newVal);

// Table functions
pTable initTable();
void deleteTable(pTable table);
pItem searchTableItem(pTable table, char* name);
bool checkTableItemConflict(pTable table, pItem item);
void addTableItem(pTable table, pItem item);
void deleteTableItem(pTable table, pItem item);
void clearCurDepthStackList(pTable table);
// void addStructLayer(pTable table);
// void minusStructLayer(pTable table);
// boolean isInStructLayer(pTable table);
void printTable(pTable table);

//Global error_count
extern int semErrors;

// Global functions
//by P.J. Weinberger
static inline unsigned int getHashCode(char* name) {
    unsigned int val = 0, i; // 初始化哈希值和临时变量
    for (; *name; ++name) { // 遍历字符串中的每个字符
        val = (val << 2) + *name; // 左移2位并加上当前字符的ASCII值
        if (i = val & ~HASH_TABLE_SIZE) // 检查超出哈希表大小的高位
            val = (val ^ (i >> 12)) & HASH_TABLE_SIZE; // 将高位的影响反馈并清除高位
    }
    return val; // 返回最终的哈希值
}


static inline void pError(ErrorType type, int line, char* msg) {
    printf("Error type %d at Line %d: %s\n", type, line, msg);
    semErrors ++;
}

void traverseTree(pNode node);

// Generate symbol table functions
void ExtDefList(pNode node);
void CodeDec(pNode node);
void MainDec(pNode node);
void ExtDecList(pNode node, pType specifier);
pType Specifier(pNode node);
pType StructSpecifier(pNode node);
pItem VarDec(pNode node, pType specifier);
void FunDec(pNode node, pType returnType);
void VarList(pNode node, pItem func);
pFieldList ParamDec(pNode node);
void FunBody(pNode node, pType returnType, char* funcname);
void CompoundStat(pNode node, pType returnType);
void StatList(pNode node, pType returnType);
void Statements(pNode node, pType returnType);
void DefList(pNode node, pItem structInfo);
void Def(pNode node, pItem structInfo);
void DecList(pNode node, pType specifier, pItem structInfo);
void Dec(pNode node, pType specifier, pItem structInfo);
pType Expr(pNode node);
void Args(pNode node, pItem funcInfo);

#endif