#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M, N, L, K;
    double *A = NULL;
    FILE *in = fopen("data.txt", "r");
    FILE *out = fopen("res.txt", "w");

    if (in == NULL || out == NULL) {
        if (out)
            fprintf(out, "ERROR\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return -1;
    }

    if (fscanf(in, "%d %d %d %d", &M, &N, &L, &K) != 4 || M <= 0 || L <= 0 || K <= 0) {
        fprintf(out, "ERROR\n");
        fclose(in);
        fclose(out);
        return -1;
    }

    A = (double *)malloc(L * K * sizeof(double));
    if (!A) {
        fprintf(out, "ERROR\n");
        fclose(in);
        fclose(out);
        return -1;
    }

    for (int i = 0; i < L * K; i++) {
        if (fscanf(in, "%lf", &A[i]) != 1) {
            fprintf(out, "ERROR\n");
            free(A);
            fclose(in);
            fclose(out);
            return -1;
        }
    }
    fclose(in);

    // Флаги для строк и столбцов
    int *rows_with_mod = (int *)calloc(L, sizeof(int));
    int *cols_with_mod = (int *)calloc(K, sizeof(int));
    if (!rows_with_mod || !cols_with_mod) {
        fprintf(out, "ERROR\n");
        free(A);
        free(rows_with_mod);
        free(cols_with_mod);
        fclose(out);
        return -1;
    }

    // Отметить строки и столбцы, содержащие элементы с остатком N по модулю M
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            int val = (int)A[i * K + j];
            if (val % M == N) {
                rows_with_mod[i] = 1;
                cols_with_mod[j] = 1;
            }
        }
    }

    // Модификация элементов по условиям задачи
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            if (rows_with_mod[i] && cols_with_mod[j]) {
                int found = 0;
                for (int t = 0; t < j; t++) {
                    if (A[i * K + t] == A[i * K + j]) {
                        found = 1;
                        break;
                    }
                    // printf("%d\n", found);
                }
                A[i * K + j] = found;
            }
        }
    }

    // Вывод результатов
    fprintf(out, "%d %d %d %d\n", M, N, L, K);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            fprintf(out, "%.0lf ", A[i * K + j]);
        }
        fprintf(out, "\n");
    }

    // Очистка
    free(A);
    free(rows_with_mod);
    free(cols_with_mod);
    fclose(out);

    return 0;
}
