#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double num;
    double sum = 0.0;
    int count = 0;
    scanf("%lf", &num);
    while (fabs(num) > EPS) {
        sum += num;
        count++;
        scanf("%lf", &num);
    }
    printf("%lf", sum / count);
    return 0;
}