#include <stdio.h>
#include <stdbool.h>
int main()
{
    int prev, cur, count;
    count = 1;
    scanf("%d", &prev);
    scanf("%d", &cur);
    while (cur != 0) {
        if (cur > prev) count++;
        prev = cur;
        scanf("%d", &cur);
    }
    printf("%d", count);
    return 0;
}