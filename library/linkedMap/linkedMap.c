#include "linkedMap.h"
#include <stdio.h>
#include <stdlib.h>

struct LinkedMap {
    MapElement* head;
    MapElement* tail;
    int mapSize;
};

struct MapElement {
    int value;
    MapElement* nextElement;
    MapElement* previousElement;
};

LinkedMap* makeNewLinkedMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->head = NULL;
    map->tail = NULL;
    map->mapSize = 0;
    return map;
}

MapElement* makeNewLinkedMapElement(int value, LinkedMap* map)
{
    MapElement* newElement = malloc(sizeof(MapElement));
    newElement->value = value;
    newElement->nextElement = NULL;
    newElement->previousElement = NULL;
    return newElement;
}

void putElement(LinkedMap* map, int value)
{
    MapElement* element = makeNewLinkedMapElement(value, map);
    if (!map->head) {
        map->head = element;
        map->tail = element;
    } else {
        element->previousElement = map->tail;
        map->tail->nextElement = element;
        map->tail = element;
    }
    map->mapSize++;
}

bool isSymmetrical(LinkedMap* map)
{
    MapElement* first = map->head;
    MapElement* second = map->tail;
    for (int i = 0; i < map->mapSize / 2; i++) {
        if (first->value != second->value)
            return false;
        first = first->nextElement;
        second = second->previousElement;
    }
    return true;
}

void freeLinkedMap(LinkedMap* map)
{
    MapElement* next = NULL;
    for (MapElement* currentElement = map->head; currentElement; currentElement = next) {
        next = currentElement->nextElement;
        free(currentElement);
    }
    free(map);
}