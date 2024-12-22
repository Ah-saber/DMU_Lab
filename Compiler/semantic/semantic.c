#include "semantic.h"

pTable table;
int semErrors = 0;

// Type functions
pType newType(Kind kind, ...) {
    pType p = (pType)malloc(sizeof(Type));
    assert(p != NULL);
    p->kind = kind;
    va_list vaList;
    assert(kind == BASIC || kind == ARRAY || kind == STRUCTURE ||
           kind == FUNCTION);
    switch (kind) {
        case BASIC:
            va_start(vaList, 1);
            p->u.basic = va_arg(vaList, BasicType);
            break;
        case ARRAY:
            va_start(vaList, 2);
            p->u.array.elem = va_arg(vaList, pType);
            p->u.array.size = va_arg(vaList, int);
            break;
        case STRUCTURE:
            va_start(vaList, 2);
            p->u.structure.structName = va_arg(vaList, char*);
            p->u.structure.field = va_arg(vaList, pFieldList);
            break;
        case FUNCTION:
            va_start(vaList, 3);
            p->u.function.argc = va_arg(vaList, int);
            p->u.function.argv = va_arg(vaList, pFieldList);
            p->u.function.returnType = va_arg(vaList, pType);
            break;
    }
    va_end(vaList);
    return p;
}

pType copyType(pType src) {
    if (src == NULL) return NULL;
    pType p = (pType)malloc(sizeof(Type));
    assert(p != NULL);
    p->kind = src->kind;
    assert(p->kind == BASIC || p->kind == ARRAY || p->kind == STRUCTURE ||
           p->kind == FUNCTION);
    switch (p->kind) {
        case BASIC:
            p->u.basic = src->u.basic;
            break;
        case ARRAY:
            p->u.array.elem = copyType(src->u.array.elem);
            p->u.array.size = src->u.array.size;
            break;
        case STRUCTURE:
            p->u.structure.structName = newString(src->u.structure.structName);
            p->u.structure.field = copyFieldList(src->u.structure.field);
            break;
        case FUNCTION:
            p->u.function.argc = src->u.function.argc;
            p->u.function.argv = copyFieldList(src->u.function.argv);
            p->u.function.returnType = copyType(src->u.function.returnType);
            break;
    }

    return p;
}

void deleteType(pType type) {
    assert(type != NULL);
    assert(type->kind == BASIC || type->kind == ARRAY ||
           type->kind == STRUCTURE || type->kind == FUNCTION);
    pFieldList temp = NULL;
    // pFieldList tDelete = NULL;
    switch (type->kind) {
        case BASIC:
            break;
        case ARRAY:
            deleteType(type->u.array.elem);
            type->u.array.elem = NULL;
            break;
        case STRUCTURE:
            if (type->u.structure.structName)
                free(type->u.structure.structName);
            type->u.structure.structName = NULL;

            temp = type->u.structure.field;
            while (temp) {
                pFieldList tDelete = temp;
                temp = temp->tail;
                deleteFieldList(tDelete);
            }
            type->u.structure.field = NULL;
            break;
        case FUNCTION:
            deleteType(type->u.function.returnType);
            type->u.function.returnType = NULL;
            temp = type->u.function.argv;
            while (temp) {
                pFieldList tDelete = temp;
                temp = temp->tail;
                deleteFieldList(tDelete);
            }
            type->u.function.argv = NULL;
            break;
    }
    free(type);
}

bool checkType(pType type1, pType type2) {
    if (type1 == NULL || type2 == NULL) return TRUE;
    if (type1->kind == FUNCTION || type2->kind == FUNCTION) return FALSE;
    if (type1->kind != type2->kind)
        return FALSE;
    else {
        assert(type1->kind == BASIC || type1->kind == ARRAY ||
               type1->kind == STRUCTURE);
        switch (type1->kind) {
            case BASIC:
                return type1->u.basic == type2->u.basic;
            case ARRAY:
                return checkType(type1->u.array.elem, type2->u.array.elem);
            case STRUCTURE:
                return !strcmp(type1->u.structure.structName,
                               type2->u.structure.structName);
        }
    }
}

// void printType(pType type) {
//     if (type == NULL) {
//         printf("type is NULL.\n");
//     } else {
//         printf("type kind: %d\n", type->kind);
//         switch (type->kind) {
//             case BASIC:
//                 printf("type basic: %d\n", type->u.basic);
//                 break;
//             case ARRAY:
//                 printf("array size: %d\n", type->u.array.size);
//                 printType(type->u.array.elem);
//                 break;
//             case STRUCTURE:
//                 if (!type->u.structure.structName)
//                     printf("struct name: NULL\n");
//                 else {
//                     printf("struct name: %s\n", type->u.structure.structName);
//                 }
//                 printFieldList(type->u.structure.field);
//                 break;
//             case FUNCTION:
//                 printf("function argc: %d\n", type->u.function.argc);
//                 printf("function args:\n");
//                 printFieldList(type->u.function.argv);
//                 printf("return type:\n");
//                 printType(type->u.function.returnType);
//                 break;
//         }
//     }
// }

// FieldList functions
pFieldList newFieldList(char* newName, pType newType) {
    pFieldList p = (pFieldList)malloc(sizeof(FieldList));
    assert(p != NULL);
    p->name = newString(newName);
    p->type = newType;
    p->tail = NULL;
    return p;
}

pFieldList copyFieldList(pFieldList src) {
    assert(src != NULL);
    pFieldList head = NULL, cur = NULL;
    pFieldList temp = src;

    while (temp) {
        if (!head) {
            head = newFieldList(temp->name, copyType(temp->type));
            cur = head;
            temp = temp->tail;
        } else {
            cur->tail = newFieldList(temp->name, copyType(temp->type));
            cur = cur->tail;
            temp = temp->tail;
        }
    }
    return head;
}

