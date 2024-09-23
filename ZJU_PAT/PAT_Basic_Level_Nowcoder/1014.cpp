#include <bits/stdc++.h>

int a(int n) {
    int x = 2;
    int s = 0;
    while (x * x <= n) {
        if (n % x == 0) {
            s++;
            while (n % x == 0) {
                n /= x;
            }
        }
        x++;
    }
    if (n > 1) {
        s++;
    }
    return s;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", a(n));
    }
    return 0;
}