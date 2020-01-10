// https://open.kattis.com/problems/primalrepresentation
// 0.87s, damn, so close
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

namespace LinearSieve {

    const int MAXN = 100005;
    ll prime[MAXN] = {0};
    ll num_prime = 0;
    ll isNotPrime[MAXN] = {1, 1};

    // Generate the prime table from 1 to MAXN
    inline static
    void pre() {
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
}

namespace Factorization {

    ll factor[1000];    // Save the result of factorizations
    int tol;    //Count of every prime

    ll mult_mod(ll a, ll b, ll c) { // a * b % c
        a %= c;
        b %= c;
        ll result = 0;
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

    ll pow_mod(ll x, ll n, ll mod) {  // x^n % c
        if (n == 1)
            return x % mod;
        x %= mod;
        ll tmp = x;
        ll result = 1;
        while (n > 0) {
            if ((n & 1) > 0)
                result = mult_mod(result, tmp, mod);
            tmp = mult_mod(tmp, tmp, mod);
            n >>= 1;
        }
        return result;
    }

    bool millerRabinPrimeCheckHelper(ll a, ll n, ll x, ll t) {
        ll result = pow_mod(a, x, n);
        ll last = result;
        for (int i = 1; i <= t; i++) {
            result = mult_mod(result, result, n);
            if (result == 1 && last != 1 && last != n - 1)
                return true;
            last = result;
        }
        return result != 1;
    }

    bool millerRabinPrimeCheck(ll n) {
        const int s = 5;
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if ((n & 1) == 0)
            return false;
        if (n <= 100001 && !LinearSieve::isNotPrime[n])
            return true;
        ll x = n - 1;
        ll t = 0;
        while ((x & 1) == 0) {
            x >>= 1;
            t++;
        }
        for (int i = 0; i < s; i++) {
            ll a = rand() % (n - 1) + 1;
            if (millerRabinPrimeCheckHelper(a, n, x, t))
                return false;
        }
        return true;
    }

    ll gcd(ll a, ll b) { //A gcd func which considers the negative nums
        if (a == 0)
            return 1;
        if (a < 0)
            return gcd(-a, b);
        while (b > 0) {
            ll t;
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll Pollard_rho(ll x, ll c)
    {
        ll i = 1, k = 2;
        ll x0 = rand() % x;
        ll y = x0;
        while (true) {
            i++;
            x0 = (mult_mod(x0, x0, x) + c) % x;
            ll d = gcd(y - x0, x);
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

    void findfac(ll n) {
        if (millerRabinPrimeCheck(n)) {
            factor[tol++] = n;
            return;
        }
        ll p = n;
        while (p >= n)
            p = Pollard_rho(p, rand() % (n - 1) + 1);
        findfac(p);
        findfac(n / p);
    }
}

int main() {

    LinearSieve::pre();
    ll n;
    bool isNegative;
    bool firstItem;
    map<ll, ll> table;

    while (~scanf("%lld", &n)) {

        memset(Factorization::factor, 0, sizeof(ll) * 1000);
        isNegative = false;
        firstItem = true;
        Factorization::tol = 0;
        if (n < 0) {
            n = -n;
            isNegative = true;
        }
        Factorization::findfac(n);
        sort(Factorization::factor, Factorization::factor + Factorization::tol);

        // stats
        table.clear();
        for (int item = 0; item < Factorization::tol; item++) {
            if (table.find(Factorization::factor[item]) == table.end()) {
                table[Factorization::factor[item]] = 1;
            }
            else
                table[Factorization::factor[item]]++;
        }

        // output
        if (isNegative) {
            printf("-1");
            firstItem = false;
        }
        for (const auto &it : table) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            if (it.second == 1) {
                printf("%lld", it.first);
            } else {
                printf("%lld^%lld", it.first, it.second);
            }
        }
        printf("\n");
    }

    return 0;
}
