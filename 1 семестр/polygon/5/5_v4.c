#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9
#define INF 1e9
#define STEPS 60

typedef struct {
    double x, y;
} Point;

typedef struct {
    double a, b, c;
} Line;

// Функция вычисления расстояния от точки (x, y) до прямой
double distance_to_line(double x, double y, Line l) {
    return fabs(x * l.a + y * l.b + l.c);
}

// Функция вычисления радиуса вписанной окружности с центром в (x, y)
double compute_radius(double x, double y, Line *lines, int n) {
    double min_dist = INF;
    for (int i = 0; i < n; i++) {
        double dist = distance_to_line(x, y, lines[i]);
        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    return min_dist;
}

// Функция нахождения y, при котором радиус максимален (тернарный поиск по Y)
double find_best_y(double x, Point *polygon, Line *lines, int n) {
    double lower_y = INF, upper_y = -INF;

    // Определяем диапазон возможных значений Y для текущего X
    for (int i = 0; i < n; i++) {
        double x1 = polygon[i].x, y1 = polygon[i].y;
        double x2 = polygon[(i + 1) % n].x, y2 = polygon[(i + 1) % n].y;

        if (fabs(x1 - x2) < EPS) continue; // Пропускаем вертикальные стороны

        if (x1 > x2) {
            double temp;
            temp = x1, x1 = x2, x2 = temp;
            temp = y1, y1 = y2, y2 = temp;
        }

        if (x1 <= x + EPS && x - EPS <= x2) {
            double y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
            if (y < lower_y) lower_y = y;
            if (y > upper_y) upper_y = y;
        }
    }

    // Тернарный поиск по Y
    for (int step = 0; step < STEPS; step++) {
        double diff = (upper_y - lower_y) / 3;
        double y1 = lower_y + diff, y2 = upper_y - diff;

        double r1 = compute_radius(x, y1, lines, n);
        double r2 = compute_radius(x, y2, lines, n);

        if (r1 < r2)
            lower_y = y1;
        else
            upper_y = y2;
    }

    return compute_radius(x, lower_y, lines, n);
}

// Функция нахождения центра и радиуса вписанной окружности (тернарный поиск по X)
double find_inscribed_radius(Point *polygon, Line *lines, int n) {
    double left_x = INF, right_x = -INF;

    // Определяем диапазон возможных значений X
    for (int i = 0; i < n; i++) {
        if (polygon[i].x < left_x) left_x = polygon[i].x;
        if (polygon[i].x > right_x) right_x = polygon[i].x;
    }

    // Тернарный поиск по X
    for (int step = 0; step < STEPS; step++) {
        double diff = (right_x - left_x) / 3;
        double x1 = left_x + diff, x2 = right_x - diff;

        double r1 = find_best_y(x1, polygon, lines, n);
        double r2 = find_best_y(x2, polygon, lines, n);

        if (r1 < r2)
            left_x = x1;
        else
            right_x = x2;
    }

    return find_best_y(left_x, polygon, lines, n);
}

// Функция нахождения максимального диаметра 
double max_diameter(Point *polygon, int n) {
    double max_dist = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = polygon[i].x - polygon[j].x;
            double dy = polygon[i].y - polygon[j].y;
            double d = sqrt(dx * dx + dy * dy);
            if (d > max_dist) {
                max_dist = d;
            }
        }
    }
    return max_dist;
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

    // Создаем массив уравнений прямых (сторон многоугольника)
    Line *lines = (Line *)malloc(n * sizeof(Line));
    if (!lines) {
        perror("Ошибка выделения памяти");
        free(polygon);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Point a = polygon[i], b = polygon[(i + 1) % n];
        lines[i].a = a.y - b.y;
        lines[i].b = b.x - a.x;
        double len = sqrt(lines[i].a * lines[i].a + lines[i].b * lines[i].b);
        lines[i].a /= len;
        lines[i].b /= len;
        lines[i].c = -(lines[i].a * a.x + lines[i].b * a.y);
    }

    // Вычисляем диаметры
    double D_max = max_diameter(polygon, n);
    double D_min = find_inscribed_radius(polygon, lines, n) * 2;

    printf("Диаметр(описанная окружность): %.6f\n", D_max);
    printf("Диаметр (вписанная окружность): %.6f\n", D_min);

    free(polygon);
    free(lines);
    return 0;
}
