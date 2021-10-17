#include "../library/binary/binary.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;
    int* firstBinary = calloc(16, sizeof(int));
    int* secondBinary = calloc(16, sizeof(int));
    int sum = 0;
    int* sumBinary = calloc(16, sizeof(int));

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    convertToBinary(firstNumber, firstBinary);
    convertToBinary(secondNumber, secondBinary);

    printf("First number in binary additional code: ");
    printBinary(firstBinary);
    printf("Second number in binary additional code: ");
    printBinary(secondBinary);

    addBinary(firstBinary, secondBinary, sumBinary);
    printf("Sum of numbers in binary additional code: ");
    printBinary(sumBinary);
    printf("Sum of numbers in decimal system: %d", convertToDecimal(sumBinary));

    return 0;
}