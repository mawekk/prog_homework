#include "../library/listWithCount/listWithCount.h"
#include "stdio.h"
#include "stdlib.h"

void sort(int* array, int* count, int size)
{
    int step = 1;
    int* newArray = calloc(size, sizeof(int));
    int* newCount = calloc(size, sizeof(int));
    while (step < size) {
        int index = 0;
        int left = 0;
        int mid = step;
        int right = step * 2;

        while (left < size) {
            mid = mid < size ? mid : size;
            right = right < size ? right : size;
            int first = left;
            int second = mid;

            while (first < mid & second < right) {
                if (array[first] < array[second]) {
                    newArray[index] = array[first];
                    newCount[index++] = count[first++];
                } else {
                    newArray[index] = array[second];
                    newCount[index++] = count[second++];
                }
            }

            if (first == mid) {
                while (second < right) {
                    newArray[index] = array[second];
                    newCount[index++] = count[second++];
                }

            } else {
                while (first < mid) {
                    newArray[index] = array[first];
                    newCount[index++] = count[first++];
                }
            }

            left += step * 2;
            mid = left + step;
            right = mid + step;
        }

        for (int i = 0; i < size; i++) {
            count[i] = newCount[i];
            array[i] = newArray[i];
        }
        step += step;
    }

    free(newArray);
    free(newCount);
}

int main()
{
    int number = 1;
    ListWithCount* list = makeNewListWithCount();
    printf("Enter numbers:\n");
    while (number != 0) {
        scanf("%d", &number);
        if (number != 0)
            append(list, number);
    }

    int size = getListSize(list);
    int* numbers = calloc(size, sizeof(int));
    int* count = calloc(size, sizeof(int));
    fillArrays(list, numbers, count);

    sort(numbers, count, size);

    for (int i = 0; i < size; i++)
        printf("%d %d\n", numbers[i], count[i]);

    free(numbers);
    free(count);
    freeListWithCount(list);

    return 0;
}