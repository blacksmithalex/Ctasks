#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Len(FILE *f);
void Scan(FILE *f, int *arr, int len);
void Sort(int *arr, int len);
int Func(int *A, int a);

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

int Func(int *A, int a) {
    //count uniq
    int count; 
    int countm = 1;
    int i = 0;
    for (int j = 0; j < a; j++) {
        if (A[i] == A[j]) {
            count = j - i + 1;
            if (count > countm)
                countm = count;
        } else {
            i = j;
        }
    }
    return countm;
}

int main(void) {
    FILE *ina, *inb, *out;
    int a, b, resA, resB;
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

    resA = Func(A, a);
    resB = Func(B, b);
    if (resA > resB) 
        fprintf(out, "%d", 1);
    else if (resA < resB)
        fprintf(out, "%d", -1);
    else  
         fprintf(out, "%d", 0);  
    fclose(ina);
    fclose(inb);
    fclose(out);
    free(A);
    free(B);
    return 0;
}

