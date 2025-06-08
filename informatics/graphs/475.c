#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N, M, edges;
    scanf("%d %d", &N, &M);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 0;
        
    for (int m = 0; m < M; m++){
        int i, j;
        scanf("%d %d", &i, &j);
        a[i - 1][j - 1] = 1;
        a[j - 1][i - 1] = 1;
    }
        
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    int count_first_line = 0;
    for (int j = 0; j < N; j++){
        if (a[0][j] == 1) count_first_line++;
    }
    for (int i = 1; i < N; i++){
        int count = 0;
        for (int j = 0; j < N; j++){
            if (a[i][j] == 1) count++;
        }
        if (count != count_first_line){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
