#include "../library/list.h"
#include <stdio.h>
#include <string.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(List* list, FILE* fileName)
{
    int size = 0, numberOfLogs = 0;
    fscanf(fileName, "%d", &size);
    char originalData[size], log[128] = "", firstData[128] = "", secondData[128] = "";
    fscanf(fileName, "%s", originalData);
    printf("%s\n", originalData);
    fillList(list, originalData);

    fscanf(fileName, "%d", &numberOfLogs);
    for (int i = 0; i < numberOfLogs; ++i) {
        fscanf(fileName, "%s", log);
        fscanf(fileName, "%s", firstData);
        fscanf(fileName, "%s", secondData);
        printf("%s\n", log);
        printf("%s %s\n", firstData, secondData);

        if (!strcmp(log, "REPLACE")) {
            replaceFragment(list, firstData, secondData);
            printList(list);
        }
        else if (!strcmp(log, "INSERT")) {
            insertFragment(list, firstData, secondData);
            printList(list);
        }
        else if (!strcmp(log, "DELETE")) {
            deleteFragment(list, firstData, secondData);
            printList(list);
        }
        getchar();

    }
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

    List* list = makeNewList();
    readFile(list, input);
    return 0;
}