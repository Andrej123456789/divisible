#pragma once

#include <cvector.h>
#include <simplifier/token.h>

/**
 * Convert expression into tokens
 * @param expression
 * @return vector of `Token`s
 */
cvector_vector_type(Token) lexer(char* expression);
