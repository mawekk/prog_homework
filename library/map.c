#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedMap {
    MapElement* tail;
    int mapSize;
};

struct MapElement {
    const char* key;
    int value;
    MapElement* previousElement;
};

LinkedMap* makeNewMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->tail = NULL;
    map->mapSize = 0;
    return map;
}

MapElement* makeNewMapElement(const char* key, int value, LinkedMap* map)
{
    MapElement* newElement = malloc(sizeof(MapElement));
    newElement->key = strdup(key);
    newElement->value = value;
    newElement->previousElement = map->tail;
    map->tail = newElement;
    map->mapSize++;
    return newElement;
}

MapElement* findKey(LinkedMap* map, const char* key)
{
    for (MapElement* currentElement = map->tail; currentElement; currentElement = currentElement->previousElement) {
        if (strcmp(currentElement->key, key) == 0)
            return currentElement;
    }

    return NULL;
}

bool hasKey(LinkedMap* map, const char* key)
{
    return findKey(map, key);
}

void put(LinkedMap* map, const char* key, int value)
{
    MapElement* currentElement = hasKey(map, key);
    if (currentElement)
        currentElement->value = value;
    else
        makeNewMapElement(key, value, map);
}

int get(LinkedMap* map, const char* key)
{
    MapElement* currentElement = findKey(map, key);
    return currentElement->value;
}

void printMap(LinkedMap* map, FILE* fileName)
{
    for (MapElement* currentElement = map->tail; currentElement; currentElement = currentElement->previousElement)
        fprintf(fileName, "%s,%d\n", currentElement->key, currentElement->value);
}

void freeMap(LinkedMap* map)
{
    MapElement* previous = NULL;
    for (MapElement* currentElement; currentElement; currentElement = previous) {
        free(currentElement->key);
        previous = currentElement->previousElement;
        free(currentElement);
    }
    free(map);
}