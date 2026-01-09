ListNode* Process(ListNode* h) {
    ListNode d{h, 0}, *p = &d;
    while (p->next && p->next->next) {
        auto a = p->next, b = a->next;
        a->next = b->next;
        b->next = a;
        p->next = b;
        p = a;
    }
    return d.next;
}
