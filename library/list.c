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

void printList(List* list)
{
    for (ListElement* element = list->head; element; element = element->nextElement)
        printf("%c", element->symbol);
    printf("\n");
}


bool findFragment(ListElement* start, ListElement** beginning, ListElement** ending, char* fragment)
{
    for (ListElement* current = start; current; current = current->nextElement) {
        int i = 0;
        for (ListElement* element = current; element && element->symbol == fragment[i]; element = element->nextElement) {
            if (!fragment[i + 1]) {
                *beginning = current;
                *ending = element;
                return true;
            }
            i++;
        }
    }
    return false;
}

void deleteElements(ListElement* start, ListElement* end, List* list)
{
    ListElement* element = start;
    ListElement* startPrevious = element->previousElement;
    ListElement* endNext = end->nextElement;
    ListElement* next = element->nextElement;
    while (element != endNext) {
        if (!element->previousElement)
            list->head = next;
        else
            element->previousElement->nextElement = next;
        if (next)
            next->previousElement = element->previousElement;
        free(element);
        element = next;
        if (element)
            next = element->nextElement;
    }
    if (!startPrevious)
        list->head = endNext;
    if (!endNext)
        list->tail = startPrevious;
}

void insertElements(ListElement* current, char* fragment, List* list)
{
    for (int i = 0; fragment[i]; ++i) {
        ListElement* new = makeNewElement(fragment[i]);
        if (!current) {
            if (!list->head)
                appendElement(list, new->symbol);
            else {
                new->nextElement = list->head;
                list->head->previousElement = new;
                list->head = new;
            }
            current = list->head;
        } else {
            new->previousElement = current;
            new->nextElement = current->nextElement;
            if (current->nextElement)
                current->nextElement->previousElement = new;
            current->nextElement = new;
            if (current == list->tail)
                list->tail = new;
            current = new;
        }
    }
}

bool deleteFragment(List* list, char* start, char* end)
{
    ListElement* startBeginning = NULL;
    ListElement* startEnding = NULL;
    ListElement* endBeginning = NULL;
    ListElement* endEnding = NULL;
    if (findFragment(list->head, &startBeginning, &startEnding, start)) {
        if (findFragment(startEnding->nextElement, &endBeginning, &endEnding, end)) {
            deleteElements(startBeginning, endEnding, list);
            return true;
        }
        return false;
    }
    return false;
}

bool replaceFragment(List* list, char* template, char* fragment)
{
    ListElement* templateBeginning = NULL;
    ListElement* templateEnding = NULL;

    if (findFragment(list->head, &templateBeginning, &templateEnding, template)) {
        ListElement* current = templateBeginning->previousElement;
        deleteElements(templateBeginning, templateEnding, list);
        insertElements(current, fragment, list);
        return true;
    }
    return true;
}

bool insertFragment(List* list, char* start, char* fragment)
{
    ListElement* startBeginning = NULL;
    ListElement* startEnding = NULL;
    if (findFragment(list->head, &startBeginning, &startEnding, start)) {
        ListElement* current = startEnding;
        insertElements(current, fragment, list);
        return true;
    }
    return false;
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