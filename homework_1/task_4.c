#include <math.h>
#include <stdio.h>

int numberIsPrime(number)
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
    int less_number = 2;
    printf("Enter the number:\n");
    scanf("%d", &number);

    if (number <= 1)
        printf("There are no such primes");
    else {
        printf("The primes not exceeding %d:\n", number);
        while (less_number <= number) {
            if (numberIsPrime(less_number))
                printf("%d\n", less_number);
            ++less_number;
        }
    }

    return 0;
}