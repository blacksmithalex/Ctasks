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
    int N, M;
    scanf("%d %d", &N, &M);
    int *a = (int*)malloc(N * M * sizeof(int));
    for (int i = 0; i < N * M; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, N * M);
    int K;
    scanf("%d", &K);
    int *b = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++)
        scanf("%d", &b[i]);
    bubble_sort(b, K);

    //two pointers
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N * M && j < K){
        if (b[j] <= a[i]) {
            count++;
            j++;
            i++;
        } else {
            i++;
        }
    }
    printf("%d", count);
}