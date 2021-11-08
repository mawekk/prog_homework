#include "../library/list/list.h"
#include <stdio.h>
#include <string.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* input, FILE* output)
{
    List* list = makeNewList();
    int size = 0;
    int numberOfLogs = 0;
    fscanf(input, "%d", &size);
    char originalData[size + 1];
    char log[128] = "";
    char firstData[128] = "";
    char secondData[128] = "";
    fscanf(input, "%s", originalData);
    fillList(list, originalData);

    fscanf(input, "%d", &numberOfLogs);
    for (int i = 0; i < numberOfLogs; ++i) {
        fscanf(input, "%s", log);
        fscanf(input, "%s", firstData);
        fscanf(input, "%s", secondData);

        if (!strcmp(log, "REPLACE")) {
            if (!replaceFragment(list, firstData, secondData)) {
                printf("REPLACEMENT ERROR! Operation number: %d", i + 1);
                break;
            }
        } else if (!strcmp(log, "INSERT")) {
            if (!insertFragment(list, firstData, secondData)) {
                printf("INSERTION ERROR! Operation number: %d", i + 1);
                break;
            }
        } else if (!strcmp(log, "DELETE")) {
            if (!deleteFragment(list, firstData, secondData)) {
                printf("DELETION ERROR! Operation number: %d", i + 1);
                break;
            }
        }
        printListInFile(list, output);
    }
    freeList(list);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Incorrect number of argument");
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    if (!(isFileExist(input))) {
        printf("The file doesn't exist");
        return 0;
    }

    FILE* output = fopen(argv[2], "w");
    readFile(input, output);
    fclose(input);
    fclose(output);
    return 0;
}