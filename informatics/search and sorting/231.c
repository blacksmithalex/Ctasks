#include <stdio.h>
#include <stdlib.h>

void insert(int *a, int N, int elem, int ind){
    int M = N + 1;
    ind--;
    a = (int *)realloc(a, M * sizeof(int));
    for (int i = M - 1; i > ind; i--){
        a[i] = a[i - 1];
    }
    a[ind] = elem;
}

int main()
{
    int N, elem, ind;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &elem, &ind);
    insert(a, N, elem, ind);
    for (int i = 0; i < N + 1; i++)
        printf("%d ", a[i]);
}