#include "../library/binary/binary.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    int* firstBinary = convertToBinary(firstNumber);
    int* secondBinary = convertToBinary(secondNumber);

    printf("First number in binary additional code:   ");
    printBinary(firstBinary);
    printf("Second number in binary additional code:  ");
    printBinary(secondBinary);

    int* sumBinary = convertToBinary(0);
    addBinary(firstBinary, secondBinary, sumBinary);
    printf("Sum of numbers in binary additional code: ");
    printBinary(sumBinary);
    printf("Sum of numbers in decimal system: %d", convertToDecimal(sumBinary));

    free(firstBinary);
    free(secondBinary);
    free(sumBinary);

    return 0;
}