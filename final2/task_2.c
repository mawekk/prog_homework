#include "../library/tree/tree.h"
#include "strings.h"

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* file, TreeMap* map)
{
    char word[128] = "";
    while (fscanf(file, "%s", word) != EOF) {
        putKeyInTree(map, wrapString(strdup(word)), wrapNone());
    }
}

void createOutputFile(TreeMap* map)
{
    FILE* output = fopen("output.txt", "w");
    for (TreeMapIterator iterator = getIterator(map); getKey(iterator).type != NONE_TYPE; next(&iterator)) {
        fprintf(output, "%s\n", getString(getKey(iterator)));
        free(iterator.key.stringValue);
    }
    fclose(output);
}

int main(int argc, char* argv[])
{
    FILE* input = fopen(argv[1], "r");
    if (!(isFileExist(input))) {
        printf("The file doesn't exist");
        return 0;
    }

    TreeMap* map = createTreeMap(compare);
    readFile(input, map);
    createOutputFile(map);
    deleteTreeMap(map);
    fclose(input);
    return 0;
}