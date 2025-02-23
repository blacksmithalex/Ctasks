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

// Функция нахождения максимального диаметра (описанной окружности)
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

// Функция нахождения пересечения биссектрис двух соседних углов
Point bisector_intersection(Point a, Point b, Point c) {
    double ab = distance(a, b);
    double bc = distance(b, c);

    // Центр пересечения биссектрис (средневзвешенная точка)
    double x = (a.x * bc + c.x * ab) / (ab + bc);
    double y = (a.y * bc + c.y * ab) / (ab + bc);

    return (Point){x, y};
}

// Функция нахождения расстояния от точки до стороны (отрезка)
double point_to_segment_distance(Point p, Point a, Point b) {
    double A = b.y - a.y;
    double B = a.x - b.x;
    double C = -(A * a.x + B * a.y);

    return fabs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}

// Функция нахождения максимального возможного радиуса вписанной окружности (D_min / 2)
double min_diameter(Point *polygon, int n) {
    double max_radius = 0.0;  // Инициализируем максимальный радиус

    // Перебираем пары соседних вершин и ищем пересечение биссектрис
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];
        Point c = polygon[(i + 2) % n];

        // Находим центр пересечения биссектрис
        Point center = bisector_intersection(a, b, c);

        // Ищем минимальное расстояние от центра до всех сторон
        double min_radius = 1e9;
        for (int j = 0; j < n; j++) {
            Point p1 = polygon[j];
            Point p2 = polygon[(j + 1) % n];

            double dist = point_to_segment_distance(center, p1, p2);
            if (dist < min_radius) {
                min_radius = dist;
            }
        }

        // Обновляем максимальный радиус (D_min / 2)
        if (min_radius > max_radius) {
            max_radius = min_radius;
        }
    }

    return (max_radius * 2) * (max_radius * 2);  // Умножаем на 2, чтобы получить D_min
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

    printf("Максимальный диаметр (описанная окружность): %.6f\n", D_max);
    printf("Минимальный диаметр (вписанная окружность): %.6f\n", D_min);

    free(polygon);
    return 0;
}
