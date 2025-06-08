#include <stdio.h>

int main()
{
    int N, two;
    scanf("%d", &N);
    two = 1;
    while (two * 2 <= N) two *= 2;
    if (two == N) printf("YES");
    else printf("NO");
}