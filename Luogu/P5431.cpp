#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

vector<int> a;
vector<int> a_inv;
vector<int> a_prefix_mul_inv;
vector<int> a_prefix_mul;

inline static
ll modpow(ll x, ll y, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, x %= M; y; x = (x * x) % M, y >>= 1) if (y % 2) r = (r * x) % M;
    return r;
}

int main() {

    int n, k;
    ll p;
    IO::read(n, p, k);
    a.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        IO::read(a[i]);
    }
    a_prefix_mul.resize(n + 5);
    a_prefix_mul[0] = 1;
    for (int i = 1; i <= n; ++i) {
        a_prefix_mul[i] = (int)((ll)a_prefix_mul[i - 1] * a[i] % p);
    }
    a_prefix_mul_inv.resize(n + 5);
    a_prefix_mul_inv[n] = (int)modpow(a_prefix_mul[n], p - 2, p);
    for (int i = n; i >= 1; --i) {
        a_prefix_mul_inv[i - 1] = (int)((ll)a_prefix_mul_inv[i] * a[i] % p);
    }
    vector<int>().swap(a);
    a_inv.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        a_inv[i] = (int)((ll)a_prefix_mul_inv[i] * a_prefix_mul[i - 1] % p);
    }
    vector<int>().swap(a_prefix_mul_inv);
    vector<int>().swap(a_prefix_mul);
    ll sum = 0;
    ll k_pow_mod = k % p;
    ll k_pow_mod_copy = k_pow_mod;
    for (int i = 1; i <= n; ++i) {
        sum += k_pow_mod * (ll)a_inv[i] % p;
        k_pow_mod = k_pow_mod * k_pow_mod_copy % p;
    }
    sum %= p;
    IO::writeln(sum);
    return 0;
}