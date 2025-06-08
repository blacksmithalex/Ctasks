#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    int value = 0;
    
    //0 <= i + j <= n - 1 + m - 1
    for (int diag = 0; diag <= n - 1 + m - 1; diag++){
        for (int i = 0; i < n; i++){
            int j = diag - i;
            if (0 <= i && i < n && 0 <= j && j < m) {
                A[i][j] = value;
                value++;
            }
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
