#ifndef BINARY_H
#define BINARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int* binary);
int* convertToBinary(int originalNumber);
void printBinary(int* binary);
void addBinary(int* firstTerm, int* secondTerm, int* sum);
void multiplyBinary(int* multiplied, int* multiplier, int* product);
int convertToDecimal(int* binary);
void printExponentialForm(unsigned char hex[8]);

#endif