#include <stdio.h>
#include <stdlib.h>

void fill_spiral(int *A, int N) {
    int left = 0, right = N - 1;
    int top = 0, bottom = N - 1;
    int value = 1; 

    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; j++)
            A[top * N + j] = value;
        top++;

        for (int i = top; i <= bottom; i++)
            A[i * N + right] = value;
        right--;

        for (int j = right; j >= left; j--)
            A[bottom * N + j] = value;
        bottom--;

        for (int i = bottom; i >= top; i--)
            A[i * N + left] = value;
        left++;

        // Меняем 0 ↔ 1 для следующего витка спирали
        value = 1 - value;
    }
}

void print_spiral(int *A, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", A[i * N + j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int *A = (int *)malloc(N * N * sizeof(int));

    for (int i = 0; i < N * N; i++) {
        A[i] = 0;
    }

    fill_spiral(A, N);

    print_spiral(A, N);

    free(A);

    return 0;
}
