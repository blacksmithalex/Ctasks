#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

// Функция для вычисления знака определителя 2×2 (ориентированная площадь параллелограмма)
double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Функция проверки, пересекаются ли два отрезка AB и CD
int segments_intersect(Point a, Point b, Point c, Point d) {
    double d1 = cross_product(a, b, c);
    double d2 = cross_product(a, b, d);
    double d3 = cross_product(c, d, a);
    double d4 = cross_product(c, d, b);

    // Проверяем, лежат ли точки C и D по разные стороны AB, а A и B — по разные стороны CD
    if ((d1 * d2 < 0) && (d3 * d4 < 0)) {
        return 1; // Отрезки пересекаются
    }
    return 0; // Нет пересечения
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n < 2) {
        fprintf(stderr, "Ошибка: некорректное количество точек\n");
        fclose(file);
        return 1;
    }

    Point *points = (Point *)malloc(n * sizeof(Point));
    if (!points) {
        perror("Ошибка выделения памяти");
        fclose(file);
        return 1;
    }

    // Читаем координаты точек
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf %lf", &points[i].x, &points[i].y) != 2) {
            fprintf(stderr, "Ошибка: некорректные координаты\n");
            free(points);
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    // Перебираем все пары отрезков (i, i+1) и (j, j+1) (где j > i+1)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 2; j < n - 1; j++) {
            // Исключаем соседние отрезки (они всегда соединены в вершине)
            if (i == 0 && j == n - 2) continue; // Исключаем первый и последний, так как они соединяются
            if (segments_intersect(points[i], points[i + 1], points[j], points[j + 1])) {
                printf("YES\n");
                free(points);
                return 0;
            }
        }
    }

    printf("NO\n");
    free(points);
    return 0;
}
