#include <stdio.h>
#include <stdlib.h>

int searchForTheMax(int size, int* array)
{
    int max = array[0], count = 0, position = 0, curr_size = size;

    while (count <= 1) {
        for (int i = 0; i < curr_size; ++i) {
            if (array[i] > max) {
                max = array[i];
                position = i;
            }
        }
        for (int i = 0; i < curr_size; ++i)
            if (array[i] == max) {
                ++count;
            }
        if (count == 1) {
            for (int i = position; i < curr_size - 1; ++i)
                array[i] = array[i + 1];
            count = 0;
            curr_size = curr_size - 1;
            max = array[0];
        }
        if (curr_size == 1) {
            printf("There are not such maximum!");
            exit(0);
        }
    }

    return max;
}

int main()
{
    int size;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    int* array;
    array = calloc(size, sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    printf("The maximum occurring more than 1 time: %d", searchForTheMax(size, array));

    free(array);

    return 0;
}