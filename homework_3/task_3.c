#include "../library/binary/binary.h"
#include <stdio.h>

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;

    printf("Enter numbers:\n");
    scanf("%d", &firstNumber);
    scanf("%d", &secondNumber);

    int* firstBinary = convertToBinary(firstNumber);
    int* secondBinary = convertToBinary(secondNumber);
    int* productBinary = convertToBinary(0);
    multiplyBinary(firstBinary, secondBinary, productBinary);

    printf("Product in binary code: ");
    printBinary(productBinary);
    printf("Product in decimal: %d", convertToDecimal(productBinary));

    return 0;
}