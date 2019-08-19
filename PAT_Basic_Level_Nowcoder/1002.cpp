#include <bits/stdc++.h>

int s[] = {1, 2, 0, 2, 2, 1, 0, 1};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf(s[n % 8] != 0 ? "No\n" : "Yes\n");
    }
    return 0;
}