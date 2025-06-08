#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, W;
    scanf("%d", &N);
    scanf("%d", &M);
    int A[N][M];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            A[i][j] = 0;
        }
    }

    scanf("%d", &W);
    for (int k = 0; k < W; k++){
        int i, j;
        scanf("%d", &i);
        scanf("%d", &j);
        A[i - 1][j - 1] = -1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != -1) {
                if (i - 1 >= 0 && j - 1 >= 0 && A[i - 1][j - 1] == -1) A[i][j]++;
                if (j - 1 >= 0 && A[i][j - 1] == -1) A[i][j]++;
                if (i + 1 < N && j - 1 >= 0 && A[i + 1][j - 1] == -1) A[i][j]++;
                if (i + 1 < N && A[i + 1][j] == -1) A[i][j]++;
                if (i + 1 < N && j + 1 < M && A[i + 1][j + 1] == -1) A[i][j]++;
                if (j + 1 < M && A[i][j + 1] == -1) A[i][j]++;
                if (i - 1 >= 0 && j + 1 < M && A[i - 1][j + 1] == -1) A[i][j]++;
                if (i - 1 >= 0 && A[i - 1][j] == -1) A[i][j]++;
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (A[i][j] != -1) printf("%d ", A[i][j]);
            else printf("* ");
        }
        printf("\n");
    }

    return 0;
}
