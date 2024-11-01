#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <simplifier/simplifier.h>
#include <factorer/factorer.h>

int main()
{
    char expression[1024];

    char number_input[64];
    uint64_t number = 0;

    printf("=== divisible ===\n");

    printf("Enter a algebraic expression: ");
    scanf("%1023s", expression);

    printf("Enter a number: ");
    scanf("%63s", number_input);

    number = strtoull(number_input, NULL, 10);

    printf("\n");
    printf("%"PRIu64" | %s = \n", number, expression);

    simplifier(expression);
    printf(" = \n");
    
    bool result = factorer(expression, number);
    result == true ? printf(" - TRUE!\n") : printf(" - FALSE!\n");

    return 0;
}
