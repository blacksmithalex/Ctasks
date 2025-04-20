#include <stdio.h>
#include <stdlib.h>


int process(double *a, int n, int m, int i2, int i1)
{
    // return 1, если столбец i2 > i1 в указанном смысле; 0 - иначе
    float s_diff = 0;
    for (int i = 0; i < n; i++){
        s_diff += a[i * m + i2] - a[i * m + i1];
    }
    if (s_diff > 0)
        return 1;
    else
        return 0;
}


int main (void)
{
    int m, n, i, j;
    double *a;
    FILE *in = fopen("input.txt","r");
    FILE *out = fopen("output.txt","w");
    if (in == NULL)
        return -1;
    if (out == NULL)
    {
        fclose(in);
        return -1;
    }
    if (fscanf(in, "%d", &n) != 1)
    {
        fclose(in);
        fclose(out);
        return -1;
    }
    if (fscanf(in, "%d", &m) != 1)
    {
        fclose(in);fclose(out);
        return -1;
    }
    if (n < 0 || m < 0)
    {
        fclose(in);
        fclose(out);
        return -1;
    }
    if (!(a = (double*)malloc(n * m * sizeof(double))))
    {
        fclose(in);
        fclose(out);
        return -1;
    }
    for(i = 0; i < n * m; i++)
        if (fscanf(in,"%lf ", &a[i]) != 1)
        {
            free(a);
            fclose(in);
            fclose(out);
            return -1;
        }
    fclose(in);
    if (process(a, n, m, 0, 1) == 1)
        fprintf(out, "YES");
    else
        fprintf(out, "NO");
    free(a);
    fclose(out);
    return 0;
}
