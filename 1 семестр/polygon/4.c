#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9 // Погрешность для сравнения чисел с плавающей точкой

typedef struct {
    double x, y;
} Point;

// Проверка принадлежности точки к отрезку
int is_point_on_segment(Point p, Point a, Point b) {
    // Проверка коллинеарности
    double cross_product = (b.y - a.y) * (p.x - a.x) - (b.x - a.x) * (p.y - a.y);
    if (fabs(cross_product) > EPS) {
        return 0; // Точка не лежит на прямой
    }

    // Проверка, находится ли точка между концами отрезка
    if (p.x < fmin(a.x, b.x) || p.x > fmax(a.x, b.x) ||
        p.y < fmin(a.y, b.y) || p.y > fmax(a.y, b.y)) {
        return 0; // Точка не лежит внутри отрезка
    }

    return 1; // Точка лежит на отрезке
}

// Проверка пересечения луча с ребром
int does_ray_intersect(Point p, Point a, Point b) {
    // Убедимся, что a ниже p, а b выше (или наоборот)
    if (a.y > b.y) {
        Point temp = a;
        a = b;
        b = temp;
    }

    // Если луч не пересекает диапазон по y, возвращаем 0
    if (p.y < a.y || p.y > b.y || fabs(a.y - b.y) < EPS) {
        return 0;
    }

    // Вычисляем точку пересечения
    double intersection_x = a.x + (p.y - a.y) * (b.x - a.x) / (b.y - a.y);

    // Проверяем, пересекает ли луч по x
    return intersection_x > p.x;
}

// Определение положения точки относительно многоугольника
const char *point_position(Point *polygon, int n, Point p) {
    int intersections = 0;

    for (int i = 0; i < n; i++) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];

        // Проверка, находится ли точка на границе
        if (is_point_on_segment(p, a, b)) {
            return "On the border";
        }

        // Проверка пересечения луча с ребром
        if (does_ray_intersect(p, a, b)) {
            intersections++;
        }
    }

    // Определяем положение точки
    return (intersections % 2 == 1) ? "Inside" : "Outside";
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1 || n < 3) {
        fprintf(stderr, "Error: Invalid number of vertices\n");
        fclose(file);
        return 1;
    }

    // Считываем координаты многоугольника
    Point *polygon = malloc(n * sizeof(Point));
    if (!polygon) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf %lf", &polygon[i].x, &polygon[i].y) != 2) {
            fprintf(stderr, "Error: Invalid vertex coordinates\n");
            free(polygon);
            fclose(file);
            return 1;
        }
    }

    // Считываем точку для проверки
    Point p;
    if (fscanf(file, "%lf %lf", &p.x, &p.y) != 2) {
        fprintf(stderr, "Error: Invalid point coordinates\n");
        free(polygon);
        fclose(file);
        return 1;
    }

    fclose(file);

    // Определяем положение точки
    const char *position = point_position(polygon, n, p);
    printf("%s\n", position);

    free(polygon);
    return 0;
}
