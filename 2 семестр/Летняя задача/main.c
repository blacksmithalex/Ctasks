#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/*
  Решение уравнения: I(1,x) - alpha * x = 0,
  где I(1,x) = ∫_{t=1}^x sqrt(1 + 1/(1+t^2)) dt

  Используется:
   - метод Ньютона для поиска корня
   - метод Симпсона (композитный) с адаптивным уточнением шага
     реализован через итеративное уточнение трапеций (повторное использование значений)
     и формулу Симпсона S = (4*T_{2N} - T_N) / 3
*/

/// ---------- Подынтегральная функция ----------
double integrand(double t)
{
    // f(t) = sqrt(1 + 1/(1 + t^2))
    double denom = 1.0 + t * t;
    double inside = 1.0 + 1.0 / denom;
    if (inside < 0.0)
        return NAN; // теоретически не должно случиться
    return sqrt(inside);
}

/// ---------- Помощные функции ----------
static inline bool is_bad_double(double x)
{
    return !isfinite(x);
}

/// Простая функция, интегрирует полином с коэффициентами coeff[0..m-1] (степени 0..m-1) на [a,b]
double integrate_poly_exact(double *coeff, int m, double a, double b)
{
    double res = 0.0;
    for (int k = 0; k < m; ++k)
    {
        double c = coeff[k] / (k + 1);
        res += c * (pow(b, k + 1) - pow(a, k + 1));
    }
    return res;
}

/// Приближённое вычисление производных в точке x (центральная разность)
/// Используется для оценки коэффициентов ряда Тейлора при устранении особенности (если потребуется).
void numeric_derivatives(double (*f)(double), double x, int m, double h, double *out)
{
    // вычисляем f^(k)(x) / k! приближённо через центральные разности => используем простую формулу для коэффов ряда Тейлора:
    // приближенно коэффициент при (t-x)^k / k! равен f^{(k)}(x) / k!
    // Здесь мы используем простую схема: для k=0 используем f(x), для k>=1 используем разностные схемы (приближённо).
    // Для надёжности применяем только малые m (например m<=4). В основном это вспомогательный механизм.
    out[0] = f(x);
    if (m <= 1)
        return;
    double fh = f(x + h);
    double fmh = f(x - h);
    out[1] = (fh - fmh) / (2.0 * h); // первая производная (в виде f')
    if (m <= 2)
        return;
    double f2 = (fh - 2.0 * out[0] + fmh) / (h * h);
    out[2] = f2 / 2.0; // коэффициент при (t-x)^2 / 2!
    if (m <= 3)
        return;
    // простая оценка третьей производной (грубая)
    double f2ph = f(x + 2 * h);
    double f2mh = f(x - 2 * h);
    double third = (f2ph - 2.0 * fh + 2.0 * fmh - f2mh) / (2.0 * h * h * h);
    out[3] = third / 6.0; // /3!
}

