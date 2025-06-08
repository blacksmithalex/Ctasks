#include <stdio.h>

int main()
{
    int N, f;
    scanf("%d", &N);
    f = 1;
    for (int i = 1; i <= N; i++) {
        f *= i;
    }
    printf("%d", f);
    return 0;
} 