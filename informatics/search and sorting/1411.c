#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int *a, int N){
    int swaps = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if (a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main()
{
    int N, res;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    res = bubble_sort(a, N);
    printf("%d", res);
}