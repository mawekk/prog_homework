#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedMap {
    MapElement* tail;
    int mapSize;
};

struct MapElement {
    const char *key;
    int value;
    MapElement* prevElement;
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
    newElement->prevElement = map->tail;
    map->tail = newElement;
    map->mapSize = map->mapSize + 1;
    return newElement;
}

MapElement* findKey(LinkedMap* map, const char* key)
{
    for (MapElement* currElement = map->tail; currElement; currElement = currElement->prevElement) {
        if (strcmp(currElement->key, key) == 0)
            return currElement;
    }

    return NULL;
}

bool hasKey(LinkedMap* map, const char* key)
{
    return findKey(map, key);
}

void put(LinkedMap* map, const char* key, int value)
{
    if (hasKey(map, key)) {
        MapElement* currElement = findKey(map, key);
        currElement->value = get(map, key) + value;
    }
    else
        makeNewMapElement(key, value, map);
}

int get(LinkedMap* map, const char* key)
{
    MapElement* currElement = findKey(map, key);
    return currElement->value;
}

void printMap(LinkedMap* map, FILE* fileName)
{
    for (MapElement* currElement = map->tail; currElement; currElement = currElement->prevElement)
        fprintf(fileName, "%s: %d\n", currElement->key, currElement->value);
}

void freeMap(LinkedMap* map)
{
    for (MapElement* currElement = map->tail; currElement; currElement = currElement->prevElement)
        free(currElement);
    free(map);
}