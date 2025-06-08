#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    char emptyline;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%c", &emptyline);
    int colors[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &colors[i]);

    int countbad = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (a[i][j] == 1 && colors[i] != colors[j]) countbad++;
        }
    }
    printf("%d", countbad);
    return 0;
}