void deleteFieldList(pFieldList fieldList) {
    assert(fieldList != NULL);
    if (fieldList->name) {
        free(fieldList->name);
        fieldList->name = NULL;
    }
    if (fieldList->type) deleteType(fieldList->type);
    fieldList->type = NULL;
    free(fieldList);
}

void setFieldListName(pFieldList p, char* newName) {
    assert(p != NULL && newName != NULL);
    if (p->name != NULL) {
        free(p->name);
    }
    // int length = strlen(newName) + 1;
    // p->name = (char*)malloc(sizeof(char) * length);
    // strncpy(p->name, newName, length);
    p->name = newString(newName);
}

// void printFieldList(pFieldList fieldList) {
//     if (fieldList == NULL)
//         printf("fieldList: NULL\n");
//     else {
//         printf("fieldList name: %s\n", fieldList->name);
//         printf("FieldList Type:\n");
//         printType(fieldList->type);
//         printFieldList(fieldList->tail);
//     }
// }

// tableItem functions
pItem newItem(int symbolDepth, pFieldList pfield) {
    pItem p = (pItem)malloc(sizeof(TableItem));
    assert(p != NULL);
    p->symbolDepth = symbolDepth;
    p->field = pfield;
    p->nextHash = NULL;
    p->nextSymbol = NULL;
    return p;
}

void deleteItem(pItem item) {
    assert(item != NULL);
    if (item->field != NULL) deleteFieldList(item->field);
    free(item);
}

// Hash functions
pHash newHash() {
    pHash p = (pHash)malloc(sizeof(HashTable));
    assert(p != NULL);
    p->hashArray = (pItem*)malloc(sizeof(pItem) * HASH_TABLE_SIZE);
    assert(p->hashArray != NULL);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        p->hashArray[i] = NULL;
    }
    return p;
}

void deleteHash(pHash hash) {
    assert(hash != NULL);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        pItem temp = hash->hashArray[i];
        while (temp) {
            pItem tdelete = temp;
            temp = temp->nextHash;
            deleteItem(tdelete);
        }
        hash->hashArray[i] = NULL;
    }
    free(hash->hashArray);
    hash->hashArray = NULL;
    free(hash);
}

pItem getHashHead(pHash hash, int index) {
    assert(hash != NULL);
    return hash->hashArray[index];
}

void setHashHead(pHash hash, int index, pItem newVal) {
    assert(hash != NULL);
    hash->hashArray[index] = newVal;
}
// Table functions

pTable initTable() {
    pTable table = (pTable)malloc(sizeof(Table));
    assert(table != NULL);
    table->hash = newHash();
    table->stack = newStack();
    table->unNamedStructNum = 0;
    return table;
};

void deleteTable(pTable table) {
    deleteHash(table->hash);
    table->hash = NULL;
    deleteStack(table->stack);
    table->stack = NULL;
    free(table);
};

pItem searchTableItem(pTable table, char* name) {
    unsigned hashCode = getHashCode(name);
    pItem temp = getHashHead(table->hash, hashCode);
    if (temp == NULL) return NULL;
    while (temp) {
        if (!strcmp(temp->field->name, name)) return temp;
        temp = temp->nextHash;
    }
    return NULL;
}

// Return false -> no confliction, true -> has confliction
bool checkTableItemConflict(pTable table, pItem item) {
    pItem temp = searchTableItem(table, item->field->name);
    if (temp == NULL) return FALSE;
    while (temp) {
        if (!strcmp(temp->field->name, item->field->name)) {
            if (temp->field->type->kind == STRUCTURE ||
                item->field->type->kind == STRUCTURE)
                return TRUE;
            if (temp->symbolDepth == table->stack->curStackDepth) return TRUE; //?
        }
        temp = temp->nextHash;
    }
    return FALSE;
}

void addTableItem(pTable table, pItem item) {
    assert(table != NULL && item != NULL);
    unsigned hashCode = getHashCode(item->field->name);
    pHash hash = table->hash;
    pStack stack = table->stack;
    // if (getCurDepthStackHead(stack) == NULL)
    //     setCurDepthStackHead(stack, item);
    // else {
    //     item->nextHash = getCurDepthStackHead(stack);
    //     setCurDepthStackHead(stack, item);
    // }
    item->nextSymbol = getCurDepthStackHead(stack);
    setCurDepthStackHead(stack, item);

    item->nextHash = getHashHead(hash, hashCode);
    setHashHead(hash, hashCode, item);
}

void deleteTableItem(pTable table, pItem item) {
    assert(table != NULL && item != NULL);
    unsigned hashCode = getHashCode(item->field->name);
    if (item == getHashHead(table->hash, hashCode))
        setHashHead(table->hash, hashCode, item->nextHash);
    else {
        pItem cur = getHashHead(table->hash, hashCode);
        pItem last = cur;
        while (cur != item) {
            last = cur;
            cur = cur->nextHash;
        }
        last->nextHash = cur->nextHash;
    }
    deleteItem(item);
}

bool isStructDef(pItem src) {
    if (src == NULL) return FALSE;
    if (src->field->type->kind != STRUCTURE) return FALSE;
    if (src->field->type->u.structure.structName) return FALSE;
    return TRUE;
}

// void addStructLayer(pTable table) { table->enterStructLayer++; }

// void minusStructLayer(pTable table) { table->enterStructLayer--; }

