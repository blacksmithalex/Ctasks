#include <stdio.h>
int main()
{
    int N, count;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    int last = a[N - 1];
    for (int i = N - 1; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = last;
    
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}