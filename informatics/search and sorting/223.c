#include <stdio.h>
int main()
{
    int N, x;
    int count = 0;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &x);

    for (int i = 0; i < N; i++) {
        if (a[i] == x) count++;
    }

    printf("%d", count);
    
    return 0;
}