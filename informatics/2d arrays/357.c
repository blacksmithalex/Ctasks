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
    int max_num = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < n; i++){
        int cur_num = 0;
        int cur_j = 0;
        for (int j = 0; j < m; j++){
            if (A[i][j] > cur_num){
                cur_num = A[i][j];
                cur_j = j;
            }
        }
        if (cur_num > max_num) {
            max_num = cur_num;
            max_i = i;
            max_j = cur_j;
        } 
    }
    printf("%d\n", max_num);
    printf("%d ", max_i);
    printf("%d ", max_j);
    return 0;
}
