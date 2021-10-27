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
    int* productBinary = calloc(bitDepth, sizeof(int));

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    convertToBinary(firstNumber, firstBinary, bitDepth);
    convertToBinary(secondNumber, secondBinary, bitDepth);
    multiplyBinary(firstBinary, secondBinary, productBinary, bitDepth);

    printf("Product in binary code: ");
    printBinary(productBinary, bitDepth);
    printf("Product in decimal: %d", convertToDecimal(productBinary, bitDepth));

    return 0;
}