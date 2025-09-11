#include <stdio.h>
#include <stdlib.h>

void update_matrix(int *a, int n){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int value;
            if (i + j < n - 1) value = 0;
            else if (i + j == n - 1) value = 1;
            else value = 2;
            a[i * n + j] = value;
        }
}

void print_matrix(int *a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", a[i * n + j]);
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc((n * n) * sizeof(int));
    update_matrix(a, n);
    print_matrix(a, n);
    return 0;
}