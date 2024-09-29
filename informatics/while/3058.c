#include <stdio.h>

int main()
{
    int N, d;
    scanf("%d", &N);
    d = 2;
    while (N % d != 0) d++;
    printf("%d", d);
    return 0;
}