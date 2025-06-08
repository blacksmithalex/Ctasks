#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            A[i][j] = i * j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
