#include <stdio.h>
void reverse_part(int *a, int l, int r){
    int i = l;
    int j = r;
    while (i < j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

int main()
{
    int N, A, B, C, D;
    scanf("%d", &N);
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    int a[N];
    for (int i = 0; i < N; i++) {
        a[i] = i + 1;
    }
    
    reverse_part(a, A - 1, B - 1);
    reverse_part(a, C - 1, D - 1);

    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    
    return 0;
}