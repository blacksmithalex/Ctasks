#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int max_sum = 0;
    int max_ind = 0;
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = 0; j < m; j++){
            sum += A[i][j];
        }
        if (max_sum < sum) {
            max_sum = sum;
            max_ind = i;
        }
    }
    printf("%d\n", max_sum);
    printf("%d", max_ind);
    return 0;
}
