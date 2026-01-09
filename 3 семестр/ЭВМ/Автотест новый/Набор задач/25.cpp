bool Process(TreeNode* r) {
    TreeNode* q[1000];
    int l = 0, h = 0;
    bool nullSeen = false;
    q[h++] = r;

    while (l < h) {
        auto n = q[l++];
        if (!n) nullSeen = true;
        else {
            if (nullSeen) return false;
            q[h++] = n->left;
            q[h++] = n->right;
        }
    }
    return true;
}
