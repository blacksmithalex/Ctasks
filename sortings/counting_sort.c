#include <stdio.h>
#include <stdlib.h>

#define B 1000

int main() {
    int n;
    int num;
    scanf("%d", &n);
    int a[n];
    int b[B] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        b[num]++;
    }
    int i = 0;
    while (i < n) {
        for (int num = 0; num < B; num++) {
            for (int j = 0; j < b[num]; j++){
                a[i] = num;
                i++;
            }
        }
    }

    printf("Result:");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

}
