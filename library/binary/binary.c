#include "binary.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void reverse(int* binary)
{
    for (int i = 0; i < 16; i++) {
        if (binary[i] == 0)
            binary[i] = 1;
        else
            binary[i] = 0;
    }
}

void convertToBinary(int originalNumber, int* binary)
{
    int number = abs(originalNumber);
    int i = 15;

    while (number > 0) {
        if (number % 2 == 0)
            binary[i] = 0;
        else
            binary[i] = 1;
        i--;
        number = number / 2;
    }

    if (originalNumber < 0) {
        reverse(binary);
    }
}

void printBinary(int* binary)
{
    for (int i = 0; i < 16; i++)
        printf("%d", binary[i]);
    printf("\n");
}

void addBinary(int* firstTerm, int* secondTerm, int* sum)
{
    int memory = 0;

    for (int i = 15; i >= 0; i--) {
        sum[i] = firstTerm[i] + secondTerm[i] + memory;
        if (sum[i] == 2) {
            sum[i] = 0;
            memory = 1;
        } else if (sum[i] == 3) {
            sum[i] = 1;
            memory = 1;
        } else
            memory = 0;
    }

    if (memory == 1) {
        int* remain = calloc(16, sizeof(int));
        convertToBinary(memory, remain);
        addBinary(remain, sum, sum);
    }
}

int convertToDecimal(int* binary)
{
    int number = 0;
    int degree = 1;
    int firstBite = binary[0];

    if (firstBite == 1)
        reverse(binary);
    for (int i = 15; i > 0; i--) {
        degree = 1;
        for (int j = 0; j < 15 - i; j++)
            degree = degree * 2;
        number += binary[i] * degree;
    }
    if (firstBite == 1)
        number = 0 - number;

    return number;
}