// bool isInStructLayer(pTable table) { return table->enterStructLayer > 0; }
//？？？？
void clearCurDepthStackList(pTable table) {
    assert(table != NULL);
    pStack stack = table->stack;
    pItem temp = getCurDepthStackHead(stack);
    while (temp) {
        pItem tDelete = temp;
        temp = temp->nextSymbol;
        deleteTableItem(table, tDelete);
    }
    setCurDepthStackHead(stack, NULL);
    minusStackDepth(stack);
}

// for Debug
void printTable(pTable table) {
    printf("==================================== Hash Table ====================================\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        pItem item = getHashHead(table->hash, i);
        if (item) {
            printf("\n-- Bucket [%d] --\n", i);
            while (item) {
                printf("  [Symbol Name]  : %s\n", item->field->name);
                printf("  [Symbol Depth] : %d\n", item->symbolDepth);
                printf("  -------------------- Field List --------------------\n");
                printFieldList(item->field);
                printf("  ------------------------------------------------------\n");
                item = item->nextHash;
            }
        }
    }
    printf("==================================== End of Hash Table ============================\n");
}

void printFieldList(pFieldList fieldList) {
    if (fieldList == NULL) {
        printf("    Field List: NULL\n");
    } else {
        printf("    Field Name     : %s\n", fieldList->name);
        printf("    Field Type: \n");
        printType(fieldList->type);
        printFieldList(fieldList->tail);
    }
}

void printType(pType type) {
    if (type == NULL) {
        printf("      Type: NULL\n");
    } else {
        printf("      Type Kind    : %d\n", type->kind);
        switch (type->kind) {
            case BASIC:
                printf("      [Basic Type] : %d\n", type->u.basic);
                break;
            case ARRAY:
                printf("      [Array]      : Size = %d\n", type->u.array.size);
                printf("      Array Element Type:\n");
                printType(type->u.array.elem);
                break;
            case STRUCTURE:
                if (!type->u.structure.structName) {
                    printf("      [Structure]  : Struct Name = NULL\n");
                } else {
                    printf("      [Structure]  : Struct Name = %s\n", type->u.structure.structName);
                }
                printf("    Fields as fllow:\n");
                printFieldList(type->u.structure.field);
                break;
            case FUNCTION:
                printf("      [Function]   : Arg Count = %d\n", type->u.function.argc);
                printf("    Arguments as fllow:\n");
                printFieldList(type->u.function.argv);
                printf("      Return Type:\n");
                printType(type->u.function.returnType);
                break;
        }
    }
}

void printFun(pTable table, char *funcname){
    assert(table != NULL);
    pStack stack = table->stack;
    printf("-------------------------------------- %s's ComStat Body -------------------------------------\n", funcname);
    pItem item = getCurDepthStackHead(stack);
        //printf("[%d]", i);
    printf("------------------FiledList---------------\n");
    while (item) {
        //printf(" -> name: %s depth: %d\n", item->field->name,
                //item->symbolDepth);  
        printFieldList(item->field);
        printf("-------------------------------\n"); 
        item = item->nextSymbol;
    }
    //printf("------------------End---------------\n");
    printf("\n");
    printf("-------------------------------------- %s's ComStat Body -----------------------------------\n\n", funcname);
}

// Stack functions
pStack newStack() {
    pStack p = (pStack)malloc(sizeof(Stack));
    assert(p != NULL);
    p->stackArray = (pItem*)malloc(sizeof(pItem) * HASH_TABLE_SIZE);
    assert(p->stackArray != NULL);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        p->stackArray[i] = NULL;
    }
    p->curStackDepth = 0;
    return p;
}

void deleteStack(pStack stack) {
    assert(stack != NULL);
    free(stack->stackArray);
    stack->stackArray = NULL;
    stack->curStackDepth = 0;
    free(stack);
}

void addStackDepth(pStack stack) {
    assert(stack != NULL);
    stack->curStackDepth++;
}

void minusStackDepth(pStack stack) {
    assert(stack != NULL);
    stack->curStackDepth--;
}

pItem getCurDepthStackHead(pStack stack) {
    assert(stack != NULL);
    return stack->stackArray[stack->curStackDepth];
    // return p == NULL ? NULL : p->stackArray[p->curStackDepth];
}

void setCurDepthStackHead(pStack stack, pItem newVal) {
    assert(stack != NULL);
    stack->stackArray[stack->curStackDepth] = newVal;
}

// Global function
void traverseTree(pNode node) {
    if (node == NULL) return;

    if (!strcmp(node->name, "CodeDec")) CodeDec(node);
    if(!strcmp(node->name, "MainDec")) MainDec(node);

    traverseTree(node->child);
    traverseTree(node->brother);
}


void ExtDefList(pNode node){
    assert(node != NULL);
    pNode tmp = node;
    while(tmp->child){
        if(!strcmp(tmp->child->name, "CodeDec")){
            CodeDec(tmp->child);
            tmp = tmp->child->brother;
        }
        else if(!strcmp(tmp->child->name, "MainDec")){
            MainDec(tmp->child);
            break;
        }
    }
}

