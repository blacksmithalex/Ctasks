#include <stdio.h>
#include <stdlib.h>

int* rotate(int *A, int N, int M){
    int *newA;
    newA = (int*)malloc(N * M * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            int i1 = i * M + j;
            int inew = j;
            int jnew = N - 1 - i;
            int i2 = inew * N + jnew;
            newA[i2] = A[i1];
        }
    }
    return newA;
}

int main() {
    int N, M; 
    int *A, *B;
    scanf("%d", &N);
    scanf("%d", &M);
    A = (int*)malloc(N * M * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            scanf("%d", &A[i * M + j]);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++){
    //         printf("%d ", A[i * M + j]);
    //     }
    //     printf("\n");
    // }

    printf("%d %d \n", M, N);
    B = rotate(A, N, M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++){
            printf("%d ", B[i * N + j]);
        }
        printf("\n");
    }
    return 0;
}
