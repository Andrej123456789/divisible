#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <simplifier/simplifier.h>
#include <factorer/factorer.h>

int main(int argc, char* argv[])
{
    char expression[1024];

    char number_input[64];
    uint64_t number = 0;

    printf("=== divisible ===\n");

    if (argc >= 3)
    {
        strncpy(expression, argv[1], 1024);
        strncpy(number_input, argv[2], 64);
    }

    else
    {
        printf("Enter a algebraic expression: ");
        scanf("%1023s", expression);

        printf("Enter a number: ");
        scanf("%63s", number_input);
    }

    number = strtoull(number_input, NULL, 10);

    printf("\n");
    printf("%"PRIu64" | %s = \n", number, expression);

    printf("= ");
    simplifier(expression);
    printf(" = \n");
    
    printf("= ");
    bool result = factorer(expression, number);
    result == true ? printf(" - TRUE!\n") : printf(" - FALSE!\n");

    return 0;
}
