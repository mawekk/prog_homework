#include <stdio.h>
#include <stdlib.h>
#include "../library/mergeSort/mergeSort.h"

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
    int* newArray = calloc(firstNumber + secondNumber, sizeof(int));
    for (int i = 0; i < firstNumber; i ++)
        newArray[i] = firstArray[i];
    for (int i = firstNumber; i < firstNumber + secondNumber; i ++)
        newArray[i] = secondArray[i - firstNumber];
    for (int i = 0; i < firstNumber + secondNumber; i++)
        printf("%d ", newArray[i]);
    printf("\n");
    mergeSort(newArray, firstNumber + secondNumber);
    for (int i = 0; i < firstNumber + secondNumber; i++)
        printf("%d ", newArray[i]);
    free(firstArray);
    free(secondArray);
    free(newArray);
}
