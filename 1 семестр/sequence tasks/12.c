#include <stdio.h>
int main()
{
    int i, imax, num, m;
    i = 1;
    imax = 1;
    scanf("%d", &num);
    m = num;
    while (num != 0) {
        if (num > m) {
            imax = i;
            m = num;
        }
        i += 1;
        scanf("%d", &num);
    }
    printf("%d", imax);
    return 0;
}