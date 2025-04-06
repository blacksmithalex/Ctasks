#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    bool flag = false;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < N; i++){
        if (a[i][i] == 1)
            flag = true;
    }
    
    if (flag)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}