void MainDec(pNode node){
    // MainDec:                Specifier MAIN LP VarList RP FunBody                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 4, $1, $2, $3, $4); }
    // |                   Specifier MAIN LP RP FunBody                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "MainDec", 3, $1, $2, $3); } 
    // |                   error RP 
    assert(node != NULL);
    pType specifierType = Specifier(node->child);
    char* secondName = node->child->brother->brother->brother->name;
    pNode tmp = node->child->brother->brother->brother;
    pItem p =
        newItem(table->stack->curStackDepth,
                newFieldList(node->child->brother->val,
                             newType(FUNCTION, 0, NULL, copyType(specifierType))));

    if(!strcmp(secondName, "VarList")){
        VarList(node->child->brother->brother->brother, p);
        tmp = tmp->brother;
    }

    if (checkTableItemConflict(table, p)) {
        char msg[100] = {0};
        sprintf(msg, "Redefined main function \"%s\".", p->field->name);
        pError(REDEF_FUNC, node->lineNo, msg);
        deleteItem(p);
        p = NULL;
    } else {
        addTableItem(table, p);
    }

    FunBody(tmp->brother, specifierType, "main");
    if (specifierType) deleteType(specifierType);
}

// Generate symbol table functions
void CodeDec(pNode node) {
    assert(node != NULL);
// CodeDec:                
//     |                   Specifier FunDec FunBody                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 2, $1, $2); }
//     |                   Specifier ExtDecList SEMI                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "CodeDec", 3, $1, $2, $3); }
//     |                   Specifier SEMI 
    pType specifierType = Specifier(node->child);
    char* secondName = node->child->brother->name;

    // printType(specifierType);
    // ExtDef -> Specifier ExtDecList SEMI
    if (!strcmp(secondName, "ExtDecList")) {
        // TODO: process first situation
        ExtDecList(node->child->brother, specifierType); //传入speci？
    }
    // ExtDef -> Specifier FunDec CompSt
    else if (!strcmp(secondName, "FunDec")) {
        // TODO: process third situation
        FunDec(node->child->brother, specifierType);
        FunBody(node->child->brother->brother, specifierType, node->child->brother->child->val);
    }
    if (specifierType) deleteType(specifierType);
    // printTable(table);
    // Specifier SEMI
    // this situation has no meaning
    // or is struct define(have been processe inSpecifier())
}

void ExtDecList(pNode node, pType specifier) {
    assert(node != NULL);
    // ExtDecList -> VarDec
    //             | VarDec COMMA ExtDecList
    pNode temp = node;
    while (temp) {
        pItem item = VarDec(temp->child, specifier);
        if (checkTableItemConflict(table, item)) {
            char msg[100] = {0};
            sprintf(msg, "Redefined variable \"%s\".", item->field->name);
            pError(REDEF_VAR, temp->lineNo, msg);
            deleteItem(item);
        } else {
            addTableItem(table, item);
        }
        if (temp->child->brother) {
            temp = temp->brother->brother->child; //?
        } else {
            break;
        }
    }
}

pType Specifier(pNode node) {
    assert(node != NULL);
    // Specifier -> TYPE
    //            | StructSpecifier
    pNode t = node->child;
    // Specifier -> TYPE
    if (!strcmp(t->name, "TYPE")) {
        if (!strcmp(t->val, "float")) {
            return newType(BASIC, FLOAT_TYPE);
        } else {
            return newType(BASIC, INT_TYPE);
        }
    }
    // Specifier -> StructSpecifier
    else {
        return StructSpecifier(t);
    }
}

pType StructSpecifier(pNode node) {
    assert(node != NULL);
    // StructSpecifier -> STRUCT OptTag LC DefList RC
    //                  | STRUCT Tag

    // OptTag -> ID | e
    // Tag -> ID
    pType returnType = NULL;
    pNode t = node->child->brother;
    // StructSpecifier->STRUCT OptTag LC DefList RC
    // printTreeInfo(t, 0);
    if (strcmp(t->name, "Tag")) {
        // addStructLayer(table);
        pItem structItem =
            newItem(table->stack->curStackDepth,
                    newFieldList("", newType(STRUCTURE, NULL, NULL)));
        if (!strcmp(t->name, "OptTag")) {
            setFieldListName(structItem->field, t->child->val); //?
            t = t->brother;
        }
        // unnamed struct 结构体可以不命名
        else { 
            table->unNamedStructNum ++;
            char structName[20] = {0};
            sprintf(structName, "%d", table->unNamedStructNum);
            // printf("unNamed struct's name is %s.\n", structName);
            setFieldListName(structItem->field, structName);
        }
        //现在我们进入结构体了！注意，报错信息会有不同！
        // addStackDepth(table->stack);
        if (!strcmp(t->brother->name, "DefList")) {
            DefList(t->brother, structItem);
        }

        if (checkTableItemConflict(table, structItem)) {
            char msg[100] = {0};
            sprintf(msg, "Duplicated name \"%s\".", structItem->field->name);
            pError(DUPLICATED_NAME, node->lineNo, msg);
            deleteItem(structItem);
        } else {
            returnType = newType(
                STRUCTURE, newString(structItem->field->name),
                copyFieldList(structItem->field->type->u.structure.field));

            // printf("\nnew Type:\n");
            // printType(returnType);
            // printf("\n");

            if (!strcmp(node->child->brother->name, "OptTag")) { //?
                addTableItem(table, structItem);
            }
            // OptTag -> e
            else {
                deleteItem(structItem);
            }
        }

        //我们出了结构体
        // minusStackDepth(table->stack);
        // minusStructLayer(table);
    }

    // StructSpecifier->STRUCT Tag
    else {
        pItem structItem = searchTableItem(table, t->child->val);
        if (structItem == NULL || !isStructDef(structItem)) { //表里找不到或者不是结构体
            char msg[100] = {0};
            sprintf(msg, "Undefined structure \"%s\".", t->child->val);
            pError(UNDEF_STRUCT, node->lineNo, msg);
        } else
            returnType = newType(
                STRUCTURE, newString(structItem->field->name),
                copyFieldList(structItem->field->type->u.structure.field));
    }
    // printType(returnType);
    return returnType;
}

