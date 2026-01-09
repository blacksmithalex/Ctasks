int DFS(TreeNode* n, int v) {
    if (!n) return 0;
    v = v * 10 + n->value;
    if (!n->left && !n->right) return v;
    return DFS(n->left, v) + DFS(n->right, v);
}

int Process(TreeNode* r) {
    return DFS(r, 0);
}
