#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector Vector;
Vector* makeNewVector(int size, int* map);

int scalarProduct(Vector* first, Vector* second, int size);
float vectorLength(Vector* vector, int size);
void additionOfVectors(Vector* first, Vector* second, int size, int* sum_coordinates);
void vectorDifference(Vector* first, Vector* second, int size, int* difference_coordinates);

#endif