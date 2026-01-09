bool Check(TreeNode* n, int lo, int hi) {
    if (!n) return true;
    return n->value > lo && n->value < hi &&
           Check(n->left, lo, n->value) &&
           Check(n->right, n->value, hi);
}

bool Process(TreeNode* r) {
    return Check(r, INT_MIN, INT_MAX);
}
