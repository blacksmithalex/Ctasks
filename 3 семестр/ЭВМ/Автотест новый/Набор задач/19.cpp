ListNode* Process(ListNode* h, int v) {
    ListNode d{h, 0}, *p = &d;
    while (p->next)
        if (p->next->value == v) {
            auto t = p->next;
            p->next = t->next;
            delete t;
        } else p = p->next;
    return d.next;
}
