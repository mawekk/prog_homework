#ifndef TREE_H
#define TREE_H
#include "../values/values.h"
#include <stdlib.h>

typedef struct Node Node;
typedef struct TreeMap TreeMap;
typedef struct Pair {
    Value key;
    Value value;
} Pair;

TreeMap* createTreeMap(Comparator comparator);
void deleteTreeMap(TreeMap* map);
void putKey(TreeMap* tree, Value key, Value value);
Pair removeKey(TreeMap* tree, Value key);
bool hasKey(TreeMap* tree, Value key);

#endif // TREE_H