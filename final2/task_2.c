#include "../library/map/map.h"

int compare(const void* i, const void* j)
{
    return *(int*)i - *(int*)j;
}

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* file, LinkedMap* map)
{
    char word[128] = "";
    while (fscanf(file, "%s", word) != EOF) {
        put(map, word, 1);
    }
    sortMap(map);
}

int main(int argc, char* argv[])
{
    FILE* input = fopen(argv[1], "r");
    if (!(isFileExist(input))) {
        printf("The file doesn't exist");
        return 0;
    }

    FILE* output = fopen("output.txt", "w");
    LinkedMap* map = makeNewMap();
    readFile(input, map);
    return 0;
}