#include "DNA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MapDNA
{
    MapElement* head;
    int mapSize;
};

struct MapElement
{
    const char* DNA;
    MapElement* nextElement;
};

MapDNA* makeNewMap()
{
    MapDNA* map = malloc(sizeof(MapDNA));
    map->mapSize = 0;
    map->head = NULL;

    return map;
}

MapElement* makeNewElement(MapDNA* map, const char* DNA)
{
    MapElement* new = malloc(sizeof(MapElement));
    new->nextElement = map->head;
    map->head = new;
    new->DNA = strdup(DNA);

    return new;
}

void deleteFragment(MapDNA* map, char* start, char* end)
{
    MapElement* element  = map->head;
    char* dna = strdup(element->DNA);
    char* first = strstr(dna, start);

    for (int i = 0; i < strlen(first); ++i) {
        for (int j = 0; j < strlen(dna); ++j)
            first[j] = first[j + 1];
    }
    for (int i = 0; i < strlen(end); ++i) {
        for (int j = 0; j < strlen(dna); ++j)
            first[j] = first[j + 1];
    }

    makeNewElement(map, dna);
    printf("%s", dna);
}

void replaceFragment(MapDNA* map, char* template, char* fragment)
{
    MapElement* element = map->head;
    char* dna = strdup(element->DNA);
    char* string = strstr(dna, template);

    for (int i = 0; i < strlen(fragment); ++i)
        string[i] = fragment[i];
    for (int i = 0; i < strlen((template)) - strlen(fragment); ++i) {
        for (int j = strlen(fragment); j < strlen(string); ++j) {
            string[j] = string[j + 1];
        }
    }

    makeNewElement(map, dna);
}

void insertFragment(MapDNA* map, char* start, char* fragment)
{
    MapElement* element = map->head;
    char* dna = strdup(element->DNA);
    char* position = strstr(dna, start);

    for (int i = strlen(position) + 1; i > strlen(start); --i)
        position[i] = position[i - 1];

    for (int i = strlen(start); i < strlen(start) + strlen(fragment); ++i)
        position[i] = fragment[i - strlen(start)];

    makeNewElement(map, dna);
}