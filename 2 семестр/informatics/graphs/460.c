#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    bool flag = true;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++){
            if (a[i][i] != 0 || a[i][j] != a[j][i])
                flag = false;
        }
    
    if (flag)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}
