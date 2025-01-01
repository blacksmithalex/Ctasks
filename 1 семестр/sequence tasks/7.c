#include <stdio.h>
#include <math.h>
#define EPS 1e-6
int main()
{
    double cur, prev;
    scanf("%lf", &prev);
    scanf("%lf", &cur);
    while (fabs(cur) > EPS) {
        if (fabs(cur - prev) > EPS) {
            printf("NO");
            return 0;
        }
        prev = cur;
        scanf("%lf", &cur);
    }
    printf("YES");
    return 0;
}