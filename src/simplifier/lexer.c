#include <simplifier/lexer.h>

#include <stdio.h>
#include <stddef.h>

cvector_vector_type(Token) lexer(char* expression)
{
    // cvector_vector_type(Token) tokens = NULL;

    size_t i = 0;
    while (expression[i] != '\0')
    {
        printf("%c", expression[i]);
        i++;
    }

    return NULL;
}
