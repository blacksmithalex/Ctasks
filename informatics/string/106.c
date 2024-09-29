#include <stdio.h>
#include <stdbool.h>
int countWords(const char *str) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count + 1;
}


int main()
{
    char input[1000];
    fgets(input, sizeof(input),stdin);
    int wordCount = countWords(input);
    printf("%d", wordCount);
}