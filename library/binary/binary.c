#include "binary.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define BIT_DEPTH 8

void reverse(int* binary)
{
    for (int i = 0; i < BIT_DEPTH; i++)
        binary[i] = 1 - binary[i];
}

int* convertToBinary(int originalNumber)
{
    int number = abs(originalNumber);
    int i = BIT_DEPTH - 1;
    int* binary = calloc(BIT_DEPTH, sizeof(int));

    while (number > 0) {
        binary[i] = number % 2;
        i--;
        number = number / 2;
    }

    if (originalNumber < 0) {
        reverse(binary);
        int* add = convertToBinary(1);
        addBinary(add, binary, binary);
        free(add);
    }
    return binary;
}

void printBinary(int* binary)
{
    for (int i = 0; i < BIT_DEPTH; i++)
        printf("%d", binary[i]);
    printf("\n");
}

void addBinary(int* firstTerm, int* secondTerm, int* sum)
{
    int memory = 0;
    int currentSum = 0;

    for (int i = BIT_DEPTH - 1; i >= 0; i--) {
        currentSum = firstTerm[i] + secondTerm[i] + memory;
        sum[i] = currentSum % 2;
        memory = currentSum / 2;
    }
}

int convertToDecimal(int* binary)
{
    int number = 0;
    int degree = 1;
    int firstBite = binary[0];

    if (firstBite == 1) {
        int* add = convertToBinary(-1);
        addBinary(add, binary, binary);
        reverse(binary);
        free(add);
    }
    for (int i = BIT_DEPTH - 1; i > 0; i--) {
        number += binary[i] * degree;
        degree = degree * 2;
    }
    if (firstBite == 1)
        number = 0 - number;

    return number;
}

void shiftBits(int shift, int* binary, int* newBinary)
{
    for (int i = 0; i < BIT_DEPTH; i++)
        newBinary[i] = binary[i];
    for (int j = 0; j < shift; j++) {
        for (int i = 0; i < BIT_DEPTH - 1; i++)
            newBinary[i] = newBinary[i + 1];
        newBinary[BIT_DEPTH - 1] = 0;
    }
}

void multiplyBinary(int* multiplied, int* multiplier, int* product)
{
    int* term = calloc(BIT_DEPTH, sizeof(int));
    int shift = 0;

    for (int i = 0; i < BIT_DEPTH; i++)
        product[i] = 0;

    for (int i = BIT_DEPTH - 1; i >= 0; i--) {
        if (multiplier[i] == 1) {
            shiftBits(shift, multiplied, term);
            addBinary(product, term, product);
        }
        ++shift;
    }

    free(term);
}

void appendToBinary(int* end, int length,  int* binary, int position)
{
    int j = 0;
    for (int i = position; i < position + length; i++)
        binary[i] = end[j++];
}

double convertFromBinaryToReal(int* binary, int length)
{
    double degree = 0.5;
    double real = 0;
    for (int i = 0; i < length; i++) {
        real += binary[i] * degree;
        degree = degree / 2;
    }

    return real;

}

int* convertPartToBinary(int originalNumber)
{
    int number = abs(originalNumber);
    int i = 3;
    int* binary = calloc(4, sizeof(int));

    while (number > 0) {
        binary[i] = number % 2;
        i--;
        number = number / 2;
    }

    if (originalNumber < 0) {
        reverse(binary);
        int* add = convertToBinary(1);
        addBinary(add, binary, binary);
        free(add);
    }
    return binary;
}

int calculateExponent(int* binary)
{
    int number = 0;
    int degree = 1;

    for (int i = 11; i >= 0; i--) {
        number += binary[i] * degree;
        degree = degree * 2;
    }
    return (number - 2047);
}

void convertFromHexToBinary(unsigned char hex[8])
{
    int* binary = calloc(64, sizeof(int));
    char hexString[17] = "";

    for (int i = 7; i >= 0; --i) {
        char buffer[3] = "";
        sprintf(buffer, "%02X", hex[i]);
        strcat(hexString, buffer);
    }

    int position = 0;
    for (int i = 0; i < 16; i++) {
        int number = 0;
        if (hexString[i] == 'A')
            number = 10;
        else if (hexString[i] == 'B')
            number = 11;
        else if (hexString[i] == 'C')
            number = 12;
        else if (hexString[i] == 'D')
            number = 13;
        else if (hexString[i] == 'E')
            number = 14;
        else if (hexString[i] == 'F')
            number = 15;
        else
            number = hexString[i] - '0';
        int* new = convertPartToBinary(number);
        appendToBinary(new, 4, binary, position);
        position += 4;
        free(new);
    }
    int sign = binary[0];
    int* shiftedOrder = calloc(11, sizeof(int));
    for (int i = 1; i < 13; i++)
        shiftedOrder[i - 1] = binary[i];
    int exponent = calculateExponent(shiftedOrder);
    int* mantissa = calloc(52, sizeof(int));
    for (int i = 12; i < 64; i++)
        mantissa[i - 12] = binary[i];
    double real = 1 + convertFromBinaryToReal(mantissa, 52);
    if (sign)
        real = 0 - real;
    printf("%lf * 2^%d", real, exponent);
}
