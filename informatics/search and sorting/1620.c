#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_long(const void *a, const void *b)
{
  return (*(const long *)a - *(const long *)b); // для возрастания
}

long max_num_groups(long *h, long N, long C, long inconv)
{
  long i = 0;
  long count = 0;
  while (i <= N - C)
  {
    long first = h[i];
    long last = h[i + C - 1];
    if (last - first <= inconv)
    {
      count++;
      i += C;
    }
    else
    {
      i++;
    }
  }
  return count;
}

int main()
{
  long N, R, C;
  scanf("%ld %ld %ld", &N, &R, &C);
  long *h = (long *)malloc(N * sizeof(long));
  for (long i = 0; i < N; i++)
    scanf("%ld", &h[i]);
  qsort(h, N, sizeof(long), compare_long);
  // for (long i = 0; i < N; i++)
  //   printf("%ld ", h[i]);
  long l = -1;
  long r = h[N - 1] - h[0];
  while (l + 1 != r)
  {
    long inconv = (l + r) / 2;
    if (max_num_groups(h, N, C, inconv) < R)
      l = inconv;
    else
      r = inconv;
  }
  printf("%ld", r);
}