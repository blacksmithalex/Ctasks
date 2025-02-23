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

// Функция нахождения центра вписанной окружности (пересечение биссектрис)
Point incenter(Point *polygon, int n) {
    double perimeter = 0.0;
    double x = 0.0, y = 0.0;
    
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];
        double side_length = distance(a, b);
        perimeter += side_length;
        
        x += side_length * (a.x + b.x) / 2.0;
        y += side_length * (a.y + b.y) / 2.0;
    }

    x /= perimeter;
    y /= perimeter;
    
    Point incenter = {x, y};
    return incenter;
}

// Функция нахождения радиуса вписанной окружности (минимальный диаметр)
double min_diameter(Point *polygon, int n) {
    Point center = incenter(polygon, n);  // Находим центр вписанной окружности
    double min_dist = 1e9;  // Начальное большое значение

    // Ищем минимальное расстояние от инцентра до сторон
    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        // Вычисляем расстояние от центра до отрезка AB (формула расстояния от точки до прямой)
        double A = b.y - a.y;
        double B = a.x - b.x;
        double C = -(A * a.x + B * a.y);
        double dist = fabs(A * center.x + B * center.y + C) / sqrt(A * A + B * B);

        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    return (min_dist * 2);  // Умножаем на 2, чтобы получить полный диаметр
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
