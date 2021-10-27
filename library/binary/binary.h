#ifndef BINARY_H
#define BINARY_H
#include <stdio.h>

void reverse(int* binary, int size);
void convertToBinary(int originalNumber, int* binary, int size);
void printBinary(int* binary, int size);
void addBinary(int* firstTerm, int* secondTerm, int* sum, int size);
int convertToDecimal(int* binary, int size);

#endif