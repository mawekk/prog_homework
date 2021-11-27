#include "../library/tree/tree.h"
#include "string.h"
#include <stdio.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* inputFile, FILE* outputFile, TreeMap* tree)
{
    int numberOfLogs = 0;
    fscanf(inputFile, "%d", &numberOfLogs);

    for (int i = 0; i < numberOfLogs; i++) {
        char log[22] = "";
        int size = 0;
        int count = 0;
        fscanf(inputFile, "%s", &log);
        fscanf(inputFile, "%d", &size);
        Value key = wrapInt(size);
        if (!strcmp(log, "ADD")) {
            fscanf(inputFile, "%d", &count);
            Value value = wrapInt(count);
            if (hasKeyInTree(tree, key)) {
                Pair* pair = getKeyFromTree(tree, key);
                value = wrapInt(count + getInt(pair->value));
                free(pair);
            }
            putKeyInTree(tree, key, value);
        } else if (!strcmp(log, "GET")) {
            if (hasKeyInTree(tree, key)) {
                Pair* pair = getKeyFromTree(tree, key);
                fprintf(outputFile, "%d\n", getInt(pair->value));
                free(pair);
            } else
                fprintf(outputFile, "0\n");
        } else if (!strcmp(log, "SELECT")) {
            Value sizeValue = getLowerBound(tree, key);
            if (sizeValue.type == NONE_TYPE)
                fprintf(outputFile, "SORRY\n");
            else {
                Pair* pair = getKeyFromTree(tree, sizeValue);
                fprintf(outputFile, "%d\n", getInt(pair->key));
                putKeyInTree(tree, sizeValue, wrapInt(getInt(pair->value) - 1));
                if (pair->value.intValue - 1 <= 0) {
                    removeKeyFromTree(tree, pair->key);
                }
                free(pair);
            }
        }
    }
}

void printResultInFile(FILE* fileName, TreeMap* tree)
{
    TreeMapIterator iterator = getIterator(tree);
    while (true) {
        fprintf(fileName, "%d %d\n", getInt(getKey(iterator)), getInt(getValue(iterator)));
        next(&iterator);
        if (getKey(iterator).type == NONE_TYPE)
            break;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Wrong number of arguments\n");
        return 0;
    }
    FILE* input = fopen(argv[1], "r");
    if (!isFileExist(input)) {
        printf("File doesn't exist\n");
        return 0;
    }

    FILE* output = fopen(argv[2], "w");
    TreeMap* tree = createTreeMap(compare);
    readFile(input, output, tree);
    FILE* result = fopen(argv[3], "w");
    printResultInFile(result, tree);
    deleteTreeMap(tree);
    return 0;
}