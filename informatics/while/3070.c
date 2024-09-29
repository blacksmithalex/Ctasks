#include <stdio.h>

int main()
{
    int num, sm, m; 
    sm = 0;
    m = 0;
    scanf("%d", &num);
    while (num != 0) {
        if (num > m) {
            sm = m;
            m = num;
        } else if (num > sm){
            sm = num;
        }
        scanf("%d", &num);
    }
    printf("%d", sm);
}