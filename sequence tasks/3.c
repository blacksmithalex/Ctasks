#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double num;
    double harmonic_sum = 0.0;
    int count = 0;
    scanf("%lf", &num);
    while (fabs(num) > EPS) {
        harmonic_sum += 1 / num;
        count++;
        scanf("%lf", &num);
    }
    harmonic_sum = count / harmonic_sum;
    printf("%lf", harmonic_sum);
    return 0;
}