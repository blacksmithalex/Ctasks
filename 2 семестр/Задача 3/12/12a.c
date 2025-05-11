#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-15
#define MAX(A, B) ((A) > (B) ? (A) : (B))

// Умножение двух матриц: C = A * B
void multiply(double *C, double *A, double *B, int n) {
    double *temp = (double *)calloc(n * n, sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
    for (int i = 0; i < n * n; i++) {
        C[i] = temp[i];
    }
    free(temp);
}

// Вычисление матричной экспоненты
double *matrix_exp(double *A, int n) {
    double *result = (double *)calloc(n * n, sizeof(double));
    double *term = (double *)calloc(n * n, sizeof(double));
    double *power = (double *)calloc(n * n, sizeof(double));

    for (int i = 0; i < n; i++) {
        result[i * n + i] = 1.0;
        power[i * n + i] = 1.0;
    }

    int k = 1;
    double max_term = 1.0;

    while (max_term > EPS && k < 100) {
        multiply(term, power, A, n);  // term = power * A
        for (int i = 0; i < n * n; i++) {
            power[i] = term[i] / k;
            result[i] += power[i];
        }

        max_term = 0.0;
        for (int i = 0; i < n * n; i++) {
            max_term = MAX(max_term, fabs(power[i]));
        }
        k++;
    }

    free(term);
    free(power);
    return result;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        perror("Ошибка открытия input.txt");
        return 1;
    }

    int n;
    if (fscanf(fin, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Некорректный размер матрицы\n");
        fclose(fin);
        return 1;
    }

    double *A = (double *)malloc(n * n * sizeof(double));
    if (!A) {
        perror("Ошибка выделения памяти для матрицы A");
        fclose(fin);
        return 1;
    }

    for (int i = 0; i < n * n; i++) {
        if (fscanf(fin, "%lf", &A[i]) != 1) {
            fprintf(stderr, "Ошибка чтения элемента матрицы\n");
            free(A);
            fclose(fin);
            return 1;
        }
    }
    fclose(fin);

    double *expA = matrix_exp(A, n);

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        perror("Ошибка открытия output.txt");
        free(A);
        free(expA);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fout, "%.6f ", expA[i * n + j]);
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
    free(A);
    free(expA);
    return 0;
}
