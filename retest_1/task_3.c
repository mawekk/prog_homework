#include "stdio.h"
#include <stdlib.h>
#include <time.h>

void evenInsertionSort(int* array, int size)
{
    for (int i = 2; i < size; i += 2)
        for (int j = i; j > 0 && array[j - 2] > array[j]; j -= 2) {
            int buffer = array[j - 2];
            array[j - 2] = array[j];
            array[j] = buffer;
        }
}

int main()
{
    printf("If you want to enter an array from the keyboard, enter 1.\n");
    int number = 0;
    scanf("%d", &number);
    int size = 0;
    int* array = NULL;
    if (number == 1) {
        printf("Enter the size of the array:\n");
        scanf("%d", &size);
        array = calloc(size, sizeof(int));
        printf("Enter the array elements:\n");
        for (int i = 0; i < size; ++i)
            scanf("%d", &array[i]);

    } else {
        srand(time(NULL));
        size = rand() % 100;
        array = calloc(size, sizeof(int));
        for (int i = 0; i < size; ++i)
            array[i] = rand() % 31 + 11;
    }
    evenInsertionSort(array, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    free(array);
}