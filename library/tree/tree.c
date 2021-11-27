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
    node->height = 1;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->parent = NULL;
    return node;
}

void deleteNode(Node* node)
{
    if (node) {
        deleteNode(node->leftChild);
        deleteNode(node->rightChild);
        free(node);
    }
}

void deleteTreeMap(TreeMap* tree)
{
    deleteNode(tree->root);
    free(tree);
}

int getBalanceFactor(Node* node)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (node->leftChild)
        leftHeight = node->leftChild->height;
    if (node->rightChild)
        rightHeight = node->rightChild->height;
    return rightHeight - leftHeight;
}

void updateHeight(Node* node)
{
    if (node) {
        int leftHeight = 0;
        int rightHeight = 0;
        if (node->leftChild)
            leftHeight = node->leftChild->height;
        if (node->rightChild)
            rightHeight = node->rightChild->height;
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        updateHeight(node->parent);
    }
}

Node* rotateRight(Node* root)
{
    Node* child = root->leftChild;
    child->parent = root->parent;
    root->leftChild = child->rightChild;
    if (root->leftChild)
        root->leftChild->parent = root;
    child->rightChild = root;
    if (child->rightChild)
        child->rightChild->parent = child;
    updateHeight(root);
    updateHeight(child);
    return child;
}

Node* rotateLeft(Node* root)
{
    Node* child = root->rightChild;
    child->parent = root->parent;
    root->rightChild = child->leftChild;
    if (root->rightChild)
        root->rightChild->parent = root;
    child->leftChild = root;
    if (child->leftChild)
        child->leftChild->parent = child;
    updateHeight(root);
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

void insert(Node* parent, Node* node, Value key, Value value, Comparator comparator)
{
    if (!node) {
        Node* newNode = createNode(key, value);
        if (comparator(parent->key, key) == 1)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;
        newNode->parent = parent;
        updateHeight(newNode);
    } else if (comparator(node->key, key) == 1)
        insert(node, node->leftChild, key, value, comparator);
    else if (comparator(node->key, key) == -1)
        insert(node, node->rightChild, key, value, comparator);
    else
        node->value = value;
}

void putKeyInTree(TreeMap* tree, Value key, Value value)
{
    if (!tree->root) {
        Node* node = createNode(key, value);
        tree->root = node;
    } else if (tree->comparator(tree->root->key, key) == 1)
        insert(tree->root, tree->root->leftChild, key, value, tree->comparator);
    else if (tree->comparator(tree->root->key, key) == -1)
        insert(tree->root, tree->root->rightChild, key, value, tree->comparator);
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
        return findKey(node->leftChild, key, comparator);
    else if (comparator(node->key, key) == -1)
        return findKey(node->rightChild, key, comparator);
    else {
        pair->key = key;
        pair->value = node->value;
    }
    return pair;
}

bool hasKeyInTree(TreeMap* tree, Value key)
{
    Pair* pair = findKey(tree->root, key, tree->comparator);
    if (pair->key.type == NONE_TYPE)
        return false;
    else
        return true;
}

Pair* getKeyFromTree(TreeMap* tree, Value key)
{
    Pair* pair = findKey(tree->root, key, tree->comparator);
    return pair;
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

Node* removeKey(Node* parent, Node* node, Value key, Comparator comparator)
{
    if (comparator(node->key, key) == 1)
        node->leftChild = removeKey(node, node->leftChild, key, comparator);
    else if (comparator(node->key, key) == -1)
        node->rightChild = removeKey(node, node->rightChild, key, comparator);
    else {
        Node* left = node->leftChild;
        Node* right = node->rightChild;
        if (right == NULL && left == NULL)
            return NULL;
        if (right == NULL) {
            left->parent = parent;
            return left;
        }
        Node* min = findMinimum(right);
        min->rightChild = removeMinimum(right);
        if (min->rightChild)
            min->rightChild->parent = min;
        min->leftChild = left;
        if (min->leftChild)
            min->leftChild->parent = min;
        min->parent = node->parent;
        free(node);
        return balance(min);
    }
    return balance(node);
}

void removeKeyFromTree(TreeMap* tree, Value key)
{
    if (hasKeyInTree(tree, key))
        tree->root = removeKey(NULL, tree->root, key, tree->comparator);
}

Node* findLowerBound(Node* parent, Node* root, Value key, Comparator comparator)
{
    Node* bound = NULL;
    if (!root)
        if (!parent)
            return root;
        else
            return parent;
    if (comparator(root->key, key) == 1) {
        bound = findLowerBound(root, root->leftChild, key, comparator);
        if (comparator(bound->key, key) == -1 || comparator(bound->key, root->key) == 1)
            bound = root;
    } else if (comparator(root->key, key) == -1) {
        bound = findLowerBound(root, root->rightChild, key, comparator);
        if (comparator(bound->key, key) == -1)
            bound = parent;
    } else
        bound = root;
    return bound;
}

Value getLowerBound(TreeMap* tree, Value key)
{
    Node* bound = findLowerBound(NULL, tree->root, key, tree->comparator);
    if (bound != NULL)
        return bound->key;
    else
        return wrapNone();
}

TreeMapIterator getIterator(TreeMap* tree)
{
    Node* current = findMinimum(tree->root);
    TreeMapIterator iterator = { current, current->value, current->key };
    return iterator;
}

void next(TreeMapIterator* iterator)
{
    Node* node = iterator->current;
    Node* next = NULL;
    if (node->rightChild)
        next = findMinimum(node->rightChild);
    else
        while (true) {
            if (node->parent == NULL) {
                next = NULL;
                break;
            }
            if (node->parent->leftChild == node) {
                next = node->parent;
                break;
            }
            node = node->parent;
        }
    iterator->current = next;
    if (next) {
        iterator->value = next->value;
        iterator->key = next->key;
    } else {
        iterator->value = wrapNone();
        iterator->key = wrapNone();
    }
}

Value getKey(TreeMapIterator iterator)
{
    return iterator.key;
}

Value getValue(TreeMapIterator iterator)
{
    return iterator.value;
}

