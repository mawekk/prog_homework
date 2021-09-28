#include <stdbool.h>

typedef struct LinkedMap LinkedMap;
typedef struct MapElement MapElement;

LinkedMap *makeNewMap();
MapElement *makeNewMapElement(const char *key, int value, LinkedMap *map);
bool hasKey(LinkedMap *map, const char *key);
void put(LinkedMap *map, const char *key, int value);
int get(LinkedMap *map, const char *key);
void printMap(LinkedMap *map);