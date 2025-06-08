#include <stdio.h>
#include <stdlib.h>

int update(int **A, int N, int M, int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) // Проверка выхода за границы
        return 0;

    if (A[i][j] == -1) // Если в позиции находится мина
        return 1;

    return 0;
}

int main() {
    int N, M, W;
    scanf("%d %d", &N, &M);

    // Динамическое выделение памяти для двухмерного массива
    int **A = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            A[i][j] = 0; // Инициализация значений
        }
    }

    // Чтение координат "мин"
    scanf("%d", &W);
    for (int k = 0; k < W; k++) {
        int i, j;
        scanf("%d %d", &i, &j);
        A[i - 1][j - 1] = -1; // Обозначаем мину как -1
    }

    // Обновление значений массива
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != -1) { // Если в ячейке нет мины
                for (int step_i = -1; step_i <= 1; step_i++) {
                    for (int step_j = -1; step_j <= 1; step_j++) {
                        A[i][j] += update(A, N, M, i + step_i, j + step_j);
                    }
                }
            }
        }
    }

    // Вывод массива
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == -1)
                printf("* ");
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
