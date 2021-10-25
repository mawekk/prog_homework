#include "../library/sort/mergeSort.h"

int main()
{
    int size = 0;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int* array = calloc(size, sizeof(int));
    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    mergeSort(array, size);
    printf("Merge sorted array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}