#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N, M, i, j;
    int count = 0;
    bool flag = false;
    scanf("%d %d", &N, &M);
    int a[N][N];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;

    for (int edge = 1; edge <= M; edge++){
        scanf("%d %d", &i, &j);
        if (a[i - 1][j - 1] == 1)
            flag = true;
        a[i - 1][j - 1] = 1;
    }
    if (flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
