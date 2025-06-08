#include <stdio.h>
int main()
{
    int N, count;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i < N; i+=1) {
        if (a[i] > a[i - 1]) count++;
    }
    
    printf("%d", count);
    
    return 0;
}