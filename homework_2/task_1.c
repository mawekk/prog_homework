#include "../library/map.h"
#include <stdio.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void fillMap(LinkedMap* map, FILE* fileName)
{
    char word[128] = "";

    while (fscanf(fileName, "%s", word) != EOF) {
        if(hasKey(map, word))
            put(map, word, get(map, word) + 1);
        else
            put(map, word, 1);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Incorrect number of arguments");
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    if (!(isFileExist(input))) {
        printf("The file doesn't exist");
        return 0;
    }

    FILE* output = fopen(argv[2], "w");
    LinkedMap* map = makeNewMap();

    fillMap(map, input);
    printMap(map, output);
    freeMap(map);

    return 0;
}
