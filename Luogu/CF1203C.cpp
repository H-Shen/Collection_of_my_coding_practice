#include <bits/extc++.h>

using namespace std;
using ll = long long;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = _getchar_nolock(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = _getchar_nolock();
        while (isdigit(c)) t = t * 10 + c - 48, c = _getchar_nolock();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, _putchar_nolock('-');
        if (x > 9) write(x / 10);
        _putchar_nolock(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        _putchar_nolock('\n');
    }
}
#else
namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}
#endif

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

    ll Pollard_rho(ll x, ll c) {
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {

    int n;
    IO::read(n);
    ll gcd_val, val;
    IO::read(gcd_val);
    for (int i = 1; i < n; ++i) {
        IO::read(val);
        gcd_val = gcd(gcd_val, val);
    }
    ll number_of_factors = 1;
    if (gcd_val != 1) {
        Factorization::findfac(gcd_val);
        sort(Factorization::factor, Factorization::factor + Factorization::tol);
        unordered_map<ll, ll, custom_hash> table;
        for (int item = 0; item < Factorization::tol; item++) {
            ++table[Factorization::factor[item]];
        }
        // Calculate the number of factors of gcd_val
        for (const auto &[k, v] : table) {
            number_of_factors *= (v + 1);
        }
    }
    IO::writeln(number_of_factors);

    return 0;
}
