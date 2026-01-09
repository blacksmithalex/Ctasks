bool Process(ListNode* h) {
    ListNode *s = h, *f = h, *p = nullptr;
    while (f && f->next) {
        f = f->next->next;
        auto n = s->next;
        s->next = p;
        p = s;
        s = n;
    }
    if (f) s = s->next;
    while (p && s && p->value == s->value)
        p = p->next, s = s->next;
    return !p;
}
