#include <bits/stdc++.h>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        int s = 0;
        for (int i = 2; i <= n; i++)
            s = (s + m) % i;
        printf("%d\n", s + 1);
    }
    return 0;
}