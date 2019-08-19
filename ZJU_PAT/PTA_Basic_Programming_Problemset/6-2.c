#include <stdio.h>

#define MAXN 10

double f(int n, double a[], double x);

int main() {
  int n, i;
  double a[MAXN], x;

  scanf("%d %lf", &n, &x);
  for (i = 0; i <= n; i++)
    scanf("%lf", &a[i]);
  printf("%.1f\n", f(n, a, x));
  return 0;
}

/* Your code will be pasted here */
double f(int n, double a[], double x) {
  double y = 0.0;
  for (int i = n; i >= 0; --i) {
    y = a[i] + x * y;
  }
  return y;
}