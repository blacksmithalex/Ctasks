#include <stdio.h>
unsigned char ToUpper(unsigned char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}
int main()
{
    unsigned char c;
    scanf("%c", &c);
    printf("%c", ToUpper(c));
}