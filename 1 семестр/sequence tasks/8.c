#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define EPS 1e-6
int main()
{
    double prev, cur, next;
    scanf("%lf", &prev);
    scanf("%lf", &cur);
    scanf("%lf", &next);
    while (fabs(next) > EPS) {
        bool rule1 = !(next > cur && cur > prev);
        bool rule2 = !(next < cur && cur < prev);
        if (rule1 && rule2) {
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