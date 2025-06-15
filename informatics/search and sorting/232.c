#include <stdio.h>
#include <stdlib.h>

void insert(int *a, int ind_up, int ind_down){
    int elem = a[ind_up];
    for (int i = ind_up; i > ind_down; i--){
        a[i] = a[i - 1];
    }
    a[ind_down] = elem;
}

int find_ind_down(int *a, int ind_up){
    int ind_down = 0;
    while (a[ind_down] < a[ind_up])
        ind_down++;
    return ind_down;
}

void ins_sort(int *a, int N){
    for (int i = 1; i < N; i++){
        int ind_down = find_ind_down(a, i);
        insert(a, i, ind_down);
    }
}

int main()
{
    int N, elem, ind;
    scanf("%d", &N);
    int *a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    ins_sort(a, N);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
}