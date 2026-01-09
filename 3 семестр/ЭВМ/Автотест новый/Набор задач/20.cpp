ListNode* Process(ListNode* h) {
    bool swapped;
    do {
        swapped = false;
        ListNode** p = &h;
        while ((*p)->next) {
            if ((*p)->value > (*p)->next->value) {
                auto a = *p, b = a->next;
                a->next = b->next;
                b->next = a;
                *p = b;
                swapped = true;
            }
            p = &(*p)->next;
        }
    } while (swapped);
    return h;
}
