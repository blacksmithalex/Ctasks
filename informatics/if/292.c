#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b) {
        printf("%d", a);
    } else {
        printf("%d", b);
    }
    return 0;
}