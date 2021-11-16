#include <stdio.h>
#include <stdlib.h>

long long int calculateFibonacci(int number)
{
    if (number == 0)
        return 0;
    long long int fibonacciPrevPrev = 0;
    long long int fibonacciPrev = 1;
    long long int result = 1;
    for (int i = 2; i < number + 1; i++) {
        result = fibonacciPrev + fibonacciPrevPrev;
        fibonacciPrevPrev = fibonacciPrev;
        fibonacciPrev = result;
    }
    return result;
}

int main()
{
    int number = 0;
    printf("Enter the number:\n");
    scanf("%d", &number);
    while (number < 0 || number > 90) {
        printf("The number should be from 0 to 90.\n");
        printf("Enter the number:\n");
        scanf("%d", &number);
    }
    printf("Fibonacci number = %lld", calculateFibonacci(number));
    return 0;
}