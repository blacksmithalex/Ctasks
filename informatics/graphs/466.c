#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    int count = 0;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            if (a[i][j] == 1)
                printf("%d %d\n", i + 1, j + 1);
        }
    return 0;
}
