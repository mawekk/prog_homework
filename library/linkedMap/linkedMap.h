#ifndef LINKED_MAP_H
#define LINKED_MAP_H
#include <stdbool.h>
#include <stdio.h>

typedef struct LinkedMap LinkedMap;
typedef struct MapElement MapElement;

LinkedMap* makeNewLinkedMap();
void putElement(LinkedMap* map, int value);
bool isSymmetrical(LinkedMap* map);
void freeLinkedMap(LinkedMap* map);

#endif