#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    if (b < a) a = b;
    if (c < a) a = c;
    printf("%d", a);
} 