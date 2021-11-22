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

struct TreeMapIterator {
    Node* current;
    Value key;
    Value value;
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

TreeMapIterator getIterator(TreeMap* tree)
{
    TreeMapIterator* iterator = malloc(sizeof(TreeMapIterator));
    iterator->current = tree->root;
    iterator->value = tree->root->value;
    iterator->key = tree->root->key;
}

void next(TreeMapIterator* iterator)
{
    Node* node = iterator->current;
    Node* next = NULL;
    if (node->leftChild != NULL)
        next = node->leftChild;
    else if (node->rightChild != NULL)
        next = node->rightChild;
    else if (node->parent != NULL)
        next = node->parent;
    iterator->current = next;
    if (next != NULL) {
        iterator->value = iterator->current->value;
        iterator->key = iterator->current->key;
    } else {
        iterator->value = wrapNone();
        iterator->key = wrapNone();
    }
}

Value getKey(TreeMapIterator* iterator)
{
    return iterator->key;
}

Value getValue(TreeMapIterator* iterator)
{
    return iterator->value;
}

void deleteTreeMap(TreeMap* tree)
{
    free(tree->root);
    free(tree);
}

int getBalanceFactor(Node* node)
{
    if (node->leftChild && node->rightChild)
        return node->rightChild->height - node->leftChild->height;
    else
        return 0;
}

void updateHeight(Node* node)
{
    if (node->parent != NULL) {
        node->parent->height++;
        updateHeight(node->parent);
    }
}

Node* rotateRight(Node* root)
{
    Node* child = root->leftChild;
    root->leftChild = child->rightChild;
    child->rightChild = root;
    updateHeight(child);
    return child;
}

Node* rotateLeft(Node* root)
{
    Node* child = root->rightChild;
    root->rightChild = child->leftChild;
    child->leftChild = root;
    updateHeight(child);
    return child;
}

Node* balance(Node* root)
{
    updateHeight(root);
    if (getBalanceFactor(root) == 2) {
        if (getBalanceFactor(root->rightChild) == -1)
            root->rightChild = rotateRight(root->rightChild);
        return rotateLeft(root);
    }
    if (getBalanceFactor(root) == -2) {
        if (getBalanceFactor(root->leftChild) == 1)
            root->leftChild = rotateLeft(root->leftChild);
        return rotateRight(root);
    }
    return root;
}

void insert(Node* node, Value key, Value value, Comparator comparator)
{
    if (!node) {
        Node* newNode = createNode(key, value);
        if (comparator(node->parent->key, key) == 1)
            node->parent->leftChild = newNode;
        else
            node->parent->rightChild = newNode;
        newNode->parent = node;
        updateHeight(newNode);
    } else if (comparator(node->key, key) == 1)
        insert(node->leftChild, key, value, comparator);
    else if (compare(node->key, key) == -1)
        insert(node->rightChild, key, value, comparator);
    else
        node->value = value;
}

void putKeyInTree(TreeMap* tree, Value key, Value value)
{
    if (!tree->root) {
        Node* node = createNode(key, value);
        tree->root = node;
    } else if (tree->comparator(tree->root->key, key) == 1)
        insert(tree->root->leftChild, key, value, tree->comparator);
    else if (tree->comparator(tree->root->key, key) == -1)
        insert(tree->root->rightChild, key, value, tree->comparator);
    else
        tree->root->value = value;
    tree->root = balance(tree->root);
}

Pair* findKey(Node* node, Value key, Comparator comparator)
{
    Pair* pair = malloc(sizeof(Pair));
    if (!node) {
        pair->value = wrapNone();
        pair->key = wrapNone();
        return pair;
    }
    if (comparator(node->key, key) == 1)
        findKey(node->leftChild, key, comparator);
    else if (comparator(node->key, key) == -1)
        findKey(node->rightChild, key, comparator);
    pair->key = key;
    pair->value = node->value;
    return pair;
}

bool hasKeyInTree(TreeMap* tree, Value key)
{
    Pair* pair = findKey(tree->root, key, tree->comparator);
    if (pair->value.type == NONE_TYPE)
        return false;
    else
        return true;
}

Value getKeyFromTree(TreeMap* tree, Value key)
{
    Pair* pair = findKey(tree->root, key, tree->comparator);
    return pair->value;
}

Node* findMinimum(Node* node)
{
    if (node->leftChild != NULL)
        return findMinimum(node->leftChild);
    return node;
}

Node* removeMinimum(Node* node)
{
    if (node->leftChild == NULL)
        return node->rightChild;
    node->leftChild = removeMinimum(node->leftChild);
    return balance(node);
}

Node* removeKey(Node* node, Value key, Comparator comparator)
{
    if (comparator(node->key, key) == -1)
        node->leftChild = removeKey(node->leftChild, key, comparator);
    else if (comparator(node->key, key) == -1)
        node->rightChild = removeKey(node->rightChild, key, comparator);
    else {
        Node* left = node->leftChild;
        Node* right = node->rightChild;
        free(node);
        if (!right)
            return left;
        Node* min = findMinimum(node);
        min->rightChild = removeMinimum(right);
        min->leftChild = left;
        return balance(min);
    }
    return balance(node);
}

void removeKeyFromTree(TreeMap* tree, Value key)
{
    if (hasKeyInTree(tree, key))
        removeKey(tree->root, key, tree->comparator);
}

Value getLower(Node* node, Value key, Comparator comparator)
{
    if (comparator(node->key, key) == 0)
        return node->key;
    else if (node->leftChild != NULL) {
        if (node->rightChild != NULL) {
        }
    }
}

Value getLowerBound(TreeMap* tree, Value key)
{
}

void printInFile(TreeMap* tree, FILE* file)
{
    int value = tree->root->value.intValue;
    printf("%d\n", value);
    fprintf(file, "%d", value);
}