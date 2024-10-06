#include <stdio.h>
int main()
{
    int N, count;
    scanf("%d", &N);
    int a[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    
    int i, j = N - 1;
    while (i < j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}