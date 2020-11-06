#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MAXN = 100005;

namespace Factorization {

    ll prime[MAXN] = {0};
    ll num_prime = 0;
    ll isNotPrime[MAXN] = {1, 1};

    // Generate the prime table from 1 to MAXN
    inline static
    void getPrimes() {
        for (ll i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (ll j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j]))
                    break;
            }
        }
    }

    // Calculate the number of factor p in n! (Remember this!)
    inline static
    ll calcOfAFactor(ll n, ll p) {
        ll result = 0;
        while (n != 0) {
            n /= p;
            result += n;
        }
        return result;
    }

    // The main logic
    inline static
    bool judge(ll n, ll m) {

        // Case 1:
        if (m == 0) {
            return false;
        }

        ll counter;
        for (ll i = 0; i < num_prime && prime[i] <= m; i++) {
            if (m % prime[i] == 0) {
                counter = 0;
                while (m % prime[i] == 0) {
                    ++counter;
                    m /= prime[i];
                }
                // Case 2:
                if (calcOfAFactor(n, prime[i]) < counter) {
                    return false;
                }
            }
        }
        return !(m > 1 && n < m);
    }
}

int main() {

    // pre
    Factorization::getPrimes();
    ll n, m;
    while (~scanf("%llu %llu", &n, &m)) {
        if (Factorization::judge(n, m)) {
            printf("%llu divides %llu!\n", m, n);
        } else {
            printf("%llu does not divide %llu!\n", m, n);
        }
    }

    return 0;
}