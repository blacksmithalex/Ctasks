#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Рекурсивное вычисление определителя
int determinant(int **matrix, int n)
{
    if (n == 1)
        return matrix[0][0];

    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    int det = 0;
    int sign = 1;

    // Выделяем память под подматрицу
    int **submatrix = (int **)malloc((n - 1) * sizeof(int *));
    for (int i = 0; i < n - 1; i++)
        submatrix[i] = (int *)malloc((n - 1) * sizeof(int));

    for (int k = 0; k < n; k++)
    {
        // Формируем подматрицу
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == k)
                    continue;
                submatrix[subi][subj++] = matrix[i][j];
            }
            subi++;
        }

        det += sign * matrix[0][k] * determinant(submatrix, n - 1);
        sign = -sign;
    }

    // Освобождаем память
    for (int i = 0; i < n - 1; i++)
        free(submatrix[i]);
    free(submatrix);

    return det;
}

int main()
{
    FILE *fin = fopen("input.txt", "r");
    if (!fin)
    {
        perror("Ошибка открытия input.txt");
        return 1;
    }

    int n;
    if (fscanf(fin, "%d", &n) != 1 || n <= 0 || n > MAX_SIZE)
    {
        fprintf(stderr, "Ошибка: некорректная размерность матрицы\n");
        fclose(fin);
        return 1;
    }

    // Выделяем память под матрицу
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    // Считываем матрицу из файла
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (fscanf(fin, "%d", &matrix[i][j]) != 1)
            {
                fprintf(stderr, "Ошибка чтения элемента [%d][%d]\n", i, j);
                fclose(fin);
                return 1;
            }

    fclose(fin);

    int det = determinant(matrix, n);

    FILE *fout = fopen("output.txt", "w");
    if (!fout)
    {
        perror("Ошибка открытия output.txt");
        return 1;
    }

    fprintf(fout, "Determinant: %d\n", det);
    fclose(fout);

    // Освобождение памяти
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
