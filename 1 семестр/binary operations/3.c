#include <stdio.h>
#include <stdlib.h>

// Функция для зеркального отражения байта
unsigned char reverse_byte(unsigned char byte) {
    unsigned char reversed = 0;
    for (int i = 0; i < 8; i++) {
        reversed = (reversed << 1) | (byte & 1);
        byte >>= 1;
    }
    return reversed;
}

int main() {
    int N;
    printf("Enter the number of integers (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Error: Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int count = 0;            // Количество найденных чисел
    unsigned int number = 0;  // Текущее число для проверки

    while (count < N) {
        // Выделяем младший байт
        unsigned char low_byte = number & 0xFF;
        // Выделяем следующий байт
        unsigned char next_byte = (number >> 8) & 0xFF;

        // Проверяем условие: младший байт == зеркальному отображению следующего байта
        if (low_byte == reverse_byte(next_byte)) {
            printf("%u\n", number);
            count++;
        }

        number++;
    }

    return 0;
}
