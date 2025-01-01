#include <stdio.h>

#include <stdlib.h>

void bubble_sort(float* array, int size);

int main() {
    int size;

    scanf("%d", &size);

    float *array = (float*)malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) scanf("%f", &array[i]);
    
    bubble_sort(array, size);

    for (int i = 0; i < size; i++) printf("%f ", array[i]);

    free(array);

    return 0;
}

void bubble_sort(float* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                float t;
                t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }
        }
    } 
}