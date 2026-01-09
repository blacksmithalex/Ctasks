ListNode* Process(ListNode* h, int k) {
    ListNode d{h, 0};
    ListNode *f = &d, *s = &d;
    for (int i = 0; i <= k; i++) f = f->next;
    while (f) f = f->next, s = s->next;
    ListNode* del = s->next;
    s->next = del->next;
    delete del;
    return d.next;
}
