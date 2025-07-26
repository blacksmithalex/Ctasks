#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    float c;
    scanf("%d", &a);
    scanf("%d", &b);
    c = sqrt(a * a + b * b);
    printf("%lf", c);
} 