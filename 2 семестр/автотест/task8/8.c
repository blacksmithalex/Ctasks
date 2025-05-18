#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-15

double weight(double *a,int m,int i)
{
    int j;

    double sum = 0.0;
    for (j = 0;j < m - 1; j++){
        if ((a[i * m + j + 1] - a[i * m + j]) > EPS) 
            sum += a[i * m + j + 1] - a[i * m + j];
    }
    return sum;


}


void process(double*a,int n,int m)
{
    int i,k,j;
    double w;
    for(k = 0; k < n - 1; k++)
    {
        for(i = 0;i < n - 1;i++)
        {
            if(weight(a, m, i) < weight(a, m, i + 1))
            for (j = 0; j < m; j++)
            {
                w=a[i*m+j];
                a[i*m+j]=a[(i+1)*m+j];
                a[(i+1)*m+j]=w;
            }
        }
    }
}


void multipl(double *a, double *c, int n, int m)
{
    int i, j;
    double g = 0;
    for (i = 0; i < n; i++)
    {
        g = 0;
        for(j = 0; j < m; j++)
            g += a[i * m + j] * a[j];
        c[i] = g;
    }
}

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
    process(a,n,m);
    multipl(a,c,n,m);
    fprintf(out, "%d %d\n", n, m);
    for(i = 0; i < n; i++)
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
