#include <stdio.h>
#include <stdbool.h>
int main()
{
    int prev, cur, total, count;
    count = 0;
    total = 0;
    scanf("%d", &prev);
    scanf("%d", &cur);
    while (cur != 0) {
        if (cur == prev) {
            if (count == 0) count++;
            count++;  
        } else {
            total += count;
            count = 0;
        }
        prev = cur;
        scanf("%d", &cur);
    }
    if (count > 1) total += count;
    printf("%d", total);
    return 0;
}