#include "../library/vector.h"
#include <stdio.h>

void printValues(Vector* firstVector, Vector* secondVector, int size)
{
    int* sum = calloc(size, sizeof(int));
    int* difference = calloc(size, sizeof(int));

    printf("Length of the first vector = %f\n", vectorLength(firstVector, size));
    printf("Length of the second vector = %f\n", vectorLength(secondVector, size));

    printf("Scalar product of the vectors = %d\n", scalarProduct(firstVector, secondVector, size));

    printf("Sum of the vectors:\n");
    additionOfVectors(firstVector, secondVector, size, sum);
    for (int i = 0; i < size; ++i)
        printf("%d ", sum[i]);
    printf("\n");

    printf("Difference of the vectors:\n");
    vectorDifference(firstVector, secondVector, size, difference);
    for (int i = 0; i < size; ++i)
        printf("%d ", difference[i]);
    printf("\n");
}

int main()
{
    int size = 0;

    printf("Enter the size of vector space:\n");
    scanf("%d", &size);

    int* firstCoordinates = calloc(size, sizeof(int));
    int* secondCoordinates = calloc(size, sizeof(int));

    printf("Enter the coordinates of the first vector:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &firstCoordinates[i]);
    Vector* firstVector = makeNewVector(size, firstCoordinates);

    printf("Enter the coordinates of the second vector:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &secondCoordinates[i]);
    Vector* secondVector = makeNewVector(size, secondCoordinates);

    printValues(firstVector, secondVector, size);

    return 0;
}