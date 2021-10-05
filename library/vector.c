#include "vector.h"
#include "math.h"
#include <stdlib.h>

struct Vector {
    int* coordinates;
};

Vector* makeNewVector(int size, int* map)
{
    Vector* new = malloc(sizeof(Vector));
    new->coordinates = map;

    return new;
}

int scalarProduct(Vector* first, Vector* second, int size)
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        result = result + first->coordinates[i] * second->coordinates[i];

    return result;
}

float vectorLength(Vector* vector, int size)
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        result = result + vector->coordinates[i] * vector->coordinates[i];

    return sqrt(result);
}

void additionOfVectors(Vector* first, Vector* second, int size, int* sum_coordinates)
{
    for (int i = 0; i < size; ++i)
        sum_coordinates[i] = first->coordinates[i] + second->coordinates[i];
}

void vectorDifference(Vector* first, Vector* second, int size, int* difference_coordinates)
{
    for (int i = 0; i < size; ++i)
        difference_coordinates[i] = first->coordinates[i] - second->coordinates[i];
}

void freeVector(Vector* vector)
{
    free(vector);
}