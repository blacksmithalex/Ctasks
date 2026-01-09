#include "tree.h"

Node *createSampleTree()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(10);

    root->right->right->right = new Node(15);

    return root;
}

void printTree(Node *root, int depth)
{
    if (!root)
        return;

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; ++i) // для красивого вывода
        std::cout << "    ";
    std::cout << root->value << " (" << root->balance << ")\n";

    printTree(root->left, depth + 1);
}

void destroyTree(Node *root)
{
    if (!root)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}
