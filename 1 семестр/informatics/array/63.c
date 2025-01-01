#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < N; i+=2) {
        printf("%d ", a[i]);
    }
    
    return 0;
}