#include <stdio.h>
#include <stdlib.h>

long long *memo;

long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n]; 
    }
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int num;
    long long res;
    
    printf("Write the fibonacci number: ");
    scanf("%d", &num);
    memo = (long long *)malloc((num + 1) * sizeof(long long));

    for (int i = 0; i <= num; i++) {
        memo[i] = -1;
    }

    res = fib(num);
    printf("Fib_n = %lld\n", res);

    free(memo);

    return 0;
}
