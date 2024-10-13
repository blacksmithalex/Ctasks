#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define EPS 1e-6
int main()
{
    double prev, cur, next;
    double c1 = 1.0, c2 = 1.0, c3 = 1.0, b = 4.0;
    scanf("%lf", &prev);
    scanf("%lf", &cur);
    scanf("%lf", &next);
    while (fabs(next) > EPS) {
        double val = c1 * prev + c2 * cur + c3 * next;
        if (fabs(val - b) > EPS) {
            printf("NO");
            return 0;
        }
        prev = cur;
        cur = next;
        scanf("%lf", &next);
    }
    printf("YES");
    return 0;
}