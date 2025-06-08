#include <stdio.h>

int main()
{
    int x, count;
    scanf("%d", &x);
    count = 0;
    for (int d = 1; d <= x; d++) {
        if (x % d == 0) count++;
    }
    printf("%d", count);
} 