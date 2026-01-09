struct Info { long long l = -1, r = -1; };

void DFS(TreeNode* n, int d, long long idx, Info* a) {
    if (!n) return;
    if (a[d].l == -1) a[d].l = idx;
    a[d].r = idx;
    DFS(n->left, d+1, idx*2, a);
    DFS(n->right, d+1, idx*2+1, a);
}

int Process(TreeNode* r) {
    Info a[1000];
    DFS(r, 0, 1, a);
    int w = 0;
    for (int i = 0; i < 1000; i++)
        if (a[i].l != -1)
            w = std::max(w, int(a[i].r - a[i].l + 1));
    return w;
}
