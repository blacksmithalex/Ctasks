#include <stdio.h>
#include <stdlib.h>
#include <float.h> 

#define ERR_FILE -1
#define SUCCESS 0

int count_numbers_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return ERR_FILE;
    }

    int count = 0;
    double temp;
    while (fscanf(file, "%lf", &temp) == 1) {
        count++;
    }

    fclose(file);
    return (count > 0) ? count : ERR_FILE;
}

int read_array_from_file(const char *filename, double *array, int size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return ERR_FILE;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(file, "%lf", &array[i]) != 1) {
            fclose(file);
            return ERR_FILE;
        }
    }

    fclose(file);
    return SUCCESS;
}

void sort_array_decreasing(double *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int compare_arrays(double *a, int m, double *b, int n) {
    int min_length = (m < n) ? m : n;
    int count = 0;
    for (int i = 0; i < min_length; i++) {
        if (a[i] < b[i]) count++;
    }
    return count; 
}

int write_result_to_file(const char *filename, int res1, int res2) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return ERR_FILE;
    }

    fprintf(file, "%d\n", res1);
    fprintf(file, "%d\n", res2);
    fclose(file);
    return SUCCESS;
}

int main() {
    const char *file_a = "ina.txt";
    const char *file_b = "inb.txt";
    const char *output_file = "output.txt";

    int m = count_numbers_in_file(file_a);
    int n = count_numbers_in_file(file_b);

    if (m == ERR_FILE || n == ERR_FILE) {
        fprintf(stderr, "Error: Unable to process input files\n");
        return ERR_FILE;
    }

    double *a = malloc(m * sizeof(double));
    double *b = malloc(n * sizeof(double));
    if (!a || !b) {
        perror("Error allocating memory");
        free(a);
        free(b);
        return ERR_FILE;
    }

    if (read_array_from_file(file_a, a, m) == ERR_FILE ||
        read_array_from_file(file_b, b, n) == ERR_FILE) {
        fprintf(stderr, "Error: Unable to read arrays from files\n");
        free(a);
        free(b);
        return ERR_FILE;
    }

    sort_array_decreasing(a, m);
    sort_array_decreasing(b, n);

    int res1 = compare_arrays(a, m, b, n);
    int res2 = compare_arrays(b, n, a, m);
    
    if (write_result_to_file(output_file, res1, res2) == ERR_FILE) {
        fprintf(stderr, "Error: Unable to write result to file\n");
        free(a);
        free(b);
        return ERR_FILE;
    }

    free(a);
    free(b);

    return SUCCESS;
}
