#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = 0;
        
    for (int m = 0; m < M; m++){
        int i, j;
        scanf("%d %d", &i, &j);
        if (a[i - 1][j - 1] == 0){
            a[i - 1][j - 1] = 1;
        } else {
            printf("NO");
            return 0;
        }
    }
        
    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            bool rule1 = a[i][j] == 0 && a[j][i] == 0;
            bool rule2 = a[i][j] == 1 && a[j][i] == 1;
            if (rule1 || rule2){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
