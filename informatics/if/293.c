#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b){
        printf("%d", 1);
    }
    else if (a < b)
        printf("%d", 2);
    else
        printf("%d", 0);
    return 0;
} 