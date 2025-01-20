#include "Database_functions.h"

RedBlackTree* createRedBlackTree() {
    RedBlackTree* tree = (RedBlackTree*) malloc(sizeof(RedBlackTree));
    tree->nil = (RedBlackNode*) malloc(sizeof(RedBlackNode));
    tree->nil->color = 'B';
    tree->root = tree->nil;
    return tree;
}

void leftRotate(RedBlackTree* tree, RedBlackNode* x) {
    RedBlackNode* y = x->right;
    x->right = y->left;
    if (y->left != tree->nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(RedBlackTree* tree, RedBlackNode* y) {
    RedBlackNode* x = y->left;
    y->left = x->right;
    if (x->right != tree->nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == tree->nil) {
        tree->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

void insertFixup(RedBlackTree* tree, RedBlackNode* z) {
    while (z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            RedBlackNode* y = z->parent->parent->right;
            if (y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(tree, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(tree, z->parent->parent);
            }
        } else {
            RedBlackNode* y = z->parent->parent->left;
            if (y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(tree, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = 'B';
}

void insertRedBlackTree(RedBlackTree* tree, int studentNumber) {
    RedBlackNode* z = (RedBlackNode*) malloc(sizeof(RedBlackNode));
    z->studentNumber = studentNumber;
    z->left = tree->nil;
    z->right = tree->nil;
    z->color = 'R';

    RedBlackNode* y = tree->nil;
    RedBlackNode* x = tree->root;

    while (x != tree->nil) {
        y = x;
        if (z->studentNumber < x->studentNumber) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == tree->nil) {
        tree->root = z;
    } else if (z->studentNumber < y->studentNumber) {
        y->left = z;
    } else {
        y->right = z;
    }
    insertFixup(tree, z);
}

RedBlackTree* createIndex(const char* tableName) {
    unsigned int index = hash(tableName);
    HashMap* currentTable = hashMapArray[index];
    while (currentTable) {
        if (strcmp(currentTable->table->tableName, tableName) == 0) {
            break;
        }
        currentTable = currentTable->next;
    }
    RedBlackTree* tree = createRedBlackTree();
    Record* currentRecord = currentTable->table->head;
    while (currentRecord) {
        insertRedBlackTree(tree, currentRecord->studentNumber);
        currentRecord = currentRecord->next;
    }
    return tree;
}