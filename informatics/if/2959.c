#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    if (x > 0) printf("%d", 1);
    else if (x < 0) printf("%d", -1);
    else printf("%d", 0);
    return 0;
} 