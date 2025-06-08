#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    int ind_max = 0;
    for (int i = 0; i < N; i++){
        if (a[i] > a[ind_max])
            ind_max = i;
    }
    int tmp = a[0];
    a[0] = a[ind_max];
    a[ind_max] = tmp;

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}