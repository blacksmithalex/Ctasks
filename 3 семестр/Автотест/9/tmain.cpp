#include <iostream>
#include "tree.h"

int computeBalance(Node *v)
{
    if (!v)
        return 0;
    int L = computeBalance(v->left);
    int R = computeBalance(v->right);
    v->balance = v->value + std::max(L, R);
    return v->balance;
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

        // 0 потомков
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // 1 потомок
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

        // 2 потомка
        int L = subtreeSize(root->left);
        int R = subtreeSize(root->right);

        if (L > R || L == R)
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

    computeBalance(root);
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