/// ---------- Композитный Симпсон с адаптацией через последовательное уточнение трапеций ----------
/*
  Идея:
   - Итеративно строим трапециевальные приближения T_n, где n = 1,2,4,8,...
   - Для перехода T_n -> T_{2n} пересчитываем только значения в новых серединах;
     T_{2n} = T_n / 2 + h_new * sum(f(midpoints))
   - Затем используем формулу Симпсона:
     S_n = (4*T_{2n} - T_n) / 3
   - Оценка погрешности: |S_n - S_prev|
   - Останов, когда |S_n - S_prev| < eps
   - Это позволяет повторно использовать вычисления и не пересчитывать интеграл с нуля.
*/
double adaptive_simpson(double a, double b, double eps, double *used_integ_tol)
{
    if (!(isfinite(a) && isfinite(b)))
        return NAN;
    if (a == b)
        return 0.0;
    // Проверяем корректность подынтегральной функции в начале:
    double fa = integrand(a);
    if (is_bad_double(fa))
    {
        // Если в a функция не определена (NaN, Inf), пытаемся убрать особенность:
        // Аппроксимируем функцию рядом с a полиномом порядка m-1 и интегрируем полином на [a, a+delta]
        // Затем численно считаем оставшуюся часть.
        // (Обратите внимание: это - общий эвристический блок; для строг. аналитич. оценки нужно знать тип особенности.)
        double delta = 1e-6;
        double c = a + delta;
        int m = 4;
        double coeff[4] = {0};
        // вычислим коэффициенты ряда Тейлора в точке c (сдвинули точку)
        numeric_derivatives(integrand, c, m, delta / 10.0, coeff);
        // coeff[k] ≈ f^{(k)}(c)/k!
        double poly_integral = integrate_poly_exact(coeff, m, a - c, 0.0); // интеграл по переменной s = t-c от s = a-c .. 0
        // но integrate_poly_exact ожидает степени на [a,b] — запишем явнее:
        // интегрируем по t: f(t) ≈ sum_{k} coeff[k] * (t-c)^k
        // интеграл от t=a..c
        double poly_res = 0.0;
        for (int k = 0; k < m; ++k)
        {
            double ccoef = coeff[k] / (k + 1);
            poly_res += ccoef * (pow(c, k + 1) - pow(a, k + 1) - /* поправка из-за смещения */ 0.0);
            // Примечание: это упрощение; здесь лучше было бы перевести переменные. Упрощаем ради общей схемы.
        }
        // Для простоты: если fa не определено — просто смещаем a немного вправо и считаем численно
        a = c;
        // дальше продолжаем численно; сообщим, что мы применяли специальную обработку
    }

    // Начальное трапециевальное приближение T1:
    double h = b - a;
    double T_prev = 0.5 * (integrand(a) + integrand(b)) * h;
    if (is_bad_double(T_prev))
        return NAN;
    double S_prev = NAN;
    int iter = 0;
    const int MAX_ITER = 30;    // позволяет N до 2^30 — в практических задачах ограничение по float/double
    double sum_midpoints = 0.0; // суммa значений f в новых midpoints при каждом удвоении
    double N_intervals = 1;     // текущее число трапеций (n)
    while (iter < MAX_ITER)
    {
        // считаем T_new (для 2n трапеций)
        // новые точки: a + (2k-1)*h/(2n) при переходе n -> 2n; проще: при текущем h_old = (b-a)/n, новые midpoints имеют шаг h_old/2
        double h_new = h / 2.0;
        double sum_new = 0.0;
        // количество новых узлов равно n (старому количеству трапеций)
        // используем формулу: sum f at midpoints
        for (int k = 0; k < (int)N_intervals; ++k)
        {
            double xmid = a + (k + 0.5) * h;
            double fx = integrand(xmid);
            if (is_bad_double(fx))
                return NAN;
            sum_new += fx;
        }
        double T_new = 0.5 * T_prev + h_new * sum_new;
        // Симпсон:
        double S_new = (4.0 * T_new - T_prev) / 3.0;
        if (!isnan(S_prev))
        {
            if (fabs(S_new - S_prev) < eps)
            {
                if (used_integ_tol)
                    *used_integ_tol = fabs(S_new - S_prev);
                return S_new;
            }
        }
        // подготовка к следующей итерации
        S_prev = S_new;
        T_prev = T_new;
        // удваиваем число интервалов
        N_intervals *= 2.0;
        h *= 0.5;
        iter++;
    }
    // если не сошлось по итерациям, возвращаем последнее значение
    if (used_integ_tol)
        *used_integ_tol = fabs(S_prev);
    return S_prev;
}

/// ---------- Функция, корень которой ищем ----------
double F(double x, double alpha, double integ_eps)
{
    // I(1,x) - alpha * x
    double used_tol = 0.0;
    // Если x < 1, предполагаем интеграл от 1 до x с пересчётом знака:
    if (x == 1.0)
        return -alpha * x; // интеграл 0
    double a = 1.0, b = x;
    double sign = 1.0;
    if (b < a)
    {
        double tmp = a;
        a = b;
        b = tmp;
        sign = -1.0;
    }
    double I = adaptive_simpson(a, b, integ_eps, &used_tol);
    if (!isfinite(I))
        return NAN;
    return sign * I - alpha * x;
}

/// Производная F'(x) = integrand(x) - alpha (в силу основой теоремы о производной интеграла)
double dF(double x, double alpha)
{
    return integrand(x) - alpha;
}

/// ---------- Метод Ньютона (с контролем точности) ----------
double newton_root(double x0, double alpha, double eps_root, double integ_eps, int max_iters)
{
    double x = x0;
    for (int i = 0; i < max_iters; ++i)
    {
        double Fx = F(x, alpha, integ_eps);
        double dFx = dF(x, alpha);
        printf("Newton iter %2d: x = %.12e, F(x)=%.12e, F'(x)=%.12e\n", i + 1, x, Fx, dFx);
        if (!isfinite(Fx) || !isfinite(dFx))
        {
            printf("  числовая проблема (NaN/Inf) в функции или её производной\n");
            return NAN;
        }
        if (fabs(Fx) < eps_root)
        {
            printf("  Условие по значению функции выполнено: |F(x)| < eps_root\n");
            return x;
        }
        if (fabs(dFx) < 1e-16)
        {
            printf("  Производная близка к нулю — метод Ньютона может расходиться\n");
            return NAN;
        }
        double dx = Fx / dFx;
        double x_new = x - dx;
        if (fabs(dx) < eps_root * (1.0 + fabs(x)))
        {
            printf("  Условие по шагу выполнено: |dx| < eps_root\n");
            return x_new;
        }
        x = x_new;
    }
    printf("  Достигнуто max_iters = %d, возвращаю текущее приближение\n", max_iters);
    return x;
}

