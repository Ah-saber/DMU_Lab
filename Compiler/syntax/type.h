#ifndef TYPE_H
#define TYPE_H

//type judge, INT,ID output the value; Other output nothing; Not output lineno
typedef enum nodeType{
    TOKEN_INT,  
    TOKEN_ID,
    TOKEN_OTHER,
    NOT_A_TOKEN,
} NodeType;


typedef enum ErrorType{
    WITHOUT_SEMI,
    MISSING_SCALE,
    WRONG_FOR,
    WRONG_IF,
    WRONG_WHILE,
    MISSING_MAIN,
} SynErrorType;



