#include "../library/complexNumber/complexNumber.h"

int main()
{
    double firstReal = 0;
    double firstImaginary = 0;
    printf("Enter the real and the imaginary part of the first number:\n");
    scanf("%lf", &firstReal);
    scanf("%lf", &firstImaginary);
    double secondReal = 0;
    double secondImaginary = 0;
    printf("Enter the real and the imaginary part of the second number:\n");
    scanf("%lf", &secondReal);
    scanf("%lf", &secondImaginary);

    ComplexNumber* first = createComplexNumber(firstReal, firstImaginary);
    ComplexNumber* second = createComplexNumber(secondReal, secondImaginary);

    ComplexNumber* sum = addComplexNumbers(first, second);
    printf("Sum of complex numbers = ");
    printComplexNumber(sum);
    ComplexNumber* subtract = subtractComplexNumbers(first, second);
    printf("Subtract of complex numbers = ");
    printComplexNumber(subtract);
    ComplexNumber* product = multiplyComplexNumbers(first, second);
    printf("Product of complex numbers = ");
    printComplexNumber(product);
    ComplexNumber* ratio = divideComplexNumbers(first, second);
    printf("Ratio of complex numbers = ");
    printComplexNumber(ratio);

    double firstModule = complexNumberModule(first);
    printf("Module of first complex number = %lf\n", firstModule);
    double secondModule = complexNumberModule(second);
    printf("Module of second complex number = %lf", secondModule);

    deleteComplexNumber(first);
    deleteComplexNumber(second);
    deleteComplexNumber(sum);
    deleteComplexNumber(subtract);
    deleteComplexNumber(product);
    deleteComplexNumber(ratio);
}