/// ---------- Утилиты для поиска всех корней на интервале (простая эвристика) ----------
/*
  Т.к. требование "найти все решения" не уточнено по области поиска, реализуем простую сеточную
  эвристику: переберём начальные приближения x0 на сетке [x_min, x_max] и для каждого применим Ньютон.
  Корни, лежащие близко друг к другу (|x_i - x_j| < tol_merge) считаем одинаковыми.
*/
void find_roots_alpha(double alpha, double x_min, double x_max, double eps_root, double integ_eps,
                      double x0_step, int max_newton_iters)
{
    const double tol_merge = eps_root * 10.0;
    int max_points = (int)ceil((x_max - x_min) / x0_step) + 1;
    double *roots = malloc(sizeof(double) * max_points);
    int roots_count = 0;

    for (double x0 = x_min; x0 <= x_max; x0 += x0_step)
    {
        // гарантируем, что начальное приближение не слишком близко к 1 (нижний предел интеграла)
        double x_start = x0;
        if (fabs(x_start - 1.0) < 1e-8)
            x_start += 1e-6;

        double xr = newton_root(x_start, alpha, eps_root, integ_eps, max_newton_iters);
        if (!isfinite(xr))
            continue;
        // проверяем, действительно ли xr корень
        double Fx = F(xr, alpha, integ_eps);
        if (fabs(Fx) > 1e-6)
        {
            // возможно неудачный исход
            continue;
        }
        // проверяем вхождение в диапазон
        if (xr < x_min - 1e-8 || xr > x_max + 1e-8)
            continue;
        // слияние близких корней
        bool merged = false;
        for (int k = 0; k < roots_count; ++k)
        {
            if (fabs(roots[k] - xr) < tol_merge)
            {
                // уточним корень — возьмём медиану/среднее
                roots[k] = 0.5 * (roots[k] + xr);
                merged = true;
                break;
            }
        }
        if (!merged)
        {
            roots[roots_count++] = xr;
        }
    }

    // вывод найденных корней
    if (roots_count == 0)
    {
        printf("Для alpha = %.8g корней на отрезке [%.8g, %.8g] не найдено (по сеточной эвристике).\n",
               alpha, x_min, x_max);
    }
    else
    {
        printf("Найдено %d разных корней для alpha = %.8g:\n", roots_count, alpha);
        for (int i = 0; i < roots_count; ++i)
        {
            double x = roots[i];
            double val = F(x, alpha, integ_eps);
            printf("  x_%d = %.12e, F(x) = %.3e\n", i + 1, x, val);
        }
    }
    free(roots);
}

/// ---------- main: интерфейс пользователя ----------
int main()
{
    printf("Решение уравнения I(1,x) - alpha * x = 0, где\n");
    printf("I(1,x) = ∫_{t=1}^{x} sqrt(1 + 1/(1+t^2)) dt\n\n");

    while (1)
    {
        double alpha;
        printf("Введите значение alpha (или 'q' чтобы выйти): ");
        if (scanf("%lf", &alpha) != 1)
            break;

        double eps_root;
        printf("Введите требуемую точность для корня eps_root (например 1e-8): ");
        if (scanf("%lf", &eps_root) != 1)
            break;

        double integ_eps;
        printf("Введите требуемую точность интегрирования integ_eps (например 1e-8): ");
        if (scanf("%lf", &integ_eps) != 1)
            break;

        double x_min, x_max;
        printf("Введите интервал поиска корней [x_min, x_max] (например 0.5 100): ");
        if (scanf("%lf %lf", &x_min, &x_max) != 2)
            break;

        double x0_step;
        printf("Введите шаг сетки начальных приближений x0_step (например 0.5): ");
        if (scanf("%lf", &x0_step) != 1)
            break;

        int max_newton_iters;
        printf("Введите максимальное число итераций метода Ньютона (например 50): ");
        if (scanf("%d", &max_newton_iters) != 1)
            break;

        // Простая проверка: если x_min == x_max — попробовать одно начальное приближение
        if (x_min > x_max)
        {
            double tmp = x_min;
            x_min = x_max;
            x_max = tmp;
        }

        find_roots_alpha(alpha, x_min, x_max, eps_root, integ_eps, x0_step, max_newton_iters);

        printf("\n--- Готово для alpha=%.8g ---\n\n", alpha);
    }

    printf("Выход.\n");
    return 0;
}
