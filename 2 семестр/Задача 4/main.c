#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define PI 3.1415

// ------------------------ Примеры функций ------------------------

double f_linear(double x) {
    return x - 3.0;
}

double f_parabola(double x) {
    return x * x + 2.0 * x - 10.0;
}

double f_sin(double x) {
    return sin(x);
}

double f_complex(double x) {
    return pow(2.0, x) - x - 6.0;
}

// ------------------------ Метод последовательной параболической интерполяции ------------------------

static void sort3_by_x(double xs[3], double fs[3]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2 - i; ++j) {
            if (xs[j] > xs[j+1]) {
                double tx = xs[j]; xs[j] = xs[j+1]; xs[j+1] = tx;
                double tf = fs[j]; fs[j] = fs[j+1]; fs[j+1] = tf;
            }
        }
    }
}

double min_value(double a, double b, int N, double (*f)(double)) {
    double x0 = a;
    double x2 = b;
    double x1 = 0.5 * (a + b);
    double f0 = f(x0);
    double f1 = f(x1);
    double f2 = f(x2);

    double last_x = x1;
    for (int iter = 0; iter < N; ++iter) {
        double t01 = x1 - x0;
        double t12 = x1 - x2;
        double denom = t01 * (f1 - f2) - t12 * (f1 - f0);

        double x_new;
        if (fabs(denom) < 1e-16) {
            x_new = 0.5 * (x0 + x2);
        } else {
            double num = t01 * t01 * (f1 - f2) - t12 * t12 * (f1 - f0);
            x_new = x1 - 0.5 * num / denom;
            if (!(x_new > a && x_new < b) || !(x_new > x0 && x_new < x2)) {
                x_new = 0.5 * (x0 + x2);
            }
        }

        double f_new = f(x_new);

        double xs4[4] = {x0, x1, x2, x_new};
        double fs4[4] = {f0, f1, f2, f_new};

        int used[4] = {0,0,0,0};
        for (int k = 0; k < 3; ++k) {
            int idx_min = -1;
            double cur_min = INFINITY;
            for (int j = 0; j < 4; ++j) {
                if (!used[j] && fs4[j] < cur_min) {
                    cur_min = fs4[j]; idx_min = j;
                }
            }
            used[idx_min] = 1;
        }

        double new_xs[3];
        double new_fs[3];
        int pos = 0;
        for (int j = 0; j < 4; ++j) {
            if (used[j]) {
                new_xs[pos] = xs4[j];
                new_fs[pos] = fs4[j];
                pos++;
            }
        }
        sort3_by_x(new_xs, new_fs);

        x0 = new_xs[0]; f0 = new_fs[0];
        x1 = new_xs[1]; f1 = new_fs[1];
        x2 = new_xs[2]; f2 = new_fs[2];

        last_x = x_new;
    }

    return last_x;
}

// ------------------------ Модуль исследования ------------------------

void investigate_minimizer(double (*f)(double), double x_true, double a, double b, int max_N) {
    printf(" N          |  |x_n - x_*|       |f(x_n)|          |x_n - x_{n-1}|\n");
    printf("---------------------------------------------------------------------\n");

    double prev_x = a;
    double x_n = prev_x;

    for (int n = 1; n <= max_N; ++n) {
        x_n = min_value(a, b, n, f);
        double err = fabs(x_n - x_true);
        double fv = fabs(f(x_n));
        double diff = fabs(x_n - prev_x);

        printf("%2d          | %e | %e | %e\n", n, err, fv, diff);

        prev_x = x_n;
    }

    printf("\nНайденный минимум после %d итераций: x_n = %.12lf, f(x_n) = %.12e\n\n", max_N, x_n, f(x_n));
    printf("Эталонный минимум x_* = %.12lf, f(x_*) = %.12e\n", x_true, f(x_true));
}

// ------------------------ main ------------------------

int main() {
    int choice;
    printf("Выберите функцию для исследования:\n");
    printf("1. Линейная f(x) = x - 3\n");
    printf("2. Парабола f(x) = x^2 + 2x - 10\n");
    printf("3. sin(x)\n");
    printf("4. 2^x - x - 6\n");
    printf("Ваш выбор: ");
    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    double a, b;
    int max_N;
    printf("Введите левый и правый концы отрезка a b (через пробел): ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Ошибка ввода отрезка.\n");
        return 1;
    }
    if (a >= b) {
        printf("Требуется a < b.\n");
        return 1;
    }
    printf("Введите максимальное количество итераций (max_N): ");
    if (scanf("%d", &max_N) != 1 || max_N <= 0) {
        printf("Ошибка ввода числа итераций.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            investigate_minimizer(f_linear, a, a, b, max_N); // минимум линейной на отрезке — в левой границе
            break;
        case 2:
            investigate_minimizer(f_parabola, -1.0, a, b, max_N); // минимум параболы в x=-1
            break;
        case 3:
            investigate_minimizer(f_sin, -PI/2, a, b, max_N); // минимум sin(x) на [-pi/2, pi/2] в -pi/2
            break;
        case 4:
            investigate_minimizer(f_complex, log2(1.0 / log(2.0)), a, b, max_N); // минимум 2^x - x - 6
            break;
        default:
            printf("Некорректный выбор.\n");
            return 1;
    }

    return 0;
}
