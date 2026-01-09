#include <iostream>

struct List {
    List* next;
    int digit;
};

// Добавление цифры в конец списка
void push_back(List*& head, int digit) {
    if (!head) {
        head = new List{nullptr, digit};
        return;
    }
    List* cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = new List{nullptr, digit};
}

// Сложение двух чисел
List* add(List* a, List* b) {
    List* result = nullptr;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;
        if (a) { sum += a->digit; a = a->next; }
        if (b) { sum += b->digit; b = b->next; }

        push_back(result, sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Печать числа (в обратном порядке)
void print(List* head) {
    if (!head) return;
    print(head->next);
    std::cout << head->digit;
}

int main() {
    List* num1 = nullptr; // 357
    push_back(num1, 7);
    push_back(num1, 5);
    push_back(num1, 3);

    List* num2 = nullptr; // 68
    push_back(num2, 8);
    push_back(num2, 6);

    List* sum = add(num1, num2);

    std::cout << "357 + 68 = ";
    print(sum);
    std::cout << std::endl;

    return 0;
}
