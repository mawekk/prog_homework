#include <stdio.h>
#include <stdlib.h>

void changeTheBeginningAndEnd(int beginning, int size, int* array)
{
    int element;

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
    int m, n, size;
    printf("Enter m:\n");
    scanf("%d", &m);
    printf("Enter n:\n");
    scanf("%d", &n);
    size = m + n;

    int* array = calloc(size, sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    changeTheBeginningAndEnd(m, size, array);

    printf("The new array:\n");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);

    free(array);

    return 0;
}