#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int num, res;
    printf("Write the fibonacci number: ");
    scanf("%d", &num);
    res = fib(num);
    printf("Fib_n = %d", res);
    return 0;
}
