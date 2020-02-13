#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace SievePrimes {

    vector<bool> is_prime;
    bool check_prime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    void init(int maxn) {
        for (int i = 0; i < maxn; ++i) {
            is_prime.emplace_back(check_prime(i));
        }
    }
}

namespace Factorization {

    int factor[1000];    // Save the result of factorizations
    int tol;    //Count of every prime

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

    int gcd(int a, int b) { //A gcd func which considers the negative nums
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
        if (SievePrimes::is_prime[n]) {
            factor[tol++] = n;
            return;
        }
        int p = n;
        while (p >= n)
            p = Pollard_rho(p, rand() % (n - 1) + 1);
        findfac(p);
        findfac(n / p);
    }

    unordered_map<int, int> process(int n) {
        unordered_map<int, int> result;
        if (n <= 1) {
            return result;
        }
        memset(factor, 0, sizeof(int) * 1000);
        tol = 0;
        findfac(n);
        for (int i = 0; i < tol; ++i) {
            ++result[factor[i]];
        }
        return result;
    }
}

int main() {

    int n;
    scanf("%d", &n);
    SievePrimes::init(n + 5);
    unordered_map<int, int> sum;
    for (int i = 1; i <= n; ++i) {
        auto p = Factorization::process(i);
        for (const auto &[k, v] : p) {
            sum[k] += v;
        }
    }
    vector<pair<int, int> > output(sum.begin(), sum.end());
    sort(output.begin(), output.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
        return (lhs.first < rhs.first);
    });
    for (const auto &[k, v] : output) {
        printf("%d %d\n", k, v);
    }

    return 0;
}
