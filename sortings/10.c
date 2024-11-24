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

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void group_and_sort(int *array, int size) {
    int *positive = malloc(size * sizeof(int));
    int *negative = malloc(size * sizeof(int));
    int pos_count = 0, neg_count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            positive[pos_count++] = array[i];
        } else {
            negative[neg_count++] = array[i];
        }
    }

    qsort(positive, pos_count, sizeof(int), compare);
    qsort(negative, neg_count, sizeof(int), compare);

    for (int i = 0; i < pos_count; i++) {
        array[i] = positive[i];
    }
    for (int i = 0; i < neg_count; i++) {
        array[pos_count + i] = negative[i];
    }

    free(positive);
    free(negative);
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

    int *group_sort_array = malloc(size * sizeof(int));
    int *qsort_array = malloc(size * sizeof(int));
    if (!group_sort_array || !qsort_array) {
        perror("Error allocating memory for sorting arrays");
        free(array);
        return EXIT_FAILURE;
    }

    memcpy(group_sort_array, array, size * sizeof(int));
    memcpy(qsort_array, array, size * sizeof(int));

    clock_t start = clock();
    group_and_sort(group_sort_array, size);
    clock_t end = clock();
    double group_sort_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Group Sort Time: %.6f seconds\n", group_sort_time);

    start = clock();
    qsort(qsort_array, size, sizeof(int), compare);
    end = clock();
    double qsort_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Qsort Time: %.6f seconds\n", qsort_time);

    write_array_to_file(output_filename, group_sort_array, size);

    free(array);
    free(group_sort_array);
    free(qsort_array);

    return 0;
}
