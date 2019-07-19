// https://www.nowcoder.com/practice/4f0c1e21010e4d849bde5297148e81d9

#include <stdio.h>

int K(int N, int M) {
    if (M == 0 || N == 1)
        return 1;
    if (N > M)
        return K(M, M);
    return K(N - 1, M) + K(N, M - N);
}

int main(void) {
    int M, N;
    scanf("%d %d", &M, &N);
    printf("%d\n", K(N, M));
    return 0;
}