#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int i1, int i2){
    int tmp;
    tmp = a[i1];
    a[i1] = a[i2];
    a[i2] = tmp;
}

void custom_bubble_sort(int *a, int N){
    for (int i = 0; i < 2 * N; i += 2){
        for (int j = 0; j < 2 * N - 3 - i; j += 2){
            if (a[j + 1] < a[j + 3]){
                swap(a, j + 1, j + 3);
                swap(a, j, j + 2);                
            } else if (a[j + 1] == a[j + 3]) {
                if (a[j] > a[j + 2]) {
                    swap(a, j, j + 2);
                }
            }
            // for (int i = 0; i < 2 * N; i += 2){
            //     printf("%d %d\n", a[i], a[i + 1]);
            // }
            // printf("\n");
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int *a = (int *)malloc(2 * N * sizeof(int));
    for (int i = 0; i < 2 * N; i += 2)
        scanf("%d %d", &a[i], &a[i + 1]);
    custom_bubble_sort(a, N);
    for (int i = 0; i < 2 * N; i += 2){
        printf("%d %d\n", a[i], a[i + 1]);
    }
}