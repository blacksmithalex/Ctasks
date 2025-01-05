#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (A[i][j] != A[j][i]) {
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");
    return 0;
}
