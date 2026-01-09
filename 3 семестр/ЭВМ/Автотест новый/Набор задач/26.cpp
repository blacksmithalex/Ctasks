bool Process(TreeNode* r) {
    TreeNode* q[1000];
    int l = 0, h = 0, lvl = 0;
    q[h++] = r;

    while (l < h) {
        int sz = h - l;
        int prev = lvl % 2 ? INT_MAX : INT_MIN;
        for (int i = 0; i < sz; i++) {
            auto n = q[l++];
            if ((n->value % 2) != (lvl % 2)) return false;
            if ((lvl % 2 && n->value >= prev) ||
                (!(lvl % 2) && n->value <= prev)) return false;
            prev = n->value;
            if (n->left) q[h++] = n->left;
            if (n->right) q[h++] = n->right;
        }
        lvl++;
    }
    return true;
}
