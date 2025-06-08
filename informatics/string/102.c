#include <stdio.h>
#include <stdbool.h> 
bool IsDigit(unsigned char c) {
    return (c >= '0' && c <= '9');
}

int main()
{
    unsigned char c;
    scanf("%c", &c);
    if (IsDigit(c)) printf("yes");
    else printf("no");
    
}