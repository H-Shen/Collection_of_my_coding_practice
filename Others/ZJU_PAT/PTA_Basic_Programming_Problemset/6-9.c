#include <stdio.h>

int Count_Digit(const int N, const int D);

int main() {
  int N, D;

  scanf("%d %d", &N, &D);
  printf("%d\n", Count_Digit(N, D));
  return 0;
}

/* Your code will be pasted here */
int Count_Digit(const int N, const int D) {
  int N_copy = N;
  if (N_copy < 0) {
    N_copy = -N_copy;
  }
  if (N == 0 && D == 0) {
    return 1;
  }
  int save[10] = {0};
  while (N_copy > 0) {
    ++save[N_copy % 10];
    N_copy /= 10;
  }
  return save[D];
}