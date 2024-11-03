#include <stdio.h>

#include <stdlib.h>

int binary_search_position(float* array, int size, float x);

int main() {
    FILE *input;
    int size;
    float x;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Ошибка: не удалось открыть файл input.txt\n");
        return 1;
    }

    if (fscanf(input, "%d", &size) != 1 || size <= 0) {
        printf("Ошибка: некорректное содержимое файла\n");
        fclose(input);
        return 1;
    }

    float *array = (float*)malloc(size * sizeof(float));
    if (array == NULL) {
        printf("Ошибка: недостаточно памяти\n");
        fclose(input);
        return 1;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(input, "%f", &array[i]) != 1) {
            printf("Ошибка: некорректное содержимое файла\n");
            free(array);
            fclose(input);
            return 1;
        }
    }

    fclose(input);

    printf("Введите значение x: ");
    if (scanf("%f", &x) != 1) {
        printf("Ошибка: некорректное значение x\n");
        free(array);
        return 1;
    }

    int position = binary_search_position(array, size, x);

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Ошибка: не удалось открыть файл output.txt\n");
        free(array);
        return 1;
    }

    fprintf(output, "Позиция для вставки x: %d\n", position);

    fclose(output);
    free(array);

    return 0;
}

int binary_search_position(float* array, int size, float x) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
