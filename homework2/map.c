#include "map.h"
#include <stdio.h>
#include <stdlib.h>

struct LinkedMap {
    MapElement *tail;
    int mapSize;
};

struct MapElement {
    const char *key;
    int value;
    MapElement *prevElement;
};

LinkedMap *makeNewMap()
{
    LinkedMap *map = malloc(sizeof(LinkedMap));
    map->tail = NULL;
    map->mapSize = 0;
    return map;
}

MapElement *makeNewMapElement(const char *key, int value, LinkedMap *map)
{
    MapElement *newElement = malloc(sizeof(MapElement));
    newElement->key = key;
    newElement->value = value;
    newElement->prevElement = map->tail;
    map->tail = newElement;
    map->mapSize = map->mapSize + 1;
    return newElement;
}

bool hasKey(LinkedMap *map, const char *key)
{
    MapElement *currElement = map->tail;
    for (int i = 0; i < map->mapSize; ++i) {
        if (currElement->key == key)
            return true;
        else
            currElement = currElement->prevElement;
    }

    return false;
}

void put(LinkedMap *map, const char *key, int value) {
    if (hasKey(map, key)) {
        MapElement *currElement = map->tail;
        for (int i = 0; i < map->mapSize; ++i) {
            if (currElement->key == key) {
                currElement->value = get(map, key) + value;
            }
            else
                currElement = currElement->prevElement;
        }
    }
    else
        makeNewMapElement(key, value, map);
}

int get(LinkedMap *map, const char *key)
{
    MapElement *currElement = map->tail;
    for (int i = 0; i < map->mapSize; ++i) {
        if (currElement->key == key)
            return currElement->value;
        else
            currElement = currElement->prevElement;
    }
}

void printMap(LinkedMap *map)
{
    MapElement *currElement = map->tail;
    for (int i = 0; i < map->mapSize; ++i) {
        printf("%s, %d\n", currElement->key, currElement->value);
        currElement = currElement->prevElement;
    }
}