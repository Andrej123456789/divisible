#pragma once

enum TT
{
    COEFFICIENT,
    VARIABLE,
    CONSTANT,

    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POWER,

    LPAREN,
    RPAREN,
};

typedef struct _token
{
    enum TT type;
    char* value; 
} Token;
