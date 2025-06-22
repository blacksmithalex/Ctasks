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
    while (ind_down <= ind_up && a[ind_down] <= a[ind_up])
        ind_down++;
    if (ind_down > ind_up) 
        return ind_down - 1;
    else{
        return ind_down;
    }
}

void ins_sort(int *a, int N){
    for (int i = 1; i < N; i++){
        int ind_down = find_ind_down(a, i);
        if (ind_down != i){
            insert(a, i, ind_down);
            for (int j = 0; j < N; j++){
                printf("%d ", a[j]);
            }
            printf("\n");
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
    ins_sort(a, N);
}