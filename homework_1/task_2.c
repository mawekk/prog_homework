#include <stdio.h>
#include <stdlib.h>

int max = 0;

int searchForTheMax(int size, int* array)
{
    int count = 0, position = 0, currSize = size;
    max = array[0];

    while (count <= 1) {
        for (int i = 0; i < currSize; ++i) {
            if (array[i] > max) {
                max = array[i];
                position = i;
            }
        }
        for (int i = 0; i < currSize; ++i)
            if (array[i] == max) {
                ++count;
            }
        if (count == 1) {
            for (int i = position; i < currSize - 1; ++i)
                array[i] = array[i + 1];
            count = 0;
            currSize = currSize - 1;
            max = array[0];
        }
        if (currSize <= 1)
            break;
    }

    return currSize;
}

int main()
{
    int size = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    int* array = calloc(size, sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    size = searchForTheMax(size, array);
    if (size <= 1)
        printf("There are not such maximum!");
    else
        printf("The maximum occurring more than 1 time: %d", max);

    free(array);

    return 0;
}