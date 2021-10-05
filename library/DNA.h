#ifndef DNA_H
#define DNA_H
#include <stdbool.h>
#include <stdio.h>

typedef struct MapDNA MapDNA;
typedef struct MapElement MapElement;
MapDNA* makeNewMap();
MapElement* makeNewElement(MapDNA* map, const char* DNA);
void deleteFragment(MapDNA* map, char* start, char* end);
void insertFragment(MapDNA* map, char* start, char* fragment);
void replaceFragment(MapDNA* map, char* template, char* fragment);

#endif