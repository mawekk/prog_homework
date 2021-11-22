#include "../library/tree/tree.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    TreeMap* tree = createTreeMap(compare);
    Value value = wrapInt(10);
    Value key = wrapInt(1);
    putKeyInTree(tree, key, value);
    FILE* file = fopen(argv[1], "w");
    printInFile(tree, file);
    fclose(file);
    return 0;
}