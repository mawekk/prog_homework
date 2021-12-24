#include "stdbool.h"
#include "stdio.h"
#include <stdlib.h>

void dfs(int** matrix, int vertex, int* achievable, bool* used, int nVertexes, int nEdges)
{
    used[vertex] = true;
    for (int j = 0; j < nEdges; j++) {
        if (matrix[vertex][j] > 0)
            for (int i = 0; i < nVertexes; i++)
                if (matrix[i][j] < 0 && !used[i]) {
                    achievable[i] += 1;
                    dfs(matrix, i, achievable, used, nVertexes, nEdges);
                }
    }
}

int* findAchievable(int** matrix, int nVertexes, int nEdges)
{
    int* achievable = calloc(nVertexes, sizeof(int));
    for (int i = 0; i < nVertexes; i++) {
        bool* used = calloc(nVertexes, sizeof(bool));
        dfs(matrix, i, achievable, used, nVertexes, nEdges);
    }
    return achievable;
}

int main()
{
    int nVertexes = 0;
    int nEdges = 0;
    printf("Enter the number of vertexes:\n");
    scanf("%d", &nVertexes);
    printf("Enter the number of edges:\n");
    scanf("%d", &nEdges);

    printf("Enter the matrix:\n");
    int** matrix = calloc(nVertexes, sizeof(int*));
    for (int i = 0; i < nVertexes; i++)
        matrix[i] = calloc(nEdges, sizeof(int));
    for (int i = 0; i < nVertexes; i++) {
        for (int j = 0; j < nEdges; j++)
            scanf("%d", &matrix[i][j]);
    }

    printf("Achievable vertexes:\n");
    int* achievable = findAchievable(matrix, nVertexes, nEdges);
    for (int i = 0; i < nVertexes; i++) {
        if (achievable[i] >= nVertexes - 1)
            printf("%d\n", i + 1);
    }

    free(achievable);
    for (int i = 0; i < nVertexes; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}