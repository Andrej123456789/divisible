#include <stdio.h>

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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
    printf("%"PRIu64" | %s\n", number, expression);

    return 0;
}
