#include <stdio.h>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    if (x1 == x2 || y1 == y2) printf("YES");
    else printf("NO");
    return(0);
} 