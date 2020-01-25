// https://open.kattis.com/problems/fractionallotion
//
#include <bits/extc++.h>

using namespace std;
constexpr int N = 10003;
constexpr int MAX_FACTORS = 1000;

namespace Factorization {

    int prime[N] = {0}, num_prime = 0;
    int isNotPrime[N] = {1, 1};

    void sieve() {
        for (int i = 2; i < N; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j]))
                    break;
            }
        }
    }

    int mult_mod(int a, int b, int c) { // a * b % c
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

    int factor[MAX_FACTORS];    // Save the result of factorizations
    int tol;    // Count of every prime

    int gcd(int a, int b) { // A gcd func which covers the negative nums
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
        if (!isNotPrime[n]) {
            factor[tol++] = n;
            return;
        }
        int p = n;
        while (p >= n)
            p = Pollard_rho(p, rand() % (n - 1) + 1);
        findfac(p);
        findfac(n / p);
    }

    unordered_map<int, int> getPrimeFactors(int n) {
        memset(factor, 0, sizeof(int) * 1000);
        unordered_map<int, int> result;
        if (n == 2 || n == 3) {
            result[n] = 1;
            return result;
        }
        tol = 0;
        findfac(n);
        for (int item = 0; item < tol; item++) {
            ++result[factor[item]];
        }
        return result;
    }
}

int main() {

    // pre
    Factorization::sieve();

    // input
    int n, unused, sumOfFactors;
    unordered_map<int, int> p;
    while (~scanf("%d/%d", &unused, &n)) {
        if (n == 1) {
            printf("1\n");
        } else {
            // factorization of n
            p = Factorization::getPrimeFactors(n);
            sumOfFactors = 1;
            // get number of factors of n * n
            for (const auto &i : p) {
                sumOfFactors = sumOfFactors * (2 * i.second + 1);
            }
            // divide 2 since {x, y} is the same as {y, x}
            printf("%d\n", (sumOfFactors + 1) / 2);
        }
    }

    return 0;
}
