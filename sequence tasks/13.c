#include <stdio.h>
int main()
{
    int i, imin, num, m;
    i = 1;
    imin = 1;
    scanf("%d", &num);
    m = num;
    while (num != 0) {
        if (num <= m) {
            imin = i;
            m = num;
        }
        i += 1;
        scanf("%d", &num);
    }
    printf("%d", imin);
    return 0;
}