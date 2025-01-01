#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENT_VALUE 1000 

void generate_random_array(const char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++) {
        int value = rand() % (2 * MAX_ELEMENT_VALUE + 1) - MAX_ELEMENT_VALUE;
        fprintf(file, "%d\n", value);
    }

    fclose(file);
}

int *read_array_from_file(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%d", size) != 1 || *size <= 0) {
        fprintf(stderr, "Invalid array size\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    int *array = malloc(*size * sizeof(int));
    if (!array) {
        perror("Error allocating memory for array");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *size; i++) {
        if (fscanf(file, "%d", &array[i]) != 1) {
            fprintf(stderr, "Error reading array element\n");
            free(array);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return array;
}

void write_array_to_file(const char *filename, int *array, int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = array[left + i];
    for (int i = 0; i < n2; i++) R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int is_sorted(int *array, int size) {
    for (int i = 1; i < size; i++) {
        if (array[i - 1] > array[i]) {
            return 0;
        }
    }
    return 1;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid array size\n");
        return EXIT_FAILURE;
    }

    const char *input_filename = "input.txt";
    const char *output_filename = "output.txt";

    generate_random_array(input_filename, n);

    int size;
    int *array = read_array_from_file(input_filename, &size);

    int *bubble_array = malloc(size * sizeof(int));
    memcpy(bubble_array, array, size * sizeof(int));
    clock_t start = clock();
    bubble_sort(bubble_array, size);
    clock_t end = clock();
    double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %.6f seconds\n", bubble_time);

    int *merge_array = malloc(size * sizeof(int));
    memcpy(merge_array, array, size * sizeof(int));
    start = clock();
    merge_sort(merge_array, 0, size - 1);
    end = clock();
    double merge_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %.6f seconds\n", merge_time);

    int *qsort_array = malloc(size * sizeof(int));
    memcpy(qsort_array, array, size * sizeof(int));
    start = clock();
    qsort(qsort_array, size, sizeof(int), compare);
    end = clock();
    double qsort_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Qsort Time: %.6f seconds\n", qsort_time);

    if (!is_sorted(bubble_array, size) || !is_sorted(merge_array, size) || !is_sorted(qsort_array, size)) {
        fprintf(stderr, "Sorting failed\n");
        free(array);
        free(bubble_array);
        free(merge_array);
        free(qsort_array);
        return EXIT_FAILURE;
    }

    write_array_to_file(output_filename, bubble_array, size);

    free(array);
    free(bubble_array);
    free(merge_array);
    free(qsort_array);

    return 0;
}
