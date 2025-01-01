#include <stdio.h>

int main()
{
    int x, count, d;
    scanf("%d", &x);
    count = 0;
    d = 1; 
    while (d * d <= x) {
        if (x % d == 0) {
            if (d != x / d) count += 2;
            else count += 1;
        }
        d += 1;
    }
    printf("%d", count);
} 