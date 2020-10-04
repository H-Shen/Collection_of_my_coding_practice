#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

inline static
ll modpow(ll a, ll p, ll M) {
    if (M == 1) {return 0;}ll r{};
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

inline static
ll solve(const ll &n) {
    if (n < 3) {
        return n;
    }
    ll result;
    switch (n % 3) {
        case 0:
            result = modpow(3, n / 3, MOD);
            break;
        case 1:
            result = 4 * modpow(3, (n - 4) / 3, MOD);
            break;
        default:
            result = 2 * modpow(3, (n - 2) / 3, MOD);
            break;
    }
    return result % MOD;
}

int main() {
    int t;
    IO::read(t);
    ll n;
    while (t--) {
        IO::read(n);
        IO::writeln(solve(n));
    }
    return 0;
}