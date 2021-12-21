#ifndef LIST_WITH_COUNT
#define LIST_WITH_COUNT

#include <stdio.h>

typedef struct ListWithCount ListWithCount;
typedef struct ListElement ListElement;

ListWithCount* makeNewListWithCount();
void append(ListWithCount* list, int data);
int getListSize(ListWithCount* l);
void fillArrays(ListWithCount* list, int* numbers, int* count);
void freeListWithCount(ListWithCount* list);

#endif // LIST_WITH_COUNT