#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция для численного поиска корня методом Ньютона
double newton_root(double x0, int N, double (*f)(double), double (*df)(double)) {
    double x = x0;
    for (int i = 0; i < N; i++) {
        x = x - f(x) / df(x);
    }
    return x;
}

// Примеры функций и их производных

// Линейная функция: f(x) = x - 3
double f_linear(double x) {
    return x - 3;
}

double df_linear(double x) {
    return 1;
}

// Парабола: f(x) = x^2 + 2x - 10
double f_parabola(double x) {
    return x * x + 2 * x - 10;
}

double df_parabola(double x) {
    return 2 * x + 2;
}

// Синус: f(x) = sin(x)
double f_sin(double x) {
    return sin(x);
}

double df_sin(double x) {
    return cos(x);
}

// Сложная функция: f(x) = 2^x - x - 6
double f_complex(double x) {
    return pow(2.0, x) - x - 6;
}

// Производная сложной функции: f'(x) = ln(2) * 2^x - 1
double df_complex(double x) {
    return log(2.0) * pow(2.0, x) - 1;
}

// Функция для исследования поведения ошибки
void investigate(double (*f)(double), double (*df)(double), double x_true, double x0, int max_N) {
    printf(" N          |  |x_n - x_*|       |f(x_n)|          |x_n - x_{n-1}|\n");
    printf("---------------------------------------------------------------------\n");

    double prev_x = x0;
    double x = x0;

    for (int n = 1; n <= max_N; n++) {
        x = newton_root(x0, n, f, df);

        double error = fabs(x - x_true);     // |x_n - x_*|
        double f_value = fabs(f(x));          // |f(x_n)|
        double diff = fabs(x - prev_x);       // |x_n - x_{n-1}|

        printf("%2d          | %e | %e | %e\n", n, error, f_value, diff);

        prev_x = x;
    }

    printf("\nНайденный корень после %d итераций: %.10lf\n", max_N, x);
}

int main() {
    int choice;
    printf("Выберите функцию для исследования:\n");
    printf("1. Линейная (x - 3)\n");
    printf("2. Парабола (x^2 + 2x - 10)\n");
    printf("3. Синус (sin(x))\n");
    printf("4. Сложная (2^x - x - 6)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    double x0;    // стартовая точка
    int max_N;    // максимальное количество итераций
    printf("Введите начальное приближение x0: ");
    scanf("%lf", &x0);
    printf("Введите максимальное количество итераций: ");
    scanf("%d", &max_N);

    switch (choice) {
        case 1:
            investigate(f_linear, df_linear, 3.0, x0, max_N);
            break;
        case 2:
            investigate(f_parabola, df_parabola, -1.0 + sqrt(11.0), x0, max_N);
            break;
        case 3:
            investigate(f_sin, df_sin, 0.0, x0, max_N); // корень sin(x) в 0
            break;
        case 4:
            investigate(f_complex, df_complex, 3.2, x0, max_N); // корень уравнения 2^x - x - 6 около x ≈ 3.2 (один из)
            break;
        default:
            printf("Некорректный выбор.\n");
    }

    return 0;
}
