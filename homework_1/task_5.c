#include "stdlib.h"
#include <stdio.h>

void createSpiral(int size, int** matrix)
{
    int centreI = size / 2, centreJ = size / 2;
    int number = 1;
    matrix[centreI][centreJ] = number;

    for (int i = 1; i < size; ++i) {
        if (i % 2 != 0) {
            for (int k = 0; k < i; ++k) {
                ++number;
                ++centreJ;
                matrix[centreI][centreJ] = number;
            }
            for (int k = 0; k < i; ++k) {
                ++number;
                ++centreI;
                matrix[centreI][centreJ] = number;
            }
        } else {
            for (int k = 0; k < i; ++k) {
                ++number;
                --centreJ;
                matrix[centreI][centreJ] = number;
            }
            for (int k = 0; k < i; ++k) {
                ++number;
                --centreI;
                matrix[centreI][centreJ] = number;
            }
        }
    }

    for (int j = 1; j < size; ++j) {
        ++number;
        ++centreJ;
        matrix[centreI][centreJ] = number;
    }
}

int main()
{
    int number = 0;
    printf("Enter odd number:\n");
    scanf("%d", &number);
    while (number % 2 == 0) {
        printf("Error: this number is even! Enter odd number:\n");
        scanf("%d", &number);
    }

    int** matrix = calloc(number, sizeof(int*));
    for (int i = 0; i < number; ++i)
        matrix[i] = calloc(number, sizeof(int));

    createSpiral(number, matrix);

    printf("A spiral of numbers from 1 to %d:\n", number * number);
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < number; ++j)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }

    for (int i = 0; i < number; ++i)
        free(matrix[i]);
    free(matrix);

    return 0;
}