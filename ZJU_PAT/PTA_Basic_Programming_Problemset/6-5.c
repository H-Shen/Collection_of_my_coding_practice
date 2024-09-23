#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Max( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}

/* Your code will be pasted here */ElementType Max( ElementType S[], int N )
{
  const ElementType eps = 1e-6;
  ElementType maxVal = S[0], diff = 0;

  for (int i = 1; i < N; ++i) {
    diff = maxVal - S[i];
    if (diff < -eps || diff < eps) {
      maxVal = S[i];
    }
  }
  return maxVal;
}