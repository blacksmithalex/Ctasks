#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (a[i][j] == 1) count++;
        }
    }
    printf("%d", count / 2);
    return 0;
}
