#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stdio.h>

typedef struct List List;
typedef struct ListElement ListElement;

List* makeNewList();

void fillList(List* list, char* data);
void printList(List* list);
void freeList(List* list);
void printListInFile(List* list, FILE* output);

void deleteFragment(List* list, char* start, char* end);
void insertFragment(List* list, char* start, char* fragment);
void replaceFragment(List* list, char* template, char* fragment);

#endif