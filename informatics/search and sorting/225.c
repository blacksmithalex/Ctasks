#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, x;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);
    int nearest = a[0];
    for (int i = 1; i < N; i++){
        if (abs(x - a[i]) < abs(x - nearest))
            nearest = a[i];
    }
    printf("%d", nearest);
}