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
    for (int pos = N - 1; pos >= 0; pos--){
        int ind_max = 0;
        for (int i = 0; i <= pos; i++){
            if (a[i] > a[ind_max])
                ind_max = i;
        }
        int tmp = a[pos];
        a[pos] = a[ind_max];
        a[ind_max] = tmp;
    }

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}