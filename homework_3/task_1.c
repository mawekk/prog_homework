#include "../library/binary/binary.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int const bitDepth = 16;
    int firstNumber = 0;
    int secondNumber = 0;
    int* firstBinary = calloc(bitDepth, sizeof(int));
    int* secondBinary = calloc(bitDepth, sizeof(int));
    int* sumBinary = calloc(bitDepth, sizeof(int));

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    convertToBinary(firstNumber, firstBinary, bitDepth);
    convertToBinary(secondNumber, secondBinary, bitDepth);

    printf("First number in binary additional code:   ");
    printBinary(firstBinary, bitDepth);
    printf("Second number in binary additional code:  ");
    printBinary(secondBinary, bitDepth);

    addBinary(firstBinary, secondBinary, sumBinary, bitDepth);
    printf("Sum of numbers in binary additional code: ");
    printBinary(sumBinary, bitDepth);
    printf("Sum of numbers in decimal system: %d", convertToDecimal(sumBinary, bitDepth));

    free(firstBinary);
    free(secondBinary);
    free(sumBinary);

    return 0;
}