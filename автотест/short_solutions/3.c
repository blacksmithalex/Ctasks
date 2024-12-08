#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Len(FILE *f);
void Scan(FILE *f, int *arr, int len);
void Sort(int *arr, int len);
int Func(int *A, int *B, int a, int b);

int Len(FILE *f) {
    int len = 0;
    int c;
    while (fscanf(f, "%d", &c) == 1) 
        len++;
    return len;
}

void Scan(FILE *f, int *arr, int len) {
    int i;
    for (i = 0; i < len; i++) 
        fscanf(f, "%d", &arr[i]);
}

void Sort(int *arr, int len) {
    int i, j, t;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1; j++)
            if (arr[j] > arr[j + 1]) {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

int Func(int *A, int *B, int a, int b) {
    int i, j, uniq, prev;
    uniq = 1;
    prev = B[0];
    i = 0;
    j = 0;
    while (i < a && A[i] >= B[0]) i++;
    while (i < a && j < b && B[j] <= A[a - 1]) {
        if (A[i] < B[j]) {
            uniq++;
            prev = A[i];
            while (i < a && A[i] == prev) i++;
        } else if (A[i] == B[j]) {
            while (i < a && j < b && A[i] == B[j]) j++;
        } else {
            if (B[j] > A[a - 1]) break;
            uniq++;
            prev = B[j];
            while (j < b && B[j] == prev) j++;
        }
    }
    while (i < a) {
        if (A[i] != prev) {
            uniq++;
            prev = A[i];
        }
        i++;
    }
    return uniq;
}

int main(void) {
    FILE *ina, *inb, *out;
    int a, b, uniq;
    int *A, *B;
    ina = fopen("ina.txt", "r");
    inb = fopen("inb.txt", "r");
    out = fopen("output.txt", "w");
    if (ina == NULL) 
        return -1;
    if (inb == NULL) {
        fclose(ina);
        return -1;
    }
    if (out == NULL) {
        fclose(ina);
        fclose(inb);
        return -1;
    }
    a = Len(ina);
    b = Len(inb);
    if (a == 0 || b == 0) {
        fclose(ina);
        fclose(inb);
        fclose(out);
        return -1;
    }
    rewind(ina);
    rewind(inb);
    A = (int*)malloc(a * sizeof(int));
    B = (int*)malloc(b * sizeof(int));
    Scan(ina, A, a);
    Scan(inb, B, b);
    Sort(A, a);
    Sort(B, b);
    uniq = Func(A, B, a, b);
    fprintf(out, "%d", uniq);
    fclose(ina);
    fclose(inb);
    fclose(out);
    free(A);
    free(B);
    return 0;
}

