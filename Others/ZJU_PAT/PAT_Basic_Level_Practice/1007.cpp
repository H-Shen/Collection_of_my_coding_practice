#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
int isNotPrime[maxn];
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

const int N = 100050;
int res[N] = {0};
int j = 2;

int main() {
    gen(maxn - 5);
    int i;
    int cnt = 0;
    for (i = 1; savePrime[i] < N; ++i) {
        if (savePrime[i] - savePrime[i - 1] == 2) {
            ++cnt;
        }
        for (; j <= savePrime[i]; ++j) {
            res[j] = cnt;
        }
    }
    int m;
    scanf("%d", &m);
    printf("%d\n", res[m - 1]);

    return 0;
}