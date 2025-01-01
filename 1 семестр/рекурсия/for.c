#include <stdio.h>
#include <stdlib.h>

long long fib(int n) {
    long long prev, cur, tmp;
    int i;
    prev = 0;
    cur = 1;
    for(i = 1; i < n; i++){
        tmp = prev;
        prev = cur;
        cur = prev + tmp;
    }
    return cur;
}

int main() {
    int num;
    long long res;
    printf("Write the fibonacci number: ");
    scanf("%d", &num);
    res = fib(num);
    printf("Fib_n = %lld", res);
    return 0;
}
