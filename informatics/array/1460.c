#include <stdio.h>
void right_shift(int *a, int N, int K) {
    int b[N];
    for (int i = 0; i < N; i++) {
        b[(i + K) % N] = a[i];
    }
    for (int i = 0; i < N; i++) {
        a[i] = b[i];
    }
}

int main()
{
    int N, K;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &K);
    
    right_shift(a, N, K);

    for (int i = 0; i < N; i++) printf("%d ", a[i]);
    
    return 0;
}