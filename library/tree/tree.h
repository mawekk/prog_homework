#ifndef TREE_H
#define TREE_H
#include "../values/values.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct TreeMap TreeMap;
typedef struct TreeMapIterator TreeMapIterator;
typedef struct Pair {
    Value key;
    Value value;
} Pair;

TreeMap* createTreeMap(Comparator comparator);
void deleteTreeMap(TreeMap* tree);
void putKeyInTree(TreeMap* tree, Value key, Value value);
void removeKeyFromTree(TreeMap* tree, Value key);
bool hasKeyInTree(TreeMap* tree, Value key);
Pair* getKeyFromTree(TreeMap* tree, Value key);
Value getLowerBound(TreeMap* tree, Value key);
Value getUpperBound(TreeMap* tree, Value key);

TreeMapIterator getIterator(TreeMap* tree);
void next(TreeMapIterator iterator);
Value getKey(TreeMapIterator iterator);
Value getValue(TreeMapIterator iterator);

void printInFile(TreeMap* tree, FILE* file);

#endif // TREE_H