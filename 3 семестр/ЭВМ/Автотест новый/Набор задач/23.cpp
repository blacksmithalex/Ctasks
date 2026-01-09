int Process(TreeNode* r) {
    return r ? 1 + Process(r->left) + Process(r->right) : 0;
}
