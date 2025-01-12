#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функция для проверки, является ли двоичное представление числа палиндромом
bool is_binary_palindrome(unsigned int number) {
    unsigned int reversed = 0;
    unsigned int original = number;

    // Находим первый значащий бит
    while ((original & (1U << 31)) == 0 && original > 0) {
        original <<= 1;
    }

    original = number; // Восстанавливаем значение оригинального числа

    // Инвертируем число (реверс битов)
    while (number > 0) {
        reversed = (reversed << 1) | (number & 1);
        number >>= 1;
    }

    // Проверяем, равен ли реверс оригиналу
    return original == reversed;
}

int main() {
    int N;
    printf("Enter the number of integers (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Error: Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int count = 0;            // Количество найденных чисел
    unsigned int number = 1;  // Текущее число для проверки (начинаем с 1)

    while (count < N) {
        if (is_binary_palindrome(number)) {
            printf("%u\n", number);
            count++;
        }
        number++;
    }

    return 0;
}
