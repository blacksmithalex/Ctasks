#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N, edges;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < N; i++){
        edges = 0;
        for (int j = 0; j < N; j++){
            if (a[i][j] == 1) edges++;
        }
        printf("%d\n", edges);
    }
    return 0;
}
