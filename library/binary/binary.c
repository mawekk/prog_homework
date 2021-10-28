#include "binary.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
