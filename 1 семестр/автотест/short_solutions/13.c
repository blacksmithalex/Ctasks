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
    int prev;
    int i, j;
    i = 0;
    j = 0;
    if (A[0] < B[0]) {
        i += 1;
        prev = A[0];
    } else {
        j += 1;
        prev = B[0];
    }
    while (i < a && j < b) {
        if (A[i] < B[j]) {
            if (A[i] != prev + 1) return 0;
            prev = A[i];
            i++;
        } else {
            if (B[j] != prev + 1) return 0;
            prev = B[j];
            j ++;
        }
    }

    while (i < a) {
        if (A[i] != prev + 1) return 0;
        prev = A[i];
        i++;
    }

    while (j < b) {
        if (B[j] != prev + 1) return 0;
        prev = B[j];
        j++;
    }

    return 1;
}

int main(void) {
    FILE *ina, *inb, *out;
    int a, b, check;
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
    check = Func(A, B, a, b);
    if (check)
        fprintf(out, "YES");
    else
        fprintf(out, "NO");
    fclose(ina);
    fclose(inb);
    fclose(out);
    free(A);
    free(B);
    return 0;
}

