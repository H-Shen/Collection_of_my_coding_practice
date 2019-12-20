#include <bits/stdc++.h>

int main() {
    int T, K;
    scanf("%d %d", &T, &K);

    int n1, b, t, n2;
    while (K--) {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        if (T == 0) {
            printf("Game Over.\n");
            break;
        } else if (t > T) {
            printf("Not enough tokens.  Total = %d.\n", T);
        } else if (b == 0 && n2 > n1) {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        } else if (b == 0 && n2 < n1) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        } else if (b == 1 && n2 > n1) {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        } else if (b == 1 && n2 < n1) {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        }
    }
    return 0;
}