#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
int isNotPrime[maxn];   //0 for Prime
int savePrime[maxn];
int savePrimeLen = 0;

void sieve(int n) {
    int m = static_cast<int>(sqrt(n + 0.5));
    memset(isNotPrime, 0, sizeof(isNotPrime));
    int i, j;
    for (i = 3; i <= m; i += 2) {
        if (isNotPrime[i] == 0) {
            for (j = i * i; j <= n; j += i) {
                isNotPrime[j] = 1;
            }
        }
        if (i * i > n) {
            break;
        }
    }
}

void gen(int n) {
    sieve(n);
    savePrimeLen = 1;
    savePrime[0] = 2;

    int i;
    for (i = 3; i <= n; i += 2) {
        if (isNotPrime[i] == 0) {
            savePrime[savePrimeLen] = i;
            ++savePrimeLen;
        }
    }
}

int main() {
    gen(maxn - 5);
    int i, m, n;
    scanf("%d %d", &m, &n);
    int cnt = 0;
    for (i = m - 1; i <= n - 1; ++i, ++cnt) {
        if (cnt % 10 == 9 || i == n - 1) {
            printf("%d\n", savePrime[i]);
        } else {
            printf("%d ", savePrime[i]);
        }
    }
    return 0;
}