#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int M, N, L, K;
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

    int *A = (int*)malloc(L * K * sizeof(double));
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
    int *cols_with_segment = (int *)malloc(K * sizeof(int));
    if (!cols_with_segment) {
        fprintf(out, "ERROR\n");
        free(A);
        free(cols_with_segment);
        fclose(out);
        return -1;
    }

    // Отметить строки и столбцы, содержащие элементы с остатком N по модулю M
    int count_good_cols = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            int val = (int)A[i * K + j];
            if (val >= M && val <= N) {
                cols_with_segment[j] = 1;
            }
        }
    }
    for (int j = 0; j < K; j++){
        if (cols_with_segment[j] == 1)
            count_good_cols++;
    }
    printf("%d", count_good_cols);


    int *inds = (int *)malloc(count_good_cols * sizeof(int));
    int cur_ind = 0;
    for (int j = 0; j < K; j++){
        if (cols_with_segment[j] == 1){
            inds[cur_ind] = j;
            cur_ind++;
        }
    }

    // Модификация элементов по условиям задачи
    for (int i = 0; i < L; i++) {
        for (int iter = 0; iter < count_good_cols; iter++){
            for (int j = 0; j < count_good_cols - iter - 1; j++){
                if (A[i * K + inds[j]] % M > A[i * K + inds[j + 1]] % M){
                    int tmp = A[i * K + inds[j]];
                    A[i * K + inds[j]] = A[i * K + inds[j + 1]];
                    A[i * K + inds[j + 1]] = tmp;
                }
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
    free(cols_with_segment);
    fclose(out);

    return 0;
}
