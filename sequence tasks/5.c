#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double num;
    double X = 1.2;
    scanf("%lf", &num);
    while (fabs(num) > EPS) {
        if (fabs(num - X) < EPS) {
            printf("YES");
            return 0;
        }
        scanf("%lf", &num);
    }
    printf("NO");
    return 0;
}