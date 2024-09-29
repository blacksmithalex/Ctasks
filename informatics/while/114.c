#include <stdio.h>

int main()
{
    int num, s;
    scanf("%d", &num);
    while (num != 0) {
        s += num % 10;
        num = num / 10;
    }
    printf("%d", s);
}