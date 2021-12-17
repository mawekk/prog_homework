#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include "stdio.h"

typedef struct ComplexNumber ComplexNumber;

ComplexNumber* createComplexNumber(double real, double imaginary);
void deleteComplexNumber(ComplexNumber* number);
ComplexNumber* addComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* subtractComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* multiplyComplexNumbers(ComplexNumber* first, ComplexNumber* second);
ComplexNumber* divideComplexNumbers(ComplexNumber* first, ComplexNumber* second);
double complexNumberModule(ComplexNumber* number);
void printComplexNumber(ComplexNumber* number);

#endif // COMPLEX_NUMBER_H