#include <stdio.h>
#include <stdlib.h>

#define INF 1000
int main() {
    int N, M;
    printf("Write N and M:\n");
    scanf("%d", &N);
    scanf("%d", &M);
    int A[N][M];
    printf("Write matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);
    }
    int max_sum = -INF;
    for (int i = 0; i < N; i++){
        int cur_sum = 0;
        for (int j = 0; j < M; j++)
            cur_sum += A[i][j];
        if (cur_sum > max_sum)
            max_sum = cur_sum;
    }
    printf("Max line sum is: %d", max_sum);
    return 0;
}
