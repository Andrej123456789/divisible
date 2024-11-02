#pragma once

#include <cvector.h>
#include <simplifier/token.h>

/**
 * Converts char to char*
 * @param char
 * @return char*
 */
char* char_to_charp(char c);

/**
 * Convert expression into tokens
 * @param expression
 * @return vector of `Token`s
 */
cvector_vector_type(Token) lexer(char* expression);
