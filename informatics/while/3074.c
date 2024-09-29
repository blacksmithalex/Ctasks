#include <stdio.h>

int main()
{
    int n, prev, cur, tmp;
    scanf("%d", &n);
    prev = 0;
    cur = 1;
    for (int i = 2; i <= n; i++) {
        tmp = cur;
        cur = prev + cur; 
        prev = tmp;
    }
    printf("%d", cur);
}