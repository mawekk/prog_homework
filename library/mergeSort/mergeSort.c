#include "mergeSort.h"

void mergeSort(int* array, int size)
{
    int step = 1;
    int* newArray = calloc(size, sizeof(int));
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
                if (array[first] < array[second])
                    newArray[index++] = array[first++];
                else
                    newArray[index++] = array[second++];
            }
            if (first == mid) {
                while (second < right)
                    newArray[index++] = array[second++];
            } else {
                while (first < mid)
                    newArray[index++] = array[first++];
            }
            left += step * 2;
            mid = left + step;
            right = mid + step;
        }
        for (int i = 0; i < size; i++)
            array[i] = newArray[i];
        step += step;
    }
}