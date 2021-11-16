#include <stdio.h>
#include <stdlib.h>

long long int calculateFibonacci(int number)
{
    long long int* fibonacci = calloc(number + 1, sizeof(long long int));
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < number + 1; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    long long int result = fibonacci[number];
    free(fibonacci);
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