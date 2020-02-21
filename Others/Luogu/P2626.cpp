#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr ll MOD = 2147483648;

vector<ll> A = {1,1,2,3,5};

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

    // (a + b) % c = (a%c + b%c) %c
    ll temp;
    while (A.size() <= 48) {
        temp = (A.at(A.size() - 1) % MOD + A.at(A.size() - 2) % MOD) % MOD;
        A.emplace_back(temp);
    }
    int n;
    scanf("%d", &n);
    ll result = A.at(n - 1);
    if (result == 1) {
        printf("1=1\n");
    } else {
        Factorization::findfac(result);
        sort(Factorization::factor, Factorization::factor + Factorization::tol);
        printf("%lld=", result);
        bool first_item = true;
        for (int i = 0; i < Factorization::tol; ++i) {
            if (first_item) {
                first_item = false;
            } else {
                printf("*");
            }
            printf("%lld", Factorization::factor[i]);
        }
        printf("\n");
    }

    return 0;
}
