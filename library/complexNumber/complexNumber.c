#include "complexNumber.h"
#include "math.h"
#include <stdlib.h>

struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber* createComplexNumber(double real, double imaginary)
{
    ComplexNumber* newNumber = malloc(sizeof(ComplexNumber));
    newNumber->real = real;
    newNumber->imaginary = imaginary;
    return newNumber;
}

void deleteComplexNumber(ComplexNumber* number)
{
    free(number);
}

ComplexNumber* addComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    ComplexNumber* sumNumber = createComplexNumber(first->real + second->real, first->imaginary + second->imaginary);
    return sumNumber;
}

ComplexNumber* subtractComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    ComplexNumber* differenceNumber = createComplexNumber(first->real - second->real, first->imaginary - second->imaginary);
    return differenceNumber;
}

ComplexNumber* multiplyComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    double newReal = first->real * second->real - first->imaginary * second->imaginary;
    double newImaginary = first->real * second->imaginary + first->imaginary * second->real;
    ComplexNumber* productNumber = createComplexNumber(newReal, newImaginary);
    return productNumber;
}

ComplexNumber* divideComplexNumbers(ComplexNumber* first, ComplexNumber* second)
{
    double newReal = (first->real * second->real + first->imaginary * second->imaginary) / (second->real * second->real + second->imaginary * second->imaginary);
    double newImaginary = (first->imaginary * second->real - first->real * second->imaginary) / (second->real * second->real + second->imaginary * second->imaginary);
    ComplexNumber* ratioNumber = createComplexNumber(newReal, newImaginary);
    return ratioNumber;
}
double complexNumberModule(ComplexNumber* number)
{
    return sqrt(number->real * number->real + number->imaginary * number->imaginary);
}

void printComplexNumber(ComplexNumber* number)
{
    printf("%lf + (%lf)i\n", number->real, number->imaginary);
}