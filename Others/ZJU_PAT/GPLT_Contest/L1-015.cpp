#include <bits/stdc++.h>

int main() {

    int N, M;
    char ch;
    scanf("%d %c", &N, &ch);
    if (N % 2 == 0) {
        M = N / 2;
    } else {
        M = static_cast<int>(N / 2) + 1;
    }
    int i, j;
    for (i = 1; i <= M; ++i) {
        for (j = 1; j <= N; ++j) {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}
