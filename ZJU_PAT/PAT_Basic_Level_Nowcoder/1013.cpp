#include <bits/stdc++.h>

using namespace std;

const int N = 1000003;
int prime[N] = {0};
int num_prime = 0;
int isNotPrime[N] = {1, 1};
unordered_set<int> primeSet;

//Sieve primes in linear time

void pre() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
    for (int i = 0; i < num_prime; ++i) {
        primeSet.insert(prime[i]);
    }
}

int mult_mod(int a, int b, int c) {
    a %= c;
    b %= c;
    int result = 0;
    while (b > 0) {
        if (b & 1) {
            result += a;
            result %= c;
        }
        a <<= 1;
        if (a >= c)
            a %= c;
        b >>= 1;
    }
    return result;
}

int factor[1000];
int tol;

int gcd(int a, int b) {
    if (a == 0)
        return 1;
    if (a < 0)
        return gcd(-a, b);
    while (b > 0) {
        int t;
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int Pollard_rho(int x, int c) {
    int i = 1, k = 2;
    int x0 = rand() % x;
    int y = x0;
    while (true) {
        i++;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        int d = gcd(y - x0, x);
        if (d != 1 && d != x)
            return d;
        if (y == x0)
            return x;
        if (i == k) {
            y = x0;
            k += k;
        }
    }
}

void findfac(int n) {
    if (primeSet.find(n) != primeSet.end()) {
        factor[tol++] = n;
        return;
    }
    int p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p);
    findfac(n / p);
}

int main() {
    pre();
    int n;
    while (~scanf("%d", &n)) {
        if (primeSet.find(n) != primeSet.end()) {
            printf("%d = %d\n", n, n);
        } else {
            memset(factor, 0, sizeof(int) * 1000);
            tol = 0;
            findfac(n);
            sort(factor, factor + tol);

            printf("%d = ", n);
            for (int item = 0; item < tol - 1; item++) {
                printf("%d * ", factor[item]);
            }
            printf("%d\n", factor[tol - 1]);
        }
    }
    return 0;
}