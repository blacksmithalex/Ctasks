#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cur_val, nmove, move;
    scanf("%d", &n);
    int A[2 * n + 1][2 * n + 1];
    cur_val = 0;
    nmove = 0;
    move = 1;
    int i = n, j = n;
    while (nmove != (2 * n + 1) * (2 * n + 1)) {
        A[i][j] = cur_val;
        cur_val ++;
        if (nmove % 4 == 0) {
            i -= move;
        } else if (nmove % 4 == 1) {
            j -= move;
        } else if (nmove % 4 == 2) {
            i += move;
        } else {
            j += move;
        }
        nmove ++;
        if (nmove % 2 == 0)
            move ++;
    }
    
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