pItem VarDec(pNode node, pType specifier) {
    assert(node != NULL);
    // VarDec -> ID
    //         | VarDec LB INT RB
    pNode id = node;
    // get ID
    while (id->child) id = id->child;
    pItem p = newItem(table->stack->curStackDepth, newFieldList(id->val, NULL));
    // return newItem(table->stack->curStackDepth,
    //                newFieldList(id->val, generateVarDecType(node,
    //                specifier)));

    // VarDec -> ID
    // printTreeInfo(node, 0);
    if (!strcmp(node->child->name, "ID")) {
        // printf("copy type tp %s.\n", node->child->val);
        p->field->type = copyType(specifier);   
    }
    // VarDec -> VarDec LB INT RB
    else {
        pNode varDec = node->child;
        pType temp = specifier;
        // printf("VarDec -> VarDec LB INT RB.\n");
        while (varDec->brother) {
            // printTreeInfo(varDec, 0);
            // printf("number: %s\n", varDec->brother->brother->val);
            // printf("temp type: %d\n", temp->kind);
            p->field->type =
                newType(ARRAY, copyType(temp), atoi(varDec->brother->brother->val));
            // printf("newType. newType: elem type: %d, elem size: %d.\n",
            //        p->field->type->u.array.elem->kind,
            //        p->field->type->u.array.size);
            temp = p->field->type;
            varDec = varDec->child;
        }
    }
    // printf("-------test VarDec ------\n");
    // printType(specifier);
    // printFieldList(p->field);
    // printf("-------test End ------\n");
    return p;
}

// pType generateVarDecType(pNode node, pType type) {
//     // VarDec -> ID
//     if (!strcmp(node->child->name, "ID")) return copyType(type);
//     // VarDec -> VarDec LB INT RB
//     else
//         return newType(ARRAY, atoi(node->child->brother->brother->val),
//                        generateVarDecType(node, type));
// }

void FunDec(pNode node, pType returnType) {
    assert(node != NULL);
    // FunDec -> ID LP VarList RP
    //         | ID LP RP
    pItem p =
        newItem(table->stack->curStackDepth,
                newFieldList(node->child->val,
                             newType(FUNCTION, 0, NULL, copyType(returnType))));

    // FunDec -> ID LP VarList RP
    if (!strcmp(node->child->brother->brother->name, "VarList")) {
        VarList(node->child->brother->brother, p);
    }

    // FunDec -> ID LP RP don't need process

    // check redefine
    if (checkTableItemConflict(table, p)) {
        char msg[100] = {0};
        sprintf(msg, "Redefined function \"%s\".", p->field->name);
        pError(REDEF_FUNC, node->lineNo, msg);
        deleteItem(p);
        p = NULL;
    } else {
        addTableItem(table, p);
    }
}

void VarList(pNode node, pItem func) {
    assert(node != NULL);
    // VarList -> ParamDec COMMA VarList
    //          | ParamDec

    addStackDepth(table->stack);
    int argc = 0;
    pNode temp = node->child;
    pFieldList cur = NULL;

    // VarList -> ParamDec
    pFieldList paramDec = ParamDec(temp);
    func->field->type->u.function.argv = copyFieldList(paramDec);
    cur = func->field->type->u.function.argv;
    argc++; //计数参数

    // VarList -> ParamDec COMMA VarList
    while (temp->brother) {
        temp = temp->brother->brother->child;
        paramDec = ParamDec(temp);
        if (paramDec) {
            cur->tail = copyFieldList(paramDec);
            cur = cur->tail;
            argc++;
        }
    }

    func->field->type->u.function.argc = argc;

    minusStackDepth(table->stack);
}

pFieldList ParamDec(pNode node) {
    assert(node != NULL);
    // ParamDec -> Specifier VarDec
    pType specifierType = Specifier(node->child);
    pItem p = VarDec(node->child->brother, specifierType);
    if (specifierType) deleteType(specifierType);

    if (checkTableItemConflict(table, p)) {
        char msg[100] = {0};
        sprintf(msg, "Redefined variable \"%s\".", p->field->name);
        pError(REDEF_VAR, node->lineNo, msg);
        deleteItem(p);
        return NULL;
    } 
    else {
        addTableItem(table, p);
        return p->field;
    }
}

void FunBody(pNode node, pType returnType, char* name) {
    assert(node != NULL);
// FunBody:                LC DefList StatList RC                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "FunBody", 4, $1, $2, $3, $4);  }
//     |                   error RC                                                {synError = TRUE;  }
//     ;
    addStackDepth(table->stack); //函数体内栈加一，即范围加深
    pNode temp = node->child->brother;
    if (!strcmp(temp->name, "DefList")) {
        DefList(temp, NULL);
        temp = temp->brother;
    }
    if (!strcmp(temp->name, "StatList")) {
        StatList(temp, returnType);
    }

    if(!semErrors) printFun(table, name);
    clearCurDepthStackList(table); //出函数清空所有内部变量
}

void StatList(pNode node, pType returnType) {
    // assert(node != NULL);
    // StatList -> Stmt StatList
    //           | e
    // printTreeInfo(node, 0);
    while (node) {
        Statements(node->child, returnType);
        node = node->child->brother;
    }
}

