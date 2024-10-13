#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double num;
    int count, pos;
    double X = 1.2;
    scanf("%lf", &num);
    while (fabs(num) > EPS) {
        count++;
        if (fabs(num - X) < EPS) {
            pos = count;
        }
        scanf("%lf", &num);
    }
    printf("%d", pos);
    return 0;
}