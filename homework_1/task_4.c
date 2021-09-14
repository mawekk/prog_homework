#include <math.h>
#include <stdio.h>

int numberIsPrime(int number)
{
    int flag = 1;
    for (int divisor = 2; divisor <= sqrt(number); ++divisor) {
        if (number % divisor == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main()
{
    int number;
    int lessNumber = 2;
    printf("Enter the number:\n");
    scanf("%d", &number);

    if (number <= 1)
        printf("There are no such primes");
    else {
        printf("The primes not exceeding %d:\n", number);
        while (lessNumber <= number) {
            if (numberIsPrime(lessNumber))
                printf("%d\n", lessNumber);
            ++lessNumber;
        }
    }

    return 0;
}