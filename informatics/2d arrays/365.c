#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int A[2 * n + 1][2 * n + 1];
    int x = n, y = n; // текущая позиция
    int value = 1;
    int step = 1; //шаг увеличения спирали

    A[x][x] = 0;
    
    while (step <= 2 * n) {
        //движение вверх
        for (int i = 0; i < step; i++) {
            x--;
            A[x][y] = value;
            value++;
        }

        //движение влево
        for (int i = 0; i < step; i++) {
            y--;
            A[x][y] = value;
            value++;
        }
        step++;

        //движение вниз
        for (int i = 0; i < step; i++) {
            x++;
            A[x][y] = value;
            value++;
        }

        //движение вправо
        for (int i = 0; i < step; i++) {
            y++;
            A[x][y] = value;
            value++;
        }
        step++;
    }
    while (x >= 0) {
        x--;
        A[x][y] = value;
        value++;
    }
    
    
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
