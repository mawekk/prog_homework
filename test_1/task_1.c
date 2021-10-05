#include "../library/vector.h"
#include <stdio.h>

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

    printf("Length of the first vector = %f\n", vectorLength(firstVector, size));
    printf("Length of the second vector = %f\n", vectorLength(secondVector, size));

    printf("Scalar product of the vectors = %d\n", scalarProduct(firstVector, secondVector, size));

    printf("Sum of the vectors:\n");
    int* sum = calloc(size, sizeof(int));
    additionOfVectors(firstVector, secondVector, size, sum);
    for (int i = 0; i < size; ++i)
        printf("%d ", sum[i]);
    printf("\n");

    printf("Difference of the vectors:\n");
    int* difference = calloc(size, sizeof(int));
    vectorDifference(firstVector, secondVector, size, difference);
    for (int i = 0; i < size; ++i)
        printf("%d ", difference[i]);
    printf("\n");

    return 0;
}