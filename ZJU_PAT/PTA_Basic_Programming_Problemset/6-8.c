#include <stdio.h>

int Factorial(const int N);

int main() {
  int N, NF;

  scanf("%d", &N);
  NF = Factorial(N);
  if (NF)
    printf("%d! = %d\n", N, NF);
  else
    printf("Invalid input\n");

  return 0;
}

/* Your code will be pasted here */
int Factorial(const int N) {
  if (N < 0)
    return 0;
  if (N == 0)
    return 1;

  int res = 1;
  for (int i = 1; i <= N; ++i) {
    res *= i;
  }
  return res;
}