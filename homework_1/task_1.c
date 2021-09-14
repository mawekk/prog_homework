#include <math.h>
#include <stdio.h>

int calculateIncompleteQuotient(int dividend, int divisor)
{
    int abs_dividend, abs_divisor;
    int quotient = 0;

    abs_dividend = abs(dividend);
    abs_divisor = abs(divisor);

    while (abs_dividend >= abs_divisor) {
        abs_dividend = abs_dividend - abs_divisor;
        ++quotient;
    }

    if (dividend < 0)
        quotient = -quotient - 1;
    if (divisor < 0)
        quotient = -quotient;

    return quotient;
}

int main()
{
    int a, b;
    printf("Enter a:\n");
    scanf("%d", &a);
    printf("Enter b:\n");
    scanf("%d", &b);
    while (!b) {
        printf("Error! Enter b:\n");
        scanf("%d", &b);
    }
    printf("Answer = %i\n", calculateIncompleteQuotient(a, b));
}
