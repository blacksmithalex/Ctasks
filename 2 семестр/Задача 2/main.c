#include <stdio.h>
#include <math.h>

// Метод Симпсона
double integral(double a, double b, int N, double (*f)(double)) {
    if (N % 2 != 0) N++;  // Симпсон требует четное N

    double h = (b - a) / N;
    double sum = f(a) + f(b);

    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += (i % 2 == 0 ? 2 : 4) * f(x);
    }

    return sum * h / 3.0;
}

// Функции и их точные интегралы на отрезке [a, b]

double f1(double x) { return 1.0; }
double true_integral_f1(double a, double b) { return b - a; }

double f2(double x) { return 2 * x + 1; }
double true_integral_f2(double a, double b) { return b * b + b - a * a - a; }

double f3(double x) { return x * x - 2 * x + 2; }
double true_integral_f3(double a, double b) {
    return (pow(b, 3) - pow(a, 3)) / 3.0 - (b * b - a * a) + 2 * (b - a);
}

double f4(double x) { return sin(x); }
double true_integral_f4(double a, double b) {
    return -cos(b) + cos(a);
}

void investigate(double (*f)(double), double (*true_integral)(double, double),
                 double a, double b, int max_power) {
    printf(" N     |  |I_n - I|        |I_n - I_2n|\n");
    printf("-------------------------------------------\n");

    double I_true = true_integral(a, b);
    double prev_In = integral(a, b, 1, f);

    for (int k = 0; k <= max_power; k++) {
        int N = 1 << k;
        double In = integral(a, b, N, f);
        double In2 = integral(a, b, N * 2, f);

        double error = fabs(In - I_true);
        double diff = fabs(In - In2);

        printf("%5d | %e | %e\n", N, error, diff);

        prev_In = In;
    }

    printf("\nЧисленно посчитанный интеграл при N = %d: %.10lf\n", 1 << max_power, prev_In);
    printf("Истинное значение интеграла: %.10lf\n", I_true);
}

int main() {
    int choice;
    double a, b;
    int max_power;

    printf("Выберите функцию для интегрирования:\n");
    printf("1. f(x) = 1\n");
    printf("2. f(x) = 2x + 1\n");
    printf("3. f(x) = x^2 - 2x + 2\n");
    printf("4. f(x) = sin(x)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    printf("Введите границы интегрирования (a b): ");
    scanf("%lf %lf", &a, &b);
    printf("Введите максимальную степень двойки для N (например, 5 => N до 32): ");
    scanf("%d", &max_power);

    switch (choice) {
        case 1:
            investigate(f1, true_integral_f1, a, b, max_power);
            break;
        case 2:
            investigate(f2, true_integral_f2, a, b, max_power);
            break;
        case 3:
            investigate(f3, true_integral_f3, a, b, max_power);
            break;
        case 4:
            investigate(f4, true_integral_f4, a, b, max_power);
            break;
        default:
            printf("Некорректный выбор.\n");
    }

    return 0;
}
