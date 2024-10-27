#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define EPS 1e-6

void process_x_segments(float* array, int size, float x);

int main() {
    FILE *input, *output;
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

    process_x_segments(array, size, x);

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Ошибка: не удалось открыть файл output.txt\n");
        free(array);
        return 1; 
    }

    for (int i = 0; i < size; i++) {
        fprintf(output, "%.2f\n", array[i]);
    }

    fclose(output);
    free(array);

    return 0;
}

void process_x_segments(float* array, int size, float x) {
    int start = -1, end = -1;

    for (int i = 0; i < size; i++) {
        if (fabs(array[i] - x) < EPS) {
            if (start == -1) start = i; 
            end = i;  
        } else {
            if (start != -1) {
                float left = (start > 0) ? array[start - 1] : 0.0f;
                float right = (end < size - 1) ? array[end + 1] : 0.0f;
                float replacement = (left + right) / 2.0f;

                for (int j = start; j <= end; j++) {
                    array[j] = replacement;
                }
                start = -1;
            }
        }
    }

    if (start != -1) {
        float left = (start > 0) ? array[start - 1] : 0.0f;
        float right = (end < size - 1) ? array[end + 1] : 0.0f;
        float replacement = (left + right) / 2.0f;

        for (int j = start; j <= end; j++) {
            array[j] = replacement;
        }
    }
}
