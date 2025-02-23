// Координаты выпуклого многоугольника в файле писать в порядке обхода по или против часовой стрелки.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9  // Погрешность для вычислений

typedef struct {
    double x, y;
} Point;

// Функция вычисления расстояния между двумя точками
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Функция нахождения максимального диаметра (методом вращающихся калиперов)
double max_diameter(Point *polygon, int n) {
    double max_dist = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(polygon[i], polygon[j]);
            if (d > max_dist) {
                max_dist = d;
            }
        }
    }
    return max_dist;
}

// Функция нахождения минимального диаметра (вписанная окружность)
double min_diameter(Point *polygon, int n) {
    double min_dist = 1e9;  // Начальное значение большое

    // Центр тяжести многоугольника
    double cx = 0.0, cy = 0.0;
    for (int i = 0; i < n; i++) {
        cx += polygon[i].x;
        cy += polygon[i].y;
    }
    cx /= n;
    cy /= n;

    Point center = {cx, cy};

    // Находим минимальное расстояние от центра тяжести до сторон
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        // Вычисляем расстояние от центра тяжести до отрезка AB
        double A = b.y - a.y;
        double B = a.x - b.x;
        double C = -(A * a.x + B * a.y);
        double dist = fabs(A * center.x + B * center.y + C) / sqrt(A * A + B * B);

        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    return min_dist * 2;  // Умножаем на 2, чтобы получить полный диаметр
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n < 3) {
        fprintf(stderr, "Ошибка: некорректное число вершин\n");
        fclose(file);
        return 1;
    }

    // Выделяем память для точек многоугольника
    Point *polygon = (Point *)malloc(n * sizeof(Point));
    if (!polygon) {
        perror("Ошибка выделения памяти");
        fclose(file);
        return 1;
    }

    // Читаем координаты точек
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf %lf", &polygon[i].x, &polygon[i].y) != 2) {
            fprintf(stderr, "Ошибка: некорректные координаты\n");
            free(polygon);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Вычисляем минимальный и максимальный диаметры
    double D_max = max_diameter(polygon, n);
    double D_min = min_diameter(polygon, n);

    printf("Максимальный диаметр: %.6f\n", D_max);
    printf("Минимальный диаметр: %.6f\n", D_min);

    free(polygon);
    return 0;
}
