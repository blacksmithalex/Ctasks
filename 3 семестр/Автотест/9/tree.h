#ifndef TREE_H
#define TREE_H

#include <iostream>

struct Node
{
    int value;
    int balance;
    Node *left;
    Node *right;

    Node(int v) : value(v), balance(0), left(nullptr), right(nullptr) {}
};

Node *createSampleTree();          // создание тестового дерева
void printTree(Node *root, int d); // печать поддеревьев
void destroyTree(Node *root);      // удаление дерева

#endif
