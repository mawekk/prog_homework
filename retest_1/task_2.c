#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readFile(FILE* fileName, int* letters)
{
    char symbol = fgetc(fileName);
    while (symbol != EOF) {
        if (symbol >= 97 && symbol <=122)
            letters[symbol - 97] += 1;
        symbol = fgetc(fileName);
    }
}

void printInFile(int* letters)
{
    FILE* output = fopen("output.txt", "w");
    for (int i = 0; i < 26; i++) {
        if (letters[i] != 0)
            fprintf(output, "%c: %d\n", i + 97, letters[i]);
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

    int* array = calloc(26, sizeof(int));
    readFile(input, array);
    printInFile(array);

    free(array);
    fclose(input);

    return 0;
}