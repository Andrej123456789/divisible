#include <simplifier/lexer.h>

#include <stdio.h>

void simplifier(char* expression)
{
    lexer(expression);
    printf("%s", expression);
}
