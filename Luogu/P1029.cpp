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

int main() {

    ll x, y, p, q;
    IO::read(x, y);
    ll temp = x * y;
    ll ans = 0;
    ll p_upper = static_cast<ll>(sqrt(static_cast<double>(temp))) + 1;
    for (p = 1; p <= p_upper; ++p) {
        if (temp > p && temp % p == 0) {
            q = temp / p;
            if (p <= q && __gcd(p, q) == x) {
                if (p == q) {
                    ++ans;
                } else {
                    ans += 2;
                }
            }
        }
    }
    IO::writeln(ans);

    return 0;
}
