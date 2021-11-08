#ifndef BINARY_H
#define BINARY_H
#include <stdio.h>

void reverse(int* binary);
int* convertToBinary(int originalNumber);
void printBinary(int* binary);
void addBinary(int* firstTerm, int* secondTerm, int* sum);
int convertToDecimal(int* binary);

#endif