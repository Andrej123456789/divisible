#pragma once

#include <stdbool.h>
#include <stdint.h>

/**
 * Factor out the common factor.
 * Print final expression and return is the starting expression divisible by the number.
 * @param expression
 * @param number
 * @return bool 
 */
bool factorer(char* expression, uint64_t number);
