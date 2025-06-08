#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int ind_winner = 0;
    int sum_winner = 0;
    int max_winner = 0;
    for (int i = 0; i < n; i++){
        int cur_num = 0;
        int cur_sum = 0;
        for (int j = 0; j < m; j++){
            if (A[i][j] > cur_num){
                cur_num = A[i][j];
            }
            cur_sum += A[i][j];
        }
        bool rule1 = cur_num > max_winner;
        bool rule2 = cur_num == max_winner && cur_sum > sum_winner;
        if (rule1 || rule2) {
            ind_winner = i;
            sum_winner = cur_sum;
            max_winner = cur_num;
        }
    }
    printf("%d ", ind_winner);
    return 0;
}
