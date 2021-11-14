#include "tree.h"

struct Node {
    Value key;
    Value value;
    Node* leftChild;
    Node* rightChild;
    Node* parent;
    int height;
};

struct TreeMap {
    Node* root;
    Comparator comparator;
    ValueType valueType;
    ValueType keyType;
};

TreeMap* createTreeMap(Comparator comparator)
{
    TreeMap* newTree = malloc(sizeof(TreeMap));
    newTree->root = NULL;
    newTree->valueType = NONE_TYPE;
    newTree->keyType = NONE_TYPE;
    newTree->comparator = comparator;
    return newTree;
}

Node* createNode(Value key, Value value)
{
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->key = key;
    node->height = 0;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->parent = NULL;
    return node;
}

void deleteTreeMap(TreeMap* map)
{
    free(map->comparator);
    free(map->root);
    free(map);
}

void updateHeight(Node* node)
{
    if (!node->parent) {
        node->parent->height++;
        updateHeight(node->parent);
    }
}

void insert(Node* node, Value key, Value value, int comparison)
{
    if (!node) {
        Node* newNode = createNode(key, value);
        if (comparison == 1)
            node->parent->leftChild = newNode;
        else
            node->parent->rightChild = newNode;
        newNode->height = 1;
        newNode->parent = node;
        updateHeight(newNode);
    } else if (compare(node->key, key) == 1)
        insert(node->leftChild, key, value, compare(node->key, key));
    else if (compare(node->key, key) == -1)
        insert(node->rightChild, key, value, compare(node->key, key));
    else
        node->value = value;
}

void putKey(TreeMap* tree, Value key, Value value)
{
    if (!tree->root) {
        Node* node = createNode(key, value);
        tree->root = node;
        node->height = 1;
    } else if (compare(tree->root->key, key) == 1)
        insert(tree->root->leftChild, key, value, compare(tree->root->key, key));
    else if (compare(tree->root->key, key) == -1)
        insert(tree->root->rightChild, key, value, compare(tree->root->key, key));
    else
        tree->root->value = value;
}

/*Pair* findKey(Node* node, Value key)
{
    Pair* pair = malloc(sizeof(Pair));
    if (!node) {
        pair->value = wrapNone();
        pair->key = wrapNone();
        return pair;
    }
    if (compare(node->key, key) == 1)
        findKey(node->leftChild, key);
    else if (compare(node->key, key) == -1)
        findKey(node->rightChild, key);
    else {
        pair->key = key;
        pair->value = node->value;
        return pair;
    }
}

bool hasKey(TreeMap* tree, Value key)
{
    Pair* pair = findKey(tree->root, key);
    if (pair->value.type == NONE_TYPE)
        return false;
    else
        return true;
}
*/