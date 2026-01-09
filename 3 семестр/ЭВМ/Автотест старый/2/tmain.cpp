#include <iostream>
#include "tree.h"

int computeBalance(Node *v, int &leafCount)
{
    if (!v)
    {
        leafCount = 0;
        return 0;
    }

    int leftLeaves = 0;
    int rightLeaves = 0;

    int leftNodes = computeBalance(v->left, leftLeaves);
    int rightNodes = computeBalance(v->right, rightLeaves);

    int totalNodes = 1 + leftNodes + rightNodes;

    if (!v->left && !v->right)
        leafCount = 1;
    else
        leafCount = leftLeaves + rightLeaves;

    v->balance = totalNodes - leafCount;
    return totalNodes;
}

int subtreeSize(Node *v)
{
    if (!v)
        return 0;
    return 1 + subtreeSize(v->left) + subtreeSize(v->right);
}

Node *removeByValue(Node *root, int x, bool &removed)
{
    if (!root || removed)
        return root;

    if (root->value == x)
    {
        removed = true;

        // Нет потомков
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // Один потомок
        if (!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        if (!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }

        // Два потомка
        int L = subtreeSize(root->left);
        int R = subtreeSize(root->right);

        if (L > R)
        {
            destroyTree(root->right);
            Node *t = root->left;
            delete root;
            return t;
        }
        else
        {
            destroyTree(root->left);
            Node *t = root->right;
            delete root;
            return t;
        }
    }

    root->left = removeByValue(root->left, x, removed);
    root->right = removeByValue(root->right, x, removed);
    return root;
}

int main()
{
    Node *root = createSampleTree();

    std::cout << "Исходное дерево:\n";
    printTree(root, 0);

    int leafCount = 0;
    computeBalance(root, leafCount);

    std::cout << "\nДерево с балансами:\n";
    printTree(root, 0);

    int X;
    std::cout << "\nВведите X: ";
    std::cin >> X;

    bool removed = false;
    root = removeByValue(root, X, removed);

    std::cout << "\nПосле удаления:\n";
    printTree(root, 0);

    destroyTree(root);
    return 0;
}
