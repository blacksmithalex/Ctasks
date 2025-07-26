#include <stdio.h>

int main()
{
    int N, deg_two;
    scanf("%d", &N);
    deg_two = 1;
    while (deg_two <= N){
        printf("%d ", deg_two);
        deg_two *= 2;
    }
    return 0;
}