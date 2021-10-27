#include "binary.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void reverse(int* binary, int size)
{
    for (int i = 0; i < size; i++)
        binary[i] = 1 - binary[i];
}

void convertToBinary(int originalNumber, int* binary, int size)
{
    int number = abs(originalNumber);
    int i = size - 1;

    while (number > 0) {
        binary[i] = number % 2;
        i--;
        number = number / 2;
    }

    if (originalNumber < 0) {
        reverse(binary, size);
        int* add = calloc(size, sizeof(int));
        convertToBinary(1, add, size);
        addBinary(add, binary, binary, size);
        free(add);
    }
}

void printBinary(int* binary, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d", binary[i]);
    printf("\n");
}

void addBinary(int* firstTerm, int* secondTerm, int* sum, int size)
{
    int memory = 0;
    int summa = 0;

    for (int i = size - 1; i >= 0; i--) {
        summa = firstTerm[i] + secondTerm[i] + memory;
        sum[i] = summa % 2;
        memory = summa / 2;
    }
}

int convertToDecimal(int* binary, int size)
{
    int number = 0;
    int degree = 1;
    int firstBite = binary[0];

    if (firstBite == 1) {
        int* add = calloc(size, sizeof(int));
        convertToBinary(-1, add, size);
        addBinary(add, binary, binary, size);
        reverse(binary, size);
        free(add);
    }
    for (int i = size - 1; i > 0; i--) {
        degree = 1;
        for (int j = 0; j < size - 1 - i; j++)
            degree = degree * 2;
        number += binary[i] * degree;
    }
    if (firstBite == 1)
        number = 0 - number;

    return number;
}

void shiftBits(int shift, int* binary, int* newBinary, int size)
{
    for (int i = 0; i < size; i++)
        newBinary[i] = binary[i];
    for (int j = 0; j < shift; j++) {
        for (int i = 0; i < size - 1; i++)
            newBinary[i] = newBinary[i + 1];
        newBinary[size - 1] = 0;
    }
}

void multiplyBinary(int* multiplied, int* multiplier, int* product, int size)
{
    int* term = calloc(size, sizeof(int));
    int shift = 0;

    for (int i = 0; i < size; i++)
        product[i] = 0;

    for (int i = size - 1; i >= 0; i--) {
        if (multiplier[i] == 1) {
            shiftBits(shift, multiplied, term, size);
            addBinary(product, term, product, size);
        }
        ++shift;
    }

    free(term);
}