void Statements(pNode node, pType returnType) {
    assert(node != NULL);
// Statements:             IfStat                                                  {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }      
//     |                   WhileStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   ForStat                                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   ReadStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   WriteStat                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   CompoundStat                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   ExprStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   CallStat                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 1, $1);   }  
//     |                   RETURN Expr SEMI/*RETUN*/                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Statements", 3, $1, $2, $3);}  
//     ;     

    pType expType = NULL;
    // Stmt -> ExprStat SEMI
    if (!strcmp(node->child->name, "Expr")) expType = Expr(node->child);

    // Stmt -> CompSt
    else if (!strcmp(node->child->name, "CompoundStat"))
        FunBody(node->child, returnType, "Expr");

    // Stmt -> RETURN ExprStat SEMI
    else if (!strcmp(node->child->name, "RETURN")) {
        expType = Expr(node->child->brother);

        // check return type
        if (!checkType(returnType, expType))
            pError(TYPE_MISMATCH_RETURN, node->lineNo,
                   "Type mismatched for return.");
    }

    // Stmt -> IF LP Expr RP Statements 
    else if (!strcmp(node->child->name, "IF")) {
        pNode stat = node->child->brother->brother->brother->brother;
        expType = Expr(node->child->brother->brother);
        Statements(stat, returnType);
        // Stmt -> IF LP Expr RP Statements ELSE Statements
        if (stat->brother != NULL) Statements(stat->brother->brother, returnType);
    }

    // Stmt -> WHILE LP Expr RP Statements
    else if (!strcmp(node->child->name, "WHILE")) {
        expType = Expr(node->child->brother->brother);
        Statements(node->child->brother->brother->brother->brother, returnType);
    }


    //Stmt -> ForStat
    else if (!strcmp(node->child->name, "FOR")) {
        expType = Expr(node->child->brother->brother);
        expType = Expr(node->child->brother->brother->brother->brother);
        expType = Expr(node->child->brother->brother->brother->brother->brother->brother);
        Statements(node->child->brother->brother->brother->brother->brother->brother->brother->brother, returnType);
    }
    //ReadStat
    else if (!strcmp(node->child->name, "READ")) {
        expType = Expr(node->child->brother);
    }
    //WriteStat
    else if (!strcmp(node->child->name, "WRITE")) {
        expType = Expr(node->child->brother);
    }

    if (expType) deleteType(expType);
}

// void CompoundStat(pNode node, pType returnType) {
//     assert(node != NULL);
//     // CompSt -> LC DefList StmtList RC
//     // printTreeInfo(node, 0);
//     addStackDepth(table->stack);
//     pNode temp = node->child->brother;

//     if (!strcmp(temp->name, "StmtList")) {
//         StatList(temp, returnType);
//     }

//     clearCurDepthStackList(table);
// }

void DefList(pNode node, pItem structInfo) {
    // assert(node != NULL);
    // DefList -> Def DefList
    //          | e
    while (node) {
        Def(node->child, structInfo);
        node = node->child->brother;
    }
}

void Def(pNode node, pItem structInfo) {
    assert(node != NULL);
    // Def -> Specifier DecList SEMI
    // TODO:调用接口
    pType dectype = Specifier(node->child);
    //你总会得到一个正确的type
    DecList(node->child->brother, dectype, structInfo);
    if (dectype) deleteType(dectype);
}

void DecList(pNode node, pType specifier, pItem structInfo) {
    assert(node != NULL);
    // DecList -> Dec
    //          | Dec COMMA DecList
    pNode temp = node;
    while (temp) {
        Dec(temp->child, specifier, structInfo);
        if (temp->child->brother)
            temp = temp->child->brother->brother;
        else
            break;
    }
}

void Dec(pNode node, pType specifier, pItem structInfo) {
    assert(node != NULL);
    // Dec -> VarDec
    //      | VarDec ASSIGNOP Exp

    // Dec -> VarDec
    if (node->child->brother == NULL) {
        if (structInfo != NULL) {
            // 结构体内，将VarDec返回的Item中的filedList
            // Copy判断是否重定义，无错则到结构体链表尾 记得delete掉Item ?
            pItem decitem = VarDec(node->child, specifier);
            pFieldList payload = decitem->field;
            pFieldList structField = structInfo->field->type->u.structure.field;
            pFieldList last = NULL;
            while (structField != NULL) {
                // then we have to check
                if (!strcmp(payload->name, structField->name)) {
                    //出现重定义，报错
                    char msg[100] = {0};
                    sprintf(msg, "Redefined field \"%s\".",
                            decitem->field->name);
                    pError(REDEF_FEILD, node->lineNo, msg);
                    deleteItem(decitem);
                    return;
                } else {
                    last = structField;
                    structField = structField->tail;
                }
            }
            //新建一个fieldlist,删除之前的item
            if (last == NULL) {
                // that is good
                structInfo->field->type->u.structure.field =
                    copyFieldList(decitem->field);
            } else {
                last->tail = copyFieldList(decitem->field);
            }
            deleteItem(decitem);
        } else {
            // 非结构体内，判断返回的item有无冲突，无冲突放入表中，有冲突报错delete
            pItem decitem = VarDec(node->child, specifier);
            if (checkTableItemConflict(table, decitem)) {
                //出现冲突，报错
                char msg[100] = {0};
                sprintf(msg, "Redefined variable \"%s\".",
                        decitem->field->name);
                pError(REDEF_VAR, node->lineNo, msg);
                deleteItem(decitem);
            } else {
                addTableItem(table, decitem);
            }
        }
    }
    // Dec -> VarDec ASSIGNOP Exp
    else {
        if (structInfo != NULL) {
            // 结构体内不能赋值，报错
            pError(REDEF_FEILD, node->lineNo,
                   "Illegal initialize variable in struct.");
        } else {
            // 判断赋值类型是否相符
            //如果成功，注册该符号
            pItem decitem = VarDec(node->child, specifier);
            pType exptype = Expr(node->child->brother->brother);
            if (checkTableItemConflict(table, decitem)) {
                //出现冲突，报错
                char msg[100] = {0};
                sprintf(msg, "Redefined variable \"%s\".",
                        decitem->field->name);
                pError(REDEF_VAR, node->lineNo, msg);
                deleteItem(decitem);
            }
            if (!checkType(decitem->field->type, exptype)) {
                //类型不相符
                //报错
                pError(TYPE_MISMATCH_ASSIGN, node->lineNo,
                       "Type mismatchedfor assignment.");
                deleteItem(decitem);
            }
            if (decitem->field->type && decitem->field->type->kind == ARRAY) {
                //报错，对非basic类型赋值
                pError(TYPE_MISMATCH_ASSIGN, node->lineNo,
                       "Illegal initialize variable.");
                deleteItem(decitem);
            } else {
                addTableItem(table, decitem);
            }
            // exp不出意外应该返回一个无用的type，删除
            if (exptype) deleteType(exptype);
        }
    }
}

