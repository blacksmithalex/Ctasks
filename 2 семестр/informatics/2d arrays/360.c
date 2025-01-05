#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int A[n][m];
    int good[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
        }
    }
    int max = 0;
    int count_max = 0;
    int ind_good = 0;
    for (int i = 0; i < n; i++){
        int cur_max = 0;
        for (int j = 0; j < m; j++){
            if (A[i][j] > cur_max){
                cur_max = A[i][j];
            }
        }
        if (cur_max > max) {
            max = cur_max;
            count_max = 1;
            good[0] = i;
            ind_good = 1;
        } else if (cur_max == max) {
            count_max += 1;
            good[ind_good] = i;
            ind_good++;
        }
    }
    printf("%d\n", count_max);
    for (int i = 0; i < ind_good; i++) {
        printf("%d ", good[i]);
    }
    return 0;
}
