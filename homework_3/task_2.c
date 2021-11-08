#include "../library/binary/binary.h"

typedef union Number {
    double value;
    unsigned char hexForm[8];
} Number;

int main()
{
    Number number;
    printf("Enter a number:\n");
    scanf("%lf", &number.value);
    printExponentialForm(number.hexForm);
    return 0;
}