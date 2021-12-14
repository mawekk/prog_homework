#include "stdio.h"

int main()
{
    printf("If you want to enter an array from the keyboard, enter 1.\n");
    int number = 0;
    scanf("%d", &number);
    if (number == 1) {
        int size = 0;
        printf("Enter the size of the array:\n");
        scanf("%d", &size);

        int* array = calloc(size, sizeof(int));
        printf("Enter the array elements:\n");
        for (int i = 0; i < size; ++i)
            scanf("%d", &array[i]);
    }
}