#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    int value = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i % 2 == 0) A[i][j] = value;
            else A[i][m - j - 1] = value;
            value++;
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
