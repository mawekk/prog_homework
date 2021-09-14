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
    int n;
    printf("Enter odd n:\n");
    scanf("%d", &n);
    while (n % 2 == 0) {
        printf("Error! Enter odd n:\n");
        scanf("%d", &n);
    }

    int** matrix = calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i)
        matrix[i] = calloc(n, sizeof(int));

    createSpiral(n, matrix);

    printf("A spiral of numbers from 1 to %d:\n", n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%3d ", matrix[i][j]);
        printf("\n");
    }

    free(matrix);

    return 0;
}