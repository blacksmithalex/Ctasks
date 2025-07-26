#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    for (int i = a; i <= b; i++){
        if (i % d == c)
            printf("%d ", i);
    }
    return 0;
} 