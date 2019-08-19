#include <stdio.h>

#define MAXN 10

typedef float ElementType;

ElementType Average(ElementType S[], int N);

int main() {
  ElementType S[MAXN];
  int N, i;

  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%f", &S[i]);
  printf("%.2f\n", Average(S, N));

  return 0;
}

/* Your code will be pasted here */

ElementType Average(ElementType S[], int N) {
  ElementType res = 0;
  if (N == 0)
    return res;

  for (int i = 0; i < N; ++i) {
    res += S[i];
  }
  res = res / (ElementType)N;
  return res;
}
