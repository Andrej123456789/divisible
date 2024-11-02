#pragma once

enum TT
{
    COEFFICIENT,
    VARIABLE,
    CONSTANT,

    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER,

    LPAREN,
    RPAREN,
};

typedef struct _token
{
    enum TT type;
    char* value; 
} Token;
