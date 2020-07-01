#include <iostream>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

inline
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
inline
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

inline
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

int main() {

    int t;
    ll val;
    IO::read(t);
    while (t--) {
        IO::read(val);
        if (millerRabinPrimeCheck(val)) {
            fputs("YES\n", stdout);
        } else {
            fputs("NO\n", stdout);
        }
    }

    return 0;
}
