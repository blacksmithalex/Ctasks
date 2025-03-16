#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    if (N == 1) {
        printf("%d", 1);
        return 0;
    }
    if (N == 3) {
        printf("111\n001\n111");
        return 0;
    }
    int A[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = 0;
    
    int i = 0;
    int j = 0;
    char direct = 'R';
    A[i][j] = 1;
    bool flag = true;

    while (flag) {
        if (direct == 'R') j += 1;
        if (direct == 'D') i += 1;
        if (direct == 'L') j -= 1;
        if (direct == 'U') i -= 1;
        A[i][j] = 1;
        if (direct == 'R' && (j == N - 1 || (j < N - 2 && A[i][j + 2] == 1))) direct = 'D';
        if (direct == 'D' && (i == N - 1 || (i < N - 2 && A[i + 2][j] == 1))) direct = 'L';
        if (direct == 'L' && (j == 0 || (j > 1 && A[i][j - 2] == 1))) direct = 'U';
        if (direct == 'U' && (i > 1 && A[i - 2][j] == 1)) direct = 'R';

        bool rool1 = i < N - 2 && A[i + 2][j] == 1;
        bool rool2 = i > 1 && A[i - 2][j] == 1;
        bool rool3 = j < N - 2 && A[i][j + 2] == 1;
        bool rool4 = j > 1 && A[i][j - 2] == 1;
        if (rool1 && rool2 && rool3 && rool4) flag = false;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
}
