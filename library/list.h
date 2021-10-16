#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stdio.h>

typedef struct List List;
typedef struct ListElement ListElement;

List* makeNewList();

void fillList(List* list, char* data);
void freeList(List* list);
void printListInFile(List* list, FILE* output);

bool deleteFragment(List* list, char* start, char* end);
bool insertFragment(List* list, char* start, char* fragment);
bool replaceFragment(List* list, char* template, char* fragment);

#endif