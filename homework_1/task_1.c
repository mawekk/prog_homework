#include <math.h>
#include <stdio.h>

int calculateIncompleteQuotient(int dividend, int divisor)
{
    int absDividend = abs(dividend), absDivisor = abs(divisor);
    int quotient = 0;

    while (absDividend >= absDivisor) {
        absDividend = absDividend - absDivisor;
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
    int dividend = 0, divisor = 0;
    printf("Enter the dividend:\n");
    scanf("%d", &dividend);
    printf("Enter the divisor:\n");
    scanf("%d", &divisor);
    while (divisor == 0) {
        printf("Error: division by zero! Enter the divisor again:\n");
        scanf("%d", &divisor);
    }
    printf("Answer = %i\n", calculateIncompleteQuotient(dividend, divisor));
}
