#include "../library/tree/tree.h"
#include "string.h"
#include <stdio.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* inputFile, FILE* outputFile, FILE* resultFile)
{
    int numberOfLogs = 0;
    fscanf(inputFile, "%d", &numberOfLogs);
    TreeMap* tree = createTreeMap(compare);

    for (int i = 0; i < numberOfLogs; i++) {
        char log[22] = "";
        int size = 0;
        int count = 0;
        fscanf(inputFile, "%s", &log);
        fscanf(inputFile, "%d", &size);
        printf("%d %s %d\n", i, log, size);
        Value key = wrapInt(size);
        if (!strcmp(log, "ADD")) {
            fscanf(inputFile, "%d", &count);
            Value value = wrapInt(count);
            if (hasKeyInTree(tree, key)) {
                Pair* pair = getKeyFromTree(tree, key);
                value = wrapInt(count + getInt(pair->value));
            }
            putKeyInTree(tree, key, value);
        } else if (!strcmp(log, "GET")) {
            if (hasKeyInTree(tree, key)) {
                Pair* pair = getKeyFromTree(tree, key);
                fprintf(outputFile, "%d\n", getInt(pair->value));
            } else
                fprintf(outputFile, "0\n");
        } else if (!strcmp(log, "SELECT")) {
            Value sizeValue = getLowerBound(tree, key);
            if (sizeValue.type == NONE_TYPE)
                fprintf(outputFile, "SORRY\n");
            else {
                Pair* pair = getKeyFromTree(tree, sizeValue);
                printf("%d %d %d\n", key.intValue, sizeValue.intValue, pair->value.intValue);
                fprintf(outputFile, "%d\n", getInt(pair->key));
                putKeyInTree(tree, sizeValue, wrapInt(getInt(pair->value) - 1));
                printf("%d\n", pair->value.intValue);
                if (pair->value.intValue - 1 <= 0) {
                    removeKeyFromTree(tree, pair->key);
                    printf("del\n");
                    printf("%d\n", hasKeyInTree(tree, pair->key));
                }
            }
        }
    }
    printInFile(tree, resultFile);
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
    FILE* result = fopen(argv[3], "w");
    readFile(input, output, result);
    return 0;
}