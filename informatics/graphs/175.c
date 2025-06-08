#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i, j, s;
    scanf("%d %d", &N, &M);
    int a[N][N];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;
    for (int edges = 1; edges <= M; edges++){
        scanf("%d %d", &i, &j);
        i--;
        j--;
        a[i][j] = 1;
        a[j][i] = 1;
    }

    for (i = 0; i < N; i++) {
        s = 0;
        for (j = 0; j < N; j++){
            s += a[i][j];
        }
        printf("%d ", s);
    }
    
    return 0;
}
