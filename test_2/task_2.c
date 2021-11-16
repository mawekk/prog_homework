#include <stdio.h>
#include <stdlib.h>

void mergeAndPrint(int* first, int* second, int firstSize, int secondSize)
{
    int* new = calloc(firstSize + secondSize, sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < firstSize & j < secondSize) {
        if (first[i] > second[j])
            new[k++] = first[i++];
        else
            new[k++] = second[j++];
    }
    if (i == firstSize) {
        while (j < secondSize)
            new[k++] = second[j++];
    } else {
        while (i < firstSize)
            new[k++] = first[i++];
    }
    printf("Sorted array:\n");
    for (int i = 0; i < firstSize + secondSize; i++)
        printf("%d ", new[i]);

    free(new);
}

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;
    printf("Enter the size of the first array:\n");
    scanf("%d", &firstNumber);
    int* firstArray = calloc(firstNumber, sizeof(int));
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < firstNumber; i++)
        scanf("%d", &firstArray[i]);
    printf("Enter the size of the second array:\n");
    scanf("%d", &secondNumber);
    int* secondArray = calloc(secondNumber, sizeof(int));
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < secondNumber; i++)
        scanf("%d", &secondArray[i]);
    mergeAndPrint(firstArray, secondArray, firstNumber, secondNumber);
    free(firstArray);
    free(secondArray);
    return 0;
}

//Сложность алгоритма = О(n), n - количество элементов в двух массивах
