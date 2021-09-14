#include <math.h>
#include <stdio.h>

int calculateIncompleteQuotient(int dividend, int divisor)
{
    int absDividend, absDivisor;
    int quotient = 0;

    absDividend = abs(dividend);
    absDivisor = abs(divisor);

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
