#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double num;
    double product = 1.0;
    int count = 0;
    scanf("%lf", &num);
    while (num > EPS) {
        product *= num;
        count++;
        scanf("%lf", &num);
    }
    double geometric_mean = pow(product, 1.0 / count);
    printf("%lf", geometric_mean);
    return 0;
}