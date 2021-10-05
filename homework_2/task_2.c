#include "../library/DNA.h"
#include <stdio.h>
#include <string.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readLogs(MapDNA* map, FILE* fileName)
{
    int size = 0, numberOfLogs = 0;
    fscanf(fileName, "%d", &size);
    char originalDNA[size], log[128] = "", firstData[128] = "", secondData[128] = "";
    fscanf(fileName, "%s", originalDNA);
    makeNewElement(map, originalDNA);

    fscanf(fileName, "%d", &numberOfLogs);
    for (int i = 0; i < numberOfLogs; ++i) {
        fscanf(fileName, "%s", log);
        fscanf(fileName, "%s", firstData);
        fscanf(fileName, "%s", secondData);
        if (strcmp(log, "REPLACE"))
            replaceFragment(map, firstData, secondData);
        else if (strcmp(log, "INSERT"))
            insertFragment(map, firstData, secondData);
        else
            deleteFragment(map, firstData, secondData);

    }
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Incorrect number of argument");
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    if (!isFileExist(input)) {
        printf("The file doesn't exist");
        return 0;
    }

    MapDNA* map = makeNewMap();
    readLogs(map, input);
    return 0;
}