pType Expr(pNode node) {
    assert(node != NULL);
//    Expr:                   //Bool_Expr                                               {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 1, $1);   }   
//                         ID LP Args RP                                           {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 4, $1, $2, $3, $4);   }   
//     |                   ID LP RP                                                {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }   
//     |                   Expr DOT ID                                             {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 3, $1, $2, $3);   }   
//     |                   Expr LB Expr RB                                          {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 4, $1, $2, $3, $4);   }   
//     |                   NOT Expr                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 2, $1, $2);   }
//     |                   MINUS Expr                                            {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Expr", 2, $1, $2);   }
//     |                   LP Expr RP                                              {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }   
//     |                   Expr ASSIGNOP Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }  
//     |                   Expr RELOP Expr                                 {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   } 
//     |                   Expr AND Expr                                   {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }
//     |                   Expr OR Expr                                    {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }
//     |                   Expr PLUS Expr                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "AddBool_Expr_Expr", 3, $1, $2, $3);   }  
//     |                   Expr MINUS Expr                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }  
//     |                   Expr STAR Expr                                        {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }  
//     |                   Expr DIV Expr                                         {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 3, $1, $2, $3);   }  
//     |                   ID                                                      {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 1, $1);   }  
//     |                   INT                                                     {$$ = createNode(@$.first_line, NOT_A_TOKEN, "Bool_Expr", 1, $1);   } 
//     ;
    pNode t = node->child;
    // exp will only check if the cal is right
    //  printTable(table);
    //二值运算
    if (!strcmp(t->name, "Expr")) {
        // 基本数学运算符
        if (strcmp(t->brother->name, "LB") && strcmp(t->brother->name, "DOT")) {
            pType p1 = Expr(t);
            pType p2 = Expr(t->brother->brother);
            pType returnType = NULL;

            // Exp -> Exp ASSIGNOP Exp
            if (!strcmp(t->brother->name, "ASSIGNOP")) {
                //检查左值
                pNode tchild = t->child;

                if (!strcmp(tchild->name, "INT")) {
                    //报错，左值
                    pError(LEFT_VAR_ASSIGN, t->lineNo,
                            "The left-hand side of an assignment must be "
                            "avariable.");

                } else if (!strcmp(tchild->name, "ID") ||
                            !strcmp(tchild->brother->name, "LB") ||
                            !strcmp(tchild->brother->name, "DOT")) {
                    if (!checkType(p1, p2)) {
                        //报错，类型不匹配
                        pError(TYPE_MISMATCH_ASSIGN, t->lineNo,
                                "Type mismatched for assignment.");
                    } else
                        returnType = copyType(p1);
                } else {
                    //报错，左值
                    pError(LEFT_VAR_ASSIGN, t->lineNo,
                            "The left-hand side of an assignment must be "
                            "avariable.");
                }

            }
            // Exp -> Exp AND Exp
            //      | Exp OR Exp
            //      | Exp RELOP Exp
            //      | Exp PLUS Exp
            //      | Exp MINUS Exp
            //      | Exp STAR Exp
            //      | Exp DIV Exp
            else {
                if (p1 && p2 && (p1->kind == ARRAY || p2->kind == ARRAY)) {
                    //报错，数组，结构体运算
                    pError(TYPE_MISMATCH_OP, t->lineNo,
                           "Type mismatched for operands.");
                } else if (!checkType(p1, p2)) {
                    //报错，类型不匹配
                    pError(TYPE_MISMATCH_OP, t->lineNo,
                           "Type mismatched for operands.");
                } else {
                    if (p1 && p2) {
                        returnType = copyType(p1);
                    }
                }
            }

            if (p1) deleteType(p1);
            if (p2) deleteType(p2);
            return returnType;
        }
        // 数组和结构体访问
        else {
            // Exp -> Exp LB Exp RB
            if (!strcmp(t->brother->name, "LB")) {
                //数组
                pType p1 = Expr(t);
                pType p2 = Expr(t->brother->brother);
                pType returnType = NULL;

                if (!p1) {
                    // 第一个exp为null，上层报错，这里不用再管
                } else if (p1 && p1->kind != ARRAY) {
                    //报错，非数组使用[]运算符
                    char msg[100] = {0};
                    sprintf(msg, "\"%s\" is not an array.", t->child->val);
                    pError(NOT_A_ARRAY, t->lineNo, msg);
                } else if (!p2 || p2->kind != BASIC ||
                            p2->u.basic != INT_TYPE) {
                    //报错，不用int索引[]
                    char msg[100] = {0};
                    sprintf(msg, "\"%s\" is not an integer.",
                            t->brother->brother->child->val);
                    pError(NOT_A_INT, t->lineNo, msg);
                } else {
                    returnType = copyType(p1->u.array.elem);
                }
                if (p1) deleteType(p1);
                if (p2) deleteType(p2);
                return returnType;
            }
        // Exp -> Exp DOT ID
            else {
                pType p1 = Expr(t);
                pType returnType = NULL;
                if (!p1 || p1->kind != STRUCTURE ||
                    !p1->u.structure.structName) {
                    //报错，对非结构体使用.运算符
                    pError(ILLEGAL_USE_DOT, t->lineNo, "Illegal use of \".\".");
                    if (p1) deleteType(p1);
                } else {
                    pNode ref_id = t->brother->brother;
                    pFieldList structfield = p1->u.structure.field;
                    while (structfield != NULL) {
                        if (!strcmp(structfield->name, ref_id->val)) {
                            break;
                        }
                        structfield = structfield->tail;
                    }
                    if (structfield == NULL) {
                        //报错，没有可以匹配的域名
                        printf("Error type %d at Line %d: %s.\n", 14, t->lineNo,
                                "NONEXISTFIELD");
                        
                    } else {
                        returnType = copyType(structfield->type);
                    }
                }
                if (p1) deleteType(p1);
                return returnType;
            }
        }
    }
    //单目运算符
    // Exp -> MINUS Exp
    //      | NOT Exp
    else if (!strcmp(t->name, "MINUS") || !strcmp(t->name, "NOT")) {
        pType p1 = Expr(t->brother);
        pType returnType = NULL;
        if (!p1 || p1->kind != BASIC) {
            //报错，数组，结构体运算
            printf("Error type %d at Line %d: %s.\n", 7, t->lineNo,
                   "TYPE_MISMATCH_OP");
        } else {
            returnType = copyType(p1);
        }
        if (p1) deleteType(p1);
        return returnType;
    }  //(Expr)
    else if (!strcmp(t->name, "LP")) {
        return Expr(t->brother);
    }
    // Exp -> ID LP Args RP
    //		| ID LP RP
    else if (!strcmp(t->name, "ID") && t->brother) {
        pItem funcInfo = searchTableItem(table, t->val);

        // function not find
        if (funcInfo == NULL) {
            char msg[100] = {0};
            sprintf(msg, "Undefined function \"%s\".", t->val);
            pError(UNDEF_FUNC, node->lineNo, msg);
            return NULL;
        } else if (funcInfo->field->type->kind != FUNCTION) {
            char msg[100] = {0};
            sprintf(msg, "\"%s\" is not a function.", t->val);
            pError(NOT_A_FUNC, node->lineNo, msg);
            return NULL;
        }
        // Exp -> ID LP Args RP
        else if (!strcmp(t->brother->brother->name, "Args")) {
            Args(t->brother->brother, funcInfo);
            return copyType(funcInfo->field->type->u.function.returnType);
        }
        // Exp -> ID LP RP
        else {
            if (funcInfo->field->type->u.function.argc != 0) {
                char msg[100] = {0};
                sprintf(msg,
                        "too few arguments to function \"%s\", except %d args.",
                        funcInfo->field->name,
                        funcInfo->field->type->u.function.argc);
                pError(FUNC_AGRC_MISMATCH, node->lineNo, msg);
            }
            return copyType(funcInfo->field->type->u.function.returnType);
        }
    }
    // Exp -> ID
    else if (!strcmp(t->name, "ID")) {
        pItem tp = searchTableItem(table, t->val);
        if (tp == NULL || isStructDef(tp)) {
            char msg[100] = {0};
            sprintf(msg, "Undefined variable \"%s\".", t->val);
            pError(UNDEF_VAR, t->lineNo, msg);
            return NULL;
        } else {
            // good
            return copyType(tp->field->type);
        }
    } else {
        // Exp -> FLOAT
        if (!strcmp(t->name, "FLOAT")) {
            return newType(BASIC, FLOAT_TYPE);
        }
        // Exp -> INT
        else {
            return newType(BASIC, INT_TYPE);
        }
    }
}

