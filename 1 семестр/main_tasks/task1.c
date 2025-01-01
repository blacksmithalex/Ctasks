#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    double num;
    double sum = 0.0, product = 1.0, harmonic_sum = 0.0;
    int count = 0;
    
    while (true) {
        if (scanf("%lf", &num) != 1) {
            printf("Некорректный ввод");
            return 1;
        }
        
        if (num == 0.0) break;
        
        sum += num;
        product *= num;
        harmonic_sum += 1.0 / num;
        count++;
    }
    
    if (count == 0) {
        printf("Пустой ввод");
        return 2;
    }
    
    double arithmetic_mean = sum / count;
    double harmonic_mean = count / harmonic_sum;
    
    printf("Среднее арифметическое: %lf\n", arithmetic_mean);
    printf("Среднее гармоническое: %lf\n", harmonic_mean);
    
    if (product < 0.0 && count % 2 == 0) {
        printf("Среднее геометрическое не может быть вычислено");
        return 3;
    }
    double geometric_mean = pow(product, 1.0 / count);
    printf("Среднее геометрическое: %lf\n", geometric_mean);
    
    return 0;
}