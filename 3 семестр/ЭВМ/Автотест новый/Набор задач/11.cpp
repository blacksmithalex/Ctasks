#include <iostream>

struct ListNode {
    ListNode* next;
    int digit;
};

ListNode* Process(ListNode* headA, ListNode* headB) {
    int extra = 0;

    ListNode* dummy = new ListNode{nullptr, 0};
    ListNode* res = dummy;

    while (headA != nullptr || headB != nullptr) {
        int sum = extra;

        if (headA != nullptr) {
            sum += headA->digit;
            headA = headA->next;
        }

        if (headB != nullptr) {
            sum += headB->digit;
            headB = headB->next;
        }

        res->next = new ListNode{nullptr, sum % 10};
        res = res->next;

        extra = sum / 10;
    }

    if (extra > 0) {
        res->next = new ListNode{nullptr, extra};
    }

    return dummy->next;
}

void print(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->digit << " -> ";
        head = head->next;
    }
    std::cout << "null\n";
}

int main() {
    // 5
    ListNode* headA = new ListNode{nullptr, 5};

    // 7 -> 1   (17)
    ListNode* headB = new ListNode{nullptr, 7};
    ListNode* C = new ListNode{nullptr, 1};
    headB->next = C;

    ListNode* res = Process(headA, headB);
    print(res);
}
