#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int N){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N - i - 1; j++){
            if (a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, N);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
}