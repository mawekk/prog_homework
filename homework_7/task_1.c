#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printInFile(FILE* file, int* array)
{
    fprintf(file, "%d %d\n", array[0], array[1]);
    for (int i = 0; i < array[0] + 1; i++)
        fprintf(file, "%d ", array[i + 2]);
}

void findShortestPath(int nVertex, int** matrix, int start, int end, FILE* file)
{
    int* lengths = calloc(nVertex, sizeof(int));
    bool* used = calloc(nVertex, sizeof(bool));
    int* parents = calloc(nVertex, sizeof(int));
    for (int i = 0; i < nVertex; i++)
        parents[i] = -1;
    for (int i = 0; i < nVertex; i++) {
        lengths[i] = 1000000;
        used[i] = 0;
    }
    lengths[start] = 0;

    int vertex = start;
    while (!used[vertex] && vertex != end) {
        for (int i = 0; i < nVertex; i++) {
            if (matrix[vertex][i] != 0 && matrix[vertex][i] + lengths[vertex] < lengths[i]) {
                parents[i] = vertex;
                lengths[i] = matrix[vertex][i] + lengths[vertex];
            }
        }
        used[vertex] = 1;
        int minLength = 1000000;
        for (int i = 0; i < nVertex; i++) {
            if (!used[i] && lengths[i] > -1 && lengths[i] < minLength) {
                vertex = i;
                minLength = lengths[i];
            }
        }
        if (minLength == 1000000)
            break;
    }
    if (lengths[end] == 1000000)
        fprintf(file, "There is no path from vertex %d to vertex %d.", start, end);
    else {
        int shortestPath = lengths[end];
        int number = 0;
        int* path = calloc(nVertex, sizeof(int));
        while (end != -1) {
            path[number] = end;
            end = parents[end];
            number += 1;
        }
        number -= 1;

        int* result = calloc(number + 2, sizeof(int));
        result[0] = number;
        result[1] = shortestPath;
        for (int k = number; k >= 0; k--)
            result[2 + number - k] = path[k];

        printInFile(file, result);

        free(path);
        free(result);
    }
    free(lengths);
    free(used);
    free(parents);
}

bool isFileExist(FILE* fileName)
{
    return (fileName != NULL);
}

void readGraphAndFindPath(FILE* inputFile, FILE* outputFile)
{
    int nVertex = 0;
    int nEdge = 0;
    fscanf(inputFile, "%d", &nVertex);
    fscanf(inputFile, "%d", &nEdge);
    int** matrix = calloc(nVertex, sizeof(int*));
    for (int i = 0; i < nVertex; i++)
        matrix[i] = calloc(nEdge, sizeof(int));
    int start = 0;
    int end = 0;
    for (int i = 0; i < nEdge; i++) {
        int from = 0;
        int to = 0;
        int length = 0;
        fscanf(inputFile, "%d", &from);
        fscanf(inputFile, "%d", &to);
        fscanf(inputFile, "%d", &length);
        matrix[from][to] = length;
    }
    fscanf(inputFile, "%d", &start);
    fscanf(inputFile, "%d", &end);

    findShortestPath(nVertex, matrix, start, end, outputFile);

    for (int i = 0; i < nVertex; i++)
        free(matrix[i]);
    free(matrix);
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
    readGraphAndFindPath(input, output);
    fclose(output);
    fclose(input);
    return 0;
}