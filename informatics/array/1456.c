#include <stdio.h>
int main()
{
    int N, X;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    scanf("%d", &X);
    
    int pos;
    while (pos < N && a[pos] > X) pos++;
    
    
    printf("%d", pos + 1);
    
    return 0;
}