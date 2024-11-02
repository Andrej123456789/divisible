#include <simplifier/lexer.h>

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char* char_to_charp(char c)
{
    char buffer[2];

    buffer[0] = c;
    buffer[1] = '\0';

    return strdup(buffer);
}

cvector_vector_type(Token) lexer(char* expression)
{
    cvector_vector_type(Token) tokens = NULL;

    size_t i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == ' ' || expression[i] == '\t')
        {
            i++;
        }

        else if (isdigit(expression[i]))
        {
            Token token;

            /**
             * If this number is tied with a variable, it's a coefficient.
             * Otherwise, it's a constant.
             */
            if (isalpha(expression[i + 1]))
            {
                token.type = COEFFICIENT;
                token.value = char_to_charp(expression[i]);
            }

            else
            {
                token.type = CONSTANT;
                token.value = char_to_charp(expression[i]);
            }

            cvector_push_back(tokens, token);
        }

        else if (isalpha(expression[i]))
        {
            Token token = 
            {
                .type = VARIABLE,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '+')
        {
            Token token = 
            {
                .type = ADDITION,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '-')
        {
            Token token = 
            {
                .type = SUBTRACTION,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '*')
        {
            Token token = 
            {
                .type = MULTIPLICATION,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '/')
        {
            Token token = 
            {
                .type = DIVISION,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '^')
        {
            /* I only accept powering to a number */
            if (!isdigit(expression[i + 1]))
            {
                /* return error */
            }

            char a = expression[i];
            char b = expression[i + 1];

            char _value[3];
            sprintf(_value, "%c%c", a, b);

            Token token = 
            {
                .type = POWER,
                .value = _value,
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == '(')
        {
            Token token = 
            {
                .type = LPAREN,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else if (expression[i] == ')')
        {
            Token token = 
            {
                .type = RPAREN,
                .value = char_to_charp(expression[i]),
            };

            cvector_push_back(tokens, token);
        }

        else
        {
            /* return error */
        }

        i++;
    }

    /*for (size_t i = 0; i < cvector_size(tokens); i++)
    {
        printf("[%d | %s]", tokens[i].type, tokens[i].value);
    }*/

    return NULL;
}
