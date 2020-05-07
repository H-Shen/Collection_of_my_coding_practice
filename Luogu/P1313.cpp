#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 10007;

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

constexpr int MAXN = 10050;
ll fac[MAXN];

void init(ll p) {
    fac[0] = 1;
    for (ll i = 1; i <= p; ++i) {
        fac[i] = fac[i - 1] * i % p;
    }
}

inline static
ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

ll C(ll n, ll m, ll p) {
    if (m > n) {
        return 0;
    }
    return fac[n] * modpow(fac[m] * fac[n - m], p - 2, p) % p;
}

ll Lucas(ll n, ll m, ll p) {
    if (m == 0) return 1;
    return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

int main() {

    init(MOD);
    ll a, b, k, n, m;
    IO::read(a, b, k, n, m);
    IO::writeln(modpow(a, n, MOD) * modpow(b, m, MOD) % MOD * Lucas(k, n, MOD) % MOD);

    return 0;
}