void Args(pNode node, pItem funcInfo) {
    assert(node != NULL);
    // Args -> Exp COMMA Args
    //       | Exp
    // printTreeInfo(node, 0);
    pNode temp = node;
    pFieldList arg = funcInfo->field->type->u.function.argv;
    // printf("-----function atgs-------\n");
    // printFieldList(arg);
    // printf("---------end-------------\n");
    while (temp) {
        if (arg == NULL) {
            char msg[100] = {0};
            sprintf(
                msg, "too many arguments to function \"%s\", except %d args.",
                funcInfo->field->name, funcInfo->field->type->u.function.argc);
            pError(FUNC_AGRC_MISMATCH, node->lineNo, msg);
            break;
        }
        pType realType = Expr(temp->child);
        // printf("=======arg type=========\n");
        // printType(realType);
        // printf("===========end==========\n");
        if (!checkType(realType, arg->type)) {
            char msg[100] = {0};
            sprintf(msg, "Function \"%s\" is not applicable for arguments.",
                    funcInfo->field->name);
            pError(FUNC_AGRC_MISMATCH, node->lineNo, msg);
            if (realType) deleteType(realType);
            return;
        }
        if (realType) deleteType(realType);

        arg = arg->tail;
        if (temp->child->brother) {
            temp = temp->child->brother->brother;
        } else {
            break;
        }
    }
    if (arg != NULL) {
        char msg[100] = {0};
        sprintf(msg, "too few arguments to function \"%s\", except %d args.",
                funcInfo->field->name, funcInfo->field->type->u.function.argc);
        pError(FUNC_AGRC_MISMATCH, node->lineNo, msg);
    }
}
