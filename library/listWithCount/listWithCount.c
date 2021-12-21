#include "listWithCount.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct ListWithCount {
    ListElement* head;
    ListElement* tail;
    int listSize;
};

struct ListElement {
    int data;
    int count;
    ListElement* nextElement;
};

ListWithCount* makeNewListWithCount()
{
    ListWithCount* lst = malloc(sizeof(ListWithCount));
    lst->head = NULL;
    lst->tail = NULL;
    lst->listSize = 0;
    return lst;
}

ListElement* makeNewListElement(int data)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    newElement->data = data;
    newElement->count = 1;
    newElement->nextElement = NULL;
    return newElement;
}

void append(ListWithCount* list, int data)
{
    if (list->tail && list->tail->data == data)
        list->tail->count++;
    else {
        ListElement* element = makeNewListElement(data);
        if (!list->head) {
            list->head = element;
            list->tail = element;
        } else {
            list->tail->nextElement = element;
            list->tail = element;
        }
        list->listSize++;
    }
}

int getListSize(ListWithCount* lst)
{
    return lst->listSize;
}

void fillArrays(ListWithCount* list, int* numbers, int* count)
{
    int i = 0;
    for (ListElement* current = list->head; current; current = current->nextElement) {
        numbers[i] = current->data;
        count[i] = current->count;
        ++i;
    }
}

void freeListWithCount(ListWithCount* list)
{
    ListElement* next = NULL;
    for (ListElement* element = list->head; element; element = next) {
        next = element->nextElement;
        free(element);
    }
    free(list);
}