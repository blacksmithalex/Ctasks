#include <stdio.h>
int main()
{
    int N, count;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    int m = a[0];
    
    for (int i = 1; i < N; i++) {
        if (a[i] > m) m = a[i];
    }
    
    printf("%d", m);
    
    return 0;
}