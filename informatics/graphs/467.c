#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N, M, i, j;
    int count = 0;
    scanf("%d %d", &N, &M);
    int a[N][N];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;

    for (int edge = 1; edge <= M; edge++){
        scanf("%d %d", &i, &j);
        a[i - 1][j - 1] = 1;
    }
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
