#include <stdio.h>
int main()
{
    int N, count;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < N; i+=2) {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}