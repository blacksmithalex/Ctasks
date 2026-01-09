ListNode* Process(ListNode* h) {
    for (; h && h->next;)
        if (h->value == h->next->value) {
            auto t = h->next;
            h->next = t->next;
            delete t;
        } else h = h->next;
    return h;
}
