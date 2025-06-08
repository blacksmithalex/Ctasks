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
      
    int data[N];
    int ind = 0;
    for (int i = 0; i < N; i++)
        data[i] = -1;

    for (int vert = 0; vert < N; vert++){
        bool flag = true;
        for (int j = 0; j < N; j++){
            if (a[j][vert] == 1) flag = false;
        }
        if (flag){
            data[ind] = vert + 1;
            ind += 1;
        }
    }
    printf("%d\n", ind);
    for (int i = 0; i < ind; i++)
        printf("%d\n", data[i]);

    ind = 0;
    for (int i = 0; i < N; i++)
        data[i] = -1;

    for (int vert = 0; vert < N; vert++){
        bool flag = true;
        for (int j = 0; j < N; j++){
            if (a[vert][j] == 1) flag = false;
        }
        if (flag){
            data[ind] = vert + 1;
            ind += 1;
        }
    }
    printf("%d\n", ind);
    for (int i = 0; i < ind; i++)
        printf("%d\n", data[i]);

}
