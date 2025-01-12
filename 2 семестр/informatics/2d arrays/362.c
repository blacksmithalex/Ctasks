#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    for (int j = 0; j < m; j++)
        A[0][j] = 1;
    for (int i = 0; i < n; i++)
        A[i][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++){
            A[i][j] = A[i - 1][j] + A[i][j - 1];
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
