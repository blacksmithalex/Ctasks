ListNode* Process(ListNode* h) {
    if (!h || !h->next) return h;
    ListNode* t = h;
    while (t->next) t = t->next;
    t->next = h;
    h = h->next;
    t->next->next = nullptr;
    return h;
}
