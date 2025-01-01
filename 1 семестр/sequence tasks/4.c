#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double cur, prev;
    int count = 0;
    scanf("%lf", &prev);
    scanf("%lf", &cur);
    while (fabs(cur) > EPS) {
        if (cur > prev) count++;
        prev = cur;
        scanf("%lf", &cur);
    }
    printf("%d", count);
    return 0;
}