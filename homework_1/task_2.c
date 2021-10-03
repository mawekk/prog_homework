#include <stdio.h>
#include <stdlib.h>

int searchForTheMax(int size, int* array)
{
    int max = array[0], count = 0, position = -1;

    for (int i = 0; i < size; ++i) {
        count = 0;
        for (int k = 0; k < size; ++k) {
            if (array[i] == array[k])
                ++count;
        }
        if (count > 1 && array[i] >= max) {
            max = array[i];
            position = i;
        }
    }

    return position;
}

int main()
{
    int size = 0, position = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    int* array = calloc(size, sizeof(int));
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i)
        scanf("%d", &array[i]);

    position = searchForTheMax(size, array);
    if (position == -1)
        printf("There are not such maximum!");
    else
        printf("The maximum occurring more than 1 time: %d", array[position]);

    free(array);

    return 0;
}