// https://open.kattis.com/problems/distance

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template <typename T>
    inline void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n)
            t = -t;
    }

    template <typename T, typename... Args>
    inline void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template <typename T>
    inline void write(T x) {
        if (x < 0)
            x = -x, putchar_unlocked('-');
        if (x > 9)
            write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr int MAXN = 200005;
ll A[MAXN];
ll B[MAXN];
ll n;

int main() {
    IO::read(n);
    for (int i = 0; i < n; ++i) IO::read(A[i], B[i]);
    sort(A, A + n);
    sort(B, B + n);
    ll ans = 0;
    ll temp = 0;
    for (ll i = 0; i < n; ++i) {
        ans += (A[i] * i - temp);
        temp += A[i];
    }
    temp = 0;
    for (ll i = 0; i < n; ++i) {
        ans += (B[i] * i - temp);
        temp += B[i];
    }
    IO::writeln(ans);
    return 0;
}
