#include <math.h>
#include <stdio.h>

int IsTheNumber(const int N);

int main() {
  int n1, n2, i, cnt;

  scanf("%d %d", &n1, &n2);
  cnt = 0;
  for (i = n1; i <= n2; i++) {
    if (IsTheNumber(i))
      cnt++;
  }
  printf("cnt = %d\n", cnt);

  return 0;
}

/* Your code will be pasted here */
int IsTheNumber(const int N) {
  if (N < 0) {
    return 0;
  }

  int a = sqrt((double)N);
  if (a * a != N) {
    return 0;
  }
  int save[12], len = 0;
  int N_copy = N;
  while (N_copy > 0) {

    save[len] = N_copy % 10;
    N_copy = (N_copy - save[len]) / 10;
    ++len;
  }
  if (len == 1) {
    return 0;
  }

  int i, j;
  for (i = 0; i < len - 1; ++i) {
    for (j = i + 1; j < len; ++j) {
      if (save[i] == save[j]) {
        return 1;
      }
    }
  }
  return 0;
}