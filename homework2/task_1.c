#include <stdio.h>
#include "map.h"

int main(int argc, char* argv[])
{
    FILE *input = fopen("sources/text.txt", "r"), *output = fopen("sources/dict.csv", "w");
    LinkedMap *map = makeNewMap();
    char word[128] = "";

    while(fscanf(input, "%s", word) != EOF) {
        fscanf(input, "%s", word);
        put(map, word, 1);
    }

    printMap(map);

    return 0;
}
