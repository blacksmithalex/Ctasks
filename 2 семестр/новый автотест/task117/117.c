#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int M, N, L, K;
    int *A = NULL;
    FILE *in = fopen("data.txt", "r");
    FILE *out = fopen("res.txt", "w");

    if (in == NULL || out == NULL) {
        if (out) fprintf(out, "ERROR\n");
        if (in) fclose(in);
        if (out) fclose(out);
        return -1;
    }

    if (fscanf(in, "%d %d %d %d", &M, &N, &L, &K) != 4 || M <= 0 || N < M || L <= 0 || K <= 0) {
        fprintf(out, "ERROR\n");
        fclose(in);
        fclose(out);
        return -1;
    }

    A = (int *)malloc(L * K * sizeof(int));
    if (!A) {
        fprintf(out, "ERROR\n");
        fclose(in);
        fclose(out);
        return -1;
    }

    for (int i = 0; i < L * K; i++) {
        if (fscanf(in, "%d", &A[i]) != 1) {
            fprintf(out, "ERROR\n");
            free(A);
            fclose(in);
            fclose(out);
            return -1;
        }
    }
    fclose(in);

    // Флаги для строк и столбцов
    int *rows_with_segment = (int *)malloc(L * sizeof(int));
    int *cols_with_segment = (int *)malloc(K * sizeof(int));
    if (!rows_with_segment || !cols_with_segment) {
        fprintf(out, "ERROR\n");
        free(A);
        free(rows_with_segment);
        free(cols_with_segment);
        fclose(out);
        return -1;
    }

    // Отметить строки и столбцы, содержащие элемент в диапазоне [M; N]
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            int val = A[i * K + j];
            if (val >= M && val <= N) {
                rows_with_segment[i] = 1;
                cols_with_segment[j] = 1;
            }
        }
    }

    int *Acopy = (int *)malloc(L * K * sizeof(int));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            Acopy[i * K + j] = A[i * K + j];
        }
    }

    // Модификация элементов
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            if (rows_with_segment[i] && cols_with_segment[j]) {
                bool flag = false;
                for (int curi = 0; curi < L; curi++) {
                    for (int curj = 0; curj < j; curj++){
                        if (Acopy[curi * K + curj] == Acopy[i * K + j]) {
                            flag = true;
                        }
                }
                }
                if (flag)
                    A[i * K + j] = 1;
                else
                    A[i * K + j] = 0;
            }
        }
    }

    // Вывод результатов
    fprintf(out, "%d %d %d %d\n", M, N, L, K);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            fprintf(out, "%d ", A[i * K + j]);
        }
        fprintf(out, "\n");
    }

    // Очистка
    free(A);
    free(Acopy);
    free(rows_with_segment);
    free(cols_with_segment);
    fclose(out);

    return 0;
}