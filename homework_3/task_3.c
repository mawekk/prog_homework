#include "../library/binary/binary.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;
    int* firstBinary = calloc(16, sizeof(int));
    int* secondBinary = calloc(16, sizeof(int));
    int product = 0;
    int* productBinary = calloc(16, sizeof(int));

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    convertToBinary(firstNumber, firstBinary);
    convertToBinary(secondNumber, secondBinary);
    multiplyBinary(firstBinary, secondBinary, productBinary);

    printf("Product in binary code: ");
    printBinary(productBinary);
    product = convertToDecimal(productBinary);
    printf("Product in decimal: %d", product);

    return 0;
}