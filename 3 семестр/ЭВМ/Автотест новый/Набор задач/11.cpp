ListNode* Process(ListNode* a, ListNode* b) {
    ListNode dummy{nullptr, 0}, *t = &dummy;
    int carry = 0;
    while (a || b || carry) {
        int s = carry;
        if (a) s += a->digit, a = a->next;
        if (b) s += b->digit, b = b->next;
        t->next = new ListNode{nullptr, s % 10};
        t = t->next;
        carry = s / 10;
    }
    return dummy.next;
}
