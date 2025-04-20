#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int m, n, i, j;
    double *a, *c;
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
    if (!(c = (double*)malloc(n * sizeof(double))))
    {
        free(a);
        fclose(in);
        fclose(out);
        return -1;
    }
    for (i = 0; i < n; i++)
        c[i]=0;
    for(i = 0; i < n * m; i++)
        if (fscanf(in,"%lf ", &a[i]) != 1)
        {
            free(a);
            free(c);
            fclose(in);
            fclose(out);
            return -1;
        }
    fclose(in);
    // process(a,n,m);
    // multipl(a,c,n,m);
    fprintf(out, "%d %d\n", n, m);
    for(i = 0;i < n; i++)
    {
        for(j = 0;j < m; j++)
            fprintf(out,"%lf  ", a[i * m + j]);
        fprintf(out,"\n");
    }
    fprintf(out,"\n");
    for(i = 0; i < n; i++)
        fprintf(out, "%lf\n", c[i]);
    free(a);
    free(c);
    fclose(out);
    return 0;
}
