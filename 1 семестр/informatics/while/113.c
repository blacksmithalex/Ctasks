#include <stdio.h>

int main()
{
    int N, i;
    scanf("%d", &N);
    i = 1;
    while (i * i <= N) {
        printf("%d\n", i * i);
        i++;
    }
    return 0;
}