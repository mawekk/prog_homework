#include "../library/linkedMap/linkedMap.h"

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

int main(int argc, char* argv[])
{
    FILE* input = fopen(argv[1], "r");
    if (!(isFileExist(input))) {
        printf("The file doesn't exist");
        return 0;
    }

    LinkedMap* map = makeNewLinkedMap();
    int number = 0;
    while (fscanf(input, "%d", &number) != EOF) {
        putElement(map, number);
    }
    if (isSymmetrical(map))
        printf("The map is symmetrical.\n");
    else
        printf("The map isn't symmetrical.\n");

    freeLinkedMap(map);
    fclose(input);
}
