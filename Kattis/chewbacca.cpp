// https://open.kattis.com/problems/chewbacca
//
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

ll solve(ll x, ll y, ll k) {
    if (k == 1) {
        return y - x;
    }
    ll steps = 0;
    ll total = x;
    ll counter = 0;
    while (total != 1) {
        ++counter;
        total = (total - 2) / k + 1;
    }
    ++counter;
    ll result = 0;
    ll nodes_of_current_level = 1;
    for (ll i = 1; i <= counter; ++i) {
        result += nodes_of_current_level;
        nodes_of_current_level *= k;    // since each node has k children
    }
    while (result < y) {
        y = (y - 2) / k + 1;
        ++steps;
    }
    while (y != x) {
        y = (y - 2) / k + 1;
        x = (x - 2) / k + 1;
        steps += 2;
    }
    return steps;
}

int main() {

    ll n, k, x, y;
    int q;
    IO::read(n, k, q);
    while (q--) {
        IO::read(x, y);
        if (x > y) {
            swap(x, y);
        }
        IO::writeln(solve(x, y, k));
    }
    return 0;
}
