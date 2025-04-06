#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
        
    for (int vert = 0; vert < N; vert++){
        int count1 = 0, count2 = 0;
        for (int i = 0; i < N; i++){
            if (a[i][vert] == 1) count1++;
        }
        printf("%d\n", count1);
        for (int j = 0; j < N; j++){
            if (a[vert][j] == 1) count2++;
        }
        printf("%d\n", count2);
    }

}
