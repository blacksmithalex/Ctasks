#include <stdio.h>

int main()
{
    int num, even;
    even = 0;
    scanf("%d", &num);
    while (num != 0) {
        if (num % 2 == 0) even++;
        scanf("%d", &num);
    }
    printf("%d", even);
}