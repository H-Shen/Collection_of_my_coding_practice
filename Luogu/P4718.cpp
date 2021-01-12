#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

namespace Factorization {

    constexpr int MAX_PRIME_FACTORS = 1000;
    ll factor[MAX_PRIME_FACTORS];    // Save the result of the factorization
    int tol;    // Count of prime factors

    ll multmod(ll a, ll b, ll m) {
        a = (a % m + m) % m;
        b = (b % m + m) % m;
        return ((a * b - (ll) ((ld) a / m * b) * m) % m + m) % m;
    }

    ll powmod(ll a, ll b, ll m) {
        if (m == 1) return 0;
        ll r;
        for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1)
            if (b % 2) r = multmod(r, a, m);
        return r;
    }

    // Runtime: O(logalogb)
    ll bingcd(ll a, ll b) {
        if (a < 0 || b < 0) return bingcd(abs(a), abs(b));
        if (!a || !b) return a | b;
        unsigned shift = __builtin_ctz(a | b);
        a >>= __builtin_ctz(a);
        do {
            b >>= __builtin_ctz(b);
            if (a > b) swap(a, b);
            b -= a;
        } while (b);
        return a << shift;
    }

    bool miller_rabin_subroutine(ll a, ll n, ll x, ll t) {
        ll result = powmod(a, x, n);
        ll last = result;
        for (int i = 1; i <= t; i++) {
            result = multmod(result, result, n);
            if (result == 1 && last != 1 && last != n - 1)
                return true;
            last = result;
        }
        return result != 1;
    }

    bool miller_rabin(ll n) {
        constexpr int R = 5;   // rounds
        if (n < 2) return false;
        if (n == 2) return true;
        if ((n & 1) == 0) return false;
        ll x = n - 1, t = 0;
        ll a;
        while ((x & 1) == 0) {
            x >>= 1;
            ++t;
        }
        for (int i = 0; i < R; ++i) {
            a = rand() % (n - 1) + 1;
            if (miller_rabin_subroutine(a, n, x, t)) return false;
        }
        return true;
    }

    // Base on Brent's implementation
    ll pollard_rho(ll n) {
        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;
        ll w = 0, a = 0, val = 1, g;
        ll c = rand() % (n - 1) + 1;
        for (ll k = 2;; k <<= 1, a = w, val = 1) {
            for (ll i = 1; i <= k; ++i) {
                w = (multmod(w, w, n) + c) % n;
                val = multmod(val, abs(w - a), n);
                if (! (i & 127)) {
                    g = bingcd(val, n);
                    if (g > 1) return g;
                }
            }
            g = bingcd(val, n);
            if (g > 1) return g;
        }
    }

    void find_prime_factors(ll n) {
        if (miller_rabin(n)) {
            factor[tol++] = n;
            return;
        }
        ll p = n;
        while (p >= n) p = pollard_rho(n);
        find_prime_factors(p);
        find_prime_factors(n / p);
    }
}

int main() {

    int t;
    IO::read(t);
    ll n;
    while (t--) {
        IO::read(n);
        Factorization::find_prime_factors(n);
        if (Factorization::tol == 1) {
            puts("Prime");
        } else {
            IO::writeln(*max_element(Factorization::factor, Factorization::factor + Factorization::tol));
        }
        Factorization::tol = 0;
    }
    return 0;
}