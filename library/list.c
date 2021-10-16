#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {
    ListElement* head;
    ListElement* tail;
};

struct ListElement {
    char symbol;
    ListElement* nextElement;
    ListElement* previousElement;
};

List* makeNewList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

ListElement* makeNewElement(char symbol)
{
    ListElement* new = malloc(sizeof(ListElement));
    new->symbol = symbol;
    new->nextElement = NULL;
    new->previousElement = NULL;

    return new;
}

void appendElement(List* list, char symbol)
{
    ListElement* element = makeNewElement(symbol);
    if (!list->head) {
        list->head = element;
        list->tail = element;
    } else {
        list->tail->nextElement = element;
        element->previousElement = list->tail;
        list->tail = element;
    }
}

bool findFragment(ListElement* start, ListElement** beginning, ListElement** ending, char* fragment)
{
    for (ListElement* current = start; current; current = current->nextElement) {
        char string[128] = "";
        int i = 0;
        for (ListElement* element = current; element; element = element->nextElement) {
            string[i] = element->symbol;
            if (!fragment[i + 1]) {
                *beginning = current;
                *ending = element;
                break;
            }
            i++;
        }
        if (!(strcmp(string, fragment)))
            return true;
    }
    return false;
}

void deleteElements(ListElement* start, ListElement* end, List* list)
{
    ListElement* element = start;
    ListElement* startPrevious = start->previousElement;
    ListElement* endNext = end->nextElement;
    ListElement* next = element->nextElement;
    while (element != endNext) {
        printf("%c %c\n", element->symbol, next->symbol);
        element->previousElement->nextElement = next;
        next->previousElement = element->previousElement;
        free(element);
        element = next;
        next = element->nextElement;
        printList(list);
    }
    if (!startPrevious)
        list->head = endNext;
    if (!endNext)
        list->tail = startPrevious;
}

void insertElements(ListElement* current, char* fragment, List* list)
{
    if (!current)
        current = list->head;

    for (int i = 0; fragment[i]; ++i) {
        ListElement* new = makeNewElement(fragment[i]);
        new->previousElement = current;
        new->nextElement = current->nextElement;
        current->nextElement = new;
        current->nextElement->previousElement = new;
        if (current == list->tail)
            list->tail = new;
        if (current == list->head)
            list->head = new;
        current = new;
    }
}

void deleteFragment(List* list, char* start, char* end)
{
    ListElement* startBeginning = NULL;
    ListElement* startEnding = NULL;
    ListElement* endBeginning = NULL;
    ListElement* endEnding = NULL;
    if (findFragment(list->head, &startBeginning, &startEnding, start)) {
        if (findFragment(startEnding->nextElement, &endBeginning, &endEnding, end))
            deleteElements(startBeginning, endEnding, list);
        else
            printf("ERROR");
    } else
        printf("ERROR");
}

void replaceFragment(List* list, char* template, char* fragment)
{
    ListElement* templateBeginning = NULL;
    ListElement* templateEnding = NULL;

    if (findFragment(list->head, &templateBeginning, &templateEnding, template)) {
        ListElement* current = templateBeginning->previousElement;
        deleteElements(templateBeginning, templateEnding, list);
        insertElements(current, fragment, list);
    } else
        printf("ERROR");
}

void insertFragment(List* list, char* start, char* fragment)
{
    ListElement* startBeginning = NULL;
    ListElement* startEnding = NULL;
    if (findFragment(list->head, &startBeginning, &startEnding, start)) {
        ListElement* current = startEnding;
        insertElements(current, fragment, list);
    } else
        printf("ERROR");
}

void printList(List* list)
{
    for (ListElement* element = list->head; element; element = element->nextElement)
        printf("%c", element->symbol);
    printf("\n");
}

void fillList(List* list, char* data)
{
    for (int i = 0; i < strlen(data); ++i)
        appendElement(list, data[i]);
}

void freeList(List* list)
{
    ListElement* next = NULL;
    for (ListElement* element = list->head; element; element = next) {
        next = element->nextElement;
        free(element);
    }
    free(list);
}

void printListInFile(List* list, FILE* output)
{
    for (ListElement* element = list->head; element; element = element->nextElement)
        fprintf(output, "%c", element->symbol);
    fprintf(output, "\n");
}