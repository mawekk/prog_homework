#include <stdio.h>
#include <stdlib.h>

void changeTheBeginningAndEnd(int beginning, int size, int* array)
{
    int element = 0;

    for (int i = beginning; i < size; ++i) {
        for (int j = i; j > i - beginning; --j) {
            element = array[j];
            array[j] = array[j - 1];
            array[j - 1] = element;
        }
    }
}

int main()
{
    int length1 = 0, length2 = 0, size = 0;
    printf("Enter the length of the first part of the array:\n");
    scanf("%d", &length1);
    printf("Enter the length of the second part of the array:\n");
    scanf("%d", &length2);
    size = length1 + length2;

    int* array = calloc(size, sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    changeTheBeginningAndEnd(length1, size, array);

    printf("The new array:\n");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    free(array);

    return 0;
}