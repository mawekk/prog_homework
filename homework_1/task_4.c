#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number)
{
    for (int divisor = 2; divisor <= sqrt(number); ++divisor) {
        if (number % divisor == 0)
            return false;
    }

    return true;
}

int main()
{
    int number = 0;
    printf("Enter the number:\n");
    scanf("%d", &number);

    if (number <= 1)
        printf("There are no such primes");
    else {
        printf("The primes not exceeding %d:\n", number);
        for (int i = 2; i <= number; ++i) {
            if (isPrime(i))
                printf("%d\n", i);
        }
    }

    return 0;
}